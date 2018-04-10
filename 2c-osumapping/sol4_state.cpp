#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using plii = pair<ll, pii>;

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
    priority_queue<plii, vector<plii>, greater<plii> > Q;
    Q.emplace(dist[x][1], pii(x, 1));
    while (!Q.empty()) {
        ll d = Q.top().first;
        int u = Q.top().second.first;
        int k = Q.top().second.second;
        Q.pop();
        if (visited[u][k])
            continue;
        visited[u][k] = true;
        int nk = (k+1)%t;
        for (auto v : G[u]) {
            if (!visited[v.first][nk] && d+v.second < dist[v.first][nk]) {
                dist[v.first][nk] = d+v.second;
                Q.emplace(dist[v.first][nk], pii(v.first, nk));
            }
        }
    }

    printf("%lld\n", dist[y][0] == INF ? -1 : dist[y][0]);

    return 0;
}