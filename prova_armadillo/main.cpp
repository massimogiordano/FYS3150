#include <iostream>
#include <iomanip>
#include <armadillo>
#include <cmath>
#include <stdio.h>
#include<time.h>


using namespace arma;
using namespace std;

#define FUNX  100*exp(-10*x)
#define ANALYTICSOLUT (1 - (1-exp(-10))*double(i)*h - exp(-10.*double(i)*h))


double func_h2(double, double);
double func(double);
void LU_decomposition(int, double, double* );



int main()
{

    unsigned int n=1, i, p, t;
    double *f_i, *u_i, h2, h, *v_i, *e_i, *lu_sol, e_max=0, time, time_lu;

    cout << "Number of iteration of 10^n: ";
    cin >> p;

    for(t=1; t<=p; t++){
    n *=10;
                cout << n << "_"<< endl;
    h = 1./(1.*n + 1.);
    h2 = h*h;

    f_i = new double[n+1];
    v_i = new double[n+1];
    u_i = new double[n+2];
    e_i = new double[n+1];
    lu_sol = new double[n];

    f_i[0] = 0.;

    clock_t start, finish;

    //analytical solution
    start = clock();
    for(i=1; i<=n; i++ ){
        f_i[i] = f_i[i-1] + i*func_h2(i*h, h2);
        v_i[i] = ANALYTICSOLUT;
    }
    //numerical solution
    u_i[n+1] = 0.;  //to be able to use the generical formula
    for(i=n; i>=1; i--){
        u_i[i] =( double(i)*u_i[i+1] + f_i[i] )/double(i+1);
    }
    finish = clock();
    cout<< n<<"  numerical  "<<double(finish-start)/CLOCKS_PER_SEC<<endl;

    //relative error
    for(i=1; i<=n; i++){
        e_i[i] = log10(abs(u_i[i]/ANALYTICSOLUT -1));
        if(e_i[i]<e_max){
               e_max=e_i[i];
        }
    }
    if(n<100000){
    start=clock();
    LU_decomposition(n,h, lu_sol);
    finish=clock();
    time_lu = double(finish-start)/CLOCKS_PER_SEC;
    cout<<n<<"  LU   "<< time_lu <<endl;
    }


    char name[10];
    name[0] = '1';
    for(i=1; i<p+1;i++){
        name[i]='0';
    }

    name[i++]='.';
    name[i++]='t';
    name[i++]='x';
    name[i++]='t';
    ofstream myfile (name);
      if (myfile.is_open())
      {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
      }
      else cout << "Unable to open file";
      return 0;
/*
   const char* filename1 = "ciao";
   ifstream ifile(filename1);
   string filename2 = filename1 + ".out";
   ofstream ofile(filename2);

   // new output file
   ofstream ofile(filename2, ios_base::app); // append // Read something from

   ifile << n << endl; //>> b >> c; // skips white space in between // Can test on success of reading:
*/

    //write to file
    FILE *output_file;
    output_file = fopen("outn.txt", "w") ;

    fprintf(output_file, "Dimension matrix computed: 10^%dx10^%d \n\nDuration of Numerical calcolation:  %e \n            LU calcolation:         %lf \n \nMaximun relative error: %lf\n\n", p, p,  time, time_lu, e_max);

    fprintf(output_file, "x_i          u_i     LU solution     Analytic sol    f_i     relative error\n\n" );

    for(i=1; i<=n; i++){
        fprintf(output_file, "%lf   %lf   %lf         %lf   %lf   %.30f   \n",i*h, u_i[i], lu_sol[i-1], v_i[i], func(double(i)*h), e_i[i] );
    }

    fclose (output_file);


    }
    return 0;
}


double func(double x){

    double value;
    value = FUNX;
    return value;
}


double func_h2(double x, double h2){

    double value;
    value = h2*FUNX;
    return value;
}

void LU_decomposition(int n, double h, double *lu_sol){
    vec f(n);
    mat M(n,n);
    M.zeros();
    M(0,0)=2;
    f[0]= func_h2(h, h*h);

    for(int i=1;i<n;i++){
        f[i]= func_h2((i+1.)*h, h*h);
        M(i,i)=2;
        M(i-1,i)=-1;
        M(i,i-1)=-1;
    }
    vec x=solve(M,f);

    for(int i=0; i<n; i++){
    lu_sol[i] = x[i];
    }
}
