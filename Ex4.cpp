#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
protected:
    int id;
    string login;
public:
    Utilisateur(int i, string l) {
        id = i;
        login = l;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;
public:
    Administrateur(int i, string l, string d) : Utilisateur(i, l) {
        droitsAcces = d;
    }
    void gererSysteme() {
        cout << login << " gere le systeme (droits : " << droitsAcces << ")" << endl;
    }
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;
public:
    Moderateur(int i, string l, int n) : Utilisateur(i, l) {
        niveauModeration = n;
    }
    void modererContenu() {
        cout << login << " modere le contenu (niveau : " << niveauModeration << ")" << endl;
    }
};

class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int i, string l, string d, int n)
        : Utilisateur(i, l), Administrateur(i, l, d), Moderateur(i, l, n) {
    }
    void afficher() {
        cout << "ID : " << id << endl;
        cout << "Login : " << login << endl;
        cout << "Droits : " << droitsAcces << endl;
        cout << "Niveau de moderation : " << niveauModeration << endl;
    }
};

int main() {
    SuperUtilisateur* su = NULL;
    int choix;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Gerer le systeme" << endl;
        cout << "3. Moderer le contenu" << endl;
        cout << "4. Afficher les informations" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        if (choix == 1) {
            int id, niveau;
            string login, droits;
            cout << "ID : ";
            cin >> id;
            cout << "Login : ";
            cin >> login;
            cout << "Droits d'acces : ";
            cin >> droits;
            cout << "Niveau de moderation : ";
            cin >> niveau;

            if (su != NULL) {
                delete su; // on supprime l'ancien
            }
            su = new SuperUtilisateur(id, login, droits, niveau);
            cout << "SuperUtilisateur cree !" << endl;
        }
        else if (choix == 2 || choix == 3 || choix == 4) {
            if (su == NULL) {
                cout << "Il faut d'abord creer un SuperUtilisateur." << endl;
            }
            else if (choix == 2) {
                su->gererSysteme();
            }
            else if (choix == 3) {
                su->modererContenu();
            }
            else {
                su->afficher();
            }
        }
        else if (choix != 0) {
            cout << "Choix invalide." << endl;
        }
    } while (choix != 0);

    if (su != NULL) {
        delete su;
    }
    return 0;
}
