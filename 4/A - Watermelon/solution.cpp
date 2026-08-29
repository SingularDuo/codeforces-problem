#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int w;
    if (cin >> w) {
        // A weight w can be split into two positive even numbers 
        // if and only if w is even and strictly greater than 2.
        if (w > 2 && w % 2 == 0) {
            cout << "YES
";
        } else {
            cout << "NO
";
        }
    }
 
    return 0;
}