all: programa funciones.s main.s

programa: funciones.o main.o
	gcc funciones.o main.o -o programa

funciones.o: funciones.c funciones.h
	gcc -c funciones.c

main.o: main.c funciones.h
	gcc -c main.c

funciones.s: funciones.c
	objdump -S funciones.o > funciones.s

main.s: main.c
	objdump -S main.o > main.s

clean:
	rm -f programa main.o funciones.o funciones.s main.s
