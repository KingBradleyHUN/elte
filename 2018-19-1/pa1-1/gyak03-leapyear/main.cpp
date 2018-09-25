#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "hungarian"); // Magyar �kezetes karakterek enged�lyez�se
    int evszam;
    bool szokoev;

    cout << "Adj meg egy �vszamot: ";
    cin >> evszam;

    // Hossz� megold�s

    if (evszam % 400 == 0)
    {
        szokoev = true;
    }
    else if (evszam % 100 == 0)
    {
        szokoev = false;
    }
    else if (evszam % 4 == 0)
    {
        szokoev = true;
    }
    else
    {
        szokoev = false;
    }

    if (szokoev)
    {
        cout << "sz�k��v" << endl;
    }
    else
    {
        cout << "nem sz�k��v" << endl;
    }

    // R�vid megold�s

    if (evszam % 4 == 0 && evszam % 100 != 0 || evszam % 400 == 0)
    {
        cout << "sz�k��v" << endl;
    }
    else
    {
        cout << "nem sz�k��v" << endl;
    }

    return 0;
}
