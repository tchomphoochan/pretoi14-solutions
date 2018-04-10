#include <bits/stdc++.h>
using namespace std;

struct item {
	int cnt, val, prio;
	item *l, *r;
	item(int val) : cnt(1), val(val), prio(rand()), l(NULL), r(NULL) { }
};

using pitem = item*;
int cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt(pitem t) { if(t) t->cnt = cnt(t->l) + cnt(t->r) + 1; }

void split(pitem t, int key, pitem &l, pitem &r) {
	if(!t) return void(l = r = NULL);
	if(key <= cnt(t->l)) split(t->l, key, l, t->l), r = t;
	else split(t->r, key - cnt(t->l) - 1, t->r, r), l = t;
	upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
	if(!l || !r) t = l ? l : r;
	else if(l->prio > r->prio) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

int n;
pitem t;

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		merge(t, t, new item(now));
	}
	while(n--) {
		int x; scanf("%d", &x);
		pitem t1, t2, t3;
		split(t, x-1, t1, t2);
		split(t2, 1, t2, t3);
		printf("%d\n", t2->val);
		merge(t, t1, t3);
	}
}