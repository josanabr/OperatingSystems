all: clean objeto fibofork fibothreads test

test: objeto
	gcc test.c -o test fibo.o

fibofork: objeto
	gcc fibofork.c -o fibofork fibo.o

fibothreads: objeto
	gcc fibothreads.c -o fibothreads fibo.o -pthread

fibonacci_threads:
	gcc -o fibonacci_threaded fibonacci_threaded_over_vector.c -pthread

fibonacci:
	gcc -o fibonacci fibonacci_over_vector.c

objeto:
	gcc -c fibo.c

clean:
	rm -rf fibo.o fibofork test fibothreads fibonacci_threaded fibonacci a.out
