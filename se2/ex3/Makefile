CFLAGS = -Wall -g -c
LDFLAGS = -Wall -o

prog23: prog23.o book.o processFile.o errors.o splitFields.o separator_unify.o
	gcc $(LDFLAGS) prog23 prog23.o book.o processFile.o errors.o splitFields.o separator_unify.o

prog23.o: prog23.c book.h processFile.h errors.h
	gcc $(CFLAGS) prog23.c

book.o: book.c book.h splitFields.h separator_unify.h
	gcc $(CFLAGS) book.c

processFile.o: processFile.c processFile.h errors.h
	gcc $(CFLAGS) processFile.c

errors.o: errors.c errors.h
	gcc $(CFLAGS) errors.c

splitFields.o: splitFields.c splitFields.h
	gcc $(CFLAGS) splitFields.c

separator_unify.o: separator_unify.c separator_unify.h
	gcc $(CFLAGS) separator_unify.c

clean:
	rm -f prog23 *.o