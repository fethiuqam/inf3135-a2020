
FILENAME = tp1
CFLAGS = -Wall -std=c11 -pedantic -Werror=vla
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu
SOURCE = tcv

$(FILENAME) : $(FILENAME).c lib
	gcc $(CFLAGS) -I$(CUNIT_H) -L$(CUNIT_LIB)  -o $(FILENAME) $(FILENAME).c $(SOURCE).o -lcunit

lib :
	mkdir -p 'data' && wget -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip && unzip -o ./data/tp1.zip -d ./ && rm -rf data

test : $(FILENAME)
	./tp1

.PHONY: clean

clean :
	rm -f $(FILENAME) $(FILENAME).o $(SOURCE).o $(SOURCE).h
