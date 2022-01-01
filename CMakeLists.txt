add_library(pico_tiny INTERFACE)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/tiny)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/tiny-devices)

target_sources(pico_tiny INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/heartbeat.c
  ${CMAKE_CURRENT_LIST_DIR}/src/tiny_i2c.c
  ${CMAKE_CURRENT_LIST_DIR}/src/tiny_spi.c
  ${CMAKE_CURRENT_LIST_DIR}/src/tiny_time_source.c
)

target_include_directories(pico_tiny INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(pico_tiny INTERFACE
  tiny
  tiny_devices
)
