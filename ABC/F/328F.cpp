#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

#include <iostream>
#include <vector>
using namespace std;

template<class Abel> struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<Abel> diff_weight;

	UnionFind(int n = 1, Abel SUM_UNITY = 0) {
		init(n, SUM_UNITY);
	}

	void init(int n = 1, Abel SUM_UNITY = 0) {
		par.resize(n); rank.resize(n); diff_weight.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
	}

	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			int r = root(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = r;
		}
	}

	Abel weight(int x) {
		root(x);
		return diff_weight[x];
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, Abel w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = -w;
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}

	Abel diff(int x, int y) {
		return weight(y) - weight(x);
	}
};


int main() {
    ll N, Q;
    cin >> N >> Q;
    UnionFind<ll> uf(N);
    vll ans;
    rep(i, Q) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        if (uf.issame(a, b)) {
            if (uf.diff(a, b) != -d) continue;
        }
        uf.merge(a, b, -d);
        ans.push_back(i + 1);
    }

    outv(ans);


    return 0;
}
