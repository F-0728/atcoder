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

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return 0;
}

int main() {
    ll N;
    cin >> N;
    vll h(N), a(N);
    rep(i, N) {
        cin >> h[i];
        h[i]--;
    }
    rep(i, N) {
        cin >> a[i];
    }

    segtree<ll, op, e> seg(N);
    rep(i, N) {
        seg.set(h[i], a[i] + seg.prod(0, h[i]));
    }

    cout << seg.all_prod() << endl;

    return 0;
}
