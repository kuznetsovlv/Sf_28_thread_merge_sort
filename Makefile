#Makefile
objects = main.o merge_sort.o

.PHONY: all clean
all: sort

sort: ${objects}
	gcc -o sort ${objects} -lstdc++

main.o: merge_sort.h
merge_sort.o: merge_sort.h

clean:
	-rm -f sort *.o 2>/dev/null
