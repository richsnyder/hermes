program main

  use fruit
  implicit none

  integer :: failed_asserts

  call init_fruit()
  call test_dummy()
  call get_failed_count(failed_asserts)
  call fruit_summary()
  call fruit_finalize()

  if (failed_asserts > 0) then
    call exit(-1)
  endif

contains

  subroutine test_dummy()
    call assert_true(.true.)
  end subroutine

end program
