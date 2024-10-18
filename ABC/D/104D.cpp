#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
    return a + b;
}

ll e() {
    return 0;
}

ll powMod(ll x, ll y) {
    ll MOD = mint::mod();
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    vector<segtree<ll, op, e>> seg(4, segtree<ll, op, e>(S.size()));

    rep(i, S.size()) {
        if (S.at(i) == 'A') {
            seg.at(0).set(i, 1);
        } else if (S.at(i) == 'B') {
            seg.at(1).set(i, 1);
        } else if (S.at(i) == 'C') {
            seg.at(2).set(i, 1);
        } else {
            seg.at(3).set(i, 1);
        }
    }

    mint ans = 0;
    rep(i, S.size()) {
        if (S.at(i) == 'B' || S.at(i) == '?') {
            mint leftA = seg.at(0).prod(0, i) * powMod(3, seg.at(3).prod(0, i));
            mint leftQ = seg.at(3).prod(0, i) * powMod(3, seg.at(3).prod(0, i) - 1);
            mint rightC = seg.at(2).prod(i + 1, S.size()) * powMod(3, seg.at(3).prod(i + 1, S.size()));
            mint rightQ = seg.at(3).prod(i + 1, S.size()) * powMod(3, seg.at(3).prod(i + 1, S.size()) - 1);
            mint res = (leftA + leftQ) * (rightC + rightQ);
            ans += res;
        }
    }

    cout << ans.val() << endl;

    return 0;
}
