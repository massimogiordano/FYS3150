#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    double sum_up=0, sum_down=0;
    float sum_up_float=0, sum_down_float=0;
    int n, i;

    cout << "Inserisci numero N sommatoria: " ;
    cin >> n ;

    for(i=1; i<=n ; i++){
        sum_up += 1/double(i);
        sum_up_float += 1/float(i);
    }

    for(i=n; i>0; i--){
        sum_down += 1/double(i);
        sum_down_float += 1/float(i);
        // cout << i << " - " << sum_down << endl;
    }

    cout << "S_down: " << sum_down << " float: " << sum_down_float << endl;
    cout << "S_up: " << sum_up << " float: " << sum_up_float << endl;

    /*
    double down, up;
    int k, u;

    while((up - down) == 0){



    }

*/
    return 0;
}

