#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
  int i,a;
  int terms[32]; // storage of a0, a1, etc, up to 32 bits
  int number = atoi(argv[1]); // initialise the term a0, a1 etc
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

  i=32;
  /*while(terms[i]==0){


      i--;
      i=a;
  }
*/
  a=0;
  for (i=31; i >= 0 ; i--){

     // cout << "|";

      if(terms[i]==0 && a==0){

          a==0;
          //cout << "no" << i;

      }else{
          a=1;
          cout << terms[i];
      }

    }



      cout << endl;




  return 0;
}



