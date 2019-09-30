add_subdirectory("${PROJECT_SOURCE_DIR}/googletest" "googletest")

set(TESTNAME "tests")

add_executable(${TESTNAME}
    Soundex.h
    main.cpp
    test.cpp)

target_link_libraries(${TESTNAME} gtest gmock)
add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
