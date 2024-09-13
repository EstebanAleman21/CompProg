#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    long long ans = 0, delta = 0;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            ans += a[i];
        else
            ans -= a[i];
    }

    for (int i = 0; i + 1 < n; i += 2) {
        delta += a[i] - a[i + 1];
    }

    ans -= min(delta, static_cast<long long>(k));

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
