#include "../matrix.h"

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code;
  if (!A || !B || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    res_code = OK;
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return res_code;
}