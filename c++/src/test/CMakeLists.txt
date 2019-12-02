set(TESTNAME "tests")

add_executable(${TESTNAME}
  main.cpp
  test_soundex.cpp
)

target_link_libraries(${TESTNAME}
  soundex
)

# GMock
target_link_libraries(${TESTNAME} gtest gmock)

add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
