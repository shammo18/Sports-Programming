#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int kase;
 
    cin >> kase;
    while (kase--) {
        long long n, ans = 0;
 
        cin >> n;
        for (int i = 0; i < 63; i++) {
            if (n & (1LL << i)) {
                ans += (1LL << (i + 1)) - 1;
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}