#include "../matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code;
  if (!A || !B || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    res_code = CALCULATION_ERROR;
  } else {
    res_code = OK;
    create_matrix(A->rows, B->columns, result);
    int buff = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        buff = 0;
        for (int k = 0; k < A->columns; k++) {
          buff += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = buff;
      }
    }
  }
  return res_code;
}