CFLAGS = -Wall -std=c11 -pedantic -Werror=vla 
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu

default : tp2

tp2 : tp2.o malib.o malib.h vector.o vector.h tcv.o 
	gcc $(CFLAGS) -o tp2 tp2.o malib.o vector.o tcv.o -lm

tp2.o : tp2.c malib.h vector.h tcv.h
	gcc $(CFLAGS) -c  tp2.c

malib.o : malib.c malib.h vector.h tcv.h
	gcc $(CFLAGS) -c  malib.c 

vector.o : vector.c vector.h
	gcc $(CFLAGS) -c  vector.c

tcv.o : tcv.h

tcv.h : lib
	unzip -q -o ./data/tp1.zip -d ./

lib :
	mkdir -p data && wget -q -O ./data/tp1.zip https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip > /dev/null

tp1 : tp1.c tcv.o lib
	gcc $(CFLAGS) -I$(CUNIT_H) -L$(CUNIT_LIB)  -o tp1 tp1.c tcv.o -lcunit

test-tp1a : tp1
	./tp1 

test-tp1b : tp1
	./tp1 | ./liste.sh

test-tp2 : tp2
	./tp2

.PHONY: clean lib

clean :
	rm -f tp1 tcv.h *.o
	rm -rf data/
