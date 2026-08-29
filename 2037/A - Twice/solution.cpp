#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> freq(n + 1, 0);
        for (int num : a) {
            freq[num]++;
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += freq[i] / 2;
        }
        cout << sum << endl;
    }
    return 0;
}