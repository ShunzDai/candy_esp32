idf_component_register(
  SRCS 
  main.c
  INCLUDE_DIRS
  .
)

add_subdirectory(components)

target_link_libraries(${COMPONENT_LIB}
  PRIVATE
  candy_core
)
