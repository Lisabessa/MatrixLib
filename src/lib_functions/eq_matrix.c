#include "../matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  int res_code = FAILURE;
  if (A && B && A->rows == B->rows && A->columns == B->columns) {
    res_code = SUCCESS;
    for (int i = 0; i < A->rows && res_code; i++) {
      for (int j = 0; j < A->columns && res_code; j++) {
        if ((long int)(A->matrix[i][j] * 10000000) !=
            (long int)(B->matrix[i][j] * 10000000)) {
          res_code = FAILURE;
        }
      }
    }
  }
  return res_code;
}