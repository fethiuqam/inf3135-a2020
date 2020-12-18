test1 : ./tp3 < tests/test1.txt
version #: 0.1.1008
10 0 1005 3
15 12000 1005 2000000
14 17599 1929292 3.4
14 19012 2929298 0.1
15 19511 1005 1929292 1929298 2000000 2929298
21 37.3 -10.2 152
22 1 1 1
23 2 0 0
test2 : ./tp3 -i < tests/test1.txt
version #: 0.1.1008
10 0 1005 3
15 12000 1005 2000000
14 17599 1929292 3.4
14 19012 2929298 0.1
15 19511 1005 1929292 1929298 2000000 2929298
21 37.3 -10.2 152
22 1 1 1
23 2 0 0
information invalide
  trx non reconnue : 0
  trx avec ts non sequentiel : 0
test3 : ./tp3 -d < tests/test1.txt
version #: 0.1.1008
10 0 1005 3
15 12000 1005 2000000
14 17599 1929292 3.4
14 19012 2929298 0.1
15 19511 1005 1929292 1929298 2000000 2929298
21 37.3 -10.2 152
22 1 1 1
23 2 0 0
information detaillee
  trx  1 : 9
  trx  2 : 4
  trx  3 : 4
  trx  4 : 2
  trx  5 : 2
  le dernier ts lu : 19511
test4 : ./tp3 -s < tests/test1.txt
version #: 0.1.1008
10 0 1005 3
15 12000 1005 2000000
14 17599 1929292 3.4
14 19012 2929298 0.1
15 19511 1005 1929292 1929298 2000000 2929298
21 37.3 -10.2 152
22 1 1 1
23 2 0 0
information sommaire
  nbr trx valides : 11
  nbr trx (total) : 22
test5 : ./tp3 -t < tests/test1.txt
version #: 0.1.1008
test6 : ./tp3 -d -s -i -t < tests/test2.txt
version #: 0.1.1008
information invalide
  trx non reconnue : 0
  trx avec ts non sequentiel : 1
information detaillee
  trx  1 : 11
  trx  2 : 4
  trx  3 : 4
  trx  4 : 2
  trx  5 : 2
  le dernier ts lu : 19511
information sommaire
  nbr trx valides : 12
  nbr trx (total) : 25
test7 : ./tp3 < tests/test2.txt
version #: 0.1.1008
10 0 1005 3
15 12000 1005 2000000
14 17599 1929292 3.4
14 19012 2929298 0.1
15 19511 1005 1929292 1929298 2000000 2929298
21 37.2 -10.2 152
22 1 1 1
23 2 0 0
