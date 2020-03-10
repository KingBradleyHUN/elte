#include <iostream>

using namespace std;

// Szignat�ra
int str_to_int(string szam)
{
    int eredmeny = 0;
    bool negativ_e = szam[0] == '-';

    int kezdo = negativ_e ? 1 : 0;
    // Ternary operator (?:)
    // Felt�teles kifejez�s
    // Excel HA f�ggv�ny
    for (int i = kezdo; i < szam.length(); i += 1)
    {
        eredmeny *= 10;
        eredmeny += (int)(szam[i] - '0');
    }

    return negativ_e ? eredmeny * -1 : eredmeny;
}

int main()
{
    // Be
    string bemenet;
    // Ki
    int kimenet;

    // Beolvas�s
    cin >> bemenet;

    // Feldolgoz�s
    kimenet = str_to_int(bemenet);

    // Ki�r�s
    cout << kimenet << endl;

    return 0;
}
