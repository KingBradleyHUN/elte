#include <iostream>

using namespace std;

int main()
{
    // Statikus t�mb
    const string napok[] = {"monday",
                            "tuesday",
                            "wednesday",
                            "thursday",
                            "friday",
                            "saturday",
                            "sunday"};
    // Be
    string nev;
    cin >> nev;
    // Feldolgoz�s
    int i = 0;
    while (napok[i] != nev)
    {
        ++i;
    }
    cout << i + 1 << endl;

    return 0;
}
