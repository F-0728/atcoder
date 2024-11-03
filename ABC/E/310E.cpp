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
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vll s(N);
    rep(i, N) {
        s.at(i) = S.at(i) - '0';
    }
    // 0...累積NANDが0 1...累積NANDが1
    vvll dp(N, vll(2, 0));
    if (s.at(0) == 0) {
        dp.at(0).at(0) = 1;
    } else {
        dp.at(0).at(1) = 1;
    }
    rep(i, N - 1) {
        if (s.at(i + 1) == 0) {
            dp.at(i + 1).at(0)++;
            dp.at(i + 1).at(1) = dp.at(i).at(0) + dp.at(i).at(1);
        } else {
            dp.at(i + 1).at(0) = dp.at(i).at(1);
            dp.at(i + 1).at(1) = dp.at(i).at(0) + 1;
        }
    }

    ll ans = 0;
    rep(i, N) {
        ans += dp.at(i).at(1);
    }

    cout << ans << endl;

    return 0;
}
