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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll L, Q;
    cin >> L >> Q;
    set<ll> S;
    rep(i, Q) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            S.insert(x);
        } else {
            if (S.empty()) {
                cout << L << endl;
                continue;
            }
            auto iter = S.lower_bound(x);
            if (iter == S.begin()) {
                cout << *iter << endl;
            } else if (iter == S.end()) {
                cout << L - *prev(iter) << endl;
            } else {
                cout << *iter - *prev(iter) << endl;
            }
        }
    }

    return 0;
}
