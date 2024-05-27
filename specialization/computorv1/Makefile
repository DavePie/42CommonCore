
FILES:= src/main.rs
EXEC:= target/release/computorv1
ARG:= X^2 + 3 * X + 3 = X^3 - X^3 + X^2 * 2

all: build

run:
	./target/release/computorv1 "$(ARG)"

EXEC: build

build: FILES
	cargo build -r

clean:
	cargo clean

re: clean all

.PHONY: all build clean re