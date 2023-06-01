make: main.c isNumber.c isNumber.h
	gcc -o isNumber main.c isNumber.c isNumber.h

clean: isNumber
	rm isNumber