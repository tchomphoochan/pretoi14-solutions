#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n;
int A[N], seg[N<<2];

void update(int i, int x, int p=1, int b=1, int e=n) {
    if (b == e) {
        ++seg[p];
        return;
    }
    int m = (b+e)/2;
    if (i <= m)
        update(i, x, p<<1, b, m);
    else
        update(i, x, p<<1|1, m+1, e);
    seg[p] = seg[p<<1] + seg[p<<1|1];
}

int query(int l, int r, int p=1, int b=1, int e=n) {
    if (b > e || b > r || e < l)
        return 0;
    if (b >= l && e <= r)
        return seg[p];
    int m = (b+e)/2;
    return query(l, r, p<<1, b, m) + query(l, r, p<<1|1, m+1, e);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    int nx = n;
    while (nx--) {
        int x;
        scanf("%d", &x);
        int b = 1;
        int e = n;
        while (b < e) {
            int m = (b+e)/2;
            int l = m;
            if (l-query(1, m) >= x)
                e = m;
            else
                b = m+1;
        }
        printf("%d\n", A[e]);
        update(e, 1);
    }
    
    return 0;
}