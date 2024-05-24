add_subdirectory(candy)

target_compile_options(candy_core
  PRIVATE
  -Wno-format
)
