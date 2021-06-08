main: build/src/main.o build/src/HangFileRead.o build/src/HangWordStruct.o build/src/HangConsoleDraw.o build/src/HangRandWord.o build/src/HangGrammarCheck.o
	gcc -Wall -Werror build/src/HangFileRead.o build/src/HangWordStruct.o build/src/HangConsoleDraw.o build/src/HangRandWord.o build/src/HangGrammarCheck.o build/src/main.o -o bin/Hangman

test: build/test/main.o build/test/HangFileRead.o build/test/HangWordStruct.o build/test/HangConsoleDraw.o build/test/HangRandWord.o build/test/HangGrammarCheck.o
	gcc -Wall -Werror build/test/main.o build/test/HangFileRead.o build/test/HangWordStruct.o build/test/HangConsoleDraw.o build/test/HangRandWord.o build/test/HangGrammarCheck.o -o bin/test

play: bin/main
	./bin/Hangman

build/src/main.o: src/main.c
	gcc -MP -MMD -Wall -Werror -c src/main.c -o build/src/main.o

build/src/HangFileRead.o: src/HangFileRead.c
	gcc -MP -MMD -Wall -Werror -c src/HangFileRead.c -o build/src/HangFileRead.o

build/src/HangWordStruct.o: src/HangWordStruct.c
	gcc -MP -MMD -Wall -Werror -c src/HangWordStruct.c -o build/src/HangWordStruct.o

build/src/HangConsoleDraw.o: src/HangConsoleDraw.c
	gcc -MP -MMD -Wall -Werror -c src/HangConsoleDraw.c -o build/src/HangConsoleDraw.o

build/src/HangRandWord.o: src/HangRandWord.c
	gcc -MP -MMD -Wall -Werror -c src/HangRandWord.c -o build/src/HangRandWord.o

build/src/HangGrammarCheck.o: src/HangGrammarCheck.c
	gcc -MP -MMD -Wall -Werror -c src/HangGrammarCheck.c -o build/src/HangGrammarCheck.o

build/test/main.o: test/test.c
	gcc -I thirdparty -I src -MP -MMD -Wall -Werror -c test/test.c -o build/test/main.o

build/test/HangFileRead.o: src/HangFileRead.c
	gcc -MP -MMD -Wall -Werror -c src/HangFileRead.c -o build/test/HangFileRead.o

build/test/HangWordStruct.o: src/HangWordStruct.c
	gcc -MP -MMD -Wall -Werror -c src/HangWordStruct.c -o build/test/HangWordStruct.o

build/test/HangConsoleDraw.o: src/HangConsoleDraw.c
	gcc -MP -MMD -Wall -Werror -c src/HangConsoleDraw.c -o build/test/HangConsoleDraw.o

build/test/HangRandWord.o: src/HangRandWord.c
	gcc -MP -MMD -Wall -Werror -c src/HangRandWord.c -o build/test/HangRandWord.o

build/test/HangGrammarCheck.o: src/HangGrammarCheck.c
	gcc -MP -MMD -Wall -Werror -c src/HangGrammarCheck.c -o build/test/HangGrammarCheck.o

.PHONY: clean

clean:
	rm -rf build/src/*
	rm -rf build/test/*
	rm -rf bin/*
