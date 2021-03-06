! <testinfo>
! test_generator=config/mercurium-fortran
! </testinfo>
MODULE SOME_TYPE
  TYPE RATIONAL
    INTEGER :: N, D
  END TYPE
END MODULE SOME_TYPE

PROGRAM MAIN
  USE SOME_TYPE
  
  IMPLICIT NONE
  
  INTERFACE
    FUNCTION RATIONAL_PLUS (L, R, RES)
      IMPORT RATIONAL
      TYPE (RATIONAL), INTENT (IN) :: L, R
      TYPE (RATIONAL), INTENT (OUT):: RES
    END FUNCTION RATIONAL_PLUS
  END INTERFACE
  
  TYPE ( RATIONAL ) :: X, Y, Z
  REAL :: A
  X = RATIONAL (1, 2)
  Y = RATIONAL (10, 20)
  A = RATIONAL_PLUS(X, Y, Z)
  
  PRINT *, Z
  
END PROGRAM MAIN
