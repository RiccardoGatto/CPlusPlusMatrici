#include <iostream>
#include <random>
using namespace std;

int main()
{
    int righe = 9;
    int colonne = 9;
    int matrice[righe][colonne];
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = rand() % 10;
        }
    }
    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int trattini = colonne * 2 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < righe; i++)
    {
        cout << i << "|  ";

        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    cout << "______________________________________________________\n"
         << endl;
    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < righe; i++)
    {
        cout << i << "|  ";

        for (int j = 0; j < colonne; j++)
        {
            if (matrice[i][j] >= 5)
            {
                cout << matrice[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "______________________________________________________\n"
         << endl;
    int somma = 0;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            somma += matrice[i][j];
        }
    }
    cout << "La somma di tutti i numeri della matrice e' " << somma;
}