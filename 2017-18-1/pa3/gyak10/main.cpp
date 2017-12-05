/// N�v:
/// Neptun-k�d:
/// e-mail:
///
/// Feladat:
///   A keret program seg�ts�g�vel a tanult 6 egyszer� bels� rendez�s hat�konys�g�t
///   vizsg�ljuk. V�grehajt�si id�, t�mbelemre vonatkoz� hasonl�t�s- �s mozgat�s-sz�m
///   elemsz�mt�l f�gg�s�re vagyunk kiv�ncsiak.
///   A program rendez� elj�r�sainak l�nyegi r�sze hi�nyzanak, ezt kell p�tolni.
///   �gyeljen arra, hogy a hSzam �s az mSzam v�ltoz�kat megfelel�en n�velje, amikor
///   a rendez�s sor�n egy hasonl�t�st, ill. egy mozgat�st hajt v�gre.

#include <iostream>
#include <windows.h>  //a srand f�ggv�nyhez, a HANDLE t�pushoz, a system-hez (pause �s a cls DOS-parancsokhoz)
#include <time.h>     //a time �s clock f�ggv�nyekhez
#include <iomanip>    ///a setw-hez
using namespace std;

const int maxN=8001;//a sorozat maxim�lis hossza
const int kiN=120;//a megjelen�tend� (r�sz)sorozat hossza
int s[maxN],r[maxN];//seg�d �s rendezend� elemek t�mbje
int elemSzam;//t�nyleges elemsz�m
int kezdet,veg,elteltIdo;//fut�si id� kezdete, v�ge, hossza
int hSzam, mSzam;//hasonl�t�sok sz�ma, mozgat�sok sz�m

//beolvassa a min..max k�z�tti eg�sz sz�mot (max<min => max=v�gtelen)
void be_int(string kerdes, int &n, int min, int max, string uzenet);
//felt�lt�sm�d beolvas�sa:
int feltoltesMod();
//felt�lt� elj�r�sok:
void feltoltVeletlennel();
void feltoltNovekedve();
void feltoltCsokkenve();
void feltoltMajdnemRendezve();
//hat�konys�gm�r�shez:
void oraIndul();
void oraAll();
//r-et rendez� elj�r�sok:
void egyszeruCseres();
void minimumKivalsztasos();
void buborek();
void javitottBuborek();
void beilleszteses();
void javitottBeilleszteses();
//cout<=r[1..min(kiN,elemSzam)]
void tombKiiras(string cim);
void kiertekeles(string cim);
//r<=s:
void masol();
//billenty�-lenyom�sra v�rakozik:
void billreVar();
//kurzor-poz�cion�l�s a konzol-ablakban:
void curPos(int s, int o);
//k�perny�t�rl�s:
void ujLap();

int main()
{
    srand(time(NULL));//v�letlensz�m-gener�tor inicializ�l�sa

    //a rendezend� t�mb felt�lt�se:
    be_int("Elemszam:",elemSzam,11,maxN,"Nem jo elemszam!");
    switch (feltoltesMod())
    {
      case 0:
        feltoltNovekedve(); break;
      case 1:
        feltoltCsokkenve(); break;
      case 2:
        feltoltMajdnemRendezve(); break;
      case 3:
        feltoltVeletlennel(); break;
    }
    //a rendez�sek:
    //egyszeruCseres();
    //minimumKivalsztasos();
    //buborek();
    //javitottBuborek();
    //beilleszteses();
    javitottBeilleszteses();

    return 0;
}

//beolvassa a min..max k�z�tti eg�sz sz�mot (max<min => max=v�gtelen)
void be_int(string kerdes, int &n, int min, int max, string uzenet)
{
    bool hiba;
    string tmp;

    do
    {
      if (max>=min)
      {
        curPos(0,0); cout<<setfill(' ')<<setw(80)<<' '; curPos(0,0);
        cout << kerdes << " (" << min << ".." << max << "):"; cin >> n;
        hiba=cin.fail() || cin.peek()!='\n' || n<min || n>max;
      }
        else
      {
        curPos(0,0); cout<<setfill(' ')<<setw(80)<<' '; curPos(0,0);
        cout << kerdes << " (" << min << "..):"; cin >> n;
        hiba=cin.fail() || cin.peek()!='\n' || n<min;
      }
      if (hiba)
      {

        cout<<uzenet+" Mehetunk?\n";
        cin.clear(); getline(cin,tmp,'\n'); //puffer�r�t�s
        getline(cin,tmp,'\n'); //az utzenetre v�lasz beolvas�sa
        curPos(1,0); cout<<setfill(' ')<<setw(80)<<' ';
        curPos(2,0); cout<<setfill(' ')<<setw(80)<<' ';
      }
    }
    while(hiba);
}

//felt�lt�sm�d beolvas�sa:
int feltoltesMod()
{
    int melyik;
    bool hiba; char c;
    string tmp;

    ujLap();
    cout << "Valasszon az alabbi feltoltesmodok kozul:" << endl;
    cout << "0: novekedoen" << endl;
    cout << "1: csokkenve" << endl;
    cout << "2: majdnem (novekedoen) rendezve" << endl;
    cout << "3: veletlenszeruen" << endl;
    cout << "Melyik (0..3): ";
    do
    {
        curPos(5,15); cout << "                             "; curPos(5,15);
        cin >> melyik;
        hiba = cin.fail() || (0>melyik || melyik>3);
        if(hiba)
        {
            cout<<" Hibas adat! Mehetunk?\n";
            cin.clear(); getline(cin,tmp,'\n'); //puffer�r�t�s
            getline(cin,tmp,'\n'); //a "Mehet�nkre?" v�lasz beolvas�sa
            curPos(6,0); cout<<setfill(' ')<<setw(80)<<' ';
            curPos(7,0); cout<<setfill(' ')<<setw(80)<<' ';
        }
    }
    while (hiba);
    return melyik;
}

void feltoltNovekedve()
{
    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]+rand()%3;
        r[i]=s[i];
    }
    tombKiiras("Feltolt novekedve");
}

void feltoltCsokkenve()
{
    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]-rand()%3;
        r[i]=s[i];
    }
    tombKiiras("Feltolt csokkenve");
}

void feltoltMajdnemRendezve()
{
    int j,k,sv;

    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]+rand()%3;
        r[i]=s[i];
    }
    for(int i=1;i<=elemSzam/10;++i)
    {
        j=rand()%elemSzam+1;
        do
        {
            k=rand()%elemSzam+1;
        }
        while (j==k);
        sv=s[j]; s[j]=s[k]; s[k]=sv;
        r[j]=r[k]; r[k]=sv;
    }
    tombKiiras("Feltolt majdnem rendezve");
}

void feltoltVeletlennel()
{
    for(int i=1;i<=elemSzam;++i)
    {
        s[i]=rand()%elemSzam+1;
        r[i]=s[i];
    }
    tombKiiras("Feltolt veletlennel");
}

void oraIndul()
{
    kezdet=clock();
    hSzam=0; mSzam=0;
}

void oraAll()
{
    veg=clock();
    elteltIdo=veg-kezdet;
}

void tombKiiras(string cim)
{
    ujLap();
    cout << cim << endl << endl;
    int meddig; //ameddig list�zza az elemeket... az ellen�rz�s kedv��rt
    if (elemSzam<kiN)
    {
        meddig=elemSzam;
    }
    else
    {
        meddig=kiN;
    }
    for(int i=1;i<=meddig;++i)
    {
        cout << /*setw(4) << i << ':' << */setw(5) << r[i];
    }
    cout << endl;
    billreVar();
}

void kiertekeles(string cim)
{
    tombKiiras(cim);
    cout << "\nEltelt ido:" << elteltIdo;
    cout << " | Hasonlitasok szama:" << hSzam << " | Mozgatasok szama:" << mSzam << endl;
    billreVar();
}

void csere(int a, int b)
{
    ++mSzam;
    int t = r[a];
    r[a] = r[b];
    r[b] = t;
}

void egyszeruCseres()
{
    oraIndul();

/*Ide j�n az r rendez�se */
    for (int i = 1; i <= elemSzam - 1; ++i)
    {
        for (int j = i + 1; j <= elemSzam; ++j)
        {
            ++hSzam;
            if (r[i] > r[j])
            {
                csere(i, j);
            }
        }
    }

    oraAll();
    kiertekeles("Egyszeru cseres");
    masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}

void minimumKivalsztasos()
{
    oraIndul();

/*Ide j�n az r rendez�se */
    for (int i = 1; i < elemSzam; ++i) {
        int m = i;
        for (int j = m + 1; j <= elemSzam; ++j)
        {
            ++hSzam;
            if (r[j] < r[m])
            {
                m = j;
            }
        }
        csere(i, m);
    }

     oraAll();
     kiertekeles("Minimum-kivalasztasos");
     masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}

void buborek()
{
    oraIndul();

/*Ide j�n az r rendez�se */
    for (int i = elemSzam; i > 1; --i)
    {
        for (int j = 1; j <= i - 1; ++j) // j: bubor�k els� elem�nek az indexe
        {
            ++hSzam;
            if (r[j] > r[j+1])
            {
                csere(j, j+1);
            }
        }
    }

    oraAll();
    kiertekeles("Buborekos");
    masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}

void javitottBuborek()
{
    oraIndul();

/*Ide j�n az r rendez�se */
    int i = elemSzam;
    while (i > 1)
    {
        int cs = 0;
        for (int j = 1; j <= i - 1; ++j) // j: bubor�k els� elem�nek az indexe
        {
            ++hSzam;
            if (r[j] > r[j+1])
            {
                csere(j, j+1);
                cs = j;
            }
        }
        i = cs;
    }

    oraAll();
    kiertekeles("Javitott buborekos");
    masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}

void beilleszteses()
{
    oraIndul();

/*Ide j�n az r rendez�se */
    for (int i = 2; i <= elemSzam; ++i)
    {
        int j = i-1;
        while (j >= 1 && r[j] > r[j+1])
        {
            ++hSzam;
            csere(j, j+1);
            --j;
        }
        ++hSzam;
    }

    oraAll();
    kiertekeles("Beilleszteses");
    masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}



int szetvalogat(int a, int f)
{
    int nagyobb = f -1;
    int kisebb = a;
    int i = kisebb;
    while (nagyobb > kisebb)
    {
        if (r[i] > f) {
            csere(i, nagyobb);
            //tombKiiras("");
            --nagyobb;
        } else {
            ++kisebb;
            ++i;
        }
    }
    csere(f, nagyobb);
    return nagyobb;
}

void gyorsRendezes(int a, int f)
{
    if (a < f)
    {
        int p = szetvalogat(a, f);
        gyorsRendezes(a, p - 1);
        gyorsRendezes(p + 1, f);
    }
}

void javitottBeilleszteses()
{
    oraIndul();

    gyorsRendezes(1, elemSzam);

    oraAll();
    kiertekeles("Javitott beilleszteses");
    masol(); /* Az eredeti �rt�k vissza�ll�t�sa */
}

//r<=s:
void masol()
{
    for (int i=1;i<=elemSzam;++i)
    {
        r[i]=s[i];
    }
}

//billenty�-lenyom�sra v�rakozik
void billreVar()
{
    system("pause");//windows eset�ben!
}

//kurzor-poz�cion�l�s a konzol-ablakban:
void curPos(int s, int o)
{
    COORD hova;
    hova.X=o; hova.Y=s;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),hova);
}

//k�perny�t�rl�s:
void ujLap()
{
    system("cls"); //k�perny�t�rl�s
}
