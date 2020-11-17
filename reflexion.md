## Processus de réflexion et démarche 

Ce programme est une simulation d’un module beacon qui traite des transactions à partir de l’entrée standard et répond aussi par des transactions sur la sortie standard.

De ce fait j’ai commencé à implémenter une struct nommée Beacon qui contient les informations nécessaires au traitement des transactions tel que l’id, timestamp courant, puissance, deux tableauX valeurs et comptValeurs pour gérer les températures  humaines,  les températures  ambiantes et les pulsations,  un tableau dynamique pour les id des pastilles de premier niveau, un tableau pour comptabiliser les erreurs d’invalidité, un tableau de compteurs d’erreur et un tableau des erreurs cumulées.

Pour implémenter le tableau dynamique de la struct Beacon, j’ai utiliser le fichier vector.c vue au cours, que j’ai modifié le type du data int en size_t pour les besoins du tp2 et ajouté la fonction conatainV.

La méthode main commence par initialiser l’objet beacon avec l’allocation de mémoire pour le tableau dynamique, puis affiche la version, lit l’entrée standard en boucle jusqu’à la fin des lignes, puis affiche les transactions de fin du programme et termine par la libération de la mémoire.
 
chaque ligne lue est traitée par la fonction traiterLigne qui utilise sscanf pour vérifier le format de la ligne puis vérifie le timestamp lu en le comparant avec le timestamp du beacon, ensuite elle vérifie le no de transaction pour appeler la fonction adéquate par un switch case.

Pour valider les valeurs lues en transactions , j’ai du vérifier la version par la fonction getVersion pour utiliser la bonne fonction de validation.