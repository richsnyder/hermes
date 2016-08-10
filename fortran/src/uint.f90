module uint

  use, intrinsic :: iso_c_binding, only : c_int8_t,c_int16_t,c_int32_t,c_int64_t
  implicit none
  private

  type, public :: unsigned
      integer, private :: width
      integer(kind = c_int64_t), private :: value
    contains
      generic, public :: assignment(=) => assign_u
      generic, public :: operator(+) => add_u_u, &
          add_u_08, add_u_16, add_u_32, add_u_64, &
          add_08_u, add_16_u, add_32_u, add_64_u
      generic, public :: operator(-) => sub_u_u, &
          sub_u_08, sub_u_16, sub_u_32, sub_u_64, &
          sub_08_u, sub_16_u, sub_32_u, sub_64_u
      generic, public :: operator(*) => mlt_u_u, &
          mlt_u_08, mlt_u_16, mlt_u_32, mlt_u_64, &
          mlt_08_u, mlt_16_u, mlt_32_u, mlt_64_u
      generic, public :: operator(/) => div_u_u, &
          div_u_08, div_u_16, div_u_32, div_u_64, &
          div_08_u, div_16_u, div_32_u, div_64_u
      generic, public :: operator(**) => pow_u_u, &
          pow_u_08, pow_u_16, pow_u_32, pow_u_64, &
          pow_08_u, pow_16_u, pow_32_u, pow_64_u
      generic, public :: operator(<) => lt_u_u, &
          lt_u_08, lt_u_16, lt_u_32, lt_u_64, &
          lt_08_u, lt_16_u, lt_32_u, lt_64_u
      generic, public :: operator(<=) => le_u_u, &
          le_u_08, le_u_16, le_u_32, le_u_64, &
          le_08_u, le_16_u, le_32_u, le_64_u
      generic, public :: operator(>) => gt_u_u, &
          gt_u_08, gt_u_16, gt_u_32, gt_u_64, &
          gt_08_u, gt_16_u, gt_32_u, gt_64_u
      generic, public :: operator(>=) => ge_u_u, &
          ge_u_08, ge_u_16, ge_u_32, ge_u_64, &
          ge_08_u, ge_16_u, ge_32_u, ge_64_u
      generic, public :: operator(==) => eq_u_u, &
          eq_u_08, eq_u_16, eq_u_32, eq_u_64, &
          eq_08_u, eq_16_u, eq_32_u, eq_64_u
      generic, public :: operator(/=) => ne_u_u, &
          ne_u_08, ne_u_16, ne_u_32, ne_u_64, &
          ne_08_u, ne_16_u, ne_32_u, ne_64_u

      procedure, private, pass(self) :: assign_u
      procedure, private, pass(self) :: add_u_u
      procedure, private, pass(self) :: add_u_08
      procedure, private, pass(self) :: add_u_16
      procedure, private, pass(self) :: add_u_32
      procedure, private, pass(self) :: add_u_64
      procedure, private, pass(self) :: add_08_u
      procedure, private, pass(self) :: add_16_u
      procedure, private, pass(self) :: add_32_u
      procedure, private, pass(self) :: add_64_u
      procedure, private, pass(self) :: sub_u_u
      procedure, private, pass(self) :: sub_u_08
      procedure, private, pass(self) :: sub_u_16
      procedure, private, pass(self) :: sub_u_32
      procedure, private, pass(self) :: sub_u_64
      procedure, private, pass(self) :: sub_08_u
      procedure, private, pass(self) :: sub_16_u
      procedure, private, pass(self) :: sub_32_u
      procedure, private, pass(self) :: sub_64_u
      procedure, private, pass(self) :: mlt_u_u
      procedure, private, pass(self) :: mlt_u_08
      procedure, private, pass(self) :: mlt_u_16
      procedure, private, pass(self) :: mlt_u_32
      procedure, private, pass(self) :: mlt_u_64
      procedure, private, pass(self) :: mlt_08_u
      procedure, private, pass(self) :: mlt_16_u
      procedure, private, pass(self) :: mlt_32_u
      procedure, private, pass(self) :: mlt_64_u
      procedure, private, pass(self) :: div_u_u
      procedure, private, pass(self) :: div_u_08
      procedure, private, pass(self) :: div_u_16
      procedure, private, pass(self) :: div_u_32
      procedure, private, pass(self) :: div_u_64
      procedure, private, pass(self) :: div_08_u
      procedure, private, pass(self) :: div_16_u
      procedure, private, pass(self) :: div_32_u
      procedure, private, pass(self) :: div_64_u
      procedure, private, pass(self) :: pow_u_u
      procedure, private, pass(self) :: pow_u_08
      procedure, private, pass(self) :: pow_u_16
      procedure, private, pass(self) :: pow_u_32
      procedure, private, pass(self) :: pow_u_64
      procedure, private, pass(self) :: pow_08_u
      procedure, private, pass(self) :: pow_16_u
      procedure, private, pass(self) :: pow_32_u
      procedure, private, pass(self) :: pow_64_u
      procedure, private, pass(self) :: lt_u_u
      procedure, private, pass(self) :: lt_u_08
      procedure, private, pass(self) :: lt_u_16
      procedure, private, pass(self) :: lt_u_32
      procedure, private, pass(self) :: lt_u_64
      procedure, private, pass(self) :: lt_08_u
      procedure, private, pass(self) :: lt_16_u
      procedure, private, pass(self) :: lt_32_u
      procedure, private, pass(self) :: lt_64_u
      procedure, private, pass(self) :: le_u_u
      procedure, private, pass(self) :: le_u_08
      procedure, private, pass(self) :: le_u_16
      procedure, private, pass(self) :: le_u_32
      procedure, private, pass(self) :: le_u_64
      procedure, private, pass(self) :: le_08_u
      procedure, private, pass(self) :: le_16_u
      procedure, private, pass(self) :: le_32_u
      procedure, private, pass(self) :: le_64_u
      procedure, private, pass(self) :: gt_u_u
      procedure, private, pass(self) :: gt_u_08
      procedure, private, pass(self) :: gt_u_16
      procedure, private, pass(self) :: gt_u_32
      procedure, private, pass(self) :: gt_u_64
      procedure, private, pass(self) :: gt_08_u
      procedure, private, pass(self) :: gt_16_u
      procedure, private, pass(self) :: gt_32_u
      procedure, private, pass(self) :: gt_64_u
      procedure, private, pass(self) :: ge_u_u
      procedure, private, pass(self) :: ge_u_08
      procedure, private, pass(self) :: ge_u_16
      procedure, private, pass(self) :: ge_u_32
      procedure, private, pass(self) :: ge_u_64
      procedure, private, pass(self) :: ge_08_u
      procedure, private, pass(self) :: ge_16_u
      procedure, private, pass(self) :: ge_32_u
      procedure, private, pass(self) :: ge_64_u
      procedure, private, pass(self) :: eq_u_u
      procedure, private, pass(self) :: eq_u_08
      procedure, private, pass(self) :: eq_u_16
      procedure, private, pass(self) :: eq_u_32
      procedure, private, pass(self) :: eq_u_64
      procedure, private, pass(self) :: eq_08_u
      procedure, private, pass(self) :: eq_16_u
      procedure, private, pass(self) :: eq_32_u
      procedure, private, pass(self) :: eq_64_u
      procedure, private, pass(self) :: ne_u_u
      procedure, private, pass(self) :: ne_u_08
      procedure, private, pass(self) :: ne_u_16
      procedure, private, pass(self) :: ne_u_32
      procedure, private, pass(self) :: ne_u_64
      procedure, private, pass(self) :: ne_08_u
      procedure, private, pass(self) :: ne_16_u
      procedure, private, pass(self) :: ne_32_u
      procedure, private, pass(self) :: ne_64_u
  end type

  interface unsigned
    module procedure new_u
    module procedure new_08
    module procedure new_16
    module procedure new_32
    module procedure new_64
    module procedure new_08_w
    module procedure new_16_w
    module procedure new_32_w
    module procedure new_64_w
  end interface

  interface digits
    module procedure u_digits
  end interface

  interface huge
    module procedure u_huge
  end interface

  interface int
    module procedure u_int
  end interface

  interface radix
    module procedure u_radix
  end interface

  interface range
    module procedure u_range
  end interface

  public :: digits
  public :: huge
  public :: int
  public :: radix
  public :: range

contains

  function new_u(a_unsigned) result(self)
    type(unsigned), intent(in) :: a_unsigned
    type(unsigned) :: self

    self%width = a_unsigned%width
    self%value = a_unsigned%value
  end function

  function new_08(a_value) result(self)
    integer(kind = c_int8_t), intent(in) :: a_value
    type(unsigned) :: self

    self%width = 32
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_16(a_value) result(self)
    integer(kind = c_int16_t), intent(in) :: a_value
    type(unsigned) :: self

    self%width = 32
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_32(a_value) result(self)
    integer(kind = c_int32_t), intent(in) :: a_value
    type(unsigned) :: self

    self%width = 32
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_64(a_value) result(self)
    integer(kind = c_int64_t), intent(in) :: a_value
    type(unsigned) :: self

    self%width = 32
    self%value = ibits(a_value, 0, self%width)
  end function

  function new_08_w(a_value, a_width) result(self)
    integer(kind = c_int8_t), intent(in) :: a_value
    integer, intent(in) :: a_width
    type(unsigned) :: self

    self%width = min(a_width, 63)
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_16_w(a_value, a_width) result(self)
    integer(kind = c_int16_t), intent(in) :: a_value
    integer, intent(in) :: a_width
    type(unsigned) :: self

    self%width = min(a_width, 63)
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_32_w(a_value, a_width) result(self)
    integer(kind = c_int32_t), intent(in) :: a_value
    integer, intent(in) :: a_width
    type(unsigned) :: self

    self%width = min(a_width, 63)
    self%value = ibits(int(a_value, kind = c_int64_t), 0, self%width)
  end function

  function new_64_w(a_value, a_width) result(self)
    integer(kind = c_int64_t), intent(in) :: a_value
    integer, intent(in) :: a_width
    type(unsigned) :: self

    self%width = min(a_width, 63)
    self%value = ibits(a_value, 0, self%width)
  end function

  function u_int(a_unsigned) result(value)
    type(unsigned), intent(in) :: a_unsigned
    integer(kind = c_int64_t) :: value

    value = a_unsigned%value
  end function

  function u_digits(a_unsigned) result(value)
    type(unsigned), intent(in) :: a_unsigned
    integer :: value

    value = a_unsigned%width
  end function

  function u_huge(a_unsigned) result(value)
    type(unsigned), intent(in) :: a_unsigned
    integer(kind = c_int64_t) :: value

    value = 2_c_int64_t ** a_unsigned%width - 1_c_int64_t
  end function

  function u_radix(a_unsigned) result(value)
    type(unsigned), intent(in) :: a_unsigned
    integer :: value

    value = 2
  end function

  function u_range(a_unsigned) result(value)
    type(unsigned), intent(in) :: a_unsigned
    integer :: value

    value = int(log10(real(huge(a_unsigned))))
  end function

  subroutine assign_u(self, a_unsigned)
    class(unsigned), intent(out) :: self
    type(unsigned), intent(in) :: a_unsigned

    self%width = a_unsigned%width
    self%value = a_unsigned%value
  end subroutine

  function add_u_u(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, a_operand%width)
    result%value = ibits(self%value + a_operand%value, 0, result%width)
  end function

  function add_u_08(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = self%value + int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_u_16(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = self%value + int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_u_32(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = self%value + int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_u_64(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = self%value + int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_08_u(a_operand, self) result(result)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = int(a_operand, kind = c_int64_t) + self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_16_u(a_operand, self) result(result)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = int(a_operand, kind = c_int64_t) + self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_32_u(a_operand, self) result(result)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = int(a_operand, kind = c_int64_t) + self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function add_64_u(a_operand, self) result(result)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = int(a_operand, kind = c_int64_t) + self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_u_u(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, a_operand%width)
    result%value = ibits(self%value - a_operand%value, 0, result%width)
  end function

  function sub_u_08(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = self%value - int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_u_16(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = self%value - int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_u_32(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = self%value - int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_u_64(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = self%value - int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_08_u(a_operand, self) result(result)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = int(a_operand, kind = c_int64_t) - self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_16_u(a_operand, self) result(result)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = int(a_operand, kind = c_int64_t) - self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_32_u(a_operand, self) result(result)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = int(a_operand, kind = c_int64_t) - self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function sub_64_u(a_operand, self) result(result)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = int(a_operand, kind = c_int64_t) - self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_u_u(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, a_operand%width)
    result%value = ibits(self%value * a_operand%value, 0, result%width)
  end function

  function mlt_u_08(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = self%value * int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_u_16(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = self%value * int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_u_32(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = self%value * int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_u_64(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = self%value * int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_08_u(a_operand, self) result(result)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = int(a_operand, kind = c_int64_t) * self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_16_u(a_operand, self) result(result)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = int(a_operand, kind = c_int64_t) * self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_32_u(a_operand, self) result(result)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = int(a_operand, kind = c_int64_t) * self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function mlt_64_u(a_operand, self) result(result)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = int(a_operand, kind = c_int64_t) * self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_u_u(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, a_operand%width)
    result%value = ibits(self%value / a_operand%value, 0, result%width)
  end function

  function div_u_08(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = self%value / int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_u_16(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = self%value / int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_u_32(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = self%value / int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_u_64(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 64)
    result%value = self%value / int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_08_u(a_operand, self) result(result)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = int(a_operand, kind = c_int64_t) / self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_16_u(a_operand, self) result(result)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = int(a_operand, kind = c_int64_t) / self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_32_u(a_operand, self) result(result)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = int(a_operand, kind = c_int64_t) / self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function div_64_u(a_operand, self) result(result)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = int(a_operand, kind = c_int64_t) / self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_u_u(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, a_operand%width)
    result%value = ibits(self%value ** a_operand%value, 0, result%width)
  end function

  function pow_u_08(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = self%value ** int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_u_16(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = self%value ** int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_u_32(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = self%value ** int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_u_64(self, a_operand) result(result)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = self%value ** int(a_operand, kind = c_int64_t)
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_08_u(a_operand, self) result(result)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 8)
    result%value = int(a_operand, kind = c_int64_t) ** self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_16_u(a_operand, self) result(result)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 16)
    result%value = int(a_operand, kind = c_int64_t) ** self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_32_u(a_operand, self) result(result)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 32)
    result%value = int(a_operand, kind = c_int64_t) ** self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function pow_64_u(a_operand, self) result(result)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    type(unsigned) :: result

    result%width = max(self%width, 63)
    result%value = int(a_operand, kind = c_int64_t) ** self%value
    result%value = ibits(result%value, 0, result%width)
  end function

  function lt_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value < a_operand%value
  end function

  function lt_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%lt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function lt_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%lt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function lt_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%lt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function lt_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value < a_operand
  end function

  function lt_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%lt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function lt_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%lt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function lt_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%lt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function lt_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand < self%value
  end function

  function le_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value <= a_operand%value
  end function

  function le_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%le_64_u(int(a_operand, kind = c_int64_t))
  end function

  function le_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%le_64_u(int(a_operand, kind = c_int64_t))
  end function

  function le_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%le_64_u(int(a_operand, kind = c_int64_t))
  end function

  function le_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value <= a_operand
  end function

  function le_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%le_u_64(int(a_operand, kind = c_int64_t))
  end function

  function le_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%le_u_64(int(a_operand, kind = c_int64_t))
  end function

  function le_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%le_u_64(int(a_operand, kind = c_int64_t))
  end function

  function le_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand <= self%value
  end function

  function gt_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value > a_operand%value
  end function

  function gt_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%gt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function gt_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%gt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function gt_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%gt_64_u(int(a_operand, kind = c_int64_t))
  end function

  function gt_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value > a_operand
  end function

  function gt_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%gt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function gt_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%gt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function gt_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%gt_u_64(int(a_operand, kind = c_int64_t))
  end function

  function gt_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand > self%value
  end function

  function ge_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value >= a_operand%value
  end function

  function ge_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ge_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ge_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ge_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ge_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ge_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ge_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value >= a_operand
  end function

  function ge_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ge_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ge_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ge_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ge_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ge_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ge_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand >= self%value
  end function

  function eq_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value == a_operand%value
  end function

  function eq_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%eq_64_u(int(a_operand, kind = c_int64_t))
  end function

  function eq_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%eq_64_u(int(a_operand, kind = c_int64_t))
  end function

  function eq_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%eq_64_u(int(a_operand, kind = c_int64_t))
  end function

  function eq_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value == a_operand
  end function

  function eq_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%eq_u_64(int(a_operand, kind = c_int64_t))
  end function

  function eq_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%eq_u_64(int(a_operand, kind = c_int64_t))
  end function

  function eq_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%eq_u_64(int(a_operand, kind = c_int64_t))
  end function

  function eq_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand == self%value
  end function

  function ne_u_u(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    type(unsigned), intent(in) :: a_operand
    logical :: condition

    condition = self%value /= a_operand%value
  end function

  function ne_u_08(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int8_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ne_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ne_u_16(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int16_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ne_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ne_u_32(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int32_t), intent(in) :: a_operand
    logical :: condition

    condition = self%ne_64_u(int(a_operand, kind = c_int64_t))
  end function

  function ne_u_64(self, a_operand) result(condition)
    class(unsigned), intent(in) :: self
    integer(kind = c_int64_t), intent(in) :: a_operand
    logical :: condition

    condition = self%value /= a_operand
  end function

  function ne_08_u(a_operand, self) result(condition)
    integer(kind = c_int8_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ne_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ne_16_u(a_operand, self) result(condition)
    integer(kind = c_int16_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ne_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ne_32_u(a_operand, self) result(condition)
    integer(kind = c_int32_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = self%ne_u_64(int(a_operand, kind = c_int64_t))
  end function

  function ne_64_u(a_operand, self) result(condition)
    integer(kind = c_int64_t), intent(in) :: a_operand
    class(unsigned), intent(in) :: self
    logical :: condition

    condition = a_operand /= self%value
  end function

end module
