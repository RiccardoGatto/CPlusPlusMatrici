#include <iostream>
#include <random>
#include <string>
#include <time.h>
using namespace std;
const int RIGHE = 30;
const int COLONNE = 30;

bool putE(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{

    // cout << "Inserisco a E" << endl;
    if (x > (col - word.length()))
    {
        return false;
    }
    else
    {
        bool check;
        for (int i = x; i < x + word.length(); i++)
        {
            if (mat[y][i] == word.at(i - x) || mat[y][i] == ' ')
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
        return check;
    }
}

bool putSE(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a SE" << endl;
    if ((x > (col - word.length())) and (x > (rig - word.length())))
    {
        return false;
    }
    else
    {
        int i = x;
        int j = y;
        bool check = true;
        while (i < x + word.length())
        {
            if ((mat[j][i] == word.at(i - x)) or (mat[j][i] == ' '))
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
        return check;
    }
}

bool putS(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a S" << endl;
    if (y > col - word.length())
    {
        return false;
    }
    {
        bool check;
        int j = y;
        while (j < y + word.length())
        {
            if ((mat[j][x] == word.at(j - y)) or (mat[j][x] == ' '))
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
        return check;
    }
}

bool putSW(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a SW" << endl;
    if (x < word.length() - 1 or (y > (col - word.length())))
    {
        // cout << "non consentito"<< endl;
        return false;
    }
    else
    {
        int i = x;
        int j = y;
        int index = 0;
        bool check = true;
        while (index < word.length())
        {
            if ((mat[j][i] == word.at(index)) or (mat[j][i] == ' '))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            i--;
            j++;
            index++;
        }
        if (check)
        {
            i = x;
            j = y;
            index = 0;
            while (index < word.length())
            {
                mat[j][i] = word.at(index);
                i--;
                j++;
                // cout << word.at(index) << "con indice " << index << endl;
                index++;
            }
        }
        return check;
    }
}

bool putW(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a W" << endl;
    bool check = true;
    if (x < word.length() - 1)
    {
        return false;
    }
    else
    {
        int i = x;
        int index = 0;
        while (index < word.length())
        {
            if ((mat[y][i] == word.at(index)) or (mat[y][i] == ' '))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            i--;
            index++;
        }
        if (check)
        {
            i = x;
            index = 0;
            while (index < word.length())
            {
                mat[y][i] = word.at(index);
                i--;
                index++;
            }
        }
        return check;
    }
}

bool putNW(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a NW" << endl;
    if ((x < word.length() - 1) or (y < word.length() - 1))
    {
        return false;
    }
    else
    {
        bool check = true;
        int i = x;
        int j = y;
        int index = 0;
        while (index < word.length())
        {
            if ((mat[j][i] == word.at(index)) or (mat[j][i] == ' '))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            j--;
            i--;
            index++;
        }

        if (check)
        {
            i = x;
            j = y;
            index = 0;
            while (index < word.length())
            {
                mat[j][i] = word.at(index);
                i--;
                j--;
                index++;
            }
        }
        return check;
    }
}

bool putN(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a N" << endl;
    bool check = true;
    if (y < word.length() - 1)
    {
        return false;
    }
    else
    {
        int j = y;
        int index = 0;
        while (index < word.length())
        {
            if ((mat[j][x] == word.at(index)) or (mat[j][x] == ' '))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            j--;
            index++;
        }
        if (check)
        {
            j = y;
            index = 0;
            while (index < word.length())
            {
                mat[j][x] = word.at(index);
                j--;
                index++;
            }
        }
        return check;
    }
}

bool putNE(string word, int x, int y, char mat[][COLONNE], int rig, int col)
{
    // cout << "Inserisco a NE" << endl;
    if ((x > (col - word.length())) or (y < word.length() - 1))
    {
        return false;
    }
    else
    {
        bool check = true;
        int i = x;
        int j = y;
        int index = 0;
        while (index < word.length())
        {
            if ((mat[j][i] == word.at(index)) or (mat[j][i] == ' '))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
            j--;
            i++;
            index++;
        }

        if (check)
        {
            i = x;
            j = y;
            index = 0;
            while (index < word.length())
            {
                mat[j][i] = word.at(index);
                i++;
                j--;
                index++;
            }
        }
        return check;
    }
}

void stampaIndici(int COLONNE)
{
    cout << "      ";
    for (int i = 0; i < COLONNE; i++)
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
    int trattini = COLONNE * 3 + 6;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void stampaMat(char mat[][COLONNE], int rig, int col)
{
    stampaIndici(COLONNE);
    for (int i = 0; i < rig; i++)
    {
        if (i < 10)
        {
            cout << i << " |  ";
        }
        else
        {
            cout << i << "|  ";
        }
        for (int j = 0; j < col; j++)
        {
            cout << " " << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void inizializzaConTrattino(char mat[][COLONNE], int rig, int col)
{
    for (int i = 0; i < rig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = ' ';
        }
    }
}

void inserisciParola(string word, char mat[][COLONNE], int rig, int col)
{
    srand(time(NULL));
    int coordX = rand() % COLONNE;
    int coordY = rand() % RIGHE;
    /*int coordX;
    int coordY;
    cin >> coordX;
    cin >> coordY;
    cout << coordX << "   " << coordY << endl;*/
    int dir = rand() % 8;
    // int dir = 7;
    switch (dir)
    {
    case 0:
    {
        while (!putE(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 1:
    {
        while (!putSE(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 2:
    {
        while (!putS(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 3:
    {
        while (!putSW(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 4:
    {
        while (!putW(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 5:
    {
        while (!putNW(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 6:
    {
        while (!putN(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    case 7:
    {
        while (!putNE(word, coordX, coordY, mat, rig, col))
        {
            coordX = rand() % COLONNE;
            coordY = rand() % RIGHE;
            dir = rand() % 8;
        }
    }
    break;
    }
}

int main()
{
    char matrice[RIGHE][COLONNE];
    inizializzaConTrattino(matrice, RIGHE, COLONNE);
    stampaMat(matrice, RIGHE, COLONNE);
    string parola;
    while (true)
    {
        cout << "Parola da inserire: ";
        cin >> parola;
        inserisciParola(parola, matrice, RIGHE, COLONNE);
        stampaMat(matrice, RIGHE, COLONNE);
    }
}