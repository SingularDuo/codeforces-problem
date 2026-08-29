#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1505;
const int ALPHABET = 26;
 
int n;
string s;
int ans[ALPHABET][MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    cin >> s;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }
 
    for (int c = 0; c < ALPHABET; c++) {
        for (int i = 0; i < n; i++) {
            int replace_ct = 0;
            for (int j = i; j < n; j++) {
                if (a[j] != c) replace_ct++;
                ans[c][replace_ct] = max(ans[c][replace_ct], j - i + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            ans[c][i] = max(ans[c][i], ans[c][i - 1]);
        }
    }
 
    int q;
    cin >> q;
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        cout << ans[c - 'a'][m] << '
';
    }
 
    return 0;
}