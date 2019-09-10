all: lib bin

lib: obj
	ar rc libdummynet.a dummynet.o

obj:
	gcc -c dummynet.c 

bin: lib
	gcc -L . main.c -o server -ldummynet
clean:
	rm -rf dummynet.o libdummynet.a server

  
