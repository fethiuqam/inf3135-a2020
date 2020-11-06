CFLAGS = -Wall -std=c11 -pedantic -Werror=vla
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu
SOURCE = tcv

tp1 : tp1.c lib
	gcc $(CFLAGS) -I$(CUNIT_H) -L$(CUNIT_LIB)  -o tp1 tp1.c $(SOURCE).o -lcunit

lib :
	mkdir -p 'data' && wget -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip && unzip -o ./data/tp1.zip -d ./ && rm -rf data

test-tp1a : tp1
	./tp1 

test-tp1b : tp1
	./tp1 | ./liste.sh

.PHONY: clean

clean :
	rm -f tp1  $(SOURCE).h *.o