module uint

  use, intrinsic :: iso_c_binding, only : c_int8_t,  &
                                          c_int16_t, &
                                          c_int32_t, &
                                          c_int64_t
  implicit none
  private

  type, public :: uint8_t
    integer(kind = c_int8_t), private :: bits
  end type

  type, public :: uint16_t
    integer(kind = c_int16_t), private :: bits
  end type

  type, public :: uint32_t
    integer(kind = c_int32_t), private :: bits
  end type

  type, public :: uint64_t
    integer(kind = c_int64_t), private :: bits
  end type

  interface uint8_t
    module procedure new_uint08_default
    module procedure new_uint08_value08
    module procedure new_uint08_value16
    module procedure new_uint08_value32
    module procedure new_uint08_value64
  end interface

  interface uint16_t
    module procedure new_uint16_default
    module procedure new_uint16_value08
    module procedure new_uint16_value16
    module procedure new_uint16_value32
    module procedure new_uint16_value64
  end interface

  interface uint32_t
    module procedure new_uint32_default
    module procedure new_uint32_value08
    module procedure new_uint32_value16
    module procedure new_uint32_value32
    module procedure new_uint32_value64
  end interface

  interface uint64_t
    module procedure new_uint64_default
    module procedure new_uint64_value08
    module procedure new_uint64_value16
    module procedure new_uint64_value32
    module procedure new_uint64_value64
  end interface

  interface assignment(=)
    module procedure assign_uint08_uint08
    module procedure assign_uint08_uint16
    module procedure assign_uint08_uint32
    module procedure assign_uint08_uint64
    module procedure assign_uint16_uint08
    module procedure assign_uint16_uint16
    module procedure assign_uint16_uint32
    module procedure assign_uint16_uint64
    module procedure assign_uint32_uint08
    module procedure assign_uint32_uint16
    module procedure assign_uint32_uint32
    module procedure assign_uint32_uint64
    module procedure assign_uint64_uint08
    module procedure assign_uint64_uint16
    module procedure assign_uint64_uint32
    module procedure assign_uint64_uint64
  end interface

  interface operator(+)
    module procedure add_uint08_uint08
    module procedure add_uint08_uint16
    module procedure add_uint08_uint32
    module procedure add_uint08_uint64
    module procedure add_uint16_uint08
    module procedure add_uint16_uint16
    module procedure add_uint16_uint32
    module procedure add_uint16_uint64
    module procedure add_uint32_uint08
    module procedure add_uint32_uint16
    module procedure add_uint32_uint32
    module procedure add_uint32_uint64
    module procedure add_uint64_uint08
    module procedure add_uint64_uint16
    module procedure add_uint64_uint32
    module procedure add_uint64_uint64
  end interface

  interface operator(-)
    module procedure subtract_uint08_uint08
    module procedure subtract_uint08_uint16
    module procedure subtract_uint08_uint32
    module procedure subtract_uint08_uint64
    module procedure subtract_uint16_uint08
    module procedure subtract_uint16_uint16
    module procedure subtract_uint16_uint32
    module procedure subtract_uint16_uint64
    module procedure subtract_uint32_uint08
    module procedure subtract_uint32_uint16
    module procedure subtract_uint32_uint32
    module procedure subtract_uint32_uint64
    module procedure subtract_uint64_uint08
    module procedure subtract_uint64_uint16
    module procedure subtract_uint64_uint32
    module procedure subtract_uint64_uint64
  end interface

  interface operator(*)
    module procedure multiply_uint08_uint08
    module procedure multiply_uint08_uint16
    module procedure multiply_uint08_uint32
    module procedure multiply_uint08_uint64
    module procedure multiply_uint16_uint08
    module procedure multiply_uint16_uint16
    module procedure multiply_uint16_uint32
    module procedure multiply_uint16_uint64
    module procedure multiply_uint32_uint08
    module procedure multiply_uint32_uint16
    module procedure multiply_uint32_uint32
    module procedure multiply_uint32_uint64
    module procedure multiply_uint64_uint08
    module procedure multiply_uint64_uint16
    module procedure multiply_uint64_uint32
    module procedure multiply_uint64_uint64
  end interface

  interface operator(/)
    module procedure divide_uint08_uint08
    module procedure divide_uint08_uint16
    module procedure divide_uint08_uint32
    module procedure divide_uint08_uint64
    module procedure divide_uint16_uint08
    module procedure divide_uint16_uint16
    module procedure divide_uint16_uint32
    module procedure divide_uint16_uint64
    module procedure divide_uint32_uint08
    module procedure divide_uint32_uint16
    module procedure divide_uint32_uint32
    module procedure divide_uint32_uint64
    module procedure divide_uint64_uint08
    module procedure divide_uint64_uint16
    module procedure divide_uint64_uint32
    module procedure divide_uint64_uint64
  end interface

  interface operator(==)
    module procedure eq_uint08_uint08
    module procedure eq_uint08_uint16
    module procedure eq_uint08_uint32
    module procedure eq_uint08_uint64
    module procedure eq_uint16_uint08
    module procedure eq_uint16_uint16
    module procedure eq_uint16_uint32
    module procedure eq_uint16_uint64
    module procedure eq_uint32_uint08
    module procedure eq_uint32_uint16
    module procedure eq_uint32_uint32
    module procedure eq_uint32_uint64
    module procedure eq_uint64_uint08
    module procedure eq_uint64_uint16
    module procedure eq_uint64_uint32
    module procedure eq_uint64_uint64
  end interface

  interface operator(/=)
    module procedure ne_uint08_uint08
    module procedure ne_uint08_uint16
    module procedure ne_uint08_uint32
    module procedure ne_uint08_uint64
    module procedure ne_uint16_uint08
    module procedure ne_uint16_uint16
    module procedure ne_uint16_uint32
    module procedure ne_uint16_uint64
    module procedure ne_uint32_uint08
    module procedure ne_uint32_uint16
    module procedure ne_uint32_uint32
    module procedure ne_uint32_uint64
    module procedure ne_uint64_uint08
    module procedure ne_uint64_uint16
    module procedure ne_uint64_uint32
    module procedure ne_uint64_uint64
  end interface

  interface operator(<)
    module procedure lt_uint08_uint08
    module procedure lt_uint08_uint16
    module procedure lt_uint08_uint32
    module procedure lt_uint08_uint64
    module procedure lt_uint16_uint08
    module procedure lt_uint16_uint16
    module procedure lt_uint16_uint32
    module procedure lt_uint16_uint64
    module procedure lt_uint32_uint08
    module procedure lt_uint32_uint16
    module procedure lt_uint32_uint32
    module procedure lt_uint32_uint64
    module procedure lt_uint64_uint08
    module procedure lt_uint64_uint16
    module procedure lt_uint64_uint32
    module procedure lt_uint64_uint64
  end interface

  interface operator(<=)
    module procedure le_uint08_uint08
    module procedure le_uint08_uint16
    module procedure le_uint08_uint32
    module procedure le_uint08_uint64
    module procedure le_uint16_uint08
    module procedure le_uint16_uint16
    module procedure le_uint16_uint32
    module procedure le_uint16_uint64
    module procedure le_uint32_uint08
    module procedure le_uint32_uint16
    module procedure le_uint32_uint32
    module procedure le_uint32_uint64
    module procedure le_uint64_uint08
    module procedure le_uint64_uint16
    module procedure le_uint64_uint32
    module procedure le_uint64_uint64
  end interface

  interface operator(>=)
    module procedure ge_uint08_uint08
    module procedure ge_uint08_uint16
    module procedure ge_uint08_uint32
    module procedure ge_uint08_uint64
    module procedure ge_uint16_uint08
    module procedure ge_uint16_uint16
    module procedure ge_uint16_uint32
    module procedure ge_uint16_uint64
    module procedure ge_uint32_uint08
    module procedure ge_uint32_uint16
    module procedure ge_uint32_uint32
    module procedure ge_uint32_uint64
    module procedure ge_uint64_uint08
    module procedure ge_uint64_uint16
    module procedure ge_uint64_uint32
    module procedure ge_uint64_uint64
  end interface

  interface operator(>)
    module procedure gt_uint08_uint08
    module procedure gt_uint08_uint16
    module procedure gt_uint08_uint32
    module procedure gt_uint08_uint64
    module procedure gt_uint16_uint08
    module procedure gt_uint16_uint16
    module procedure gt_uint16_uint32
    module procedure gt_uint16_uint64
    module procedure gt_uint32_uint08
    module procedure gt_uint32_uint16
    module procedure gt_uint32_uint32
    module procedure gt_uint32_uint64
    module procedure gt_uint64_uint08
    module procedure gt_uint64_uint16
    module procedure gt_uint64_uint32
    module procedure gt_uint64_uint64
  end interface

  interface abs
    module procedure abs_uint08
    module procedure abs_uint16
    module procedure abs_uint32
    module procedure abs_uint64
  end interface

  interface achar
    module procedure achar_uint08
    module procedure achar_uint16
    module procedure achar_uint32
    module procedure achar_uint64
  end interface

  interface bge
    module procedure bge_uint08
    module procedure bge_uint16
    module procedure bge_uint32
    module procedure bge_uint64
  end interface

  interface bgt
    module procedure bgt_uint08
    module procedure bgt_uint16
    module procedure bgt_uint32
    module procedure bgt_uint64
  end interface

  interface bit_size
    module procedure bit_size_uint08
    module procedure bit_size_uint16
    module procedure bit_size_uint32
    module procedure bit_size_uint64
  end interface

  interface ble
    module procedure ble_uint08
    module procedure ble_uint16
    module procedure ble_uint32
    module procedure ble_uint64
  end interface

  interface blt
    module procedure blt_uint08
    module procedure blt_uint16
    module procedure blt_uint32
    module procedure blt_uint64
  end interface

  interface btest
    module procedure btest_uint08
    module procedure btest_uint16
    module procedure btest_uint32
    module procedure btest_uint64
  end interface

  interface char
    module procedure char_uint08
    module procedure char_uint16
    module procedure char_uint32
    module procedure char_uint64
  end interface

  interface dble
    module procedure dble_uint08
    module procedure dble_uint16
    module procedure dble_uint32
    module procedure dble_uint64
  end interface

  interface digits
    module procedure digits_uint08
    module procedure digits_uint16
    module procedure digits_uint32
    module procedure digits_uint64
  end interface

  interface dim
    module procedure dim_uint08
    module procedure dim_uint16
    module procedure dim_uint32
    module procedure dim_uint64
  end interface

  interface dshiftl
    module procedure dshiftl_uint08
    module procedure dshiftl_uint16
    module procedure dshiftl_uint32
    module procedure dshiftl_uint64
  end interface

  interface dshiftr
    module procedure dshiftr_uint08
    module procedure dshiftr_uint16
    module procedure dshiftr_uint32
    module procedure dshiftr_uint64
  end interface

  interface float
    module procedure float_uint08
    module procedure float_uint16
    module procedure float_uint32
    module procedure float_uint64
  end interface

  interface huge
    module procedure huge_uint08
    module procedure huge_uint16
    module procedure huge_uint32
    module procedure huge_uint64
  end interface

  interface iand
    module procedure iand_uint08
    module procedure iand_uint16
    module procedure iand_uint32
    module procedure iand_uint64
  end interface

  interface ibclr
    module procedure ibclr_uint08
    module procedure ibclr_uint16
    module procedure ibclr_uint32
    module procedure ibclr_uint64
  end interface

  interface ibits
    module procedure ibits_uint08
    module procedure ibits_uint16
    module procedure ibits_uint32
    module procedure ibits_uint64
  end interface

  interface ibset
    module procedure ibset_uint08
    module procedure ibset_uint16
    module procedure ibset_uint32
    module procedure ibset_uint64
  end interface

  interface ieor
    module procedure ieor_uint08
    module procedure ieor_uint16
    module procedure ieor_uint32
    module procedure ieor_uint64
  end interface

  interface int
    module procedure int_uint08
    module procedure int_uint16
    module procedure int_uint32
    module procedure int_uint64
  end interface

  interface int2
    module procedure int2_uint08
    module procedure int2_uint16
    module procedure int2_uint32
    module procedure int2_uint64
  end interface

  interface int8
    module procedure int8_uint08
    module procedure int8_uint16
    module procedure int8_uint32
    module procedure int8_uint64
  end interface

  interface ior
    module procedure ior_uint08
    module procedure ior_uint16
    module procedure ior_uint32
    module procedure ior_uint64
  end interface

  interface ishft
    module procedure ishft_uint08
    module procedure ishft_uint16
    module procedure ishft_uint32
    module procedure ishft_uint64
  end interface

  interface ishftc
    module procedure ishftc_uint08
    module procedure ishftc_uint16
    module procedure ishftc_uint32
    module procedure ishftc_uint64
  end interface

  interface leadz
    module procedure leadz_uint08
    module procedure leadz_uint16
    module procedure leadz_uint32
    module procedure leadz_uint64
  end interface

  interface maskl
    module procedure maskl_uint08
    module procedure maskl_uint16
    module procedure maskl_uint32
    module procedure maskl_uint64
  end interface

  interface maskr
    module procedure maskr_uint08
    module procedure maskr_uint16
    module procedure maskr_uint32
    module procedure maskr_uint64
  end interface

  interface merge_bits
    module procedure merge_bits_uint08
    module procedure merge_bits_uint16
    module procedure merge_bits_uint32
    module procedure merge_bits_uint64
  end interface

  interface mod
    module procedure mod_uint08
    module procedure mod_uint16
    module procedure mod_uint32
    module procedure mod_uint64
  end interface

  interface modulo
    module procedure mod_uint08
    module procedure mod_uint16
    module procedure mod_uint32
    module procedure mod_uint64
  end interface

  interface mvbits
    module procedure mvbits_uint08
    module procedure mvbits_uint16
    module procedure mvbits_uint32
    module procedure mvbits_uint64
  end interface

  interface not
    module procedure not_uint08
    module procedure not_uint16
    module procedure not_uint32
    module procedure not_uint64
  end interface

  interface popcnt
    module procedure popcnt_uint08
    module procedure popcnt_uint16
    module procedure popcnt_uint32
    module procedure popcnt_uint64
  end interface

  interface poppar
    module procedure poppar_uint08
    module procedure poppar_uint16
    module procedure poppar_uint32
    module procedure poppar_uint64
  end interface

  interface radix
    module procedure radix_uint08
    module procedure radix_uint16
    module procedure radix_uint32
    module procedure radix_uint64
  end interface

  interface range
    module procedure range_uint08
    module procedure range_uint16
    module procedure range_uint32
    module procedure range_uint64
  end interface

  interface shifta
    module procedure shifta_uint08
    module procedure shifta_uint16
    module procedure shifta_uint32
    module procedure shifta_uint64
  end interface

  interface shiftl
    module procedure shiftl_uint08
    module procedure shiftl_uint16
    module procedure shiftl_uint32
    module procedure shiftl_uint64
  end interface

  interface shiftr
    module procedure shiftr_uint08
    module procedure shiftr_uint16
    module procedure shiftr_uint32
    module procedure shiftr_uint64
  end interface

  interface sign
    module procedure sign_uint08
    module procedure sign_uint16
    module procedure sign_uint32
    module procedure sign_uint64
  end interface

  interface storage_size
    module procedure storage_size_uint08
    module procedure storage_size_uint16
    module procedure storage_size_uint32
    module procedure storage_size_uint64
  end interface

  interface trailz
    module procedure trailz_uint08
    module procedure trailz_uint16
    module procedure trailz_uint32
    module procedure trailz_uint64
  end interface

  public :: operator(+)
  public :: operator(-)
  public :: operator(*)
  public :: operator(/)
  public :: operator(==)
  public :: operator(/=)
  public :: operator(<)
  public :: operator(<=)
  public :: operator(>=)
  public :: operator(>)

  public :: abs
  public :: achar
  public :: bge
  public :: bgt
  public :: bit_size
  public :: ble
  public :: blt
  public :: char
  public :: dble
  public :: digits
  public :: dim
  public :: dshiftl
  public :: dshiftr
  public :: float
  public :: huge
  public :: iand
  public :: ibclr
  public :: ibits
  public :: ibset
  public :: ieor
  public :: int
  public :: int2
  public :: int8
  public :: ior
  public :: ishft
  public :: ishftc
  public :: leadz
  public :: maskl
  public :: maskr
  public :: merge_bits
  public :: mod
  public :: modulo
  public :: mvbits
  public :: not
  public :: popcnt
  public :: poppar
  public :: radix
  public :: range
  public :: shifta
  public :: shiftl
  public :: shiftr
  public :: sign
  public :: storage_size
  public :: trailz

contains

  function new_uint08_default() result(this)
    type(uint8_t) :: this

    this%bits = 0_C_INT8_T
  end function

  function new_uint08_value08(i8) result(this)
    type(uint8_t) :: this
    integer(kind = c_int8_t) :: i8

    this%bits = i8
  end function

  function new_uint08_value16(i16) result(this)
    type(uint8_t) :: this
    integer(kind = c_int16_t) :: i16

    this%bits = ucast_16_08(i16)
  end function

  function new_uint08_value32(i32) result(this)
    type(uint8_t) :: this
    integer(kind = c_int32_t) :: i32

    this%bits = ucast_32_08(i32)
  end function

  function new_uint08_value64(i64) result(this)
    type(uint8_t) :: this
    integer(kind = c_int64_t) :: i64

    this%bits = ucast_64_08(i64)
  end function

  function new_uint16_default() result(this)
    type(uint16_t) :: this

    this%bits = 0_C_INT16_T
  end function

  function new_uint16_value08(i8) result(this)
    type(uint16_t) :: this
    integer(kind = c_int8_t) :: i8

    this%bits = ucast_08_16(i8)
  end function

  function new_uint16_value16(i16) result(this)
    type(uint16_t) :: this
    integer(kind = c_int16_t) :: i16

    this%bits = i16
  end function

  function new_uint16_value32(i32) result(this)
    type(uint16_t) :: this
    integer(kind = c_int32_t) :: i32

    this%bits = ucast_32_16(i32)
  end function

  function new_uint16_value64(i64) result(this)
    type(uint16_t) :: this
    integer(kind = c_int64_t) :: i64

    this%bits = ucast_64_16(i64)
  end function

  function new_uint32_default() result(this)
    type(uint32_t) :: this

    this%bits = 0_C_INT32_T
  end function

  function new_uint32_value08(i8) result(this)
    type(uint32_t) :: this
    integer(kind = c_int8_t) :: i8

    this%bits = ucast_08_32(i8)
  end function

  function new_uint32_value16(i16) result(this)
    type(uint32_t) :: this
    integer(kind = c_int16_t) :: i16

    this%bits = ucast_16_32(i16)
  end function

  function new_uint32_value32(i32) result(this)
    type(uint32_t) :: this
    integer(kind = c_int32_t) :: i32

    this%bits = i32
  end function

  function new_uint32_value64(i64) result(this)
    type(uint32_t) :: this
    integer(kind = c_int64_t) :: i64

    this%bits = ucast_64_32(i64)
  end function

  function new_uint64_default() result(this)
    type(uint64_t) :: this

    this%bits = 0_C_INT64_T
  end function

  function new_uint64_value08(i8) result(this)
    type(uint64_t) :: this
    integer(kind = c_int8_t) :: i8

    this%bits = ucast_08_64(i8)
  end function

  function new_uint64_value16(i16) result(this)
    type(uint64_t) :: this
    integer(kind = c_int16_t) :: i16

    this%bits = ucast_16_64(i16)
  end function

  function new_uint64_value32(i32) result(this)
    type(uint64_t) :: this
    integer(kind = c_int32_t) :: i32

    this%bits = ucast_32_64(i32)
  end function

  function new_uint64_value64(i64) result(this)
    type(uint64_t) :: this
    integer(kind = c_int64_t) :: i64

    this%bits = i64
  end function

  subroutine assign_uint08_uint08(this, other)
    type(uint8_t), intent(out) :: this
    type(uint8_t), intent(in) :: other

    this%bits = other%bits
  end subroutine

  subroutine assign_uint08_uint16(this, other)
    type(uint8_t), intent(out) :: this
    type(uint16_t), intent(in) :: other

    this%bits = ucast_16_08(other%bits)
  end subroutine

  subroutine assign_uint08_uint32(this, other)
    type(uint8_t), intent(out) :: this
    type(uint32_t), intent(in) :: other

    this%bits = ucast_32_08(other%bits)
  end subroutine

  subroutine assign_uint08_uint64(this, other)
    type(uint8_t), intent(out) :: this
    type(uint64_t), intent(in) :: other

    this%bits = ucast_64_08(other%bits)
  end subroutine

  subroutine assign_uint16_uint08(this, other)
    type(uint16_t), intent(out) :: this
    type(uint8_t), intent(in) :: other

    this%bits = ucast_08_16(other%bits)
  end subroutine

  subroutine assign_uint16_uint16(this, other)
    type(uint16_t), intent(out) :: this
    type(uint16_t), intent(in) :: other

    this%bits = other%bits
  end subroutine

  subroutine assign_uint16_uint32(this, other)
    type(uint16_t), intent(out) :: this
    type(uint32_t), intent(in) :: other

    this%bits = ucast_32_16(other%bits)
  end subroutine

  subroutine assign_uint16_uint64(this, other)
    type(uint16_t), intent(out) :: this
    type(uint64_t), intent(in) :: other

    this%bits = ucast_64_16(other%bits)
  end subroutine

  subroutine assign_uint32_uint08(this, other)
    type(uint32_t), intent(out) :: this
    type(uint8_t), intent(in) :: other

    this%bits = ucast_08_32(other%bits)
  end subroutine

  subroutine assign_uint32_uint16(this, other)
    type(uint32_t), intent(out) :: this
    type(uint16_t), intent(in) :: other

    this%bits = ucast_16_32(other%bits)
  end subroutine

  subroutine assign_uint32_uint32(this, other)
    type(uint32_t), intent(out) :: this
    type(uint32_t), intent(in) :: other

    this%bits = other%bits
  end subroutine

  subroutine assign_uint32_uint64(this, other)
    type(uint32_t), intent(out) :: this
    type(uint64_t), intent(in) :: other

    this%bits = ucast_64_32(other%bits)
  end subroutine

  subroutine assign_uint64_uint08(this, other)
    type(uint64_t), intent(out) :: this
    type(uint8_t), intent(in) :: other

    this%bits = ucast_08_64(other%bits)
  end subroutine

  subroutine assign_uint64_uint16(this, other)
    type(uint64_t), intent(out) :: this
    type(uint16_t), intent(in) :: other

    this%bits = ucast_16_64(other%bits)
  end subroutine

  subroutine assign_uint64_uint32(this, other)
    type(uint64_t), intent(out) :: this
    type(uint32_t), intent(in) :: other

    this%bits = ucast_32_64(other%bits)
  end subroutine

  subroutine assign_uint64_uint64(this, other)
    type(uint64_t), intent(out) :: this
    type(uint64_t), intent(in) :: other

    this%bits = other%bits
  end subroutine

  function add_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c%bits = add08(a%bits, b%bits)
  end function

  function add_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = add16(ucast_08_16(a%bits), b%bits)
  end function

  function add_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = add32(ucast_08_32(a%bits), b%bits)
  end function

  function add_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(ucast_08_64(a%bits), b%bits)
  end function

  function add_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = add16(a%bits, ucast_08_16(b%bits))
  end function

  function add_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = add16(a%bits, b%bits)
  end function

  function add_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = add32(ucast_16_32(a%bits), b%bits)
  end function

  function add_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(ucast_16_64(a%bits), b%bits)
  end function

  function add_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = add32(a%bits, ucast_08_32(b%bits))
  end function

  function add_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = add32(a%bits, ucast_16_32(b%bits))
  end function

  function add_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = add32(a%bits, b%bits)
  end function

  function add_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(ucast_32_64(a%bits), b%bits)
  end function

  function add_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(a%bits, ucast_08_64(b%bits))
  end function

  function add_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(a%bits, ucast_16_64(b%bits))
  end function

  function add_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(a%bits, ucast_32_64(b%bits))
  end function

  function add_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = add64(a%bits, b%bits)
  end function

  function subtract_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c%bits = subtract08(a%bits, b%bits)
  end function

  function subtract_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = subtract16(ucast_08_16(a%bits), b%bits)
  end function

  function subtract_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = subtract32(ucast_08_32(a%bits), b%bits)
  end function

  function subtract_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(ucast_08_64(a%bits), b%bits)
  end function

  function subtract_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = subtract16(a%bits, ucast_08_16(b%bits))
  end function

  function subtract_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = subtract16(a%bits, b%bits)
  end function

  function subtract_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = subtract32(ucast_16_32(a%bits), b%bits)
  end function

  function subtract_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(ucast_16_64(a%bits), b%bits)
  end function

  function subtract_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = subtract32(a%bits, ucast_08_32(b%bits))
  end function

  function subtract_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = subtract32(a%bits, ucast_16_32(b%bits))
  end function

  function subtract_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = subtract32(a%bits, b%bits)
  end function

  function subtract_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(ucast_32_64(a%bits), b%bits)
  end function

  function subtract_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(a%bits, ucast_08_64(b%bits))
  end function

  function subtract_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(a%bits, ucast_16_64(b%bits))
  end function

  function subtract_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(a%bits, ucast_32_64(b%bits))
  end function

  function subtract_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = subtract64(a%bits, b%bits)
  end function

  function multiply_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    integer(kind = c_int8_t) :: accumulator

    accumulator = 0_C_INT8_T
    c%bits = multiply08(a%bits, b%bits, accumulator)
  end function

  function multiply_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: accumulator

    accumulator = 0_C_INT16_T
    c%bits = multiply16(ucast_08_16(a%bits), b%bits, accumulator)
  end function

  function multiply_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: accumulator

    accumulator = 0_C_INT32_T
    c%bits = multiply32(ucast_08_32(a%bits), b%bits, accumulator)
  end function

  function multiply_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(ucast_08_64(a%bits), b%bits, accumulator)
  end function

  function multiply_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: accumulator

    accumulator = 0_C_INT16_T
    c%bits = multiply16(a%bits, ucast_08_16(b%bits), accumulator)
  end function

  function multiply_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: accumulator

    accumulator = 0_C_INT16_T
    c%bits = multiply16(a%bits, b%bits, accumulator)
  end function

  function multiply_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: accumulator

    accumulator = 0_C_INT32_T
    c%bits = multiply32(ucast_16_32(a%bits), b%bits, accumulator)
  end function

  function multiply_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(ucast_16_64(a%bits), b%bits, accumulator)
  end function

  function multiply_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: accumulator

    accumulator = 0_C_INT32_T
    c%bits = multiply32(a%bits, ucast_08_32(b%bits), accumulator)
  end function

  function multiply_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: accumulator

    accumulator = 0_C_INT32_T
    c%bits = multiply32(a%bits, ucast_16_32(b%bits), accumulator)
  end function

  function multiply_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: accumulator

    accumulator = 0_C_INT32_T
    c%bits = multiply32(a%bits, b%bits, accumulator)
  end function

  function multiply_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(ucast_32_64(a%bits), b%bits, accumulator)
  end function

  function multiply_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(a%bits, ucast_08_64(b%bits), accumulator)
  end function

  function multiply_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(a%bits, ucast_16_64(b%bits), accumulator)
  end function

  function multiply_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(a%bits, ucast_32_64(b%bits), accumulator)
  end function

  function multiply_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: accumulator

    accumulator = 0_C_INT64_T
    c%bits = multiply64(a%bits, b%bits, accumulator)
  end function

  function divide_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    integer(kind = c_int8_t) :: remainder

    c%bits = divide08(a%bits, b%bits, remainder)
  end function

  function divide_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: remainder

    c%bits = divide16(ucast_08_16(a%bits), b%bits, remainder)
  end function

  function divide_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: remainder

    c%bits = divide32(ucast_08_32(a%bits), b%bits, remainder)
  end function

  function divide_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(ucast_08_64(a%bits), b%bits, remainder)
  end function

  function divide_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: remainder

    c%bits = divide16(a%bits, ucast_08_16(b%bits), remainder)
  end function

  function divide_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: remainder

    c%bits = divide16(a%bits, b%bits, remainder)
  end function

  function divide_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: remainder

    c%bits = divide32(ucast_16_32(a%bits), b%bits, remainder)
  end function

  function divide_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(ucast_16_64(a%bits), b%bits, remainder)
  end function

  function divide_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: remainder

    c%bits = divide32(a%bits, ucast_08_32(b%bits), remainder)
  end function

  function divide_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: remainder

    c%bits = divide32(a%bits, ucast_16_32(b%bits), remainder)
  end function

  function divide_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: remainder

    c%bits = divide32(a%bits, b%bits, remainder)
  end function

  function divide_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(ucast_32_64(a%bits), b%bits, remainder)
  end function

  function divide_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(a%bits, ucast_08_64(b%bits), remainder)
  end function

  function divide_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(a%bits, ucast_16_64(b%bits), remainder)
  end function

  function divide_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(a%bits, ucast_32_64(b%bits), remainder)
  end function

  function divide_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: remainder

    c%bits = divide64(a%bits, b%bits, remainder)
  end function

  function eq_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = equal08(a%bits, b%bits)
  end function

  function eq_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = equal16(ucast_08_16(a%bits), b%bits)
  end function

  function eq_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = equal32(ucast_08_32(a%bits), b%bits)
  end function

  function eq_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = equal64(ucast_08_64(a%bits), b%bits)
  end function

  function eq_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = equal16(a%bits, ucast_08_16(b%bits))
  end function

  function eq_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = equal16(a%bits, b%bits)
  end function

  function eq_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = equal32(ucast_16_32(a%bits), b%bits)
  end function

  function eq_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = equal64(ucast_16_64(a%bits), b%bits)
  end function

  function eq_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = equal32(a%bits, ucast_08_32(b%bits))
  end function

  function eq_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = equal32(a%bits, ucast_16_32(b%bits))
  end function

  function eq_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = equal32(a%bits, b%bits)
  end function

  function eq_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = equal64(ucast_32_64(a%bits), b%bits)
  end function

  function eq_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = equal64(a%bits, ucast_08_64(b%bits))
  end function

  function eq_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = equal64(a%bits, ucast_16_64(b%bits))
  end function

  function eq_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = equal64(a%bits, ucast_32_64(b%bits))
  end function

  function eq_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = equal64(a%bits, b%bits)
  end function

  function ne_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint08_uint08(a, b)
  end function

  function ne_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint08_uint16(a, b)
  end function

  function ne_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint08_uint32(a, b)
  end function

  function ne_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint08_uint64(a, b)
  end function

  function ne_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint16_uint08(a, b)
  end function

  function ne_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint16_uint16(a, b)
  end function

  function ne_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint16_uint32(a, b)
  end function

  function ne_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint16_uint64(a, b)
  end function

  function ne_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint32_uint08(a, b)
  end function

  function ne_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint32_uint16(a, b)
  end function

  function ne_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint32_uint32(a, b)
  end function

  function ne_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint32_uint64(a, b)
  end function

  function ne_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint64_uint08(a, b)
  end function

  function ne_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint64_uint16(a, b)
  end function

  function ne_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint64_uint32(a, b)
  end function

  function ne_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = .not. eq_uint64_uint64(a, b)
  end function

  function lt_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = less08(a%bits, b%bits)
  end function

  function lt_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = less16(ucast_08_16(a%bits), b%bits)
  end function

  function lt_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = less32(ucast_08_32(a%bits), b%bits)
  end function

  function lt_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = less64(ucast_08_64(a%bits), b%bits)
  end function

  function lt_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = less16(a%bits, ucast_08_16(b%bits))
  end function

  function lt_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = less16(a%bits, b%bits)
  end function

  function lt_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = less32(ucast_16_32(a%bits), b%bits)
  end function

  function lt_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = less64(ucast_16_64(a%bits), b%bits)
  end function

  function lt_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = less32(a%bits, ucast_08_32(b%bits))
  end function

  function lt_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = less32(a%bits, ucast_16_32(b%bits))
  end function

  function lt_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = less32(a%bits, b%bits)
  end function

  function lt_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = less64(ucast_32_64(a%bits), b%bits)
  end function

  function lt_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = less64(a%bits, ucast_08_64(b%bits))
  end function

  function lt_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = less64(a%bits, ucast_16_64(b%bits))
  end function

  function lt_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = less64(a%bits, ucast_32_64(b%bits))
  end function

  function lt_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = less64(a%bits, b%bits)
  end function

  function le_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lessequal08(a%bits, b%bits)
  end function

  function le_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lessequal16(ucast_08_16(a%bits), b%bits)
  end function

  function le_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lessequal32(ucast_08_32(a%bits), b%bits)
  end function

  function le_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lessequal64(ucast_08_64(a%bits), b%bits)
  end function

  function le_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lessequal16(a%bits, ucast_08_16(b%bits))
  end function

  function le_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lessequal16(a%bits, b%bits)
  end function

  function le_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lessequal32(ucast_16_32(a%bits), b%bits)
  end function

  function le_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lessequal64(ucast_16_64(a%bits), b%bits)
  end function

  function le_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lessequal32(a%bits, ucast_08_32(b%bits))
  end function

  function le_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lessequal32(a%bits, ucast_16_32(b%bits))
  end function

  function le_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lessequal32(a%bits, b%bits)
  end function

  function le_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lessequal64(ucast_32_64(a%bits), b%bits)
  end function

  function le_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lessequal64(a%bits, ucast_08_64(b%bits))
  end function

  function le_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lessequal64(a%bits, ucast_16_64(b%bits))
  end function

  function le_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lessequal64(a%bits, ucast_32_64(b%bits))
  end function

  function le_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lessequal64(a%bits, b%bits)
  end function

  function ge_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = le_uint08_uint08(b, a)
  end function

  function ge_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = le_uint16_uint08(b, a)
  end function

  function ge_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = le_uint32_uint08(b, a)
  end function

  function ge_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = le_uint64_uint08(b, a)
  end function

  function ge_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = le_uint08_uint16(b, a)
  end function

  function ge_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = le_uint16_uint16(b, a)
  end function

  function ge_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = le_uint32_uint16(b, a)
  end function

  function ge_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = le_uint64_uint16(b, a)
  end function

  function ge_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = le_uint08_uint32(b, a)
  end function

  function ge_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = le_uint16_uint32(b, a)
  end function

  function ge_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = le_uint32_uint32(b, a)
  end function

  function ge_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = le_uint64_uint32(b, a)
  end function

  function ge_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = le_uint08_uint64(b, a)
  end function

  function ge_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = le_uint16_uint64(b, a)
  end function

  function ge_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = le_uint32_uint64(b, a)
  end function

  function ge_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = le_uint64_uint64(b, a)
  end function

  function gt_uint08_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lt_uint08_uint08(b, a)
  end function

  function gt_uint08_uint16(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lt_uint16_uint08(b, a)
  end function

  function gt_uint08_uint32(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lt_uint32_uint08(b, a)
  end function

  function gt_uint08_uint64(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lt_uint64_uint08(b, a)
  end function

  function gt_uint16_uint08(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lt_uint08_uint16(b, a)
  end function

  function gt_uint16_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lt_uint16_uint16(b, a)
  end function

  function gt_uint16_uint32(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lt_uint32_uint16(b, a)
  end function

  function gt_uint16_uint64(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lt_uint64_uint16(b, a)
  end function

  function gt_uint32_uint08(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lt_uint08_uint32(b, a)
  end function

  function gt_uint32_uint16(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lt_uint16_uint32(b, a)
  end function

  function gt_uint32_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lt_uint32_uint32(b, a)
  end function

  function gt_uint32_uint64(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lt_uint64_uint32(b, a)
  end function

  function gt_uint64_uint08(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = lt_uint08_uint64(b, a)
  end function

  function gt_uint64_uint16(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = lt_uint16_uint64(b, a)
  end function

  function gt_uint64_uint32(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = lt_uint32_uint64(b, a)
  end function

  function gt_uint64_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = lt_uint64_uint64(b, a)
  end function

  !=============================================================================
  !
  !=============================================================================

  function abs_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    type(uint8_t) :: b

    b = a
  end function

  function abs_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    type(uint16_t) :: b

    b = a
  end function

  function abs_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    type(uint32_t) :: b

    b = a
  end function

  function abs_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    type(uint64_t) :: b

    b = a
  end function

  function achar_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    character(len = 1) :: b

    b = achar(int(a))
  end function

  function achar_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    character(len = 1) :: b

    b = achar(int(a))
  end function

  function achar_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    character(len = 1) :: b

    b = achar(int(a))
  end function

  function achar_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    character(len = 1) :: b

    b = achar(int(a))
  end function

  function bge_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = bge(a%bits, b%bits)
  end function

  function bge_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = bge(a%bits, b%bits)
  end function

  function bge_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = bge(a%bits, b%bits)
  end function

  function bge_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = bge(a%bits, b%bits)
  end function

  function bgt_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = bgt(a%bits, b%bits)
  end function

  function bgt_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = bgt(a%bits, b%bits)
  end function

  function bgt_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = bgt(a%bits, b%bits)
  end function

  function bgt_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = bgt(a%bits, b%bits)
  end function

  function bit_size_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer :: b

    b = bit_size(a%bits)
  end function

  function bit_size_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer :: b

    b = bit_size(a%bits)
  end function

  function bit_size_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer :: b

    b = bit_size(a%bits)
  end function

  function bit_size_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer :: b

    b = bit_size(a%bits)
  end function

  function ble_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = ble(a%bits, b%bits)
  end function

  function ble_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = ble(a%bits, b%bits)
  end function

  function ble_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = ble(a%bits, b%bits)
  end function

  function ble_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = ble(a%bits, b%bits)
  end function

  function blt_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    logical :: c

    c = blt(a%bits, b%bits)
  end function

  function blt_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    logical :: c

    c = blt(a%bits, b%bits)
  end function

  function blt_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    logical :: c

    c = blt(a%bits, b%bits)
  end function

  function blt_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    logical :: c

    c = blt(a%bits, b%bits)
  end function

  function btest_uint08(a, pos) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    logical :: b

    b = btest(a%bits, pos)
  end function

  function btest_uint16(a, pos) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    logical :: b

    b = btest(a%bits, pos)
  end function

  function btest_uint32(a, pos) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    logical :: b

    b = btest(a%bits, pos)
  end function

  function btest_uint64(a, pos) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    logical :: b

    b = btest(a%bits, pos)
  end function

  function char_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    character(len = 1) :: b

    b = char(int(a))
  end function

  function char_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    character(len = 1) :: b

    b = char(int(a))
  end function

  function char_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    character(len = 1) :: b

    b = char(int(a))
  end function

  function char_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    character(len = 1) :: b

    b = char(int(a))
  end function

  function dble_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    double precision :: b

    b = dble(int8(a))
  end function

  function dble_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    double precision :: b

    b = dble(int8(a))
  end function

  function dble_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    double precision :: b

    b = dble(int8(a))
  end function

  function dble_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    double precision :: b

    b = dble(int8(a))
  end function

  function digits_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = digits(a%bits)
  end function

  function digits_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = digits(a%bits)
  end function

  function digits_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = digits(a%bits)
  end function

  function digits_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = digits(a%bits)
  end function

  function dim_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    if (b < a) then
      c = a - b
    else
      c = uint8_t(0)
    end if
  end function

  function dim_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    if (b < a) then
      c = a - b
    else
      c = uint16_t(0)
    end if
  end function

  function dim_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    if (b < a) then
      c = a - b
    else
      c = uint32_t(0)
    end if
  end function

  function dim_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    if (b < a) then
      c = a - b
    else
      c = uint64_t(0)
    end if
  end function

  function dshiftl_uint08(a, b, shift) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint8_t) :: c

    c%bits = dshiftl(a%bits, b%bits, shift)
  end function

  function dshiftl_uint16(a, b, shift) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint16_t) :: c

    c%bits = dshiftl(a%bits, b%bits, shift)
  end function

  function dshiftl_uint32(a, b, shift) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint32_t) :: c

    c%bits = dshiftl(a%bits, b%bits, shift)
  end function

  function dshiftl_uint64(a, b, shift) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint64_t) :: c

    c%bits = dshiftl(a%bits, b%bits, shift)
  end function

  function dshiftr_uint08(a, b, shift) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint8_t) :: c

    c%bits = dshiftr(a%bits, b%bits, shift)
  end function

  function dshiftr_uint16(a, b, shift) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint16_t) :: c

    c%bits = dshiftr(a%bits, b%bits, shift)
  end function

  function dshiftr_uint32(a, b, shift) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint32_t) :: c

    c%bits = dshiftr(a%bits, b%bits, shift)
  end function

  function dshiftr_uint64(a, b, shift) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    integer(kind = c_int32_t) :: shift
    type(uint64_t) :: c

    c%bits = dshiftr(a%bits, b%bits, shift)
  end function

  function float_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    double precision :: b

    b = float(int8(a))
  end function

  function float_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    double precision :: b

    b = float(int8(a))
  end function

  function float_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    double precision :: b

    b = float(int8(a))
  end function

  function float_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    double precision :: b

    b = float(int8(a))
  end function

  function huge_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    type(uint8_t) :: b

    b = uint8_t(-1)
  end function

  function huge_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    type(uint16_t) :: b

    b = uint16_t(-1)
  end function

  function huge_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    type(uint32_t) :: b

    b = uint32_t(-1)
  end function

  function huge_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    type(uint64_t) :: b

    b = uint64_t(-1)
  end function

  function iand_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c%bits = iand(a%bits, b%bits)
  end function

  function iand_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = iand(a%bits, b%bits)
  end function

  function iand_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = iand(a%bits, b%bits)
  end function

  function iand_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = iand(a%bits, b%bits)
  end function

  function ibclr_uint08(a, pos) result(c)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint8_t) :: c

    c%bits = ibclr(a%bits, pos)
  end function

  function ibclr_uint16(a, pos) result(c)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint16_t) :: c

    c%bits = ibclr(a%bits, pos)
  end function

  function ibclr_uint32(a, pos) result(c)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint32_t) :: c

    c%bits = ibclr(a%bits, pos)
  end function

  function ibclr_uint64(a, pos) result(c)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint64_t) :: c

    c%bits = ibclr(a%bits, pos)
  end function

  function ibits_uint08(a, pos, len) result(c)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint8_t) :: c

    c%bits = ibits(a%bits, pos, len)
  end function

  function ibits_uint16(a, pos, len) result(c)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint16_t) :: c

    c%bits = ibits(a%bits, pos, len)
  end function

  function ibits_uint32(a, pos, len) result(c)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint32_t) :: c

    c%bits = ibits(a%bits, pos, len)
  end function

  function ibits_uint64(a, pos, len) result(c)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint64_t) :: c

    c%bits = ibits(a%bits, pos, len)
  end function

  function ibset_uint08(a, pos) result(c)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint8_t) :: c

    c%bits = ibset(a%bits, pos)
  end function

  function ibset_uint16(a, pos) result(c)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint16_t) :: c

    c%bits = ibset(a%bits, pos)
  end function

  function ibset_uint32(a, pos) result(c)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint32_t) :: c

    c%bits = ibset(a%bits, pos)
  end function

  function ibset_uint64(a, pos) result(c)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: pos
    type(uint64_t) :: c

    c%bits = ibset(a%bits, pos)
  end function

  function ieor_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c%bits = ieor(a%bits, b%bits)
  end function

  function ieor_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = ieor(a%bits, b%bits)
  end function

  function ieor_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = ieor(a%bits, b%bits)
  end function

  function ieor_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = ieor(a%bits, b%bits)
  end function

  function int_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = ucast_08_32(a%bits)
    if (b < 0_C_INT32_T) b = 256_C_INT32_T + b
  end function

  function int_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = ucast_16_32(a%bits)
    if (b < 0_C_INT32_T) b = 65536_C_INT32_T + b
  end function

  function int_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = a%bits
  end function

  function int_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = ucast_64_32(a%bits)
  end function

  function int2_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = ucast_08_16(a%bits)
    if (b < 0_C_INT16_T) b = 256_C_INT16_T + b
  end function

  function int2_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = a%bits
  end function

  function int2_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = ucast_32_16(a%bits)
  end function

  function int2_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = ucast_64_16(a%bits)
  end function

  function int8_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = ucast_08_64(a%bits)
    if (b < 0_C_INT64_T) b = 256_C_INT64_T + b
  end function

  function int8_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = ucast_16_64(a%bits)
    if (b < 0_C_INT64_T) b = 65536_C_INT32_T + b
  end function

  function int8_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a%bits
    if (b < 0_C_INT64_T) b = 4294967296_C_INT64_T + b
  end function

  function int8_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a%bits
  end function

  function ior_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c%bits = ior(a%bits, b%bits)
  end function

  function ior_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c%bits = ior(a%bits, b%bits)
  end function

  function ior_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c%bits = ior(a%bits, b%bits)
  end function

  function ior_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c%bits = ior(a%bits, b%bits)
  end function

  function ishft_uint08(a, shift) result(c)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    type(uint8_t) :: c

    c%bits = ishft(a%bits, shift)
  end function

  function ishft_uint16(a, shift) result(c)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    type(uint16_t) :: c

    c%bits = ishft(a%bits, shift)
  end function

  function ishft_uint32(a, shift) result(c)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    type(uint32_t) :: c

    c%bits = ishft(a%bits, shift)
  end function

  function ishft_uint64(a, shift) result(c)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    type(uint64_t) :: c

    c%bits = ishft(a%bits, shift)
  end function

  function ishftc_uint08(a, shift, size) result(c)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    integer(kind = c_int32_t), optional, intent(in) :: size
    type(uint8_t) :: c

    c%bits = ishftc(a%bits, shift, size)
  end function

  function ishftc_uint16(a, shift, size) result(c)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    integer(kind = c_int32_t), optional, intent(in) :: size
    type(uint16_t) :: c

    c%bits = ishftc(a%bits, shift, size)
  end function

  function ishftc_uint32(a, shift, size) result(c)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    integer(kind = c_int32_t), optional, intent(in) :: size
    type(uint32_t) :: c

    c%bits = ishftc(a%bits, shift, size)
  end function

  function ishftc_uint64(a, shift, size) result(c)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: shift
    integer(kind = c_int32_t), optional, intent(in) :: size
    type(uint64_t) :: c

    c%bits = ishftc(a%bits, shift, size)
  end function

  function leadz_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer :: b

    b = leadz(a%bits)
  end function

  function leadz_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer :: b

    b = leadz(a%bits)
  end function

  function leadz_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer :: b

    b = leadz(a%bits)
  end function

  function leadz_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer :: b

    b = leadz(a%bits)
  end function

  function maskl_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    type(uint8_t) :: b

    b%bits = maskl(a%bits)
  end function

  function maskl_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    type(uint16_t) :: b

    b%bits = maskl(a%bits)
  end function

  function maskl_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    type(uint32_t) :: b

    b%bits = maskl(a%bits)
  end function

  function maskl_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    type(uint64_t) :: b

    b%bits = maskl(a%bits)
  end function

  function maskr_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    type(uint8_t) :: b

    b%bits = maskr(a%bits)
  end function

  function maskr_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    type(uint16_t) :: b

    b%bits = maskr(a%bits)
  end function

  function maskr_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    type(uint32_t) :: b

    b%bits = maskr(a%bits)
  end function

  function maskr_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    type(uint64_t) :: b

    b%bits = maskr(a%bits)
  end function

  function merge_bits_uint08(a, b, mask) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t), intent(in) :: mask
    type(uint8_t) :: c

    c%bits = merge_bits(a%bits, b%bits, mask%bits)
  end function

  function merge_bits_uint16(a, b, mask) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t), intent(in) :: mask
    type(uint16_t) :: c

    c%bits = merge_bits(a%bits, b%bits, mask%bits)
  end function

  function merge_bits_uint32(a, b, mask) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t), intent(in) :: mask
    type(uint32_t) :: c

    c%bits = merge_bits(a%bits, b%bits, mask%bits)
  end function

  function merge_bits_uint64(a, b, mask) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t), intent(in) :: mask
    type(uint64_t) :: c

    c%bits = merge_bits(a%bits, b%bits, mask%bits)
  end function

  function mod_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    integer(kind = c_int8_t) :: quotient

    quotient = divide08(a%bits, b%bits, c%bits)
  end function

  function mod_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    integer(kind = c_int16_t) :: quotient

    quotient = divide16(a%bits, b%bits, c%bits)
  end function

  function mod_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    integer(kind = c_int32_t) :: quotient

    quotient = divide32(a%bits, b%bits, c%bits)
  end function

  function mod_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    integer(kind = c_int64_t) :: quotient

    quotient = divide64(a%bits, b%bits, c%bits)
  end function

  subroutine mvbits_uint08(from, frompos, len, to, topos)
    type(uint8_t), intent(in) :: from
    integer(kind = c_int32_t), intent(in) :: frompos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint8_t), intent(inout) :: to
    integer(kind = c_int32_t), intent(in) :: topos

    call mvbits(from%bits, frompos, len, to%bits, topos)
  end subroutine

  subroutine mvbits_uint16(from, frompos, len, to, topos)
    type(uint16_t), intent(in) :: from
    integer(kind = c_int32_t), intent(in) :: frompos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint16_t), intent(inout) :: to
    integer(kind = c_int32_t), intent(in) :: topos

    call mvbits(from%bits, frompos, len, to%bits, topos)
  end subroutine

  subroutine mvbits_uint32(from, frompos, len, to, topos)
    type(uint32_t), intent(in) :: from
    integer(kind = c_int32_t), intent(in) :: frompos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint32_t), intent(inout) :: to
    integer(kind = c_int32_t), intent(in) :: topos

    call mvbits(from%bits, frompos, len, to%bits, topos)
  end subroutine

  subroutine mvbits_uint64(from, frompos, len, to, topos)
    type(uint64_t), intent(in) :: from
    integer(kind = c_int32_t), intent(in) :: frompos
    integer(kind = c_int32_t), intent(in) :: len
    type(uint64_t), intent(inout) :: to
    integer(kind = c_int32_t), intent(in) :: topos

    call mvbits(from%bits, frompos, len, to%bits, topos)
  end subroutine

  function not_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    type(uint8_t) :: b

    b%bits = not(a%bits)
  end function

  function not_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    type(uint16_t) :: b

    b%bits = not(a%bits)
  end function

  function not_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    type(uint32_t) :: b

    b%bits = not(a%bits)
  end function

  function not_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    type(uint64_t) :: b

    b%bits = not(a%bits)
  end function

  function popcnt_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = popcnt(a%bits)
  end function

  function popcnt_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = popcnt(a%bits)
  end function

  function popcnt_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = popcnt(a%bits)
  end function

  function popcnt_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = popcnt(a%bits)
  end function

  function poppar_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = poppar(a%bits)
  end function

  function poppar_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = poppar(a%bits)
  end function

  function poppar_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = poppar(a%bits)
  end function

  function poppar_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = poppar(a%bits)
  end function

  function radix_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = radix(a%bits)
  end function

  function radix_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = radix(a%bits)
  end function

  function radix_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = radix(a%bits)
  end function

  function radix_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = radix(a%bits)
  end function

  function range_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = range(a%bits)
  end function

  function range_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = range(a%bits)
  end function

  function range_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = range(a%bits)
  end function

  function range_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = range(a%bits)
  end function

  function shifta_uint08(a, shift) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint8_t) :: b

    b%bits = shifta(a%bits, shift)
  end function

  function shifta_uint16(a, shift) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint16_t) :: b

    b%bits = shifta(a%bits, shift)
  end function

  function shifta_uint32(a, shift) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint32_t) :: b

    b%bits = shifta(a%bits, shift)
  end function

  function shifta_uint64(a, shift) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint64_t) :: b

    b%bits = shifta(a%bits, shift)
  end function

  function shiftl_uint08(a, shift) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint8_t) :: b

    b%bits = shiftl(a%bits, shift)
  end function

  function shiftl_uint16(a, shift) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint16_t) :: b

    b%bits = shiftl(a%bits, shift)
  end function

  function shiftl_uint32(a, shift) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint32_t) :: b

    b%bits = shiftl(a%bits, shift)
  end function

  function shiftl_uint64(a, shift) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint64_t) :: b

    b%bits = shiftl(a%bits, shift)
  end function

  function shiftr_uint08(a, shift) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint8_t) :: b

    b%bits = shiftr(a%bits, shift)
  end function

  function shiftr_uint16(a, shift) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint16_t) :: b

    b%bits = shiftr(a%bits, shift)
  end function

  function shiftr_uint32(a, shift) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint32_t) :: b

    b%bits = shiftr(a%bits, shift)
  end function

  function shiftr_uint64(a, shift) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: shift
    type(uint64_t) :: b

    b%bits = shiftr(a%bits, shift)
  end function

  function sign_uint08(a, b) result(c)
    type(uint8_t), intent(in) :: a
    type(uint8_t), intent(in) :: b
    type(uint8_t) :: c

    c = a
  end function

  function sign_uint16(a, b) result(c)
    type(uint16_t), intent(in) :: a
    type(uint16_t), intent(in) :: b
    type(uint16_t) :: c

    c = a
  end function

  function sign_uint32(a, b) result(c)
    type(uint32_t), intent(in) :: a
    type(uint32_t), intent(in) :: b
    type(uint32_t) :: c

    c = a
  end function

  function sign_uint64(a, b) result(c)
    type(uint64_t), intent(in) :: a
    type(uint64_t), intent(in) :: b
    type(uint64_t) :: c

    c = a
  end function

  function storage_size_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = storage_size(a%bits)
  end function

  function storage_size_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = storage_size(a%bits)
  end function

  function storage_size_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = storage_size(a%bits)
  end function

  function storage_size_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = storage_size(a%bits)
  end function

  function trailz_uint08(a) result(b)
    type(uint8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = trailz(a%bits)
  end function

  function trailz_uint16(a) result(b)
    type(uint16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = trailz(a%bits)
  end function

  function trailz_uint32(a) result(b)
    type(uint32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = trailz(a%bits)
  end function

  function trailz_uint64(a) result(b)
    type(uint64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = trailz(a%bits)
  end function

  !=============================================================================
  !
  !=============================================================================

  function ucast_08_08(a) result(b)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t) :: b

    b = a
  end function

  function ucast_08_16(a) result(b)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = a
    b = iand(b, 255_C_INT16_T)
  end function

  function ucast_08_32(a) result(b)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = a
    b = iand(b, 255_C_INT32_T)
  end function

  function ucast_08_64(a) result(b)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a
    b = iand(b, 255_C_INT64_T)
  end function

  function ucast_16_08(a) result(b)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int8_t) :: b

    b = a
  end function

  function ucast_16_16(a) result(b)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = a
  end function

  function ucast_16_32(a) result(b)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = a
    b = iand(b, 65535_C_INT32_T)
  end function

  function ucast_16_64(a) result(b)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a
    b = iand(b, 65535_C_INT64_T)
  end function

  function ucast_32_08(a) result(b)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int8_t) :: b

    b = a
  end function

  function ucast_32_16(a) result(b)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = a
  end function

  function ucast_32_32(a) result(b)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = a
  end function

  function ucast_32_64(a) result(b)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a
    b = iand(b, 16777215_C_INT64_T)
  end function

  function ucast_64_08(a) result(b)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int8_t) :: b

    b = a
  end function

  function ucast_64_16(a) result(b)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int16_t) :: b

    b = a
  end function

  function ucast_64_32(a) result(b)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int32_t) :: b

    b = a
  end function

  function ucast_64_64(a) result(b)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t) :: b

    b = a
  end function

  recursive function add08(a, b) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    integer(kind = c_int8_t) :: c

    if (b == 0_C_INT8_T) then
      c = a
    else
      c = add08(ieor(a, b), shiftl(iand(a, b), 1))
    end if
  end function

  recursive function add16(a, b) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    integer(kind = c_int16_t) :: c

    if (b == 0_C_INT16_T) then
      c = a
    else
      c = add16(ieor(a, b), shiftl(iand(a, b), 1))
    end if
  end function

  recursive function add32(a, b) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    integer(kind = c_int32_t) :: c

    if (b == 0_C_INT32_T) then
      c = a
    else
      c = add32(ieor(a, b), shiftl(iand(a, b), 1))
    end if
  end function

  recursive function add64(a, b) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    integer(kind = c_int64_t) :: c

    if (b == 0_C_INT64_T) then
      c = a
    else
      c = add64(ieor(a, b), shiftl(iand(a, b), 1))
    end if
  end function

  recursive function subtract08(a, b) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    integer(kind = c_int8_t) :: c

    if (b == 0_C_INT8_T) then
      c = a
    else
      c = subtract08(ieor(a, b), shiftl(iand(not(a), b), 1))
    end if
  end function

  recursive function subtract16(a, b) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    integer(kind = c_int16_t) :: c

    if (b == 0_C_INT16_T) then
      c = a
    else
      c = subtract16(ieor(a, b), shiftl(iand(not(a), b), 1))
    end if
  end function

  recursive function subtract32(a, b) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    integer(kind = c_int32_t) :: c

    if (b == 0_C_INT32_T) then
      c = a
    else
      c = subtract32(ieor(a, b), shiftl(iand(not(a), b), 1))
    end if
  end function

  recursive function subtract64(a, b) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    integer(kind = c_int64_t) :: c

    if (b == 0_C_INT64_T) then
      c = a
    else
      c = subtract64(ieor(a, b), shiftl(iand(not(a), b), 1))
    end if
  end function

  recursive function multiply08(a, b, accumulator) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    integer(kind = c_int8_t), intent(inout) :: accumulator
    integer(kind = c_int8_t) :: c

    if (b == 0_C_INT8_T) then
      c = accumulator
    else
      if (btest(b, 0)) accumulator = add08(accumulator, a)
      c = multiply08(shiftl(a, 1), shiftr(b, 1), accumulator)
    end if
  end function

  recursive function multiply16(a, b, accumulator) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    integer(kind = c_int16_t), intent(inout) :: accumulator
    integer(kind = c_int16_t) :: c

    if (b == 0_C_INT16_T) then
      c = accumulator
    else
      if (btest(b, 0)) accumulator = add16(accumulator, a)
      c = multiply16(shiftl(a, 1), shiftr(b, 1), accumulator)
    end if
  end function

  recursive function multiply32(a, b, accumulator) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    integer(kind = c_int32_t), intent(inout) :: accumulator
    integer(kind = c_int32_t) :: c

    if (b == 0_C_INT32_T) then
      c = accumulator
    else
      if (btest(b, 0)) accumulator = add32(accumulator, a)
      c = multiply32(shiftl(a, 1), shiftr(b, 1), accumulator)
    end if
  end function

  recursive function multiply64(a, b, accumulator) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    integer(kind = c_int64_t), intent(inout) :: accumulator
    integer(kind = c_int64_t) :: c

    if (b == 0_C_INT64_T) then
      c = accumulator
    else
      if (btest(b, 0)) accumulator = add64(accumulator, a)
      c = multiply64(shiftl(a, 1), shiftr(b, 1), accumulator)
    end if
  end function

  function divide08(a, b, remainder) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    integer(kind = c_int8_t), intent(out) :: remainder
    integer(kind = c_int8_t) :: c

    integer :: i

    c = 0_C_INT8_T
    remainder = 0_C_INT8_T
    do i = 7, 0, -1
      remainder = shiftl(remainder, 1)
      call mvbits(a, i, 1, remainder, 0)
      if (remainder >= b) then
        remainder = subtract08(remainder, b)
        c = ibset(c, i)
      end if
    end do
  end function

  function divide16(a, b, remainder) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    integer(kind = c_int16_t), intent(out) :: remainder
    integer(kind = c_int16_t) :: c

    integer :: i

    c = 0_C_INT16_T
    remainder = 0_C_INT16_T
    do i = 7, 0, -1
      remainder = shiftl(remainder, 1)
      call mvbits(a, i, 1, remainder, 0)
      if (remainder >= b) then
        remainder = subtract16(remainder, b)
        c = ibset(c, i)
      end if
    end do
  end function

  function divide32(a, b, remainder) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    integer(kind = c_int32_t), intent(out) :: remainder
    integer(kind = c_int32_t) :: c

    integer :: i

    c = 0_C_INT32_T
    remainder = 0_C_INT32_T
    do i = 7, 0, -1
      remainder = shiftl(remainder, 1)
      call mvbits(a, i, 1, remainder, 0)
      if (remainder >= b) then
        remainder = subtract32(remainder, b)
        c = ibset(c, i)
      end if
    end do
  end function

  function divide64(a, b, remainder) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    integer(kind = c_int64_t), intent(out) :: remainder
    integer(kind = c_int64_t) :: c

    integer :: i

    c = 0_C_INT64_T
    remainder = 0_C_INT64_T
    do i = 7, 0, -1
      remainder = shiftl(remainder, 1)
      call mvbits(a, i, 1, remainder, 0)
      if (remainder >= b) then
        remainder = subtract64(remainder, b)
        c = ibset(c, i)
      end if
    end do
  end function

  function less08(a, b) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    logical :: c

    c = blt(a, b)
  end function

  function less16(a, b) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    logical :: c

    c = blt(a, b)
  end function

  function less32(a, b) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    logical :: c

    c = blt(a, b)
  end function

  function less64(a, b) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    logical :: c

    c = blt(a, b)
  end function

  function lessequal08(a, b) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    logical :: c

    c = ble(a, b)
  end function

  function lessequal16(a, b) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    logical :: c

    c = ble(a, b)
  end function

  function lessequal32(a, b) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    logical :: c

    c = ble(a, b)
  end function

  function lessequal64(a, b) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    logical :: c

    c = ble(a, b)
  end function

  function equal08(a, b) result(c)
    integer(kind = c_int8_t), intent(in) :: a
    integer(kind = c_int8_t), intent(in) :: b
    logical :: c

    c = ieor(a, b) == 0_C_INT8_T
  end function

  function equal16(a, b) result(c)
    integer(kind = c_int16_t), intent(in) :: a
    integer(kind = c_int16_t), intent(in) :: b
    logical :: c

    c = ieor(a, b) == 0_C_INT16_T
  end function

  function equal32(a, b) result(c)
    integer(kind = c_int32_t), intent(in) :: a
    integer(kind = c_int32_t), intent(in) :: b
    logical :: c

    c = ieor(a, b) == 0_C_INT32_T
  end function

  function equal64(a, b) result(c)
    integer(kind = c_int64_t), intent(in) :: a
    integer(kind = c_int64_t), intent(in) :: b
    logical :: c

    c = ieor(a, b) == 0_C_INT64_T
  end function

end module
