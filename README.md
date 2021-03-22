# Math for Computer Graphics

All operations are delegated to the platform native math library

- [x] Apple Platforms: `simd`
- [ ] Windows: `DirectXMath`

APIs are modeled after the math functions in Metal, HLSL, GLSL

- `graphmath::float3`
- `graphmath::float4`
- `graphmath::float4x4`

## Consumption

- **Platform**
  - Apple Platforms
  - Windows
  - **Linux is not supported**

### Vcpkg

#### Features

- `test`: setup unit tests (executable: `graphmath_test`)

## Development

### CMake

```
cmake PATH_TO_CMAKELIST \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=... \
  -DGRAPHMATH_TEST=1 \
  -DVCPKG_MANIFEST_FEATURES=test
```

- `-DCMAKE_TOOLCHAIN_FILE=...` is not always needed
- `-DGRAPHMATH_TEST=1` generate build files for development by including unit tests
- `-DVCPKG_MANIFEST_FEATURES=test` setup dependencies for testing

When this library is consumed by other libraries or applications

- `test` feature should turn on `GRAPHMATH_TEST`
