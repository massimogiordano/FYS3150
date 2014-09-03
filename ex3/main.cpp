#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int main()
{
    double  x, sum_sin=0;
    int i,k, segno=1;

    cout << "Inserire valore di partenza di x: ";
    cin >> x;

    for(i=0; i<10; i++){

        sum_sin = 0;
        segno = 1;

        for(k=1; k<16; k +=2){

            sum_sin += segno*pow(x, k)/(fact(k));
            segno *= -1;

            cout << fact(k) << " - " <<pow(x,k) <<" - " <<  sum_sin << endl;
        }

        cout << "Da libreria: " << x - sin(x) << " - " << x - sum_sin << " - x:  " << x  << endl<<endl;
        x /=2;

    }

}//con i numeri grandi non va, con quelli piccoli inceve funziona

