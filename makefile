main: main.c
	gcc main.c -o main -std=c99
	./main <test.txt
test: main
	./main < test.txt
