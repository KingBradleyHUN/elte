#include <iostream>

using namespace std;

int main()
{
    const int MAXN = 32;
    // Be
    string mondat;
    // Ki
    int magasdb, melydb, vegyesdb;

    // Beolvasas
    getline(cin, mondat);

    string szavak[MAXN];
    int szoszam = 0;
    for(int i = 0; i < mondat.length(); ++i)
    {
        if (mondat[i] == ' ')
        {
            ++szoszam;
        } else {
            szavak[szoszam] += mondat[i];
        }
    }
    //cout << szoszam + 1 << endl;

    // Megsz�mol�s
    magasdb = 0;
    for (int i = 0; i <= szoszam; ++i)
    {
        // Eld�nt�s
        bool magase;
        int j = 0;
        while (j < szavak[i].length() &&
               szavak[i][j] != 'a' &&
               szavak[i][j] != 'o' &&
               szavak[i][j] != 'u')
        {
            ++j;
        }
        magase = (j == szavak[i].length());
        // Eld�nt�s v�ge

        if (magase)
        {
            ++magasdb;
        }
    }
    cout << "Magas hangrendu: " << magasdb << endl;

    // Megsz�mol�s
    melydb = 0;
    for (int i = 0; i <= szoszam; ++i)
    {
        // Eld�nt�s
        bool melye;
        int j = 0;
        while (j < szavak[i].length() &&
               szavak[i][j] != 'e' &&
               szavak[i][j] != 'i')
        {
            ++j;
        }
        melye = (j == szavak[i].length());
        // Eld�nt�s v�ge

        if (melye)
        {
            ++melydb;
        }
    }
    cout << "Mely hangrendu: " << melydb << endl;
    cout << "Vegyes hangrendu: " <<
            szoszam + 1 - magasdb - melydb << endl;

//    for (int i = 0; i <= szoszam; ++i)
//    {
//        cout << szavak[i] << endl;
//    }


    return 0;
}
