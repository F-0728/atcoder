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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll X;
    cin >> X;
    set<ll> tousasuu;
    rep(i, 10) {
        for (ll j = -9; j <= 9; j++) {
            rep(l, 19) {
                string seq = "";
                ll k = i;
                while (k >= 0 && k <= 9 && seq.size() < l) {
                    seq += to_string(k);
                    k += j;
                }
                if (seq.size() > 0) {
                    tousasuu.insert(stoll(seq));
                }
            }
        }
    }
    ll ans = *tousasuu.lower_bound(X);
    cout << ans << endl;

    return 0;
}
