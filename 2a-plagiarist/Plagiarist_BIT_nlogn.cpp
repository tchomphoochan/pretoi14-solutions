#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;

int n, A[N], t[N+1];

void update(int x) {
	for(int i = x; i <= N; i += i&-i) t[i]--;
}

int query(int x) {
	int l = 1, r = N, c = 0;
	while(l < r) {
		int m = (l + r) >> 1;
		if(t[m] + c >= x) r = m;
		else l = m+1, c += t[m];
	}
	return l;
}

int main() {
	for(int i = 1; i <= N; ++i) t[i] = i&-i;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		int ret = query(now);
		printf("%d\n", A[ret]);
		update(ret);
	}
}