#include "unity.h"


int my_add(int a, int b) {
    return a + b;
}

int my_sub(int a, int b) {
    return a - b;
}

// ---- Tests ----
void test_addition_should_add_two_numbers(void) {
    TEST_ASSERT_EQUAL_INT(4, my_add(2, 2));
}

void test_subtraction_should_subtract_two_numbers(void) {
    TEST_ASSERT_EQUAL_INT(1, my_sub(3, 2));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_addition_should_add_two_numbers);
    RUN_TEST(test_subtraction_should_subtract_two_numbers);

    return UNITY_END();
}