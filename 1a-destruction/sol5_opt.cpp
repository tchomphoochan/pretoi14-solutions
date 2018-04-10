#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e17;
const int N = 100010;
const int M = 100010;
const int K = 1010;

ll A[N], qs[N], dp[2][N], pmin[2][N];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    pmin[0][0] = INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &A[i]);
        qs[i] = qs[i-1]+A[i];
        pmin[0][i] = min(pmin[0][i-1], -qs[i-1]);
    }
    
    for (int i = 1; i <= k; ++i) {
        int x = i&1;
        dp[x][0] = INF;
        pmin[x][0] = INF;
        for (int j = 1; j <= n; ++j) {
            dp[x][j] = dp[x][j-1];
            if (j-m+1 >= 1)
                dp[x][j] = min(dp[x][j], pmin[x^1][j-m+1] + qs[j]);
            pmin[x][j] = min(pmin[x][j-1], dp[x][max(j-2, 0)] - qs[j-1]);
        }
    }

    printf("%lld\n", qs[n]-dp[k&1][n]);

    return 0;
}