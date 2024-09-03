#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_
// Libraries

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Basic matrix structure

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// SUCCESS and FAILURE for comparison

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MTRX 1
#define CALC_ERROR 2

int s21_eq_matrix(matrix_t *A, matrix_t *B);

// All operations (except matrix comparison) should return the resulting code:
//    0 - OK
//    1 - Error, incorrect matrix
//    2 - Calculation error (mismatched matrix sizes; matrix for which
//    calculations cannot be performed, etc.)

// Additional functions

int s21_is_valid(int rows, int columns);
int s21_is_compatible(matrix_t *A, matrix_t *B);
double s21_dabs(double value);
double s21_minor_of_element(matrix_t *A, int i, int j);

// Basic functions

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_H_