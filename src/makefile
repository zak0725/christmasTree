all: main

FLAGS=-lpthread -g -Wall -lncurses

main: main.c christ.o colors.o screen.o flakes.o
	gcc $^ -o $@ $(FLAGS)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm *.o main

