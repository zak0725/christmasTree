FLAGS=-g -Wall -lncurses

christmas: src/main.c src/christ.o src/colors.o src/flakes.o
	gcc $^ -o $@ $(FLAGS)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm *.o main

