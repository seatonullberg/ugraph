INCLUDE=-Iinclude
SRC=src/*.c

bench:
	mkdir -p bin
	gcc $(INCLUDE) -Ibenches/include -lm -o bin/ugraph-benchmarks $(SRC) benches/*.c
	./bin/ugraph-benchmarks

clean:
	rm -rf bin

shared:
	mkdir -p bin
	gcc $(INCLUDE) -c -fPIC src/ugraph.c -o bin/ugraph.o
	gcc -shared bin/ugraph.o -o bin/libugraph.so

test:
	mkdir -p bin
	gcc $(INCLUDE) -Itests/include -lm -o bin/ugraph-tests $(SRC) tests/*.c
	./bin/ugraph-tests