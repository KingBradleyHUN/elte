#include <iostream>

using namespace std;

int main()
{

    /**
     * Szignum f�ggv�ny
     */

    // Be
    double x;
    // Ki
    double sgn;

    // Beolvas�s
    cout << "x = ";
    cin >> x;
    // Feldolgoz�s
    if (x < 0)
    {
        sgn = -1;
    }
    else if (x == 0)
    {
        sgn = 0;
    }
    else
    {
        sgn = 1;
    }
    // Ki�r�s
    cout << "sgn(x) = " << sgn << endl;

    return 0;
}
