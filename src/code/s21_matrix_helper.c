#include "../s21_matrix.h"

int s21_is_valid(int rows, int columns) {
  int status = SUCCESS;
  if (rows <= 0 || columns <= 0) status = FAILURE;
  return status;
}
int s21_is_compatible(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (A->rows != B->rows && A->columns != B->columns) {
    status = FAILURE;
  }
  return status;
}

double s21_dabs(double value) { return (value < 0) ? -value : value; }

double s21_minor_of_element(matrix_t *A, int i, int j) {
  matrix_t result = {0};
  int rows = A->rows - 1;
  int columns = A->columns - 1;
  int subc = 0, subr = 0;
  s21_create_matrix(rows, columns, &result);
  for (int r = 0; r < rows + 1; r++) {
    if (r == i) {
      subr++;
      continue;
    }
    subc = 0;
    for (int c = 0; c < columns + 1; c++) {
      if (c == j) {
        subc++;
        continue;
      }
      result.matrix[r - subr][c - subc] = A->matrix[r][c];
    }
  }
  double double_res = 0;
  s21_determinant(&result, &double_res);
  s21_remove_matrix(&result);
  return double_res;
}