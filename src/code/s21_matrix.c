#include "../s21_matrix.h"

//     typedef struct matrix_struct {
//     double** matrix;
//     int rows;
//     int columns;
// } matrix_t;

// All operations (except matrix comparison) should return the resulting code:
//    0 - OK
//    1 - Error, incorrect matrix
//    2 - Calculation error (mismatched matrix sizes; matrix for which
//    calculations cannot be performed, etc.)

// Basic functions

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!s21_is_valid(rows, columns) || result == NULL) return INCORRECT_MTRX;
  result->rows = rows;
  result->columns = columns;
  int status = OK;
  double **matrix = NULL;
  if ((matrix = (double **)calloc(rows, sizeof(double *))) != NULL) {
    for (int i = 0; i < rows; i++) {
      if ((matrix[i] = (double *)calloc(columns, sizeof(double))) == NULL) {
        for (int j = i; j >= 0; i--) {
          free(matrix[j]);
        }
        free(matrix);
        matrix = NULL;
      }
    }
    if (matrix != NULL) {
      result->matrix = matrix;
    }
  } else {
    status = CALC_ERROR;
  }

  return status;
}
void s21_remove_matrix(matrix_t *A) {
  if (A == NULL) return;
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
  return;
}
// SUCCESS and FAILURE for comparison

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = s21_is_compatible(A, B);
  if (status == SUCCESS) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns && status == SUCCESS; c++) {
        double num = s21_dabs((double)A->matrix[r][c] - B->matrix[r][c]);
        double ernum = 1e-6;
        if (num <= ernum && num >= 0) {
          // printf("%.15f\n",  (double)A->matrix[r][c]);
          // printf("%.15f\n",  (double)B->matrix[r][c]);
          // printf("%.15f\n",  s21_dabs((double)A->matrix[r][c] -
          // B->matrix[r][c])); printf("%.15f\n", (double)0.0000001);
          status = SUCCESS;
        } else {
          status = FAILURE;
        }
      }
    }
  }
  return status;
}
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  int status = OK;
  if (!s21_is_compatible(A, B)) status = CALC_ERROR;
  if (status == OK) {
    s21_remove_matrix(result);
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[r][c] = A->matrix[r][c] + B->matrix[r][c];
      }
    }
  }
  return status;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  int status = OK;
  if (!s21_is_compatible(A, B)) status = CALC_ERROR;
  if (status == OK) {
    s21_remove_matrix(result);
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[r][c] = A->matrix[r][c] - B->matrix[r][c];
      }
    }
  }
  return status;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      result == NULL) {
    return INCORRECT_MTRX;
  }
  s21_remove_matrix(result);
  int status = s21_create_matrix(A->rows, A->columns, result);
  if (status == OK) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[r][c] = A->matrix[r][c] * number;
      }
    }
  }
  return status;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  /*
   1 2
   3 4
   5 6 A

   1 2 3 B
   4 5 6
  */
  int status = OK;
  if (!s21_is_valid(A->rows, A->columns) ||
      !s21_is_valid(B->rows, B->columns) || A->columns != B->rows)
    status = CALC_ERROR;
  if (status == OK) {
    s21_remove_matrix(result);
    status = s21_create_matrix(A->rows, B->columns, result);
  }
  if (status == OK) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < B->columns; c++) {
        result->matrix[r][c] = 0;
        for (int k = 0; k < B->rows; k++) {
          result->matrix[r][c] += A->matrix[r][k] * B->matrix[k][c];
        }
      }
    }
  }
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      result == NULL) {
    return INCORRECT_MTRX;
  }
  /*
            1 4   1 2 3
  A = A^T = 2 5 = 4 5 6
            3 6

  */
  s21_remove_matrix(result);
  int status = s21_create_matrix(A->columns, A->rows, result);
  if (status == OK) {
    for (int r = 0; r < A->rows; r++) {
      for (int c = 0; c < A->columns; c++) {
        result->matrix[c][r] = A->matrix[r][c];
      }
    }
  }
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  if (A->rows != A->columns) {
    return CALC_ERROR;
  }
  s21_remove_matrix(result);
  s21_create_matrix(A->rows, A->columns, result);
  for (int r = 0; r < A->rows; r++) {
    for (int c = 0; c < A->columns; c++) {
      // printf("%d\n", r*A->columns+c);
      result->matrix[r][c] =
          s21_minor_of_element(A, r, c) * (((r + c) % 2 == 0) ? 1 : -1);
    }
  }
  return OK;
}
int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  if (A->rows != A->columns) {
    return CALC_ERROR;
  }
  *result = 0;
  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t for_complement = {0};
    s21_create_matrix(A->rows, A->columns, &for_complement);
    s21_calc_complements(A, &for_complement);
    for (int i = 0; i < A->columns; i++) {
      *result += A->matrix[0][i] * for_complement.matrix[0][i];
      // printf("%lf\n", for_complement.matrix[0][i]);
    }
    s21_remove_matrix(&for_complement);
  }
  return OK;
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MTRX;
  }
  if (A->rows != A->columns) {
    return CALC_ERROR;
  }
  int status = OK;
  double determinant = 0;
  s21_determinant(A, &determinant);
  if (s21_dabs(determinant) > __DBL_EPSILON__) {
    s21_remove_matrix(result);
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t temp_compl = {0};
    s21_calc_complements(A, &temp_compl);
    matrix_t temp_transp = {0};
    s21_transpose(&temp_compl, &temp_transp);
    s21_mult_number(&temp_transp, (1 / determinant), result);
    s21_remove_matrix(&temp_compl);
    s21_remove_matrix(&temp_transp);
  } else {
    status = CALC_ERROR;
  }
  return status;
}