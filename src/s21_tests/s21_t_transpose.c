#include "s21_tests.h"

START_TEST(s21_transpose_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 2;

  s21_create_matrix(rows, columns, &A);

  int status = s21_transpose(&A, &result);

  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_transpose_2) {
  matrix_t A = {0};
  matrix_t result = {0};

  int rows = 1;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(result.matrix[2][0], 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *test_transpose(void) {
  Suite *s = suite_create("===Transpose matrix===");
  TCase *tc = tcase_create("transpose_tc");

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);

  suite_add_tcase(s, tc);
  return s;
}