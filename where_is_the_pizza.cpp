#include <iostream>
#include <vector>
#include <cstdio> // Para scanf y printf

using namespace std;

const int N = 100100;
int n;
vector<int> a(N), b(N), c(N), par(N), sz(N);
vector<bool> used(N);

int find(int v) {
    if (par[v] == v) 
        return v;
    return par[v] = find(par[v]);  
}

bool unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (v == u) return false; 
    if (sz[v] < sz[u]) swap(v, u);  
    sz[v] += sz[u];
    par[u] = v;
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        used[i] = false;
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        if (c[i] != 0) used[c[i]] = true;
    }

    long long ans = 1;
    const long long mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        if (c[i] != 0) continue;  
        int v = a[i], u = b[i];
        if (used[v] || used[u] || v == u) continue;
        if (!unite(v, u)) 
            ans = (ans * 2) % mod;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
