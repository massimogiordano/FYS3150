#include <iostream>
#define PRECISION 1.0E-7

using namespace std;


int main ()
{

  int i,a,e=0, exp=0, lung=0, plus=0, mantissa_lunghezza;
  int num_int, bin_int[100], bin_dec[100], both[200], bin_exp[10];
  float num_dec, dec;

  cout << "Inserire un numero decimale:" << endl;
  cin >> num_dec;


  cout << num_dec << endl;

  if(num_dec < 0){
      num_dec *= -1;
      plus = 1;
  }
  //separo parte intera e parte decimale

  num_int = (int) num_dec;

  dec = num_dec - num_int;

  cout << num_int << " - " << dec << endl;

  //pulisco gli array
  for (i=99; i >= 0 ; i--){
    bin_dec[i] = 5;
    bin_int[i] = 3;
  }

  //trasformo il numero interno in binario

  a= num_int;
  i =0;

  while(a >0)
  {
      bin_int[i] = a%2;
      a /= 2;
      i++;
  }

 //stampo la parte intera

  for (i=99; i >= 0 ; i--){

     if (bin_int[i] == 0 || bin_int[i] == 1)  {
        cout <<   bin_int[i];
        lung++;
     }
  }

  exp = e;

 //stampo il punto per la parte decimale

  cout << "." ;

  i = 99;

  while(dec > PRECISION ) {

      dec = dec * 2;

      if( (int)dec >= 1 ){

          bin_dec[i] = 1;
          //num_dec *=10;
          dec = dec - 1;
      }else{

          bin_dec[i] = 0;
      }


      cout << bin_dec[i] ;

      i--;

      //evitare errori e conflitti tra precisione e lunghezza array
      if(i==0)
          dec = PRECISION;

   }  // end of while





  //sposto la virgola

  i++;

  cout<< endl << "both" << endl;

  while(i != 100){

      both[e] = bin_dec[i];
      e++;
      i++;

  }

  i=0;

  while(i != lung){ //lunghezza vettore numero binario parte intera

      both[e] = bin_int[i];
      i++;
      e++;

}
  e--;

  exp= lung -1;

  cout << "binario con esponente:" << both[e] << ".";
 e--;
  mantissa_lunghezza = e;

 // mantissa_lunghezza = e;
  while(e>=0){

      cout << both[e];

      e--;
  }

cout << " x 2^" << exp << endl << endl;

cout << "memorizzazione binaria: "<< plus << " ";

exp += 127;

for(i=0; i<8; i++){
    bin_exp[i] = exp%2;
    exp /= 2;
}

for(i=7; i>=0; i--){

    cout <<  bin_exp[i];
}


cout << " ";

for(i=mantissa_lunghezza; i > (mantissa_lunghezza -23) ; i--){
    cout << both[i];
}
cout << endl;

    return 0;
}
