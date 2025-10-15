#include <Windows.h>
#include <iostream>
#include <cmath> 
#include <stdio.h>

#define PI 3.141592653589793

using namespace std;

double calcul_fc(double R, double C) {
	return 1.0 / (2.0 * PI * R * C);
}

int main() {
	SetConsoleOutputCP(65001);
	double R, C, fc;
	int type_filtre, choix;

	cout << "=== FILTRE PASSIF RC ===" << endl;
	cout << "1 - Passe-Bas" << endl;
	cout << "2 - Passe-Haut" << endl;
	cout << "Choisir le type de filtre : ";
	cin >> type_filtre;

	if (type_filtre != 1 && type_filtre != 2) {
		cout << "Type de filtre invalide." << endl;
		return 1;
	}

	cout << "La fréquence de coupure est-elle connue ? (1 = Oui / 2 = Non) : ";
	cin >> choix;

	if (choix == 1) {
		cout << "Entrez la fréquence de coupure fc (Hz) : ";
		cin >> fc;

		// série E12 pour les résistances
		double E12[12] = { 1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2 };
		cout << "\nValeurs possibles de composants pour fc ≈ " << fc << " Hz :" << endl;
		for (double e : E12) {
			R = e * 1000; // 1kΩ, 1.2kΩ, etc.
			C = 1.0 / (2.0 * PI * R * fc);
			cout << "R = " << R << " Ω\tC ≈ " << C * 1e6 << " µF" << endl;
		}
	}
	else if (choix == 2) {
		cout << "Entrez les valeurs de R (Ω) et C (F) : ";
		cin >> R >> C;
		fc = calcul_fc(R, C);
		cout << "\nFréquence de coupure calculée : fc = " << fc << " Hz\n";

		cout << "\n=== Réponse fréquentielle ===" << endl;
		cout << "Fréquence (Hz)\tAmplification\tGain (dB)" << endl;

		for (int i = 0; i < 15; i++) {
			double f = (fc / 10.0) * pow(10.0, i / 7.0); // progression logarithmique
			double w = 2.0 * PI * f;
			double T = 0.0;

			if (type_filtre == 1)  // Passe-bas
				T = 1.0 / sqrt(1.0 + pow(w * R * C, 2));
			else                   // Passe-haut
				T = (w * R * C) / sqrt(1.0 + pow(w * R * C, 2));

			double G = 20.0 * log10(T);
			printf("%10.2f\t%10.4f\t%10.2f\n", f, T, G);
		}
	}
	else {
		cout << "Choix invalide." << endl;
	}
	return 0;
}


/*
	- Définir Type de filtre (passe haut / bas)
	- Est-ce que la fréquence de coupure est connu (si oui donne les valeurs probables de : résistance + condensateur / si non demande les valeurs des resistances et du conensateur)

	================================================================

	- Si OUI:
	- Propose des résistances (EX: serie E12) et un condensateur 

	================================================================

	- Si NON : 
	- Calcul de la fréquence de coupure (utiliser la focntion "double" en demandant la valeur de R & C)
	- Créer un tableau de 15 valeurs avec :
		- Les Fréquences (entre fc/10 et 10fc comprenant fc)
		- Amplification (T ou A = Vs/Ve)
		- Gain ( 20log(Amplification) )

*/
