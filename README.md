# pico-tiny
Interface library for using [tiny](https://github.com/ryanplusplus/tiny) and [tiny-devices](https://github.com/ryanplusplus/tiny-devices) with Raspberry Pi Pico.

## Setup
In `CmakeLists.txt`, first add as a subdirectory:

```cmake
add_subdirectory(<path to>/pico-tiny)
```

then add as a link library:

```cmake
target_link_libraries(<target name>
  ...
  pico_tiny
)
```
