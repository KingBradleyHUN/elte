// A) Feladat: Adott egy eg�sz sz�m 1-7 k�z�tt.
//    A h�tnek melyik napj�t jel�li az adott sz�m?

#include <iostream>

using namespace std;

int main()
{
    const string hetnapjai[7] = {
        "hetfo", "kedd", "szerda", "csutortok",
        "pentek", "szombat", "vasarnap"
    };
    int nap;

    cout << "Add meg a napnak a sorszamat: ";
    cin >> nap;

    cout << hetnapjai[nap - 1] << endl;

    return 0;
}
