CFLAGS = -Wall -g -c
LDFLAGS = -Wall -o

prog24: prog24.o book.o processFile.o errors.o splitFields.o separator_unify.o strcmp_ic.o
	gcc $(LDFLAGS) prog24 prog24.o book.o processFile.o errors.o splitFields.o separator_unify.o strcmp_ic.o

prog24.o: prog24.c book.h processFile.h errors.h
	gcc $(CFLAGS) prog24.c

book.o: book.c book.h splitFields.h separator_unify.h strcmp_ic.h
	gcc $(CFLAGS) book.c

processFile.o: processFile.c processFile.h errors.h
	gcc $(CFLAGS) processFile.c

errors.o: errors.c errors.h
	gcc $(CFLAGS) errors.c

splitFields.o: splitFields.c splitFields.h
	gcc $(CFLAGS) splitFields.c

separator_unify.o: separator_unify.c separator_unify.h
	gcc $(CFLAGS) separator_unify.c

strcmp_ic.o: strcmp_ic.c strcmp_ic.h
	gcc $(CFLAGS) strcmp_ic.c

clean:
	rm -f prog24 *.o