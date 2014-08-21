/* comments in C begin like this and end with */
#include <iostream> /* atof function */
#include <math.h>   /* sine function */
#include <stdio.h>  /* printf function */

using namespace std;

int main ()
{
  double r, s;        /* declare variables */
  cin >> r ;
  //r = atof(argv[1]);  /* convert the text argv[1] to double */
  s = sin(r);
  cout << "Hello, World! sin("<< r <<") =" << s << endl;
  return 0;           /* success execution of the program */
}


