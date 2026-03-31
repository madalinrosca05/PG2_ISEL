prog14: prog14.o separator_unify.o splitFields.o 
	gcc -Wall -o prog16 prog16.o separator_unify.o splitFields.o 

prog16.o: prog16.c separator_unify.h splitFields.h
	gcc -Wall -c prog16.c

separator_unify.o: separator_unify.c separator_unify.h
	gcc -Wall -c separator_unify.c

splitFields.o: splitFields.c splitFields.h
	gcc -Wall -c splitFields.c

clean:
	rm -f prog14 *.o