#include <bits/stdc++.h>
using namespace std;
 
#define spd ios::sync_with_stdio(false); cin.tie(nullptr);
 
int uniqCnt(int m) {
    unordered_set<int> s;   
    while (m--) {
        int v; cin >> v;
        s.insert(v);
    }
    return (int)s.size();
}
 
void run() {
    int q; cin >> q;
    while (q--) {
        int sz; cin >> sz;
        int k = uniqCnt(sz);
        cout << (k * 2 - 1) << "
";
    }
}
 
int main() {
    spd;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    run();
    return 0;
}