all: str.o 4dchess.o
	gcc 4dchess.o lib/string/str.o -o 4dchess

4dchess.o:
	gcc -c 4dchess.c

str.o:
	make -C lib/string

clean:
	make -C lib/string clean
	rm -f *.o 4dchess
