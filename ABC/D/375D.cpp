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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

int main() {
    string S;
    cin >> S;
    ll N = S.size();

    vector<segtree<ll, op, e>> seg(26, segtree<ll, op, e>(N));
    rep(i, N) {
        seg[S[i] - 'A'].set(i, 1);
    }
    ll ans = 0;
    rep(i, N) {
        if (i == 0 || i == N - 1) continue;
        ll cnt = 0;
        rep(j, 26) {
            cnt += seg[j].prod(0, i) * seg[j].prod(i + 1, N);
        }
        ans += cnt;
    }

    cout << ans << endl;

    return 0;
}
