CFLAGS = -Wall -c
LDFLAGS = -Wall -o

prog21: prog21.o lineprint.o errors.o processFile.o
	gcc $(LDFLAGS) prog21 prog21.o lineprint.o errors.o processFile.o

prog21.o: prog21.c lineprint.h errors.h processFile.h
	gcc $(CFLAGS) prog21.c 

lineprint.o: lineprint.c
	gcc $(CFLAGS) lineprint.c

errors.o: errors.c
	gcc $(CFLAGS) errors.c

processFile.o: processFile.c
	gcc $(CFLAGS) processFile.c

errors.o: errors.c errors.h
	gcc -Wall -c errors.c

clean:
	rm prog21 *.o