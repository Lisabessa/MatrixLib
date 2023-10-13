#include "../matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  int res_code;
  if (!A || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else {
    res_code = OK;
    create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return res_code;
}