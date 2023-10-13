#include "../matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;

  if (!A || !result) {
    res_code = ERROR_INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    create_matrix(A->rows, A->columns, result);
    matrix_t minored_matrix;
    double determinantA = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        find_minor(*A, i, j, &minored_matrix);
        determinant(&minored_matrix, &determinantA);
        result->matrix[i][j] = determinantA;
        remove_matrix(&minored_matrix);
      }
    }

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] *= pow(-1, i + j);
      }
    }
  }
  return res_code;
}
