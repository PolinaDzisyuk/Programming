cmake_minimum_required(VERSION 3.10)

project(strong_number_tests)

find_package(cmocka REQUIRED)

add_executable(strong_number_tests strong_number.c test_strong_number.c)
target_link_libraries(strong_number_tests cmocka)


add_test(NAME zero     COMMAND strong_number_tests test_num_is_zero)
add_test(NAME negative COMMAND strong_number_tests test_num_is_negative)
add_test(NAME strong   COMMAND strong_number_tests test_num_is_strong)
add_test(NAME not_strong COMMAND strong_number_tests test_num_is_not_strong)

set_tests_properties(zero PROPERTIES ENVIRONMENT "CMOCKA_COLOR=1")
set_tests_properties(negative PROPERTIES ENVIRONMENT "CMOCKA_COLOR=1")
set_tests_properties(strong PROPERTIES ENVIRONMENT "CMOCKA_COLOR=1")
set_tests_properties(not_strong PROPERTIES ENVIRONMENT "CMOCKA_COLOR=1")

enable_testing()
