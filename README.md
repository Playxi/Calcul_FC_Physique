🔌 Analyseur de Filtres Passifs RC (Passe-Bas/Passe-Haut)
📝 Description du Projet
Ce programme en C++ est un outil d'analyse et d'aide à la conception de filtres passifs RC (composés d'une Résistance et d'un Condensateur). Il permet de manipuler les relations fondamentales des filtres passe-bas et passe-haut du premier ordre, souvent utilisés en électronique.

✨ Fonctionnalités
Le programme offre deux modes d'utilisation principaux, guidant l'utilisateur selon les données connues :

Analyse de Composants (Mode 1) :

Si la fréquence de coupure (fc) est connue, l'outil propose des couples de valeurs (R et C) normalisées. Il utilise les valeurs standard de la série E12 pour la résistance, facilitant le choix de composants existants pour atteindre la fc souhaitée.

Analyse de Fréquence (Mode 2) :

Si les valeurs de la Résistance (R) et du Condensateur (C) sont connues, le programme calcule la fc théorique.

Il génère ensuite une table de réponse fréquentielle complète, affichant l'Amplification et le Gain en décibels (dB) pour une plage de fréquences pertinente autour de la fc calculée.

🛠️ Compilation
Ce projet est développé en C++ et s'appuie sur les librairies standard pour les opérations mathématiques, les entrées/sorties console et la gestion de l'encodage.

Prérequis
Un compilateur C++ (GCC, Clang, ou l'environnement Visual Studio).

⚙️ Détails du Code
Le programme principal (main()) invite l'utilisateur à choisir le type de filtre (Passe-Bas ou Passe-Haut) puis à sélectionner le mode d'analyse :

Choix de type de filtre : L'utilisateur sélectionne entre Passe-Bas (1) et Passe-Haut (2).

Mode 1 (fc connue) : Une boucle simple itère sur les valeurs normalisées de la série E12 pour la résistance, affichant la valeur de C correspondante pour la fc fournie.

Mode 2 (R et C connues) : Après le calcul de la fc, une boucle utilise une progression logarithmique des fréquences pour générer et imprimer la table de réponse fréquentielle (Amplification T et Gain G en dB).
