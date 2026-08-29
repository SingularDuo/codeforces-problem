#include <bits/stdc++.h>
using namespace std;
 
// Định nghĩa alias __int128 thành i128 cho gọn:
using i128 = __int128;
 
// Hàm đọc một số __int128 từ stdin (có thể âm)
i128 read_i128() {
    i128 x = 0;
    bool neg = false;
    int c = getchar();  // Đổi thành int để tránh warning
    // Bỏ qua mọi ký tự không phải chữ số và không phải dấu '-'
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return neg ? -x : x;
}
 
// Hàm in một số __int128 ra stdout (đệ quy)
void print_i128(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x >= 10) {
        print_i128(x / 10);
    }
    putchar(char('0' + (int)(x % 10)));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    // Đọc số lượng test cases t (chắc t ≤ 1000, nên chuyển t128 về long long để loop)
    i128 t128 = read_i128();
    long long t = (long long)t128;
 
    while (t--) {
        // Đọc n (1 ≤ n ≤ 50)
        i128 n128 = read_i128();
        int n = (int)n128;
 
        vector<i128> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = read_i128();
        }
 
        // Nếu n ≤ 1, luôn fashionable nên không cần xoá
        if (n <= 1) {
            print_i128(0);
            putchar('
');
            continue;
        }
 
        // Tách 2 nhóm: chẵn và lẻ, và tìm min/max trong mỗi nhóm
        bool has_even = false, has_odd = false;
        i128 mn_even = 0, mx_even = 0;
        i128 mn_odd  = 0, mx_odd  = 0;
 
        for (int i = 0; i < n; i++) {
            if ((a[i] & 1) == 0) {  // a[i] % 2 == 0
                if (!has_even) {
                    has_even = true;
                    mn_even = mx_even = a[i];
                } else {
                    mn_even = min(mn_even, a[i]);
                    mx_even = max(mx_even, a[i]);
                }
            } else {
                if (!has_odd) {
                    has_odd = true;
                    mn_odd = mx_odd = a[i];
                } else {
                    mn_odd = min(mn_odd, a[i]);
                    mx_odd = max(mx_odd, a[i]);
                }
            }
        }
 
        // Tính số phần tử giữ lại nếu chọn cặp (mn_even, mx_even)
        i128 keep_even = 0;
        if (has_even) {
            for (int i = 0; i < n; i++) {
                if (a[i] >= mn_even && a[i] <= mx_even) {
                    keep_even++;
                }
            }
        }
 
        // Tính số phần tử giữ lại nếu chọn cặp (mn_odd, mx_odd)
        i128 keep_odd = 0;
        if (has_odd) {
            for (int i = 0; i < n; i++) {
                // LƯU Ý: ở đây phải dùng mx_odd (không phải mx_dd)
                if (a[i] >= mn_odd && a[i] <= mx_odd) {
                    keep_odd++;
                }
            }
        }
 
        // Chọn phương án giữ được nhiều phần tử hơn
        i128 best_keep = 0;
        if (has_even) best_keep = max(best_keep, keep_even);
        if (has_odd)  best_keep = max(best_keep, keep_odd);
 
        // Kết quả: số phần tử cần xoá = n - best_keep
        i128 ans = n128 - best_keep;
        print_i128(ans);
        putchar('
');
    }
    return 0;
}