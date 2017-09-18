module hermes

  ! TO DO
  ! -----
  !
  ! * Handle unsigned integers, characters, and vectors in:
  !   - server_reply_with_result

  use, intrinsic :: iso_c_binding
  use :: xdr
  use :: uint
  use :: zmq
  implicit none
  private

  type, abstract, public :: serializable
    contains
      procedure(serializable_read), public, deferred :: read
      procedure(serializable_write), public, deferred :: write
      procedure(serializable_size), public, deferred :: size
  end type

  type, private :: header
      logical, private :: has_more
      character(kind = c_char, len = 8), private :: encoding
    contains
      procedure, private :: header_init
      procedure, private :: header_recv
      procedure, public :: header_send
      procedure, public :: more => header_more
      procedure, public :: magic => header_magic
      procedure, public :: number => header_number
  end type

  type, public, extends(header) :: request_header
    contains
      procedure, public :: send => request_header_send
      procedure, public :: recv => request_header_recv
  end type

  type, public, extends(header) :: reply_header
    contains
      procedure, public :: send => reply_header_send
      procedure, public :: recv => reply_header_recv
  end type

  type, public :: iarchive
      type(xdr_t), private :: xdr
    contains
      generic, public :: create => iarchive_create, iarchive_create_c_ptr
      procedure, public :: destroy => iarchive_destroy
      procedure, public :: value => iarchive_read
      procedure, public :: unsigned => iarchive_read_unsigned
      procedure, public :: character => iarchive_read_character
      procedure, public :: string => iarchive_read_string
      procedure, public :: length => iarchive_read_vector_length
      procedure, public :: vector => iarchive_read_vector
      procedure, public :: unsigned_vector => iarchive_read_unsigned_vector
      procedure, public :: character_vector => iarchive_read_character_vector

      procedure, private :: iarchive_create
      procedure, private :: iarchive_create_c_ptr
  end type

  type, public :: oarchive
      type(xdr_t), private :: xdr
    contains
      procedure, public :: create => oarchive_create
      procedure, public :: destroy => oarchive_destroy
      procedure, public :: value => oarchive_write
      procedure, public :: unsigned => oarchive_write_unsigned
      procedure, public :: character => oarchive_write_character
      procedure, public :: vector => oarchive_write_vector
      procedure, public :: unsigned_vector => oarchive_write_unsigned_vector
      procedure, public :: character_vector => oarchive_write_character_vector
  end type

  type, public :: archive_sizer
    contains
      procedure, public :: value => archive_sizer_value
      procedure, public :: unsigned => archive_sizer_unsigned
      procedure, public :: character => archive_sizer_character
      procedure, public :: vector => archive_sizer_vector
      procedure, public :: unsigned_vector => archive_sizer_unsigned_vector
      procedure, public :: character_vector => archive_sizer_character_vector
  end type

  type, public :: client
      type(c_ptr), public :: socket
      type(zmq_msg_t), public :: exception
      integer(kind = c_int32_t), public :: exception_id
    contains
      procedure, public :: open => client_open
      procedure, public :: close => client_close

      procedure, public :: get_header => client_get_header
      procedure, public :: get_result_value => client_get_result_value
      procedure, public :: get_result_unsigned => client_get_result_unsigned
      procedure, public :: get_result_character => client_get_result_character
      procedure, public :: get_result_string => client_get_result_string
      procedure, public :: get_result_vector => client_get_result_vector
      procedure, public :: get_result_unsigned_vector => client_get_result_unsigned_vector
      procedure, public :: get_result_character_vector => client_get_result_character_vector
      procedure, public :: get_exception => client_get_exception
      procedure, public :: catch_exception => client_catch_exception
  end type

  type, abstract, public :: server
      type(c_ptr), public :: socket
      type(zmq_msg_t), private :: exception
      integer(kind = c_int32_t), private :: exception_id
    contains
      procedure, public :: open => server_open
      procedure, public :: close => server_close
      generic, public :: serve => server_serve, server_serve_count
      procedure(server_serve_once), public, deferred :: serve_once

      procedure, private :: server_serve
      procedure, private :: server_serve_count
      procedure, public :: get_request => server_get_request
      procedure, public :: outcome => server_outcome
      procedure, public :: undefined => server_undefined
      procedure, public :: throw_error => server_throw_error
      procedure, public :: throw_exception => server_throw_exception
      procedure, public :: reply_with_error => server_reply_with_error
      procedure, public :: reply_with_exception => server_reply_with_exception
      procedure, public :: reply_with_result_value => server_reply_with_result_value
      procedure, public :: reply_with_result_unsigned => server_reply_with_result_unsigned
      procedure, public :: reply_with_result_character => server_reply_with_result_character
      procedure, public :: reply_with_result_vector => server_reply_with_result_vector
      procedure, public :: reply_with_result_unsigned_vector => server_reply_with_result_unsigned_vector
      procedure, public :: reply_with_result_character_vector => server_reply_with_result_character_vector
      procedure, public :: reply_with_void => server_reply_with_void
  end type

  interface

    function serializable_read(self, a_archive) result(status)
      import serializable
      import iarchive
      class(serializable) :: self
      type(iarchive), intent(inout) :: a_archive
      logical :: status
    end function

    function serializable_write(self, a_archive) result(status)
      import serializable
      import oarchive
      class(serializable) :: self
      type(oarchive), intent(inout) :: a_archive
      logical :: status
    end function

    function serializable_size(self, a_sizer) result(nbytes)
      use, intrinsic :: iso_c_binding, only : c_size_t
      import serializable
      import archive_sizer
      class(serializable) :: self
      type(archive_sizer), intent(in) :: a_sizer
      integer(kind = c_size_t) :: nbytes
    end function

    subroutine server_serve_once(self)
      import server
      class(server) :: self
    end subroutine

  end interface

contains

  function hash(a_text) result(value)
    character(kind = c_char, len = *), intent(in) :: a_text
    integer(kind = c_int64_t) :: value

    integer :: n

    value = X'811C9DC5'
    do n = 1, len(a_text)
      value = ieor(value, ichar(a_text(n:n)))
      value = value * X'01000193'
      value = iand(value, X'FFFFFFFF')
    end do
  end function

  subroutine header_init(self, a_magic, a_number, a_more)
    class(header) :: self
    integer(kind = c_int8_t), intent(in) :: a_magic
    integer(kind = c_int32_t), intent(in) :: a_number
    logical, intent(in) :: a_more

    self%has_more = a_more
    self%encoding(1:1) = transfer(a_magic, self%encoding(1:1))
    self%encoding(2:4) = transfer(0, self%encoding(2:4))
    self%encoding(5:8) = transfer(a_number, self%encoding(5:8))
  end subroutine

  function header_recv(self, a_socket) result(status)
    class(header) :: self
    type(c_ptr), intent(inout) :: a_socket
    logical :: status

    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code
    character(kind = c_char, len = 8), pointer :: buffer

    status = zmq_msg_init(message) >= 0
    if (status) then
      status = zmq_msg_recv(message, a_socket, 0) == 8_c_size_t
      call c_f_pointer(zmq_msg_data(message), buffer)
      self%encoding = transfer(buffer, self%encoding)
      self%has_more = zmq_msg_more(message)
      code = zmq_msg_close(message)
    end if
  end function

  function header_send(self, a_socket) result(status)
    class(header) :: self
    type(c_ptr), intent(inout) :: a_socket
    logical :: status

    type(zmq_msg_t) :: message
    integer(kind = c_int) :: flags
    integer(kind = c_int) :: nbytes
    character(kind = c_char, len = 8), pointer :: buffer

    status = zmq_msg_init_size(message, 8_c_size_t) >= 0
    if (status) then
      call c_f_pointer(zmq_msg_data(message), buffer)
      buffer = transfer(self%encoding, buffer)
      flags = merge(ZMQ_SNDMORE, 0, self%has_more)
      nbytes = zmq_msg_send(message, a_socket, flags)
      status = nbytes == 8
    end if
  end function

  function header_more(self) result(more)
    class(header) :: self
    logical :: more

    more = self%has_more
  end function

  function header_magic(self) result(magic)
    class(header) :: self
    integer(kind = c_int8_t) :: magic

    magic = transfer(self%encoding(1:1), magic)
  end function

  function header_number(self) result(number)
    class(header) :: self
    integer(kind = c_int32_t) :: number

    number = transfer(self%encoding(5:8), number)
  end function

  function request_header_send(self, a_socket, a_number, a_more) result(status)
    class(request_header) :: self
    type(c_ptr), intent(inout) :: a_socket
    integer(kind = c_int32_t), intent(in) :: a_number
    logical, intent(in) :: a_more
    logical :: status

    call self%header_init(1_c_int8_t, a_number, a_more)
    status = self%header_send(a_socket)
  end function

  function request_header_recv(self, a_socket) result(status)
    class(request_header) :: self
    type(c_ptr), intent(inout) :: a_socket
    logical :: status

    status = self%header_recv(a_socket) .and. self%magic() == 1_c_int8_t
  end function

  function reply_header_send(self, a_socket, a_number, a_more) result(status)
    class(reply_header) :: self
    type(c_ptr), intent(inout) :: a_socket
    integer(kind = c_int32_t), intent(in) :: a_number
    logical, intent(in) :: a_more
    logical :: status

    call self%header_init(2_c_int8_t, a_number, a_more)
    status = self%header_send(a_socket)
  end function

  function reply_header_recv(self, a_socket) result(status)
    class(reply_header) :: self
    type(c_ptr), intent(inout) :: a_socket
    logical :: status

    status = self%header_recv(a_socket) .and. self%magic() == 2_c_int8_t
  end function

  subroutine iarchive_create(self, a_data, a_size)
    class(iarchive) :: self
    character(kind = c_char, len = :), pointer, intent(in) :: a_data
    integer(kind = c_size_t), intent(in) :: a_size

    call self%xdr%create(a_data, a_size)
  end subroutine

  subroutine iarchive_create_c_ptr(self, a_data, a_size)
    class(iarchive) :: self
    type(c_ptr), intent(in) :: a_data
    integer(kind = c_size_t), intent(in) :: a_size
    character(kind = c_char, len = :), pointer :: buffer

    call c_f_pointer(a_data, buffer)
    call self%xdr%create(buffer, a_size)
  end subroutine

  subroutine iarchive_destroy(self)
    class(iarchive) :: self

    call self%xdr%destroy()
  end subroutine

  function iarchive_read(self, a_object) result(status)
    class(iarchive) :: self
    class(*), intent(out) :: a_object
    logical :: status

    select type(a_object)
      type is (logical)
        status = self%xdr%get(a_object)
      type is (integer(kind = c_int8_t))
        status = self%xdr%get(a_object)
      type is (integer(kind = c_int16_t))
        status = self%xdr%get(a_object)
      type is (integer(kind = c_int32_t))
        status = self%xdr%get(a_object)
      type is (integer(kind = c_int64_t))
        status = self%xdr%get(a_object)
      type is (real(kind = c_float))
        status = self%xdr%get(a_object)
      type is (real(kind = c_double))
        status = self%xdr%get(a_object)
      type is (character(kind = c_char, len = *))
        status = self%xdr%get(a_object)
      class is (serializable)
        status = a_object%read(self)
    end select
  end function

  function iarchive_read_unsigned(self, a_object) result(status)
    class(iarchive) :: self
    class(*), intent(out) :: a_object
    logical :: status

    select type(a_object)
      type is (uint8_t)
        status = self%xdr%get_unsigned(a_object)
      type is (uint16_t)
        status = self%xdr%get_unsigned(a_object)
      type is (uint32_t)
        status = self%xdr%get_unsigned(a_object)
      type is (uint64_t)
        status = self%xdr%get_unsigned(a_object)
    end select
  end function

  function iarchive_read_character(self, a_value) result(status)
    class(iarchive) :: self
    character(kind = c_char), intent(out) :: a_value
    logical :: status

    status = self%xdr%get_character(a_value)
  end function

  function iarchive_read_string(self, a_string) result(status)
    class(iarchive) :: self
    character(kind = c_char, len = :), allocatable, intent(out) :: a_string
    logical :: status

    status = self%xdr%allocate_string(a_string)
  end function

  function iarchive_read_vector_length(self, a_length) result(status)
    class(iarchive) :: self
    integer(kind = c_int32_t), intent(out) :: a_length
    logical :: status

    status = self%value(a_length)
  end function

  function iarchive_read_vector(self, a_objects) result(status)
    class(iarchive) :: self
    class(*), dimension(:), intent(inout) :: a_objects
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    status = .true.
    length = size(a_objects)
    do n = 1, length
      status = status .and. self%value(a_objects(n))
    end do
  end function

  function iarchive_read_unsigned_vector(self, a_objects) result(status)
    class(iarchive) :: self
    class(*), dimension(:), intent(inout) :: a_objects
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    status = .true.
    length = size(a_objects)
    do n = 1, length
      status = status .and. self%unsigned(a_objects(n))
    end do
  end function

  function iarchive_read_character_vector(self, a_values) result(status)
    class(iarchive) :: self
    character(kind = c_char), dimension(:), intent(inout) :: a_values
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    status = .true.
    length = size(a_values)
    do n = 1, length
      status = status .and. self%character(a_values(n))
    end do
  end function

  subroutine oarchive_create(self, a_data, a_size)
    class(oarchive) :: self
    character(kind = c_char, len = :), pointer, intent(in) :: a_data
    integer(kind = c_size_t), intent(in) :: a_size

    call self%xdr%create(a_data, a_size)
  end subroutine

  subroutine oarchive_destroy(self)
    class(oarchive) :: self

    call self%xdr%destroy()
  end subroutine

  function oarchive_write(self, a_object) result(status)
    class(oarchive) :: self
    class(*), intent(in) :: a_object
    logical :: status

    select type(a_object)
      type is (logical)
        status = self%xdr%put(a_object)
      type is (integer(kind = c_int8_t))
        status = self%xdr%put(a_object)
      type is (integer(kind = c_int16_t))
        status = self%xdr%put(a_object)
      type is (integer(kind = c_int32_t))
        status = self%xdr%put(a_object)
      type is (integer(kind = c_int64_t))
        status = self%xdr%put(a_object)
      type is (real(kind = c_float))
        status = self%xdr%put(a_object)
      type is (real(kind = c_double))
        status = self%xdr%put(a_object)
      type is (character(kind = c_char, len = *))
        status = self%xdr%put(a_object)
      class is (serializable)
        status = a_object%write(self)
    end select
  end function

  function oarchive_write_unsigned(self, a_object) result(status)
    class(oarchive) :: self
    class(*), intent(in) :: a_object
    logical :: status

    select type(a_object)
      type is (uint8_t)
        status = self%xdr%put_unsigned(a_object)
      type is (uint16_t)
        status = self%xdr%put_unsigned(a_object)
      type is (uint32_t)
        status = self%xdr%put_unsigned(a_object)
      type is (uint64_t)
        status = self%xdr%put_unsigned(a_object)
    end select
  end function

  function oarchive_write_character(self, a_value) result(status)
    class(oarchive) :: self
    character(kind = c_char), intent(in) :: a_value
    logical :: status

    status = self%xdr%put_character(a_value)
  end function

  function oarchive_write_vector(self, a_objects) result(status)
    class(oarchive) :: self
    class(*), dimension(:), intent(in) :: a_objects
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_objects)
    status = self%value(length)
    do n = 1, length
      status = status .and. self%value(a_objects(n))
    end do
  end function

  function oarchive_write_unsigned_vector(self, a_objects) result(status)
    class(oarchive) :: self
    class(*), dimension(:), intent(in) :: a_objects
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_objects)
    status = self%value(length)
    do n = 1, length
      status = status .and. self%unsigned(a_objects(n))
    end do
  end function

  function oarchive_write_character_vector(self, a_values) result(status)
    class(oarchive) :: self
    character(kind = c_char), dimension(:), intent(in) :: a_values
    logical :: status

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_values)
    status = self%value(length)
    do n = 1, length
      status = status .and. self%character(a_values(n))
    end do
  end function

  function archive_sizer_value(self, a_object) result(nbytes)
    class(archive_sizer) :: self
    class(*), intent(in) :: a_object
    integer(kind = c_size_t) :: nbytes

    select type(a_object)
      type is (logical)
        nbytes = 4_c_size_t
      type is (integer(kind = c_int8_t))
        nbytes = 4_c_size_t
      type is (integer(kind = c_int16_t))
        nbytes = 4_c_size_t
      type is (integer(kind = c_int32_t))
        nbytes = 4_c_size_t
      type is (integer(kind = c_int64_t))
        nbytes = 8_c_size_t
      type is (real(kind = c_float))
        nbytes = 4_c_size_t
      type is (real(kind = c_double))
        nbytes = 8_c_size_t
      type is (character(kind = c_char, len = *))
        nbytes = 4 * ((len(a_object, kind = c_size_t) + 3) / 4)
      class is (serializable)
        nbytes = a_object%size(self)
    end select
  end function

  function archive_sizer_unsigned(self, a_object) result(nbytes)
    class(archive_sizer) :: self
    class(*), intent(in) :: a_object
    integer(kind = c_size_t) :: nbytes

    select type(a_object)
      type is (uint8_t)
        nbytes = 4_c_size_t
      type is (uint16_t)
        nbytes = 4_c_size_t
      type is (uint32_t)
        nbytes = 4_c_size_t
      type is (uint64_t)
        nbytes = 8_c_size_t
    end select
  end function

  function archive_sizer_character(self, a_value) result(nbytes)
    class(archive_sizer) :: self
    character(kind = c_char), intent(in) :: a_value
    integer(kind = c_size_t) :: nbytes

    nbytes = 4_c_size_t
  end function

  function archive_sizer_vector(self, a_objects) result(nbytes)
    class(archive_sizer) :: self
    class(*), dimension(:), intent(in) :: a_objects
    integer(kind = c_size_t) :: nbytes

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_objects)
    nbytes = 4_c_size_t
    do n = 1, length
      nbytes = nbytes + self%value(a_objects(n))
    end do
  end function

  function archive_sizer_unsigned_vector(self, a_objects) result(nbytes)
    class(archive_sizer) :: self
    class(*), dimension(:), intent(in) :: a_objects
    integer(kind = c_size_t) :: nbytes

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_objects)
    nbytes = 4_c_size_t
    do n = 1, length
      nbytes = nbytes + self%unsigned(a_objects(n))
    end do
  end function

  function archive_sizer_character_vector(self, a_values) result(nbytes)
    class(archive_sizer) :: self
    character(kind = c_char), dimension(:), intent(in) :: a_values
    integer(kind = c_size_t) :: nbytes

    integer(kind = c_int32_t) :: n
    integer(kind = c_int32_t) :: length

    length = size(a_values)
    nbytes = 4_c_size_t
    do n = 1, length
      nbytes = nbytes + self%character(a_values(n))
    end do
  end function

  function client_open(self, a_context, a_endpoint, a_type) result(code)
    class(client) :: self
    type(c_ptr), intent(in) :: a_context
    character(kind = c_char, len = *), intent(in) :: a_endpoint
    integer(kind = c_int), intent(in) :: a_type
    integer(kind = c_int) :: code

    self%socket = zmq_socket(a_context, a_type)
    code = zmq_connect(self%socket, a_endpoint)
  end function

  function client_close(self) result(code)
    class(client) :: self
    integer(kind = c_int) :: code

    code = zmq_msg_close(self%exception)
    if (c_associated(self%socket)) then
      code = zmq_close(self%socket)
      if (code >= 0) then
        self%socket = c_null_ptr
      end if
    end if
  end function

  function client_get_header(self) result(header)
    class(client) :: self
    type(reply_header) :: header

    logical :: status

    status = header%recv(self%socket)
    self%exception_id = header%number()
  end function

  subroutine client_get_result_value(self, a_result)
    class(client) :: self
    class(*), pointer, intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%value(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_unsigned(self, a_result)
    class(client) :: self
    class(*), pointer, intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%unsigned(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_character(self, a_result)
    class(client) :: self
    character(kind = c_char), intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%character(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_string(self, a_result)
    class(client) :: self
    character(kind = c_char, len = :), allocatable, intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%string(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_vector(self, a_result)
    class(client) :: self
    class(*), dimension(:), intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%vector(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_unsigned_vector(self, a_result)
    class(client) :: self
    class(*), dimension(:), intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%unsigned_vector(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_result_character_vector(self, a_result)
    class(client) :: self
    character(kind = c_char), dimension(:), intent(out) :: a_result

    logical :: status
    type(iarchive) :: in
    type(zmq_msg_t) :: message
    integer(kind = c_int) :: code

    code = zmq_msg_init(message)
    code = zmq_msg_recv(message, self%socket, 0)
    call in%create(zmq_msg_data(message), zmq_msg_size(message))
    status = in%character_vector(a_result)
    code = zmq_msg_close(message)
  end subroutine

  subroutine client_get_exception(self)
    class(client) :: self

    integer(kind = c_int) :: code

    code = zmq_msg_close(self%exception)
    code = zmq_msg_init(self%exception)
    code = zmq_msg_recv(self%exception, self%socket, 0)
  end subroutine

  function client_outcome(self) result(code)
    class(client) :: self
    integer(kind = c_int32_t) :: code

    code = self%exception_id
  end function

  subroutine client_catch_exception(self, a_number, a_exception)
    class(client) :: self
    integer(kind = c_int32_t), intent(in) :: a_number
    class(serializable), pointer, intent(inout) :: a_exception

    logical :: status
    type(c_ptr) :: msg_data
    type(iarchive) :: in
    integer(kind = c_int) :: code
    integer(kind = c_size_t) :: msg_size

    if (a_number == self%exception_id) then
      msg_data = zmq_msg_data(self%exception)
      msg_size = zmq_msg_size(self%exception)
      call in%create(msg_data, msg_size)
      status = in%value(a_exception)
      code = zmq_msg_close(self%exception)
    end if
  end subroutine

  function server_open(self, a_context, a_endpoint, a_type) result(code)
    class(server) :: self
    type(c_ptr), intent(in) :: a_context
    character(kind = c_char, len = *), intent(in) :: a_endpoint
    integer(kind = c_int), intent(in) :: a_type
    integer(kind = c_int) :: code

    self%socket = zmq_socket(a_context, a_type)
    code = zmq_bind(self%socket, a_endpoint)
  end function

  function server_close(self) result(code)
    class(server) :: self
    integer(kind = c_int) :: code

    if (c_associated(self%socket)) then
      code = zmq_close(self%socket)
      if (code >= 0) then
        self%socket = c_null_ptr
      end if
    end if
  end function

  subroutine server_serve(self)
    class(server) :: self

    do
      call self%serve_once()
    end do
  end subroutine

  subroutine server_serve_count(self, count)
    class(server) :: self
    integer(kind = c_int), intent(in) :: count
    integer(kind = c_int) :: n

    do n = 1, count
      call self%serve_once()
    end do
  end subroutine

  function server_get_request(self) result(header)
    class(server) :: self
    type(request_header) :: header

    logical :: status

    self%exception_id = 0
    status = header%recv(self%socket)
  end function

  function server_outcome(self) result(code)
    class(server) :: self
    integer(kind = c_int32_t) :: code

    code = self%exception_id
  end function

  subroutine server_undefined(self, a_header)
    class(server) :: self
    type(request_header), intent(in) :: a_header

    logical :: more
    logical :: status
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code

    more = a_header%more()
    do while (more)
      code = zmq_msg_init(message)
      code = zmq_msg_recv(message, self%socket, 0)
      more = zmq_msg_more(message)
      code = zmq_msg_close(message)
    end do
    status = header%send(self%socket, 0, .false.)
  end subroutine

  subroutine server_throw_error(self)
    class(server) :: self

    self%exception_id = 1
  end subroutine

  subroutine server_throw_exception(self, a_exception, a_id, a_size)
    class(server) :: self
    class(serializable), pointer, intent(in) :: a_exception
    integer(kind = c_int32_t), intent(in) :: a_id
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    self%exception_id = a_id
    code = zmq_msg_init_size(self%exception, a_size)
    call c_f_pointer(zmq_msg_data(self%exception), buffer)
    call archive%create(buffer, a_size)
    status = archive%value(a_exception)
  end subroutine

  subroutine server_reply_with_error(self)
    class(server) :: self

    logical :: status
    type(reply_header) :: header

    status = header%send(self%socket, 0, .false.)
  end subroutine

  subroutine server_reply_with_exception(self, a_number)
    class(server) :: self
    integer(kind = c_int32_t), intent(in) :: a_number

    logical :: status
    type(reply_header) :: header
    integer(kind = c_int) :: code

    status = header%send(self%socket, a_number, .true.)
    code = zmq_msg_send(self%exception, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_value(self, a_result, a_size)
    class(server) :: self
    class(*), pointer, intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%value(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_unsigned(self, a_result, a_size)
    class(server) :: self
    class(*), pointer, intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%unsigned(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_character(self, a_result, a_size)
    class(server) :: self
    character(kind = c_char), intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%character(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_vector(self, a_result, a_size)
    class(server) :: self
    class(*), dimension(:), intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%vector(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_unsigned_vector(self, a_result, a_size)
    class(server) :: self
    class(*), dimension(:), intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%unsigned_vector(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_result_character_vector(self, a_result, a_size)
    class(server) :: self
    character(kind = c_char), dimension(:), intent(in) :: a_result
    integer(kind = c_size_t), intent(in) :: a_size

    logical :: status
    type(oarchive) :: archive
    type(zmq_msg_t) :: message
    type(reply_header) :: header
    integer(kind = c_int) :: code
    character(kind = c_char, len = :), pointer :: buffer

    code = zmq_msg_init_size(message, a_size)
    call c_f_pointer(zmq_msg_data(message), buffer)
    call archive%create(buffer, a_size)
    status = archive%character_vector(a_result)
    status = header%send(self%socket, 1, .true.)
    code = zmq_msg_send(message, self%socket, 0)
  end subroutine

  subroutine server_reply_with_void(self)
    class(server) :: self

    logical :: status
    type(reply_header) :: header

    status = header%send(self%socket, 1, .false.)
  end subroutine

end module
