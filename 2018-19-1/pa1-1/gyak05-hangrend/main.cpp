#include <iostream>

using namespace std;
// � visszat�r�si t�pus (bool)
//   � azonos�t� (magashangrendu)
//                  � bemeneti v�ltoz�k (string szo)
bool magashangrendu(string szo) {
    int i = 0;
    while (i < szo.length() &&
           (szo[i] != 'a' && szo[i] != 'o' && szo[i] != 'u'))
    {
        i += 1;
    }
    return (i == szo.length());
}

bool melyhangrendu(string szo) {
    int i = 0;
    while (i < szo.length() &&
           (szo[i] != 'e' && szo[i] != 'i'))
    {
        i += 1;
    }
    return (i == szo.length());
}

int main()
{
    setlocale(LC_ALL, "hungarian");

    int N;
    cout << "H�ny darab sz� lesz? ";
    cin >> N;

    string szavak[N];
    for (int i = 0; i < N; ++i)
    {
        cout << "Add meg az " << (i + 1) << ". sz�t: ";
        cin >> szavak[i];
    }

    int dbmely = 0, dbmagas = 0, dbvegyes = 0;
    // Megsz�mol�s t�tel
    for (int i = 0; i < N; ++i)
    {
        if (magashangrendu(szavak[i]))
        {
            dbmagas += 1;
        }
        else if (melyhangrendu(szavak[i]))
        {
            dbmely += 1;
        }
        else
        {
            dbvegyes += 1;
        }
    }

    cout << "Magas hangrend� szavak sz�ma: " << dbmagas << endl;
    cout << "M�ly hangrend� szavak sz�ma: " << dbmely << endl;
    cout << "Vegyes hangrend� szavak sz�ma: " << dbvegyes << endl;

    return 0;
}
