all: clean objeto fibofork fibothreads test

test: objeto
	gcc test.c -o test fibo.o

fibofork: objeto
	gcc fibofork.c -o fibofork fibo.o

fibothreads: objeto
	gcc fibothreads.c -o fibothreads fibo.o -pthread

objeto:
	gcc -c fibo.c

clean:
	rm -rf fibo.o fibofork test fibothreads
