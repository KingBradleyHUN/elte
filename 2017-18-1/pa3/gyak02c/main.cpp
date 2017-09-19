#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Be
    double a, b, c;
    // Ki
    double x1, x2;

    // Beolvas�s
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    if (a == 0)
    {
        cout << "Az `a` erteke nem lehet 0" << endl;
        return 1;
    }
    else if ((b * b - 4 * a * c) < 0)
    {
        cout << "A diszkriminans nem lehet negativ" << endl;
        return 2;
    }
    // Feldolgoz�s
    double d = sqrt(b * b - 4 * a * c);
    x1 = (-b + d) / (2 * a);
    x2 = (-b - d) / (2 * a);
    // Ki�r�s
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    return 0;
}
