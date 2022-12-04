#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    int num;
    int prime_num = 0;

    cout << "Please enter an integer number (>=2):";
    cin >> n;

    for (int i=2; i<=n+1; i++) {
        if (num == 1) {
            prime_num++;
        }
        num = 1;
        for (int j=2; j<=sqrt(i); j++) {
                    if (i % j == 0) {
                        num = 0;
                    }
                    if (num == 0) {
                        break;
            }
        }
    }
    cout << "The number of prime numbers between 2 and " << n << " is " << prime_num << endl;

    return 0;
}
