# Math for Computer Graphics

## Development

### CMake

```
cmake PATH_TO_CMAKELIST \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=... \
  -DGRAPHMATH_DEV=1
```

- `-DCMAKE_TOOLCHAIN_FILE=...` is not always needed
- `-DGRAPHMATH_DEV=1` generate build files for development; this flags does the following
  - Enable `test` feature in `vcpkg.json`
  - Include tests
