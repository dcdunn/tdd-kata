add_executable("soundex-cli"
  main.cpp
)

target_link_libraries("soundex-cli"
  soundex
)
