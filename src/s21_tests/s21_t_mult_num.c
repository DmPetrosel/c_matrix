#include "s21_tests.h"

START_TEST(s21_mult_n_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  double num = 5.51;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = (r + c);
    }
  }

  int status = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_n_2) {
  matrix_t A = {0};
  matrix_t result = {0};

  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double num = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = (r + c) + 1;
    }
  }
  int status = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result.matrix[1][1], 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *test_mult_number(void) {
  Suite *s = suite_create("===Mult number matrix===");
  TCase *tc = tcase_create("mult_n_tc");

  tcase_add_test(tc, s21_mult_n_1);
  tcase_add_test(tc, s21_mult_n_2);

  suite_add_tcase(s, tc);
  return s;
}