// ILIA - TP1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
using namespace std;

int mode;

int tirer(int &nn, int &nv) {
  int boule;
  if (nn == 0) nv--;
  else if (nv == 0) nn--;
  else {
    if (mode)
    {
      boule = rand() % 2;
    }
    else {
      cout << "Quelle boule tirer (1)? (0: noir, 1: vert) ";
      cin >> boule;
    }
    if (boule) nv--; else nn--;
    return boule;
  }
}

int main()
{
  srand(time(NULL));
  system("color 0a");
  int nn;
  int nv;

  cout << "Mode de jeu? (0: manuel, 1: auto) ";
  cin >> mode;

  do {
    cout << "Entrez le nombre de boules noires: ";
    cin >> nn;
    cout << "Entrez le nombre de boules vertes: ";
    cin >> nv;
    cout << "Total: " << (nn + nv) << " boules." << endl;
  } while (nn + nv > 20 || nn + nv < 1 || nn < 0 || nv < 0);

  int boule1;
  int boule2;
  while (nn + nv > 1) {
    cout << endl;
    boule1 = tirer(nn, nv);
    boule2 = tirer(nn, nv);
    if (boule1 == boule2) nn++; else nv++;
    cout << "Boule 1: " << (boule1 ? "Verte" : "Noire") << ", ";
    cout << "Boule 2: " << (boule2 ? "Verte" : "Noire") << ", ";
    cout << "Boule reintroduite: " << (boule1 == boule2 ? "Noire" : "Verte") << endl;
    cout << "Resultat: " << nn << " boule(s) noire(s) et " << nv << " boule(s) verte(s) \n";
  }
  cout << endl << endl << "Derniere boule: " << (nv ? "Verte" : "Noire") << endl;
}
