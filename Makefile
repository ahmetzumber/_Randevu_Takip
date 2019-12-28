all: kutuphanem run

kutuphanem: main.o kutuphanem.o
	gcc main.o kutuphanem.o -o kutuphanem

main.o: main.c
	gcc -c main.c

kutuphanem.o: kutuphanem.c kutuphanem.h
	gcc -c kutuphanem.c

clean:
	del *.o kutuphanem.exe

run:
	kutuphanem.exe