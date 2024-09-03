#ifndef S21_TESTS_H_
#define S21_TESTS_H_

// Libs
#include <check.h>
#include <stddef.h>
#include <stdio.h>

#include "../s21_matrix.h"

// SUCCESS and FAILURE for comparison
// SUCCESS 1
// FAILURE 0

Suite *test_equal(void);

// All operations (except matrix comparison) should return the resulting code:
//    0 - OK
//    1 - Error, incorrect matrix
//    2 - Calculation error (mismatched matrix sizes; matrix for which
//    calculations cannot be performed, etc.)

// Basic functions

Suite *test_create_remove_matrix(void);
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_transpose(void);
Suite *test_calc_complements(void);
Suite *test_determinant(void);
Suite *test_inverse_matrix(void);

#endif  // S21_TESTS_H_