#include "../matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int res_code;
  if (!A || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else {
    res_code = OK;
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return res_code;
}