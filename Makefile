main: build/src/main.o
	gcc -Wall -Werror build/src/main.o -o bin/Hangman

test: build/test/main.o
	gcc -Wall -Werror build/test/main.o -o bin/test

play: bin/main
	./bin/Hangman

build/src/main.o: src/main.c
	gcc -MP -MMD -Wall -Werror -c src/main.c -o build/src/main.o

build/test/main.o: test/test.c
	gcc -I thirdparty -I src -MP -MMD -Wall -Werror -c test/test.c -o build/test/main.o

.PHONY: clean

clean:
	rm -rf build/*
	rm -rf bin/*
