#include <iostream>
using namespace std;

class Technicien {
protected:
    float salaire;
public:
    Technicien(float s) {
        salaire = s;
    }
    void afficherSalaire() {
        cout << "Salaire technicien : " << salaire << " DH" << endl;
    }
};

class Comptable {
protected:
    float salaire;
public:
    Comptable(float s) {
        salaire = s;
    }
    void afficherSalaire() {
        cout << "Salaire comptable : " << salaire << " DH" << endl;
    }
};

class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(float st, float sc) : Technicien(st), Comptable(sc) {
    }
    void afficherTousSalaires() {
        // on utilise :: pour eviter l'ambiguite
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e(5000, 7000);

    e.afficherTousSalaires();

    // e.afficherSalaire();  // erreur : appel ambigu
    e.Technicien::afficherSalaire();
    e.Comptable::afficherSalaire();

    return 0;
}