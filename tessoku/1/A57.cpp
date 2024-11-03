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
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) {
        cin >> A.at(i);
        A.at(i)--;
    }

    vpll query(Q);
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        x--;
        query.at(i) = make_pair(x, y);
    }

    vvll dp(N, vll(31, 0));
    rep(i, N) {
        dp.at(i).at(0) = A.at(i);
    }
    rep(j, 30) {
        rep(i, N) {
            dp.at(i).at(j + 1) = dp.at(dp.at(i).at(j)).at(j);
        }
    }

    rep(i, Q) {
        ll x, y;
        x = query.at(i).first;
        y = query.at(i).second;
        vll bit(31, 0);
        rep(j, 31) {
            if (y & (1 << j)) {
                bit.at(j) = 1;
            }
        }
        // outv(bit);
        ll ans = x;
        rep(j, 31) {
            if (bit.at(j)) {
                ans = dp.at(ans).at(j);
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}
