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

mint op(mint a, mint b) {
    return a + b;
}

mint e() {
    return 0;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    vector<segtree<mint, op, e>> dp(N + 1, segtree<mint, op, e>(K + 1));
    dp[0].set(0, 1);
    rep(i, N) {
        rep(j, K + 1) {
            ll left = max(0LL, j - A[i]);
            ll right = j;
            dp[i + 1].set(j, dp[i].prod(left, right + 1));
        }
    }

    cout << dp[N].get(K).val() << endl;

    return 0;
}
