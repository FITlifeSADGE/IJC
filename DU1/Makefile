CC = gcc
CFLAGS= -std=c11 -O2 -Wall -Wextra -pedantic -g -lm
LOGIN = xkapra00
#-m32 stále nefunguje

all: primes primes-i steg-decode

run: primes primes-i
	ulimit -s 65000 && time ./primes
	ulimit -s 65000 && time ./primes-i


primes: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) primes.o error.o eratosthenes.o bitset.o -o primes

primes-i: primes-i.o error.o eratosthenes-i.o bitset-i.o
	$(CC) $(CFLAGS) primes-i.o error.o eratosthenes-i.o bitset-i.o -o primes-i

steg-decode: steg-decode-i.o error.o eratosthenes-i.o ppm.o bitset-i.o
	$(CC) $(CLAGS) steg-decode-i.o ppm.o error.o eratosthenes-i.o bitset-i.o -o steg-decode



primes.o: primes.c eratosthenes.h error.h bitset.h
	$(CC) $(CFLAGS) -c -o primes.o primes.c

eratosthenes.o: eratosthenes.c eratosthenes.h error.h bitset.h
	$(CC) $(CFLAGS) -c -o eratosthenes.o eratosthenes.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c -o error.o error.c

ppm.o: error.h ppm.c ppm.h
	$(CC) $(CFLAGS) -c -o ppm.o ppm.c

bitset.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -c -o bitset.o bitset.c


primes-i.o: primes.c eratosthenes.h error.h bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o primes-i.o primes.c

eratosthenes-i.o: eratosthenes.c eratosthenes.h error.h bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o eratosthenes-i.o eratosthenes.c

steg-decode-i.o: steg-decode.c eratosthenes.h error.h ppm.h bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o steg-decode-i.o steg-decode.c

bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o bitset-i.o bitset.c



clean:
	rm -f primes primes-i steg-decode *.o
	$(LOGIN).zip

valgrind:
	valgrind --leak-check=yes ./primes

test:
	./primes|factor && ./primes-i|factor

image:
	./steg-decode du1-obrazek.ppm

zip:
	zip $(LOGIN).zip *.c *.h Makefile
