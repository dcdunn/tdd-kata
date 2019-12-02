# Top level CMake

# GMock target
add_subdirectory("${PROJECT_SOURCE_DIR}/googletest" "googletest")

# Source targets
add_subdirectory(app)
add_subdirectory(soundex)
add_subdirectory(test)
