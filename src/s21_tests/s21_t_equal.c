#include "s21_tests.h"

START_TEST(s21_eq_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double num = 5.51;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = B.matrix[r][c] = (r + c) * num;
    }
  }
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double num = 5.51;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = B.matrix[r][c] = (r + c) * num;
    }
  }
  A.matrix[0][1] = 4;
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns + 1, &B);

  double num = 5.51;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = (r + c) * num;
    }
  }
  for (int r = 0; r < rows + 1; r++) {
    for (int c = 0; c < columns + 1; c++) {
      B.matrix[r][c] = (r + c) * num;
    }
  }
  A.matrix[0][1] = 4;
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123456789;
  A.matrix[0][1] = 1.123456789;
  A.matrix[0][2] = 1.123456789;
  A.matrix[1][0] = 1.123456789;
  A.matrix[1][1] = 1.123456789;
  A.matrix[1][2] = 1.123456789;

  B.matrix[0][0] = 1.123456789;
  B.matrix[0][1] = 1.123456789;
  B.matrix[0][2] = 1.123456789;
  B.matrix[1][0] = 1.123456789;
  B.matrix[1][1] = 1.123456789;
  B.matrix[1][2] = 1.123456111;
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
START_TEST(s21_eq_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123456789;
  A.matrix[0][1] = 1.123456789;
  A.matrix[0][2] = 1.123456789;
  A.matrix[1][0] = 1.123456789;
  A.matrix[1][1] = 1.123456789;
  A.matrix[1][2] = 1.123456789;

  B.matrix[0][0] = 1.123456789;
  B.matrix[0][1] = 1.123456789;
  B.matrix[0][2] = 1.123456789;
  B.matrix[1][0] = 1.123456789;
  B.matrix[1][1] = 1.123456789;
  B.matrix[1][2] = 1.123451111;
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

Suite *test_equal(void) {
  Suite *s = suite_create("===Is matrix equal===");
  TCase *tc = tcase_create("eq_tc");

  tcase_add_test(tc, s21_eq_1);
  tcase_add_test(tc, s21_eq_2);
  tcase_add_test(tc, s21_eq_3);
  tcase_add_test(tc, s21_eq_4);
  tcase_add_test(tc, s21_eq_5);

  suite_add_tcase(s, tc);
  return s;
}