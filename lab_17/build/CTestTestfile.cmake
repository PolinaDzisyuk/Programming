# CMake generated Testfile for 
# Source directory: /home/pdzisyuk/programming/Programming/lab_17
# Build directory: /home/pdzisyuk/programming/Programming/lab_17/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(zero "/home/pdzisyuk/programming/Programming/lab_17/build/strong_number_tests" "test_num_is_zero")
set_tests_properties(zero PROPERTIES  ENVIRONMENT "CMOCKA_COLOR=1" _BACKTRACE_TRIPLES "/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;11;add_test;/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;0;")
add_test(negative "/home/pdzisyuk/programming/Programming/lab_17/build/strong_number_tests" "test_num_is_negative")
set_tests_properties(negative PROPERTIES  ENVIRONMENT "CMOCKA_COLOR=1" _BACKTRACE_TRIPLES "/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;12;add_test;/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;0;")
add_test(strong "/home/pdzisyuk/programming/Programming/lab_17/build/strong_number_tests" "test_num_is_strong")
set_tests_properties(strong PROPERTIES  ENVIRONMENT "CMOCKA_COLOR=1" _BACKTRACE_TRIPLES "/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;13;add_test;/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;0;")
add_test(not_strong "/home/pdzisyuk/programming/Programming/lab_17/build/strong_number_tests" "test_num_is_not_strong")
set_tests_properties(not_strong PROPERTIES  ENVIRONMENT "CMOCKA_COLOR=1" _BACKTRACE_TRIPLES "/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;14;add_test;/home/pdzisyuk/programming/Programming/lab_17/CMakeLists.txt;0;")
