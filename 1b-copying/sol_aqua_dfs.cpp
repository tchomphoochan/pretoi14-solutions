#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 200010;
const int M = 500010;

int n, m, p;
bool vis[N];
int num[N];
vector<pii> G[N];
pii P[M];

void dfs(int u, int k, int x)
{
    vis[u] = true;
    num[u] = x;
    for (auto v : G[u]) {
        if (v.second < k && !vis[v.first])
            dfs(v.first, k, x);
    }
}

bool check(int k)
{
    fill(vis, vis+n+1, false);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i, k, i);
    }
    for (int i = 0; i < p; ++i) {
        if (num[P[i].first] == num[P[i].second])
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for (int i = 0; i < p; ++i)
        scanf("%d%d", &P[i].first, &P[i].second);

    int b = 1;
    int e = 1e9+1;
    while (b < e) {
        int mid = (b+e+1)/2;
        if (check(mid))
            b = mid;
        else
            e = mid-1;
    }

    if (e == 1e9+1)
        e = -1;
    printf("%d\n", e);
    
    return 0;
}