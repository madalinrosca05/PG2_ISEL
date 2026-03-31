prog16: prog16.o separator_unify.o splitFields.o strcmp_ic.o errors.o
	gcc -Wall -o prog16 prog16.o separator_unify.o splitFields.o strcmp_ic.o errors.o

prog16.o: prog16.c separator_unify.h splitFields.h strcmp_ic.h errors.h
	gcc -Wall -c prog16.c

separator_unify.o: separator_unify.c separator_unify.h
	gcc -Wall -c separator_unify.c

splitFields.o: splitFields.c splitFields.h
	gcc -Wall -c splitFields.c

strcmp_ic.o: strcmp_ic.c strcmp_ic.h
	gcc -Wall -c strcmp_ic.c

errors.o: errors.c errors.h
	gcc -Wall -c errors.c

clean:
	rm -f prog16 *.o