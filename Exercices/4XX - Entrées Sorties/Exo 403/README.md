## Exercice 403

Cet exercice continue sur le thème de l'exercice 402. Il s'agit de jouer et se familiariser avec la table ASCII.

### Principe

Avec la table ASCII dans le README de l'exercice 402, on voit qu'il y a deux fois l'alphabet. Une fois en minuscule et une fois en majuscule. Il suffit donc, pour passer d'une minuscule à une majuscule, de calculer la différence entre une lettre minuscule et sa majuscule et d'ajouter ce résultat à la lettre minuscule entrée par l'utilisateur.

### Nouveautés

J'ai implémenté dans cet exercice la première instance de blindage. Le blindage de données consiste à vérifier que des données sont bien du type ou de la forme à laquelle le programme s'attend à les voir.
Ici, on s'attend à ce que l'utilisateur entre une lettre minuscule. Si ce n'est pas le cas, on l'informe que son entrée n'est pas valide, et on ne poursuit pas l'opération. Il n'y a pas de boucle, puisqu'elles n'ont pas encore été vues en cours.

### Critiques de l'exercice

La demande de ne pas utiliser l'espacement en dur de 32 entre une lettre minuscule et sa majuscule est un peu étrange. Le principe de l'exercice est de jouer avec la table ASCII, donc pourquoi ne pas laisser étudier cette table et expérimenter ? C'est un peu comme si on demandait de sommer un nombre par lui-même au lieu de le multiplier.