FROM ubuntu:latest AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    g++ \


WORKDIR /app
COPY src .

FROM builder AS gcc_builder
RUN mkdir -p build_gcc && cd build_gcc


FROM builder AS clang_builder
RUN mkdir -p build_clang && cd build_clang
WORKDIR /app

COPY --from=gcc_builder /app/build_gcc/greater-than-counter .
ENTRYPOINT ["./greater-than-counter"]
