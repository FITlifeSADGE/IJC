CC = gcc
CFLAGS = -O2 -std=c99 -pedantic -Wall -Wextra -g -lm
FILES = htab_init.o htab_move.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o
LOGIN = xkapra00

all: tail libhtab.a libhtab.so wordcount wordcount-dynamic


tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@ -static

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@	

#
libhtab.a: $(FILES)
	ar rcs $@ $^

libhtab.so: $(FILES)
	$(CC) $(CFLAGS) -fPIC -shared  $^ -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c htab.h htab_struct.h
	$(CC) $(CFLAGS) -fPIC -c $<  

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o tail libhtab.a libhtab.so wordcount wordcount-dynamic

count:
	./wordcount <test.txt | sort -k 2,2 -n

count_dynamic:
	export LD_LIBRARY_PATH="." && ./wordcount-dynamic <test.txt | sort -k 2,2 -n

zip:
	zip $(LOGIN).zip *.c *.h Makefile