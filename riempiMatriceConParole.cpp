#include <iostream>
#include <random>
#include <string>
#include <time.h>
using namespace std;
const int righe = 10;
const int colonne = 10;

void putE(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    // cout << "Inserisco a E" << endl;
    if (x <= (col - word.length()))
    {
        bool check = true;
        for (int i = x; i < x + word.length(); i++)
        {
            if (mat[y][i] == word.at(i - x) || mat[y][i] == '-')
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check)

        {
            for (int i = x; i < x + word.length(); i++)
            {
                mat[y][i] = word.at(i - x);
            }
        }
    }
}

void putSE(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a SE" << endl;
    if ((x <= (col - word.length())) and (y <= (rig - word.length())))
    {
        int i = x;
        int j = y;
        bool check = true;
        while (i < x + word.length())
        {
            if ((mat[j][i] == word.at(i - x)) or (mat[j][i] == '-'))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            i++;
            j++;
        }
        if (check)
        {
            i = x;
            j = y;
            while (i < x + word.length())
            {
                mat[j][i] = word.at(i - x);
                i++;
                j++;
            }
        }
    }
}

void putS(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a S" << endl;
    if (y <= col - word.length())
    {
        bool check;

        int j = y;
        while (j < y + word.length())
        {
            if ((mat[j][x] == word.at(j - y)) or (mat[j][x] == '-'))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            j++;
        }
        if (check)
        {
            j = y;
            while (j < y + word.length())
            {
                mat[j][x] = word.at(j - y);
                j++;
            }
        }
    }
}

void putSW(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a SW" << endl;
}

void putW(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a W" << endl;
}

void putNW(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a NW" << endl;
}

void putN(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a N" << endl;
}

void putNE(string word, int x, int y, char mat[][colonne], int rig, int col)
{
    cout << "Inserisco a NE" << endl;
}

void stampaIndici(char colonne)
{
    cout << "      ";
    for (int i = 0; i < colonne; i++)
    {
        if (i < 10)
        {
            cout << i << "  ";
        }
        else
        {
            cout << i << " ";
        }
    }
    cout << endl;
    int trattini = colonne * 3 + 6;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void stampaMat(char mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        if (i < 10)
        {
            cout << i << " |  ";
            for (int j = 0; j < col; j++)
            {
                cout << " " << mat[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << i << "|  ";
            for (int j = 0; j < col; j++)
            {
                cout << " " << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void inizializzaConTrattino(char mat[][colonne], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = '-';
        }
    }
}

void inserisciParola(string word, char mat[][colonne], int rig, int col)
{
    srand(time(NULL));
    //int coordX = rand() % colonne;
    //int coordY = rand() % righe;
    int coordX;
    int coordY;
    cin >> coordX;
    cin >> coordY;
    cout << coordX << "   " << coordY << endl;
    // int dir = rand() % 8;
    int dir = 2;
    switch (dir)
    {
    case 0:
    {
        putE(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 1:
    {
        putSE(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 2:
    {
        putS(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 3:
    {
        putSW(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 4:
    {
        putW(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 5:
    {
        putNW(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 6:
    {
        putN(word, coordX, coordY, mat, rig, col);
    }
    break;
    case 7:
    {
        putNE(word, coordX, coordY, mat, rig, col);
    }
    break;
    }
}

int main()
{
    char matrice[righe][colonne];
    inizializzaConTrattino(matrice, righe, colonne);
    stampaIndici(colonne);
    stampaMat(matrice, righe, colonne);
    string parola;
    while (true)
    {
        cout << "Parola da inserire: ";
        cin >> parola;
        inserisciParola(parola, matrice, righe, colonne);
        stampaIndici(colonne);
        stampaMat(matrice, righe, colonne);
    }
}