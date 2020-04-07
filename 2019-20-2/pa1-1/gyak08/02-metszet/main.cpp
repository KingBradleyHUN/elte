#include <iostream>

using namespace std;

void tomb_ki(const int tomb[], const int db)
{
    for (int i = 0; i < db; i += 1)
    {
        cout << tomb[i] + 1 << ((i < db - 1) ? " " : "");
    }
}

int main()
{
    // Be:
    int N, M;
    cin >> N >> M;
    string elso_zh[N];
    string masodik_zh[M];
    // Ki:
    int Db;
    int volt_mindketton[N];

    // Beolvas�s:
    for (int i = 0; i < N; i += 1)
    {
        cin >> elso_zh[i];
    }
    for (int i = 0; i < M; i += 1)
    {
        cin >> masodik_zh[i];
    }

    // Feldolgoz�s
    Db = 0;
    for (int i = 0; i < N; i += 1)
    {
        int j = 0;
        while (j < M && elso_zh[i] != masodik_zh[j])
        {
            j += 1;
        }
        if (j < M)
        {
            volt_mindketton[Db] = i;
            Db += 1;
        }
    }

    // Ki�r�s:
    tomb_ki(volt_mindketton, Db);

    return 0;
}
