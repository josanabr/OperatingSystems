math:
	gcc -o math math.c -lm 
animals: libanimalvoz.a
	gcc -L. -o animals animals.c -lanimalvoz
libanimalvoz.a: animalvoz.o
	ar -cvq libanimalvoz.a animalvoz.o
animalvoz.o:
	gcc -c animalvoz.c
clean:
	rm -f math animals a.out lib*.a *.o 
