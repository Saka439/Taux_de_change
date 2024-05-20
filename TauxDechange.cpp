#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, double> TauxDeChange;

// Fonction pour convertir un montant d'une devise à une autre
double convertir(double montant, const string& devise_source, const string& devise_destination, const TauxDeChange& taux) {
    // Vérification de la prise en charge ou non des devises
    if (taux.find(devise_source) == taux.end() || taux.find(devise_destination) == taux.end()) {
        cout << "Devise non prise en charge." << endl;
        return -1; 
    }

    
    double taux_conversion = taux.at(devise_destination) / taux.at(devise_source);
    return montant * taux_conversion;
}

int main() {
    // Définition des taux de change pré-définis
    TauxDeChange taux = {
        {"EUR", 1.0},
        {"USD", 1.22},
        {"CAD", 1.48}, 
        {"XOF", 655.957} // 1 EUR = 655.957 XOF (le 20-05-2024)
    };

    
    double montant;
    string devise_source, devise_destination;
    cout << "Entrez le montant : ";
    cin >> montant;
    cout << "Entrez la devise source (par exemple, CAD) : ";
    cin >> devise_source;
    cout << "Entrez la devise de destination (par exemple, USD,XOF,EUR) : ";
    cin >> devise_destination;

    // Conversion du montant
    double montant_converti = convertir(montant, devise_source, devise_destination, taux);

    // Affichage du résultat
    if (montant_converti != -1) {
        cout << "Le montant converti est : " << montant_converti << " " << devise_destination << endl;
    }

    return 0;
}
