#include <iostream>

using namespace std;

int main()
{
    // Bemenet
    string szoveg;

    // Beolvas�s
    cout << "Add meg a szoveget: " << endl;
    getline(cin, szoveg);

    string maxszo = "";
    string szo = "";
    for (int i = 0; i < szoveg.size(); i += 1)
    {
        // Sorozatsz�m�t�s
        if (szoveg[i] != ' ')
        {
            szo += szoveg[i];
        }
        // Maximumkiv�laszt�s
        else
        {
            if (szo.size() > maxszo.size())
            {
                maxszo = szo;
            }
            szo = "";
        }
    }

    if (szo.size() > maxszo.size())
    {
        maxszo = szo;
    }

    // Ki�r�s
    cout << "A leghosszabb szo: " << maxszo << endl;

    return 0;
}
