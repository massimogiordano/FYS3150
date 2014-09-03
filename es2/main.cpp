#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
  int i,a;
  int terms[32]; // storage of a0, a1, etc, up to 32 bits
  int number = atoi(argv[1]); // initialise the term a0, a1 etc

  // try a different way to see if the numember is divisble by 2

  a = number;



  for (i=0; i < 32 ; i++){

      terms[i] = 0;
    }

  for (i=0; i < 32 ; i++){
    terms[i] = number%2;
    number /= 2;
  }
  // write out results
  cout << "Number of bytes used= " << sizeof(number) << endl;
  for (i=0; i < 32 ; i++){
    cout << " Term nr: " << i << "Value= " << terms[i];
    cout << endl;
  }

  for (i=32; i > 0 ; i--){
    cout << terms[i];
    }
    cout << endl;

    //stampo solo gli ultimi numeri dei 32 bit che rappresentano il numero
  a=0;

    for (i=31; i >= 0 ; i--){

        if(terms[i]==0 && a==0){
            a==0;
        }else{
            a=1;
            cout << terms[i];
        }

    }

    cout << endl;

    return 0;
}



