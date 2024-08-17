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
    ll N, K;
    cin >> N >> K;
    vll X(N);
    rep(i, N) {
        cin >> X.at(i);
        X.at(i)--;
    }
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vvll dp(N, vll(60, -1));
    rep(i, N) {
        dp.at(i).at(0) = X.at(i);
    }
    rep(j, 59) {
        rep(i, N) {
            if (dp.at(i).at(j) == -1) continue;
            dp.at(i).at(j + 1) = dp.at(dp.at(i).at(j)).at(j);
        }
    }

    vll ans(N);
    rep(i, N) {
        ans.at(i) = i;
    }
    rep(i, N) {
        ll x = i;
        rep(j, 60) {
            if ((K >> j) & 1) {
                ans.at(i) = dp.at(x).at(j);
                x = dp.at(x).at(j);
            }
        }
    }
    rep(i, N) {
        cout << A.at(ans.at(i)) << " ";
    }
    cout << endl;

    return 0;
}
