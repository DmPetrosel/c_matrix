#include "s21_tests.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 2;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  // double num = 1.0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = (double)(c + r * columns + 1);
      // printf("%lf ", A.matrix[r][c]);
    }
    // printf("\n");
  }
  for (int r = 0; r < columns; r++) {
    for (int c = 0; c < rows; c++) {
      B.matrix[r][c] = (double)(c + r * rows + 1);
      // printf("%lf ", B.matrix[r][c]);
    }
    // printf("\n");
  }
  int status = s21_mult_matrix(&A, &B, &result);
  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < rows; c++){
  //         printf("%lf ", result.matrix[r][c]);
  //     }
  //     printf("\n");
  // }
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(26 - result.matrix[1][1]), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("===Mult matrix===");
  TCase *tc = tcase_create("mult_matrix_tc");

  tcase_add_test(tc, s21_mult_matrix_1);
  // tcase_add_test(tc, s21_mult_matrix_2);

  suite_add_tcase(s, tc);
  return s;
}