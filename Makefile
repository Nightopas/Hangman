main: build/src/main.o build/src/HangFileRead.o build/src/HangWordStruct.o
	gcc -Wall -Werror build/src/HangFileRead.o build/src/HangWordStruct.o build/src/main.o -o bin/Hangman

test: build/test/main.o build/test/HangFileRead.o build/test/HangWordStruct.o
	gcc -Wall -Werror build/test/main.o build/test/HangFileRead.o build/test/HangWordStruct.o -o bin/test

play: bin/main
	./bin/Hangman

build/src/main.o: src/main.c
	gcc -MP -MMD -Wall -Werror -c src/main.c -o build/src/main.o

build/src/HangFileRead.o: src/HangFileRead.c
	gcc -MP -MMD -Wall -Werror -c src/HangFileRead.c -o build/src/HangFileRead.o

build/src/HangWordStruct.o: src/HangWordStruct.c
	gcc -MP -MMD -Wall -Werror -c src/HangWordStruct.c -o build/src/HangWordStruct.o

build/test/main.o: test/test.c
	gcc -I thirdparty -I src -MP -MMD -Wall -Werror -c test/test.c -o build/test/main.o

build/test/HangFileRead.o: src/HangFileRead.c
	gcc -MP -MMD -Wall -Werror -c src/HangFileRead.c -o build/test/HangFileRead.o

build/test/HangWordStruct.o: src/HangWordStruct.c
	gcc -MP -MMD -Wall -Werror -c src/HangWordStruct.c -o build/test/HangWordStruct.o

.PHONY: clean

clean:
	rm -rf build/src/*
	rm -rf build/test/*
	rm -rf bin/*
