#include <iostream>
#include <string>
using namespace std;

int main() {

    string Palindrome;

    cout << "Please enter a string (length < 100):";
    cin >> Palindrome;

    for (int i=0; i<(Palindrome.length()/2); i++) {
        if (Palindrome[i] == Palindrome[Palindrome.length()-1-i]) {
            continue;
        }
        else {
            cout << Palindrome << " is NOT a Palindrome." << endl;
            return 0;
        }
    }
    cout << Palindrome << " is a Palindrome." << endl;

    return 0;
}
