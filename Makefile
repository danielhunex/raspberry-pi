all: output_file_name

output_file_name: matrix.o
	gcc -Wall -pedantic ledmatrix.c  -l bcm2835 -l m -o

matrix.o: ledmatrix.c
	gcc -c ledmatrix.c

clean:
	rm -rf *o output_file_name