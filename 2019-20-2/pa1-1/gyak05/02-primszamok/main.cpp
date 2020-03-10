#include <iostream>

using namespace std;

bool prim_e(int x)
{
    int i = 2;
    while (i <= (x / 2) && x % i != 0)
    {
        i += 1;
    }
    return i > (x / 2);
}

int main()
{
    // Be:
    int a, b;
    // Ki:
    int db;

    // Beolvas�s
    cin >> a;
    cin >> b;

    // Feldolgoz�s (megsz�mol�s)
    db = 0;
    for (int i = a; i <= b; i += 1)
    {
        if (prim_e(i))
        {
            db += 1;
        }
    }

    // Ki�r�s
    cout << db << endl;

    return 0;
}
