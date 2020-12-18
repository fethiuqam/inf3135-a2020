# Travail pratique 3

![test-c](https://github.com/fethiuqam/inf3135-a2020/workflows/test-c/badge.svg)

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

   Le programme accepte 4 options qui modifient son affichage sur la sortie standard tel que :

   - option -i information invalide
      Lorsqu'un code de transaction n'est reconnu;
      Lorsque le timestamp est inférieur au temps précédent;
   - option -d information détaillée
      Le nombre de transactions pour chacun des types de transactions;
   - option -s information sommaire
      Le nombre total de transactions valides;
      Le nombre total de transactions reçues;
   - option -t mode tranquille
      Le mode tranquille n'affiche pas transaction en sortie;

   l'execution du programme peut se faire avec l'une des commandes suivantes : 
   
   ~~~~
   # sans option
   $ ./tp3
   $ cat file.dat | ./tp3
   $ head -n 100 file.txt| tail -n 25 | ./tp3

   # avec option(s) de la ligne de commande (-d détaillé, -s sommaire, -t tranquille -i invalide)
   $ ./tp3 -s -d -i
   $ ./tp3 -s
   $ ./tp3 -t
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

   - Un fichier `tp3.c` qui contient la fonction main.
   - Les fichiers `malib.c` et `malib.h` qui contiennet les fonctions et les structures utilisées dans le fichier `tp3.c`
   - Les fichiers `outil3.c` et `outil3.h` qui contiennet les fonctions et les structures utilisées par `malib.c` , `malib.h` et le fichier `tp3.c`
   - Un fichier `README.md` contenant la description et les informations importante du projet
   - Un fichier `Makefile` responsable de la compilation et du téléchargement des sources, et supportant les appels `make`, `make clean`, `make lib`, `make default`, `make tp3`.
   - Un fichier `cp.txt` contenant le code permanent de l'auteur du projet;

   ## Références

   - [CUnit Home](http://cunit.sourceforge.net/index.html)
   - [CUnit Framework](http://cunit.sourceforge.net/doxdocs/group__Framework.html)
   - le fichier [vector.c](https://github.com/guyfrancoeur/INF3135_A2020/blob/master/code/vector.c) exemple pedagogique MIT license GF 2019, vu en cours dans le repertoire code.

   ## Statut

   Le projet est complété ne contenant aucun bug pour l'instant.
   
   
   
   ## Autoévaluation
   
   Selon le barème, mon travail vaut 20.
