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

int main() {
    ll MOD = 1048576;
    ll Q;
    cin >> Q;

    vll A(1 << 20, -1);
    set<ll> S;
    rep(i, 1 << 20) {
        S.insert(i);
    }
    rep(i, Q) {
        ll t, x;
        cin >> t >> x;
        if (t == 2) cout << A.at(x % MOD) << endl;
        else {
            auto idx = S.lower_bound(x % MOD);
            if (idx == S.end()) {
                idx = S.lower_bound(0);
            }
            A.at(*idx) = x;
            S.erase(idx);
        }
    }

    return 0;
}
