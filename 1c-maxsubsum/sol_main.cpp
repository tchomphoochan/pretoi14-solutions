#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 1e5+5;

int n, w, h;
long A[N], B[N];

int main() {
	scanf("%d %d %d", &n, &w, &h);
	for(int i = 1; i <= n; ++i) scanf("%lld", A+i), A[i] += A[i-1];
	for(int i = 1; i <= n; ++i) scanf("%lld", B+i), B[i] += B[i-1];
	long mx1 = 0, mx2 = 0;
	for(int i = w; i <= n; ++i) mx1 = max(mx1, A[i] - A[i-w]);
	for(int i = h; i <= n; ++i) mx2 = max(mx2, B[i] - B[i-h]);
	printf("%lld\n", mx1 * h + mx2 * w);
}