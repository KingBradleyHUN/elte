#include <iostream>

using namespace std;

int main()
{
    // Be
    int N;
    // Ki
    int P;
    // Beolvas�s
    cout << "Adj meg egy pozitiv egesz szamot: ";
    cin >> N;
    if (N < 0)
    {
        cout << "N nem lehet negativ" << endl;
        return(1);
    }
    // Feldolgoz�s

    P = 1;
    // ++i, i++, i = i + 1, i += 1
    for (int i = 1; i <= N; ++i)
    {
        //P = P * i;
        P *= i;
    }
    // Ki�r�s
    cout << N << "! = " << P << endl;

    return 0;
}
