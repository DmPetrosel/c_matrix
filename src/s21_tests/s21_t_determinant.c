#include "s21_tests.h"

START_TEST(s21_det_1) {
  matrix_t A = {0};
  double result = 0;
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(result - 0), __DBL_EPSILON__);
  s21_remove_matrix(&A);
}
START_TEST(s21_det_2) {
  matrix_t A = {0};
  double result = 0;
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 9;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(result - 40), __DBL_EPSILON__);
  s21_remove_matrix(&A);
}
START_TEST(s21_det_3) {
  matrix_t A = {0};
  double result = 0;
  int rows = 2;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 2);
  ck_assert_double_le(s21_dabs(result - 0), __DBL_EPSILON__);

  s21_remove_matrix(&A);
}

Suite *test_determinant(void) {
  Suite *s = suite_create("===Determinant of matrix===");
  TCase *tc = tcase_create("det_tc");

  tcase_add_test(tc, s21_det_1);
  tcase_add_test(tc, s21_det_2);
  tcase_add_test(tc, s21_det_3);

  suite_add_tcase(s, tc);
  return s;
}