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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;

    // 0...0の数と一緒, 1...0の数と違う
    vector<vector<mint>> dp(N, vector<mint>(2, 0));
    dp.at(0).at(0) = M;
    dp.at(0).at(1) = 0;
    rep(i, N - 1) {
        dp.at(i + 1).at(0) = dp.at(i).at(1);
        dp.at(i + 1).at(1) = dp.at(i).at(0) * (M - 1) + dp.at(i).at(1) * (M - 2);
    }

    cout << dp.at(N - 1).at(1).val() << endl;

    return 0;
}
