INCLUDE=-Iinclude -Iexternal/c-algorithms/src

bench:
	mkdir -p bin
	gcc $(INCLUDE) -Ibenches/include -lm -o bin/ugraph-benchmarks external/c-algorithms/src/*.c src/*.c benches/*.c
	./bin/ugraph-benchmarks

clean:
	rm -rf bin

test:
	mkdir -p bin
	gcc $(INCLUDE) -Itests/include -lm -o bin/ugraph-tests external/c-algorithms/src/*.c src/*.c tests/*.c
	./bin/ugraph-tests