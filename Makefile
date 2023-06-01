make: main.c validNumber.c validNumber.h
	gcc -o validNumber main.c validNumber.c validNumber.h

clean: validNumber
	rm validNumber