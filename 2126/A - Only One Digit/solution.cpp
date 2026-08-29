#include <bits/stdc++.h>
using namespace std;
 
bool share_digit(int x, int y) {
    string sx = to_string(x), sy = to_string(y);
    for (char cx : sx) {
        for (char cy : sy) {
            if (cx == cy) return true;
        }
    }
    return false;
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        for (int y = 0; ; y++) {
            if (share_digit(x, y)) {
                cout << y << '
';
                break;
            }
        }
    }
    return 0;
}