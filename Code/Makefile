all: exe

exe: main.o topSortDFS.o topSortInternal.o
	  gcc main.o topSortDFS.o topSortInternal.o -o exe

main.o: main.c
	  gcc -c main.c

topSortDFS.o: topSortDFS.c
	  gcc -c topSortDFS.c

topSortInternal.o: topSortInternal.c
	  gcc -c topSortInternal.c

clean:
	  rm *.o exe
	
