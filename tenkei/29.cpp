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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll op (ll a, ll b) {
    a = max(a, b);
    return a;
}

ll e () {
    return 0;
}

ll mapping (ll f, ll x) {
    if (f == -1) return x;
    return f;
}

ll composition (ll f, ll g) {
    if (f == -1) return g;
    return f;
}

ll id () {
    return -1;
}


int main() {
    ll W, N;
    cin >> W >> N;
    ll pow = 1;
    while (pow < W) {
        pow *= 2;
    }
    lazy_segtree<ll, op, e, ll, mapping, composition, id> bricks(2 * pow);
    rep(i, N) {
        ll L, R;
        cin >> L >> R;
        L--;
        ll ans = bricks.prod(L, R);
        bricks.apply(L, R, ans + 1);
        cout << ans + 1 << endl;
    }


    return 0;
}
