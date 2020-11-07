CFLAGS = -Wall -std=c11 -pedantic -Werror=vla 
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu
SOURCE = tcv

default : tp2

tp2 : tp2.o malib.o malib.h vector.o vector.h $(SOURCE).o $(SOURCE).h 
	gcc $(CFLAGS) -o tp2 tp2.o malib.o vector.o $(SOURCE).o -lm

tp2.o : tp2.c malib.h vector.h
	gcc $(CFLAGS) -c  tp2.c

malib.o : malib.c malib.h vector.h $(SOURCE).h
	gcc $(CFLAGS) -c  malib.c 

vector.o : vector.c vector.h  $(SOURCE).h
	gcc $(CFLAGS) -c  vector.c

$(SOURCE).o : $(SOURCE).h
	make lib

lib :
	mkdir -p 'data' && wget -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip && unzip -o ./data/tp1.zip -d ./ && rm -rf data

tp1 : tp1.c $(SOURCE).o
	gcc $(CFLAGS) -I$(CUNIT_H) -L$(CUNIT_LIB)  -o tp1 tp1.c $(SOURCE).o -lcunit



test-tp1a : tp1
	./tp1 

test-tp1b : tp1
	./tp1 | ./liste.sh

test-tp2 : tp2
	./tp2

.PHONY: clean

clean :
	rm -f tp1  $(SOURCE).h *.o