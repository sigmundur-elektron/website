# ---- Build stage ----
FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    cmake ninja-build git curl zip unzip tar \
    pkg-config gcc g++ && \
    rm -rf /var/lib/apt/lists/*

# Install vcpkg
ENV VCPKG_ROOT=/opt/vcpkg
RUN git clone https://github.com/microsoft/vcpkg "$VCPKG_ROOT" && \
    "$VCPKG_ROOT/bootstrap-vcpkg.sh" -disableMetrics

WORKDIR /app
COPY vcpkg.json .
COPY CMakeLists.txt .
COPY CMakePresets.json .
COPY src/ src/

RUN cmake -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" && \
    cmake --build build --config Release

# ---- Runtime stage ----
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/build/AcmeBackend /usr/local/bin/AcmeBackend

EXPOSE 8080
CMD ["AcmeBackend"]
