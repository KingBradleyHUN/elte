#include <iostream>

using namespace std;

int main()
{
    /**
     * Kreditindex kisz�m�t�sa
     */

    // Be
    int kreditosszeg;
    // Ki
    double kreditindex;

    // Beolvas�s
    cout << "Add meg a kreditosszeget: ";
    cin >> kreditosszeg;
    // Feldolgoz�s
    kreditindex = (double)kreditosszeg / 30;
    //kreditindex = kreditosszeg / 30.0;
    // Ki�r�s
    cout << "A kreditindex: " << kreditindex << endl;

    return 0;
}
