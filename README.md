# Travail pratique 1

   ## Description
   
   Ce programme a été réalisé dans le cadre du cours Construction et maintenance de logiciels INF3135 , session Automne 2020 à l'université de l'UQAM

   Le programme consiste en une simulation de traitement de transactions reçues par un module beacon de plusieurs capteurs et d'autres modules voisins, et réagissant par l'émission de transactions à son tour.

   ## Auteur

   FETHI BEY ABI AYAD  ( ABIF10108204 )

   ## Fonctionnement

   Le programme doit lire à partir de l'entrée standard stdin une ou plusieurs lignes.
   Chaque ligne consiste en une transaction que le programme doit traiter.
   la transaction en entrée contient :
   - un timestamp informant le temps de la transaction.
   - un numero à deux chiffres de 00 à 05 qui détermine le type de transaction.
   - une succession de valeurs qui diffère d'un type de transaction à un autre.

   l'execution du programme peut se faire avec l'une des commandes suivantes : 
   
   ~~~~
      $ ./tp2

      $ cat file.dat | ./tp2

      $ ./script.sh | ./tp2

      $ head -n 100 file.txt | ./tp2
      ...
   ~~~~
   
   Après le traitement des transactions par le programme, ce dernier peut émettre d'autres transactions sur la sortie standard stdout qui contiennent :
   - un numero à deux chiffre (10, 14, 15, 21, 22, 23) qui détermine le type de transaction.
   - une succession de valeurs qui diffère d'un type de transaction à un autre. 

   Un exemple d'une suite de transactions d'entrée : 

   ~~~~
    0 00 1000 3
    2 01 38.2
    2001 01 ERREUR
    10020 02 -10.2
    11112 03 157
    17599 04 -85 1929292
    19012 04 -35 1929298
    19511 05 1929298 100123 100987
   ~~~~

   la sortie correspondante à cette entrée est  : 

   ~~~~
    version #: 0.1.10005
    10 0 1000 3
    14 17599 1929292 3.4
    14 19012 1929298 0.1
    15 19511 1000 1929292 1929298
    21 38.2 -10.2 157
    22 0 0 0
    23 0 0 0
   ~~~~

   ## Contenu du projet

   - Un fichier `tp2.c` qui contient la fonction main.
   - Les fichiers `malib.c` et `malib.h` qui contiennet toutes les fonctions et les structures utilisées dans le fichier `tp2.c`
   - Un fichier `README.md` contenant la description et les informations importante du projet
   - Un fichier `reflexion.md` qui démontre le processus de réflexion durant le travail; 
   - Un fichier `Makefile` responsable de la compilation et du téléchargement des sources, et supportant les appels `make`, `make clean`, `make lib`, `make default`, `make tp1`, `make tp2`, `make test-tp1a`, `make test-tp1b`, `make test-tp2`;
   - Un fichier `cp.txt` contenant le code permanent de l'auteur du projet;
   - Un fichier `liste.sh` contenant le script qui filtre les fonctions qui réussissent les tests;
   - Un fichier `tp1.c` contenant le code source du tp1;
   
   ## Processus de réflexion

   - [Description de la reflexion](reflexion.md) au cours de la construction du tp2. 

   ## Références

   - [CUnit Home](http://cunit.sourceforge.net/index.html)
   - [CUnit Framework](http://cunit.sourceforge.net/doxdocs/group__Framework.html)
   - le fichier [vector.c](https://github.com/guyfrancoeur/INF3135_A2020/blob/master/code/vector.c) exemple pedagogique MIT license GF 2019, vu en cours dans le repertoire code.

   ## Statut

   Le projet est complété ne contenant aucun bug pour l'instant.
   
   
   
   ## Autoévaluation
   
   Selon le barème, mon travail vaut 20.
