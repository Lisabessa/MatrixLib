# Matrix Library

Implementation of the matrix.h library.   

In this project I will implement my own library for processing numerical matrices in the C programming language. Matrices are one of the basic data structures in programming, e.g. they are used to represent table values, for computational tasks and neural networks. As part of the project you will learn more about matrices and solidify knowledge of structured programming.


## Matrix

A matrix is a collection of numbers arranged into a fixed number of rows and columns.
Matrix A is a rectangular table of numbers arranged in m rows and n columns

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```


## Matrix operations

All operations (except matrix comparison) should return the resulting code:
- 0 - OK
- 1 - Error, incorrect matrix
- 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)

### Creating matrices (create_matrix)

```c
int create_matrix(int rows, int columns, matrix_t *result);
```

### Cleaning of matrices (remove_matrix)

```c
void remove_matrix(matrix_t *A);
```

### Matrix comparison (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int eq_matrix(matrix_t *A, matrix_t *B);
```

The matrices A, B are equal |A = B| if they have the same dimensions and the corresponding elements are identical, thus for all i and j: A(i,j) = B(i,j)

The comparison must be up to and including 7 decimal places.

### Adding (sum_matrix) and subtracting matrices (sub_matrix)

```c
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```


### Matrix multiplication by scalar (mult_number). Multiplication of two matrices (mult_matrix)

```c
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```


### Matrix transpose (transpose)

```c
int transpose(matrix_t *A, matrix_t *result);
```


### Minor of matrix and matrix of algebraic complements (calc_complements)
```c
int calc_complements(matrix_t *A, matrix_t *result);
```


### Matrix determinant

```c
int determinant(matrix_t *A, double *result);
```


### Inverse of the matrix (inverse_matrix)

```c
int inverse_matrix(matrix_t *A, matrix_t *result);
```