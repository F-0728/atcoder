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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vvll dp(N, vll(3, 0));
    if (S.at(0) == 'R') {
        dp.at(0).at(0) = 0;
        dp.at(0).at(1) = -INF;
        dp.at(0).at(2) = 1;
    }
    if (S.at(0) == 'S') {
        dp.at(0).at(0) = 1;
        dp.at(0).at(1) = 0;
        dp.at(0).at(2) = -INF;
    }
    if (S.at(0) == 'P') {
        dp.at(0).at(0) = -INF;
        dp.at(0).at(1) = 1;
        dp.at(0).at(2) = 0;
    }
    rep(i, N - 1) {
        if (S.at(i + 1) == 'R') {
            dp.at(i + 1).at(0) = max(dp.at(i).at(1), dp.at(i).at(2));
            dp.at(i + 1).at(1) = -INF;
            dp.at(i + 1).at(2) = max(dp.at(i).at(0), dp.at(i).at(1)) + 1;
        }
        if (S.at(i + 1) == 'S') {
            dp.at(i + 1).at(0) = max(dp.at(i).at(1), dp.at(i).at(2)) + 1;
            dp.at(i + 1).at(1) = max(dp.at(i).at(0), dp.at(i).at(2));
            dp.at(i + 1).at(2) = -INF;
        }
        if (S.at(i + 1) == 'P') {
            dp.at(i + 1).at(0) = -INF;
            dp.at(i + 1).at(1) = max(dp.at(i).at(0), dp.at(i).at(2)) + 1;
            dp.at(i + 1).at(2) = max(dp.at(i).at(0), dp.at(i).at(1));
        }
    }
    ll ans = max(dp.at(N - 1).at(0), max(dp.at(N - 1).at(1), dp.at(N - 1).at(2)));
    cout << ans << endl;

    return 0;
}
