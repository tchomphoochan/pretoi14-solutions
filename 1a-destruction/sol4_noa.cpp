#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e17;
const int N = 10010;
const int M = 10010;
const int K = 1010;

ll qs[N], dp[K][N], pmin[K][N];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    pmin[0][0] = INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i-1];
        pmin[0][i] = min(pmin[0][i-1], -qs[i-1]);
    }
    
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = INF;
        pmin[i][0] = INF;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j-1];
            if (j-m+1 >= 1)
                dp[i][j] = min(dp[i][j], pmin[i-1][j-m+1] + qs[j]);
            pmin[i][j] = min(pmin[i][j-1], dp[i][max(j-2, 0)] - qs[j-1]);
        }
    }

    printf("%lld\n", qs[n]-dp[k][n]);

    return 0;
}