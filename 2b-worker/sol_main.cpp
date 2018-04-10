#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using edge = pair<int, pii>;

const int N = 1010;

int n, T[N], B[N];
int parent[N];

int root(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = root(parent[u]);
}

bool merge(int u, int v)
{
    u = root(u);
    v = root(v);
    if (u != v) {
        parent[u] = v;
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    vector<edge> E;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &T[i]);
        E.emplace_back(T[i], pii(0, i));
        parent[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &B[i]);
        for (int j = 1; j < i; ++j)
            E.emplace_back(B[i]+B[j], pii(i, j));
    }

    sort(E.begin(), E.end());
    ll sum = 0;
    for (auto e : E) {
        if (merge(e.second.first, e.second.second))
            sum += e.first;
    }
    printf("%lld\n", sum);

    return 0;
}