#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const ll INF = 1e17;
const int N = 10010;
const int M = 10010;
const int T = 10;

vector<pii> G[N];
bool visited[N];
ll dist[N];

int main()
{
    int n, m, t, x, y;
    scanf("%d%d%d%d%d", &n, &m, &t, &x, &y);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(v, w);
    }

    for (int i = 1; i <= n; ++i)
        dist[i] = INF;
    dist[x] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > Q;
    Q.emplace(dist[x], x);
    while (!Q.empty()) {
        ll d = Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto v : G[u]) {
            if (!visited[v.first] && d+v.second < dist[v.first]) {
                dist[v.first] = d+v.second;
                Q.emplace(dist[v.first], v.first);
            }
        }
    }

    printf("%lld\n", dist[y] == INF ? -1 : dist[y]);

    return 0;
}