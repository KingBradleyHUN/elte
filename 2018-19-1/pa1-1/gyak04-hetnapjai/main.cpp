#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "hungarian");

    string kezdo_nap;
    int hanyadik_nap;

    cout << "Melyik napon kezd�d�tt az �v? ";
    cin >> kezdo_nap;
    cout << "Hanyadik napra vagy k�v�ncsi? ";
    cin >> hanyadik_nap;

    string napok[7] = { "h�tf�", "kedd", "szerda",
                        "cs�t�rt�k", "p�ntek",
                        "szombat", "vas�rnap" };
    int i = 0;
    while (napok[i] != kezdo_nap)
    {
        i = i + 1;
        // i++; ++i; i += 1;
    }
    int kezdo_nap_sorszam = i;
    int nap_sorszam = (hanyadik_nap + kezdo_nap_sorszam - 1) % 7;

    cout << "A " << hanyadik_nap << ". nap "
         << napok[nap_sorszam] << endl;
    return 0;
}
