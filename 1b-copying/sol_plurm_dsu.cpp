#include <bits/stdc++.h>
using namespace std;

const int N = 4e4+5;

int n, m, p, u, v, w, ans, H[N];
vector<tuple<int, int, int> > g;
vector<pair<int, int> > q;

int find(int x) { return H[x] = H[x] == x ? x : find(H[x]); }

bool check(int m) {
	for(int i = 1; i <= n; ++i) H[i] = i;
	for(auto x : g) if(get<2>(x) < m) H[find(get<0>(x))] = find(get<1>(x));
	for(auto x : q) if(find(x.first) == find(x.second)) return false;
	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	while(m--) scanf("%d %d %d", &u, &v, &w), g.emplace_back(u, v, w); 
	while(p--) scanf("%d %d", &u, &v), q.emplace_back(u, v); 
	for(int i = 29; i >= 0; --i) if(check(ans|1<<i)) ans |= 1<<i;
	if(ans > 1e9) puts("-1");
	else printf("%d\n", ans);
}