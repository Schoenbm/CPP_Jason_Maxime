Projet C++ 26/11/2020
Jason Gavalda
Maxime Schoenberger

Nous nous sommes arreter au millieu de la partie 3 du projet faute de temps pour résoudre les problèmes encontrés.

Tout les fichiers peuvent indépendamment être compilés, mais le make ne marche pas: Lorsque l'on essaye de générer
le fichier executable, g++ nous renvoie en erreur: "undefined reference to" et nous ne comprenons pas pourquoi.
Il y a pour nous deux possibilités: - les fichier .o ne sont pas bien linké, mais après avoir utilisé des makefiles
génériques nous ne pensons pas que ce soit possible.
				    - les fonctions désignés ne sont pas définies, mais comme chaque fichier compile
indépendamment ces fonctions sont forcémment correctement appelées et définies dans le fichier.
										
