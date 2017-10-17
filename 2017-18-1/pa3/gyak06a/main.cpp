#include <iostream>

using namespace std;

int main()
{
    const int honapok[12] =
        {31,28,31,30,31,30,31,31,30,31,30,31};
    // Be
    int e, h, n;
    // Ki
    int x;

    // Beolvas�s
    bool hiba;
    do
    {
        cout << "Add meg melyik ev: ";
        cin >> e;
        hiba = cin.fail();
        if (hiba)
        {
            cout << "Hibas bemenet, probald ujra" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    while(hiba);
    cin.clear();
    cin.ignore(1024, '\n');

    do
    {
        cout << "Add meg hanyadik honap: ";
        cin >> h;
        hiba = cin.fail() || (1 > h || h > 12);
        if (hiba)
        {
            cout << "Hibas bemenet, probald ujra" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    while(hiba);
    cin.clear();
    cin.ignore(1024, '\n');

    do
    {
        cout << "Add meg hanyadik nap: ";
        cin >> n;
        hiba = cin.fail() || (1 > n || n > 31) ||
               (
                    (honapok[h-1] < n) &&
                    !(e % 4 == 0 && h == 2 && n == 29)
               );
        if (hiba)
        {
            cout << "Hibas bemenet, probald ujra" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    while(hiba);
    cin.clear();
    cin.ignore(1024, '\n');

    // Feldolgoz�s
    // Eltelt h�napok
    x = 0;
    for (int i = 0; i < h - 1; ++i)
    {
        x += honapok[i];
    }
    // Napok hozz�ad�sa
    x += n;
    // Sz�k��vek kezel�se
    if (e % 4 == 0 && h > 2)
    {
        x += 1;
    }

    // Kimenet
    cout << "Az adott evben " << x << " nap telt el " <<
         e << "." << h << "." << n << "-ig." << endl;

    return 0;
}
