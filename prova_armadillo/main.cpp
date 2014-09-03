#include <iostream>

#include <armadillo>


using namespace arma;
using namespace std;

#define FUNX  100*exp(-10*x);


double func(double, double h2);

int main()
{

    unsigned int n, i;
    double *f_i, *u_i, h2, h;
    unsigned int *matrix;

    cout << "Number of stemps: ";
    cin >> n;

    h = 1./(1.*n + 1.);
    h2 = h*h;
    cout << h2 << endl;

    f_i = new double[n+1];
    u_i = new double[n+2];

    f_i[0] = 0.;
    for(i=1; i<=n; i++ ){

        f_i[i] = f_i[i-1] + i*func(i*h, h2);

    }


    for(i=1; i<=n; i++ ){
    cout << f_i[i] << " - ";
    }


    u_i[n+1] = 0.;
    for(i=n; i>=1; i--){

        u_i[i] =( double(i)*u_i[i+1] + f_i[i] )/double(i+1);

        //cout << f_i[n] << "-" << u_i[n] <<" - " << u_i[n+1] << "-" << n << endl;

    }

    cout << endl << "u_i:      True value:"  << endl;

    for(i=1; i<=n; i++ ){
    cout << u_i[i] << " - " << (1 - (1-exp(-10))*double(i)*h - exp(-10.*double(i)*h))<< endl;
    }



    return 0;
}


double func(double x, double h2){

    double value;

    value = h2*FUNX;

    return value;


}
