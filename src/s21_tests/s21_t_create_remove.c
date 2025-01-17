#include "s21_tests.h"

START_TEST(s21_cr_rm_1) {
  matrix_t matrix = {0};
  int err_create = s21_create_matrix(2, 3, &matrix);
  ck_assert_int_eq(err_create, 0);
  matrix.matrix[1][2] = 5.0001;
  ck_assert_double_eq(matrix.matrix[1][2], 5.0001);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_cr_rm_2) {
  matrix_t matrix = {0};
  int err_create = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(err_create, 1);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_cr_rm_3) {
  int err_create = s21_create_matrix(2, 3, NULL);
  ck_assert_int_eq(err_create, 1);
  s21_remove_matrix(NULL);
}
START_TEST(s21_cr_rm_4) {
  matrix_t *matrix_ptr = NULL;
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}
START_TEST(s21_cr_rm_5) {
  matrix_t *matrix_ptr = {0};
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}
START_TEST(s21_cr_rm_6) {
  matrix_t *matrix_ptr = {0};
  s21_remove_matrix(matrix_ptr);
  s21_create_matrix(1, 3, matrix_ptr);
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}
START_TEST(s21_cr_rm_7) {
  matrix_t *matrix_ptr = NULL;
  s21_create_matrix(1, 3, matrix_ptr);
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}
START_TEST(s21_cr_rm_8) {
  matrix_t *matrix_ptr = NULL;
  s21_create_matrix(1, 3, matrix_ptr);
  s21_remove_matrix(matrix_ptr);
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}
START_TEST(s21_cr_rm_9) {
  matrix_t *matrix_ptr = NULL;
  s21_remove_matrix(matrix_ptr);
  ck_assert_ptr_null(matrix_ptr);
}

Suite *test_create_remove_matrix(void) {
  Suite *s = suite_create("===Create and remove matrix===");
  TCase *tc = tcase_create("create_tc");

  tcase_add_test(tc, s21_cr_rm_1);
  tcase_add_test(tc, s21_cr_rm_2);
  tcase_add_test(tc, s21_cr_rm_3);
  tcase_add_test(tc, s21_cr_rm_4);
  tcase_add_test(tc, s21_cr_rm_5);
  tcase_add_test(tc, s21_cr_rm_6);
  tcase_add_test(tc, s21_cr_rm_7);
  tcase_add_test(tc, s21_cr_rm_8);
  tcase_add_test(tc, s21_cr_rm_9);

  suite_add_tcase(s, tc);
  return s;
}