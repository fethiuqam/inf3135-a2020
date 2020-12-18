~~~

wget -q -P data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip > /dev/null || wget -q -P data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip > /dev/null \
	|| wget -q -P data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip > /dev/null
unzip -q -o ./data/*.zip -d ./  
gcc -Wall -std=c11 -pedantic -Werror=vla  -c  tp3.c
gcc -Wall -std=c11 -pedantic -Werror=vla  -c  malib.c 
gcc -Wall -std=c11 -pedantic -Werror=vla  -c  outil3.c 
gcc -Wall -std=c11 -pedantic -Werror=vla  -o tp3 tp3.o malib.o outil3.o tcv.o -lm
