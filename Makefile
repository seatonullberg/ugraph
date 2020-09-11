INCLUDE=-Iinclude -Iexternal

clean:
	rm -rf bin

test:
	mkdir -p bin
	gcc $(INCLUDE) -Itests/include -lm -o bin/libatompack-tests src/*.c tests/*.c
	./bin/libatompack-tests