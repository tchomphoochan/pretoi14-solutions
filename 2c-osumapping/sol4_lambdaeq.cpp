#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e17;
const int N = 10010;
const int M = 10010;
const int T = 10;

vector<pii> G[N];
bool visited[N][T];
ll dist[N][T];

int main()
{
    int n, m, t, x, y;
    scanf("%d%d%d%d%d", &n, &m, &t, &x, &y);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(v, w);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < t; ++j)
            dist[i][j] = INF;
    }
    dist[x][1%t] = 0;
    auto cmp = [&] (pii a, pii b) {
        return dist[a.first][a.second] >= dist[b.first][b.second];
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> Q(cmp);
    Q.emplace(x, 1);
    while (!Q.empty()) {
        int u = Q.top().first;
        int k = Q.top().second;
        ll d = dist[u][k];
        Q.pop();
        if (visited[u][k])
            continue;
        visited[u][k] = true;
        int nk = (k+1)%t;
        for (auto v : G[u]) {
            if (!visited[v.first][nk] && d+v.second < dist[v.first][nk]) {
                dist[v.first][nk] = d+v.second;
                Q.emplace(v.first, nk);
            }
        }
    }

    printf("%lld\n", dist[y][0] == INF ? -1 : dist[y][0]);

    return 0;
}