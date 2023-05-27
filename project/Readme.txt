Jeu d'aventure
Bienvenue dans notre jeu d'aventure, où vous serez le héros de votre propre histoire ! Préparez-vous à affronter des défis palpitants et à prendre des décisions difficiles qui détermineront le cours de votre aventure. 
Soyez sur vos gardes, car certains choix pourraient être irréversibles et entraîner de lourdes conséquences. Préparez-vous à vivre une aventure inoubliable et bonne chance dans votre quête héroïque !

Lancement du jeu
Lancer le terminal, Tapez make copy_text_files pour charger les fichiers nécessaires pour le programme puis tapez make .
Lancer le fichier Game.c, compiler le, puis exécuter le .
Lorsque vous exécutez le programme, celui-ci appelle différentes fonctions pour faire progresser votre histoire. 
Tout d'abord, le programme vous demande si vous souhaitez continuer votre histoire à partir de votre dernière sauvegarde. 
Si tel est le cas, une fonction ouvrira et copiera les informations du joueur dans une nouvelle structure déclarée. 
Ensuite, grâce à la variable "stage", vous pourrez reprendre votre aventure là où vous vous étiez arrêté.

Si vous ne souhaitez pas continuer à partir de la sauvegarde, vous pouvez entamer une nouvelle partie. Une fonction sera appelée pour déclarer et initialiser la structure du joueur. 
Vous pourrez par exemple choisir une arme pour commencer votre aventure. En fonction de vos choix, différentes fonctions seront appelées pour poursuivre votre histoire, et bien entendu, ces choix conduiront à des fins différentes.
La variable "stage" est mise à jour en fonction des choix du joueur, ce qui permet de retrouver le joueur dans l'histoire. 
À chaque choix effectué par le joueur, une fonction met à jour le fichier du joueur, tandis qu'une autre fonction met à jour la sauvegarde du joueur.

A la fin du programme lancez make clean_text_files .
