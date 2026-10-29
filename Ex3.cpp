#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string marque;
    string modele;
public:
    Vehicule(string ma, string mo) {
        marque = ma;
        modele = mo;
    }
};

// heritage virtuel pour eviter le probleme du diamant
class Thermique : virtual public Vehicule {
protected:
    float consommation; // L/100km
public:
    Thermique(string ma, string mo, float c) : Vehicule(ma, mo) {
        consommation = c;
    }
};

class Electrique : virtual public Vehicule {
protected:
    int autonomie; // km
public:
    Electrique(string ma, string mo, int a) : Vehicule(ma, mo) {
        autonomie = a;
    }
};

class Hybride : public Thermique, public Electrique {
public:
    // Hybride doit appeler directement le constructeur de Vehicule
    Hybride(string ma, string mo, float c, int a)
        : Vehicule(ma, mo), Thermique(ma, mo, c), Electrique(ma, mo, a) {
    }
    void afficherCaracteristiques() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation : " << consommation << " L/100km" << endl;
        cout << "Autonomie batterie : " << autonomie << " km" << endl;
    }
};

int main() {
    Hybride h("Toyota", "Prius", 4.5, 60);
    h.afficherCaracteristiques();
    return 0;
}
