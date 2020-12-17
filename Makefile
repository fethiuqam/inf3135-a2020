CFLAGS = -Wall -std=c11 -pedantic -Werror=vla 
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu
SOURCE = https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/

default : tp3

tp3 : tp3.o malib.o malib.h outil3.o outil3.h tcv.o 
	gcc $(CFLAGS) -o $@ $< malib.o outil3.o tcv.o -lm

tp3.o : tp3.c malib.h outil3.h tcv.h
	gcc $(CFLAGS) -c  $<

malib.o : malib.c malib.h outil3.h tcv.h
	gcc $(CFLAGS) -c  $< 

outil3.o : outil3.c outil3.h
	gcc $(CFLAGS) -c  $< 

tcv.o : tcv.h

tcv.h : lib
	unzip -q -o ./data/*.zip -d ./  

lib :
	wget -q -P data $(SOURCE)tp3.zip > /dev/null || wget -q -P data $(SOURCE)tp2.zip > /dev/null \
		|| wget -q -P data $(SOURCE)tp1.zip > /dev/null
	
test-tp3 : tp3
	./tp3

.PHONY: clean lib

clean :
	rm -f tp3 tcv.h *.o
	rm -rf data/
