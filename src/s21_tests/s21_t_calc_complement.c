#include "s21_tests.h"

START_TEST(s21_compl_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         A.matrix[r][c] = (r+c*rows+1);
  //         printf("%lf ",A.matrix[r][c] );
  //     }
  //     printf("\n");
  // }

  int status = s21_calc_complements(&A, &result);
  //  for(int r = 0; r < result.rows; r++){
  //     for(int c = 0; c < result.columns; c++){
  //         printf("%lf ",result.matrix[r][c] );
  //     }
  //     printf("\n");
  // }
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
START_TEST(s21_compl_2) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         A.matrix[r][c] = (r+c*rows+1);
  //         printf("%lf ",A.matrix[r][c] );
  //     }
  //     printf("\n");
  // }

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_double_le(s21_dabs(result.matrix[0][0] - 0), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
START_TEST(s21_compl_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         A.matrix[r][c] = (r+c*rows+1);
  //         printf("%lf ",A.matrix[r][c] );
  //     }
  //     printf("\n");
  // }

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_double_le(s21_dabs(result.matrix[0][1] - 10), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
START_TEST(s21_compl_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;

  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         A.matrix[r][c] = (r+c*rows+1);
  //         printf("%lf ",A.matrix[r][c] );
  //     }
  //     printf("\n");
  // }

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_double_le(s21_dabs(result.matrix[0][2] + 20), __DBL_EPSILON__);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_compl_5) {
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

  // for(int r = 0; r < rows; r++){
  //     for(int c = 0; c < columns; c++){
  //         A.matrix[r][c] = (r+c*rows+1);
  //         printf("%lf ",A.matrix[r][c] );
  //     }
  //     printf("\n");
  // }

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *test_calc_complements(void) {
  Suite *s = suite_create("===Complement of matrix===");
  TCase *tc = tcase_create("compl_tc");

  tcase_add_test(tc, s21_compl_1);
  tcase_add_test(tc, s21_compl_2);
  tcase_add_test(tc, s21_compl_3);
  tcase_add_test(tc, s21_compl_4);
  tcase_add_test(tc, s21_compl_5);

  suite_add_tcase(s, tc);
  return s;
}