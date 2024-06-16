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
    ll N, W;
    cin >> N >> W;
    vll weight(N), value(N);
    rep(i, N) {
        cin >> weight.at(i) >> value.at(i);
    }
    vvll dp(N + 1, vll(W + 1, 0));
    rep(i, N + 1) {
        rep(j, W + 1) {
            if (i == 0) {
                dp.at(i).at(j) = 0;
            } else if (j == 0) {
                dp.at(i).at(j) = 0;
            } else {
                if (j - weight.at(i - 1) >= 0) {
                    dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i - 1).at(j - weight.at(i - 1)) + value.at(i - 1));
                } else {
                    dp.at(i).at(j) = dp.at(i - 1).at(j);
                }
            }
        }
    }
    cout << dp.at(N).at(W) << endl;
    

    return 0;
}
