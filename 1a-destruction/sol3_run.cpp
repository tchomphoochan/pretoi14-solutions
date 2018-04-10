#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e17;
const int N = 10010;
const int M = 10010;
const int K = 1010;

ll A[N], dp[K][N];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    ll tt = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &A[i]);
        tt += A[i];
    }
    
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = INF;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j-1];
            ll sum = 0;
            for (int l = j; l >= 1; --l) {
                sum += A[l];
                if (l <= j-m+1)
                    dp[i][j] = min(dp[i][j], dp[i-1][max(0, l-2)] + sum);
            }
        }
    }

    printf("%lld\n", tt-dp[k][n]);

    return 0;
}