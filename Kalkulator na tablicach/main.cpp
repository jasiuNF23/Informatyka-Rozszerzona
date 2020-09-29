#include <iostream>

using namespace std;

int A[100] = {0}, B[100] = {0}, Wd[100] = {0}, Wo[100] = {0}, Wma[100] = {0}, Wmc[100] = {0};
/* A i B to tablice z liczbami wejściowymi.
Wd, Wo, Wmc to tablice z liczbami wyjściowymi poszczególnych działań.
Wma to tablica pomocnicza.
Zmienne a,b,c,d,e to zmienne pomocnicze które wykorzystuję w algorytmie.
Zmienne i,j,k to iteratory
*/
int Dodaj(int max)
{
    int a = 0, b = 0, c = 0, i = 1, e = 1;
    for (i = 1; i <= max; i++) {
        a = A[i];
        b = B[i];
        if (a + b + c > 10) {
            Wd[i] = (a + b + c) % 10;
            c = 1;
        } else
        {
            Wd[i] = a + b + c;
            c = 0;
        }
    }
    if(Wd[max+1]==0)
        e=0;
    return e;
}

void Odejmij(int max, int max1, int max2)
{
    int a = 0, b = 0, c = 0, i = 1, Ao[100] = {0}, Bo[100] =  {0};
    bool ujemna = false;
    if(max1<max2)
        ujemna= true;
    if(max1==max2&&A[1]<B[1])
        ujemna = true;
    if(ujemna)
        for (int j = 0; j <= max2; j++) {
            Ao[j] = B[j];
            Bo[j] = A[j];
        }
    else
        for (int j = 0; j <= max1; j++) {
            Ao[j] = A[j];
            Bo[j] = B[j];
        }
    for (i = 0; i < max; i++) {
        a = Ao[i+1];
        b = Bo[i+1];
        if(a-b-c<0)
        {
            Wo[max-i] = a + 10 - b - c;
            c = 1;
        }
        else
        {
            Wo[max-i] = a - b - c;
            c = 0;
        }
    }
    if(ujemna)
        Wo[0] = -1;
}

void DodajWMn(int max)
{
    int a = 0, b = 0, c = 0, i = 1, e = 1;
    for (i = 1; i <= max; i++) {
        a = Wmc[i];
        b = Wma[i];
        if (a + b + c > 10) {
            Wmc[i] = (a + b + c) % 10;
            c = 1;
        } else
        {
            Wmc[i] = a + b + c;
            c = 0;
        }
    }
}

void Pomnoz(int max1, int max2, int max)
{
    int Am[100] = {0}, Bm[100] = {0}, bufor, a = 0, b = 0, c = 0, d = 0, e = 0;

    for (int i = 1; i <= max2; ++i) {
        Wma[i-1] = 0;
        b = B[i];
        for (int j = 0; j <= max1; ++j) {
            a = A[j+1];
            d = a*b;
            Wma[j+i]=(d+c)%10;
            c = (d+c)/10;
        }
        DodajWMn(max1+e);
    }
}

int main() {
    int max1,max2,max, e = 1;
    string bufor;
    cin >> bufor;
    max1=bufor.length();
    int j = 1;
    for (int i = bufor.length() - 1; i >= 0; i--) {
        A[j] = bufor.at(i) - '0';
        j++;
    }
    cin >> bufor;
    max2 = bufor.length();
    if(max1>max2)
        max = max1;
    else
        max = max2;
    j = 1;
    for (int i = bufor.length() - 1; i >= 0; i--) {
        B[j] = bufor.at(i) - '0';
        j++;
    }

    e = Dodaj(max);
    Odejmij(max,max1,max2);
    Pomnoz(max1,max2,max);
    Podziel(max1,max2);
    for (int j = 0; j < max1+1; ++j) {
        cout << Wp[j];
    }

    cout << endl;

    for (int j = 0; j < 30; ++j) {
        cout << Wmc[j];
    }
    cout << endl;

    for (int j = max+e; j >= 1; j--) {
        cout << Wd[j];
    }
    cout << endl;



    if(Wo[0]!=0)
        cout << '-';
    for (int k = 1; k <= max; k++) {
        cout << Wo[k];
    }
    return 0;
}