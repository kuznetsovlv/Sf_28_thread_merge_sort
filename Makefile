#Makefile
objects = main.o

.PHONY: all clean
all: sort

sort: ${objects}
	gcc -o sort ${objects} -lstdc++

main.o:

clean:
	-rm -f sort *.o 2>/dev/null
