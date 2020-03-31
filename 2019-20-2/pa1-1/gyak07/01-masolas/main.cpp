#include <iostream>

using namespace std;

struct Idopont
{
    int ora;
    int perc;
};

int percek(const Idopont t)
{
    return t.ora * 60 + t.perc;
}

int main()
{
    setlocale(LC_ALL, "hungarian");

    // Be:
    int N;
    cout << "Add meg az id�pontok sz�m�t: ";
    cin >> N;

    Idopont X[N];

    // Ki:
    int Y[N];

    // Beolvas�s:
    for (int i = 0; i < N; i += 1)
    {
        cout << "Add meg a(z) " << (i+1) << ". id�pont �r�it: ";
        cin >> X[i].ora;
        cout << "Add meg a(z) " << (i+1) << ". id�pont perceit: ";
        cin >> X[i].perc;

        if (X[i].ora < 0 || X[i].ora > 23 || X[i].perc < 0 || X[i].perc > 59)
        {
            return 1;
        }
    }

    // Feldolgoz�s:
    for (int i = 0; i < N; i += 1)
    {
        Y[i] = percek(X[i]);
    }

    // Ki�r�s:
    for (int i = 0; i < N; i += 1)
    {
        cout << X[i].ora << ":" << X[i].perc << " -> " << Y[i] << " perc" << endl;
    }

    return 0;
}











