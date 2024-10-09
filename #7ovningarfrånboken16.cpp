#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const int maxantal=100;
    const float grans=5000., pro1=0.1, pro2=0.15;
    float tab [maxantal], belopp, arvode;
    int i, nr, avsluta = -1;

    for (i=0; i<maxantal; i++)
        tab[i] = 0;

    cout << "Ange försäljningsnummer och belopp (avsluta med -1):" << endl;
    while (cin >> nr && nr != -1 && cin >> belopp)
    {
        if (nr < 1 || nr > maxantal || belopp < 0)
            cout << "Felaktiga indata" << endl;
        else
            tab[nr-1] += belopp;
        if (nr - 1 > avsluta) 
                avsluta = nr - 1;
    }
    cout << endl
         << "Nummer     Belopp      Arvode" << endl
         << "======     ======      ======" << endl;
         
    for (i=0; i<maxantal; i++)
    {
        if (tab[i] > 0)
        {
            if (tab[i] <= grans)
                arvode = pro1 * tab[i];
            else   
                arvode = pro1*grans + pro2* (tab[i] - grans);
            cout << setw(4) << (i+1) << setprecision(0) << fixed
                 << setw(13) << tab[i] << setw(10) << arvode << endl;
                
        }
    }
    return 0;
}
