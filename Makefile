run: build
	./main.out

build: main.cpp
	/opt/homebrew/bin/g++-15 -std=gnu++17 -DLOCAL main.cpp -o main.out

clean:
	rm -f *.out

all: build run clean
