
FILENAME = tp1
CFLAGS = -Wall -std=c11 -pedantic -Werror=vla
CUNIT_H = /usr/include/CUnit
CUNIT_LIB = /usr/lib/x86_64-linux-gnu
TEST = tcv

$(FILENAME) : $(FILENAME).c
	gcc $(CFLAGS) -I$(CUNIT_H) -L$(CUNIT_LIB)  -o $(FILENAME) $(FILENAME).c $(TEST).o -lcunit

lib :
	mkdir -p 'data' && wget -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip && unzip ./data/tp1.zip -d ./ && rm -rf data


.PHONY: clean

clean :
	rm -f $(FILENAME) $(FILENAME).o