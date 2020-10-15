# Travail pratique 1

   ## Description
   
   Ce programme a été réalisé dans le cadre du cours Construction et maintenance de logiciels INF3135 , session Automne 2020 à l'université de l'UQAM

   Le rôle du programme est de tester et afficher les noms des fonctions qui échouent et qui passent, pour affirmer sans doute qu’elles sont les fonctions utilisables (fiables).
   
   Le programme teste à l'aide de la librairie cUnit toutes variantes des fonctions suivantes :
   
   - Valider la température humaine : validerTH_X
   - Valider la température ambiante : validerTA_X
   - Valider la pulsation : validerPulsation_X
   - Valider le Signal : validerSignal_X

   ## Auteur

   FETHI BEY ABI AYAD  ( ABIF10108204 )

   ## Fonctionnement

   Pour exécuter le programme, il suffit de lancer la commande à la racine du projet :
   
   ~~~~
       make test
   ~~~~
   
   Ce qui va telecharger les fichiers sources `tvc.h` et `tvc.o` qui sont nécessaires pour la compilation qui va suivre le téléchargement, puis l'exécution du programme tp1 qui va donner le résultat :
   ~~~~
           
     CUnit - A unit testing framework for C - Version 2.1-3
     http://cunit.sourceforge.net/


Suite: max_test_suite
  Test: test_validerTH_1 ...passed
  Test: test_validerTH_2 ...passed
  Test: test_validerTH_3 ...FAILED
    1. tp1.c:68  - CU_ASSERT_EQUAL(validerTH_3(170),true)
    2. tp1.c:69  - CU_ASSERT_EQUAL(validerTH_3(400),true)
  Test: test_validerTA_1 ...FAILED
    1. tp1.c:79  - CU_ASSERT_EQUAL(validerTH_1(-400),true)
    2. tp1.c:85  - CU_ASSERT_EQUAL(validerTH_1(0),true)
    3. tp1.c:86  - CU_ASSERT_EQUAL(validerTH_1(-10),true)
  Test: test_validerTA_2 ...FAILED
    1. tp1.c:90  - CU_ASSERT_EQUAL(validerTH_2(-128),true)
    2. tp1.c:91  - CU_ASSERT_EQUAL(validerTH_2(127),true)
    3. tp1.c:96  - CU_ASSERT_EQUAL(validerTH_2(0),true)
  Test: test_validerTA_3 ...FAILED
    1. tp1.c:101  - CU_ASSERT_EQUAL(validerTH_3(-400),true)
    2. tp1.c:102  - CU_ASSERT_EQUAL(validerTH_3(400),true)
    3. tp1.c:107  - CU_ASSERT_EQUAL(validerTH_3(0),true)
    4. tp1.c:108  - CU_ASSERT_EQUAL(validerTH_3(-10),true)
  Test: test_validerPulsation_1 ...FAILED
    1. tp1.c:112  - CU_ASSERT_EQUAL(validerPulsation_1(50),true)
    2. tp1.c:113  - CU_ASSERT_EQUAL(validerPulsation_1(200),true)
  Test: test_validerPulsation_2 ...FAILED
    1. tp1.c:122  - CU_ASSERT_EQUAL(validerPulsation_2(50),true)
    2. tp1.c:123  - CU_ASSERT_EQUAL(validerPulsation_2(127),true)
  Test: test_validerPulsation_3 ...passed
  Test: test_validerSignal_1 ...FAILED
    1. tp1.c:142  - CU_ASSERT_EQUAL(validerSignal_1(-85),true)
    2. tp1.c:143  - CU_ASSERT_EQUAL(validerSignal_1(-25),true)
  Test: test_validerSignal_2 ...passed
  Test: test_validerSignal_3 ...FAILED
    1. tp1.c:162  - CU_ASSERT_EQUAL(validerSignal_3(-85),true)
    2. tp1.c:163  - CU_ASSERT_EQUAL(validerSignal_3(-25),true)
    3. tp1.c:164  - CU_ASSERT_EQUAL(validerSignal_3(-45),true)

Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      1      1    n/a      0        0
               tests     12     12      4      8        0
             asserts     79     79     58     21      n/a

Elapsed time =    0.000 seconds

   ~~~~

Pour filtrer les résultats des tests en affichant que les fonctions qui réussissent, on peut lancer la commande après compilation :

   ~~~~
       ./tp1 | ./liste.sh
   ~~~~

Ce qui va afficher comme résultat : 

   ~~~~
       test_validerTH_1
       test_validerTH_2
       test_validerPulsation_3
       test_validerSignal_2

   ~~~~

   ## Contenu du projet

   - Un fichier `tp1.c` contenant le code source des fonctions de test ainsi que la fonction main;
   - Un fichier `Makefile` responsable de la compilation et du téléchargement des sources, et supportant les appels `make`, `make clean`, `make lib` et `make test`;
   - Un fichier `cp.txt` contenant le code permanent de l'auteur du projet;
   - Un fichier `liste.sh` contenant le script qui filtre les fonctions qui réussissent les tests;
   - Un fichier `README.md` contenant la description et les informations importante du projet
   
   ## Références

   - [CUnit Home](http://cunit.sourceforge.net/index.html)
   - [CUnit Framework](http://cunit.sourceforge.net/doxdocs/group__Framework.html)


   ## Statut

   Le projet est complété ne contenant aucun bug pour l'instant.
   
   ## Réponse
   
   #### Question 1
   Pourquoi les valeurs décimales sont nocives pour l'ordinateur ?
   
   ##### Réponse
   tous les nombres décimaux (c'est-à-dire écrits en base 10) ne sont pas forcément représentables de façon finie en binaire, et certains sont donc arrondis !
   Par exemple 0,1 en base 10 s'écrit en binaire 0b0,00011001100… avec une infinité de 0011 ce qu peut mener à des résultatas de calcul inexacts.
   
   #### Question 2
   Pourquoi faut-il respecter les limites des types de données ?
   
   ##### Réponse
   Il faut respecter les limites des types de données car si on affecte une valeur qui dépasse la limite du type, le compilateur récupère les octets nécessaires pour ce type et assigne cette nouvelle valeur.
   Par exemple, si on assigne la valeur 129 à un type char qui a une limite de 127, le compilateur lui affecte la valeur -127 et ne provoquera pas d'erreur, ce qui fausse le résultat du test.   
   
   ## Autoévaluation
   
   Selon le barème, mon travail vaut 10.
