#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
 
    // Sort to easily check adjacent triplets: (a[0], a[1], a[2]) and (a[1], a[2], a[3])
    sort(a.begin(), a.end());
 
    // Check for non-degenerate triangle (a + b > c)
    if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) {
        cout << "TRIANGLE
";
    } 
    // Check for degenerate triangle (a + b == c)
    else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) {
        cout << "SEGMENT
";
    } 
    // Neither is possible
    else {
        cout << "IMPOSSIBLE
";
    }
 
    return 0;
}