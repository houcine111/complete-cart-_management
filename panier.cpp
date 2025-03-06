#include <iostream>
#include <vector>
#include <iomanip>  // For std::fixed and std::setprecision

using namespace std;

struct Article {
    int ref;
    float prix;
    int qte;
};

class Panier {
private:
    vector<Article> articles;
     vector<Article> panierclient;

public:
    void menu();
    void administrateur();
    void client();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void ajouterpanier();
    void supprimerpanier();
    void afficherpanier();
};

void Panier::menu() {
    int choix;
    string email;
    string password;

    cout << "\n\t\t\t\t_____Menu Principal_____\n";
    cout << "\t\t\t\t1) Administrateur\n";
    cout << "\t\t\t\t2) Client\n";
    cout << "\t\t\t\t3) Exit\n";
    cout << "\t\t\t\tSelectionner un choix: ";
    cin >> choix;

    switch (choix) {
    case 1:
        cout << "\n\t\t\t\tIdentifiez-vous\n";
        cout << "\t\t\t\tEmail: ";
        cin >> email;
        cout << "\t\t\t\tPassword: ";
        cin >> password;
        if (email == "admin@admin.com" && password == "admin") {
            administrateur();
        } else {
            cout << "Erreur d'authentification\n";
        }
        break;
    case 2:
        client();
        break;
    case 3:
        exit(0);
    default:
        cout << "Selectionnez une option valide.\n";
        break;
    }
}

void Panier::administrateur() {
    int choix;

    cout << "\n\t\t\t\t_____Menu Administrateur_____\n";
    cout << "\t\t\t\t1) Ajouter un article\n";
    cout << "\t\t\t\t2) Modifier un article\n";
    cout << "\t\t\t\t3) Supprimer un article\n";
    cout << "\t\t\t\t4) voir la liste des articles\n";
    cout << "\t\t\t\t5) Revenir\n";
    cout << "\t\t\t\tSelectionner un choix: ";
    cin >> choix;

    switch (choix) {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        list();
    case 5:
        menu();
        break;
    default:
        cout << "Option non valide.\n";
        break;
    }
}
void Panier::ajouterpanier()
{

int ref;
bool found;
cout << "Entrez la reference de l'article pour ajouter au panier: ";
    cin >> ref;
    for(auto &articlecl:articles){
    if(articlecl.ref==ref){
        panierclient.push_back(articlecl);
        found=true;
        break;
    }}
if(!found){
    cout<<"la ref est invalide";
}


}
void Panier::supprimerpanier()
{
    int ref;
cout << "Entrez la reference de l'article pour le supprimer ";
    cin >> ref;
    for(auto it=panierclient.begin();it!=panierclient.end();it++){
    if(it->ref==ref){
        panierclient.erase(it);
        cout<<"article a ete supprimer avec succes";

    }}
}
void Panier::afficherpanier()
bool msg;
{
    if(!panierclient.empty()){
        for(auto &client:panierclient){
           cout << "Ref: " << client.ref << ", Prix: " << client.prix << ", Quantite: " << client.qte << endl;
            msg=true;
        }

    }

   if(!msg){ cout<<"le panier est vide";}
}
void Panier::client() {
    int choix;

    cout << "\n\t\t\t\t_____Menu Client_____\n";
    cout << "\t\t\t\t1) voir les articles\n";
    cout << "\t\t\t\t2) ajouter les article\n";
    cout << "\t\t\t\t3) supprimer article du panier\n";
    cout << "\t\t\t\t4) voir le panier\n";
    cout << "\t\t\t\t5) Revenir\n";
    cout << "\t\t\t\tSelectionner un choix: ";
    cin >> choix;

    switch (choix) {
    case 1:
       list();
        break;
    case 2:
        ajouterpanier();
        break;
    case 3:
       supprimerpanier();
       break;
    case 4:
        afficherpanier();
        break;
    case 5 :
        menu();
    default:
        cout << "Option non valide.\n";
        break;
    }
}

void Panier::add() {
    Article newArticle;

    cout << "Entrez la reference de l'article: ";
    cin >> newArticle.ref;
    cout << "Entrez le prix de l'article: ";
    cin >> newArticle.prix;
    cout << "Entrez la quantite de l'article: ";
    cin >> newArticle.qte;

    articles.push_back(newArticle);
    cout << "Article ajoute avec succes!\n";
}

void Panier::edit() {

    int ref;
    cout << "Entrez la reference de l'article a modifier: ";
    cin >> ref;

    for (auto &article : articles) {
        if (article.ref == ref) {
            cout << "Entrez le nouveau prix: ";
            cin >> article.prix;
            cout << "Entrez la nouvelle quantite: ";
            cin >> article.qte;
            cout << "Article modifie.\n";
            return;
        }
    }
    cout << "Article non trouve.\n";
}

void Panier::rem() {
    int ref;
    cout << "Entrez la reference de l'article a supprimer: ";
    cin >> ref;

for (auto it=articles.begin();it!=articles.end();){
    if(it->ref==ref){
       articles.erase(it);
       cout<<"article a ete supprime";
    }
    else cout<<"articles not found";
}

}

void Panier::list() {
    if (articles.empty()) {
        cout << "Aucun article disponible.\n";

    }

    for (const auto& article : articles) {
        cout << "Ref: " << article.ref << ", Prix: " << article.prix << ", Quantite: " << article.qte << endl;
    }
}

void Panier::receipt() {
    if (articles.empty()) {
        cout << "Le panier est vide.\n";

    }

    float total = 0.0;
    float itemTotal;

    cout << "\n\t\t\t\t_____Recu du Panier_____\n";
    cout << "Ref\tPrix\tQuantite\tTotal\n";
    cout << "-------------------------------------------------\n";}


int main() {
    Panier panier;

    while (true) {
        panier.menu();
    }

    return 0;
}
