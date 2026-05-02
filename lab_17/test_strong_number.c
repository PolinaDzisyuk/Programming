#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <stdbool.h>
#include <cmocka.h>
#include "strong_number.h"

static void test_num_is_zero(void **state) {
    (void)state;

    int func_res = isStrong(0);

    assert_false(func_res);
}

static void test_num_is_negative(void **state) {
    (void)state;
    bool res;

    int number = -26;

    if(number < 0) {
        res = false;
    }
    int func_res = isStrong(number);

    assert_int_equal(func_res, res);
}

static void test_num_is_strong(void **state) {
    (void)state;
    bool res;
    int sum = 1;

    int number = 145;
    
    long long factorial_4 = 1*2*3*4;
    long long factorial_5 = 1*2*3*4*5;
    sum += factorial_4 + factorial_5;

    if(sum == number) {
        res = true;
    }
    int func_res = isStrong(number);

    assert_int_equal(func_res, res);
}

static void test_num_is_not_strong(void **state) {
    (void)state;
    bool res;
    int sum = 1;

    int number = 26;
    
    long long factorial_2 = 1*2;
    long long factorial_6 = 1*2*3*4*5*6;
    sum = factorial_2 + factorial_6;

    if(sum != number) {
        res = false;
    }
    int func_res = isStrong(number);

    assert_int_equal(func_res, res);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_num_is_zero),
        cmocka_unit_test(test_num_is_negative),
        cmocka_unit_test(test_num_is_strong),
        cmocka_unit_test(test_num_is_not_strong),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}