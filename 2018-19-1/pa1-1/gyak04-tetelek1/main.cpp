#include <iostream>

using namespace std;

int main()
{
    int N; // Elemsz�m
    cin >> N;
    int T[N];
    // Beolvas�s
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i];
    }
    // Sz�mol�s

    // 1. �sszegz�s
    int osszeg = 0;
    for (int i = 0; i < N; ++i)
    {
        osszeg += T[i];
    }
    cout << osszeg << endl;

    // 2. megsz�mol�s
    int db = 0;
    for (int i = 0; i < N; ++i)
    {
        if (T[i] < 0)
        {
            db += 1;
        }
    }

    // 3. maximumkiv�laszt�s
    int minimum = T[0];
    for (int i = 1; i < N; ++i)
    {
        if (T[i] < minimum)
        {
            minimum = T[i];
        }
    }
    cout << minimum << endl;

    // 4. eld�nt�s
    int i = 0;
    while (i < N && T[i] >= 0)
    {
        i += 1;
    }
    bool van_e = i < N;
    cout << van_e << endl;

    // 6. keres�s
    int j = 0;
    while (j < N && T[j] != 5)
    {
        j += 1;
    }
    bool van_e_2 = j < N;
    int hanyadik = j;
    if (van_e_2)
    {
        cout << hanyadik << endl;
    }
    else
    {
        cout << "nincs" << endl;
    }

    return 0;
}
