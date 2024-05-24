include(candy/src/CMakeLists.txt)

target_compile_options(candy_core
  PRIVATE
  -Wno-format
)
