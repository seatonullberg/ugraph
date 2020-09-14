INCLUDE=-Iinclude -Iexternal/c-algorithms/src

clean:
	rm -rf bin

test:
	mkdir -p bin
	gcc $(INCLUDE) -Itests/include -lm -o bin/ugraph-tests external/c-algorithms/src/*.c src/*.c tests/*.c
	./bin/ugraph-tests