#include <iostream>

using namespace std;

// Feladat: hat�rozzuk meg n! �rt�k�t
int main()
{
    // Bemenet
    int n;
    // Kimenet
    double eredmeny;

    // Beolvas�s
    cout << "Adj meg egy pozitiv egesz szamot: ";
    cin >> n;

    // El�felt�tel
    if (n < 1)
    {
        cout << "Ez nem pozitiv egesz" << endl;
        return 1;
    }

    // Feldolgoz�s
    eredmeny = 1;
    for (int i = 2; i <= n; i += 1)
    {
        eredmeny *= i;
    }

    // Ki�r�s
    cout << "n! = " << eredmeny;

    return 0;
}
