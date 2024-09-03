#include "s21_tests.h"

START_TEST(s21_sum_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
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

  int status = s21_sum_matrix(&A, &B, &result);
  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         printf("%lf ", result.matrix[r][c]);
  //     }
  //     printf("\n");
  // }
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
START_TEST(s21_sum_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      A.matrix[r][c] = B.matrix[r][c] = 1;
    }
  }

  int status = s21_sum_matrix(&A, &B, &result);
  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         printf("%lf ", result.matrix[r][c]);
  //     }
  //     printf("\n");
  // }
  ck_assert_int_eq(status, 0);
  ck_assert_double_le(s21_dabs(result.matrix[0][0] - 2), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_sum_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

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
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("===Sum matrix===");
  TCase *tc = tcase_create("sum_tc");

  tcase_add_test(tc, s21_sum_1);
  tcase_add_test(tc, s21_sum_2);
  tcase_add_test(tc, s21_sum_3);

  suite_add_tcase(s, tc);
  return s;
}