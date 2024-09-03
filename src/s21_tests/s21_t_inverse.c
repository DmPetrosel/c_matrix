#include "s21_tests.h"

START_TEST(s21_inverse_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(result.matrix[0][0] - 1), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
START_TEST(s21_inverse_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(result.matrix[1][0] + 38), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
START_TEST(s21_inverse_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("===Inverse matrix===");
  TCase *tc = tcase_create("inverse_tc");

  tcase_add_test(tc, s21_inverse_1);
  tcase_add_test(tc, s21_inverse_2);
  tcase_add_test(tc, s21_inverse_3);

  suite_add_tcase(s, tc);
  return s;
}