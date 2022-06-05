all: exec
main.o:main.c Affco.h home.h verif.h struct.h
	gcc -c main.c -o main.o
affco.o:affco.c Affco.h signin.h signup.h struct.h 
	gcc -c affco.c -o affco.o
home.o:home.c home.h borrow.h add.h return.h struct.h purge.h
	gcc -c home.c -o home.o
verif.o:verif.c verif.h struct.h
	gcc -c verif.c -o verif.o
signup.o:signup.c signup.h struct.h purge.h charg.h
	gcc -c signup.c -o signup.o

signin.o:signin.c signin.h struct.h
	gcc -c signin.c -o signin.o

add.o:add.c add.h struct.h purge.h charg.h
	gcc -c add.c -o add.o

struct.o:struct.c struct.h
	gcc -c struct.c -o struct.o

borrow.o:borrow.c borrow.h struct.h
	gcc -c borrow.c -o borrow.o

return.o:return.c return.h struct.h
	gcc -c return.c -o return.o
	
purge.o:purge.c purge.h struct.h
	gcc -c purge.c -o purge.o
	
charg.o:charg.c charg.h struct.h
	gcc -c charg.c -o charg.o
	
selectsorting.o:selectSorting.c selectSorting.h struct.h
	gcc -c selectSorting.c -o selectsorting.o

exec:main.o verif.o affco.o home.o signup.o signin.o add.o return.o borrow.o struct.o purge.o charg.o selectsorting.o
	gcc main.o verif.o affco.o home.o signup.o signin.o add.o return.o borrow.o struct.o purge.o charg.o selectsorting.o -o exec
clean:
	rm -f *.o
	rm exec
