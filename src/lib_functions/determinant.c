#include "../matrix.h"

int determinant(matrix_t *A, double *result) {
  int res_code;
  if (!A || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    res_code = CALCULATION_ERROR;
  } else {
    res_code = OK;
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = determinant_2(*A);
    } else {
      double determinantA = 0;
      int sign = 1;
      matrix_t minored_matrix;
      double value_mul = 0;
      double buf = 0;
      for (int i = 0; i < A->rows; i++) {
        buf = 0;
        value_mul = A->matrix[0][i];
        find_minor(*A, 0, i, &minored_matrix);
        determinant(&minored_matrix, &buf);
        buf *= value_mul * sign;
        determinantA += buf;
        sign = -sign;

        remove_matrix(&minored_matrix);
      }
      *result = determinantA;
    }
  }
  return res_code;
}