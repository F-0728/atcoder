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

using S = long long;
using F = long long;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    ll N, M;
    cin >> N >> M;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N + 1);

    vector<vpll> getLeft(N + 1);
    rep(i, M) {
        ll l, r, a;
        cin >> l >> r >> a;
        l--;
        getLeft[r].push_back({l, a});
    }
    seg.set(0, 0);

    for (ll i = 1; i <= N; i++) {
        ll score = 0;
        for (auto [l, a] : getLeft[i]) {
            score += a;
        }
        ll MAX = seg.prod(0, i);
        seg.set(i, MAX + score);
        for (auto [l, a] : getLeft[i]) {
            seg.apply(l + 1, i, a);
        }
    }

    cout << seg.prod(0, N + 1) << endl;


    return 0;
}
