INCLUDE=-Iinclude -Iexternal/c-vector

clean:
	rm -rf bin

test:
	mkdir -p bin
	gcc $(INCLUDE) -Itests/include -lm -o bin/ugraph-tests src/*.c tests/*.c
	./bin/ugraph-tests