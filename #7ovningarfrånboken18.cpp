#include <iostream>
using namespace std;

void bubbleSort(int tal[], int antalTal) 
{
for (int i = 0; i < antalTal - 1; i++) 
    {
        for (int j = 0; j < antalTal - i - 1; j++) 
        {
            if (tal[j] > tal[j + 1]) 
            {
                int temp = tal[j];
                tal[j] = tal[j + 1];
                tal[j + 1] = temp;
            }
        }
    }
}

int main() {
    int antalTal;
    cout << "Antal tal som ska sorteras?: ";
    cin >> antalTal;
    
    int tal[antalTal];

    cout << "Ange " << antalTal << " heltal: ";
    for (int i = 0; i < antalTal; i++) {
        cin >> tal[i];
    }

    bubbleSort(tal, antalTal);
    cout << "Talen i storleksordning: ";
    for (int i = 0; i < antalTal; i++) 
    {
        cout << tal[i] << "";
        if (i < antalTal - 1) 
        {
            cout << " / ";
        }
    }
    return 0;
}
