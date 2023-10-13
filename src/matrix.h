#include <math.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum OPERATION_RESULT { OK, ERROR_INCORRECT_MATRIX, CALCULATION_ERROR };

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);

int eq_matrix(matrix_t *A, matrix_t *B);

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int transpose(matrix_t *A, matrix_t *result);

int determinant(matrix_t *A, double *result);
int calc_complements(matrix_t *A, matrix_t *result);
int inverse_matrix(matrix_t *A, matrix_t *result);

//----------------- AUXILIARY FUNCTIONS --------------------

void find_minor(matrix_t src, int remove_i, int remove_j, matrix_t *result);
double determinant_2(matrix_t src);
