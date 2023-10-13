#include "../matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  if (!A || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    double determinantA = 0;
    determinant(A, &determinantA);
    if (fabs(determinantA) < 1e-6) {
      res_code = CALCULATION_ERROR;
    } else {
      matrix_t complements, transposed_complements;
      calc_complements(A, &complements);
      transpose(&complements, &transposed_complements);
      remove_matrix(&complements);
      mult_number(&transposed_complements, 1.0 / determinantA, result);
      remove_matrix(&transposed_complements);
    }
  }
  return res_code;
}