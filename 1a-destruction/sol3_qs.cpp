#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e17;
const int N = 10010;
const int M = 10010;
const int K = 1010;

ll A[N], qs[N], dp[K][N];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &A[i]);
        qs[i] = qs[i-1]+A[i];
    }
    
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = INF;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j-1];
            for (int l = 1; l <= j-m+1; ++l)
                dp[i][j] = min(dp[i][j], dp[i-1][max(0, l-2)] + qs[j]-qs[l-1]);
        }
    }

    printf("%lld\n", qs[n]-dp[k][n]);

    return 0;
}