#include <iostream>
#include <random>
using namespace std;
const int righe = 10;
const int colonne = 10;

void riempiMatCasuali(int mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = rand() % 10;
        }
    }
}

void stampaTrattini(int colonne)
{
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
}

void stampaMat(int mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        cout << i << "|  ";

        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void stampaMagg5(int mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        cout << i << "|  ";

        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] >= 5)
            {
                cout << mat[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int sommaMat(int mat[][colonne], int rig, int col)
{
    int somma = 0;
    for (int i = 0; i < rig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            somma += mat[i][j];
        }
    }
    return somma;
}

void diagonaleNove(int mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j or i + j == col-1)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = 1;
            }
        }
    }
}

int main()
{
    int matrice[righe][colonne];
    riempiMatCasuali(matrice, righe, colonne);
    stampaTrattini(colonne);
    stampaMat(matrice, righe, colonne);
    cout << "______________________________________________________\n\n";
    stampaTrattini(colonne);
    stampaMagg5(matrice, righe, colonne);
    cout << "______________________________________________________\n\n";
    cout << "La somma di tutti i numeri della matrice e' " << sommaMat(matrice, righe, colonne) << endl;
    diagonaleNove(matrice, righe, colonne);
    cout << "______________________________________________________\n\n";
    stampaTrattini(colonne);
    stampaMat(matrice, righe, colonne);
    cout << "______________________________________________________\n\n";
    riempiMatCasuali(matrice, righe, colonne);
    stampaTrattini(colonne);
    stampaMat(matrice, righe, colonne);
}