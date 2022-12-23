all: christmas

FLAGS=-g -Wall -lncurses

christmas: main.c christ.o colors.o screen.o flakes.o
	gcc $^ -o $@ $(FLAGS)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm *.o christmas

