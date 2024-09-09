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
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum[i + 1] = cSum[i] + A[i];
    }

    vector<mint> dp(N + 1, 0);
    dp[0] = 1;
    vector<mint> dp_cSum(N + 1, 0);
    dp_cSum[0] = 1;

    map<ll, ll> mp;
    mp[0] = 1;

    for (ll i = 1; i <= N; i++) {
        dp[i] = dp_cSum[i - 1];
        if (mp.count(cSum[i] - K) > 0) {
            dp[i] -= mp[cSum[i] - K];
        }
        dp_cSum[i] = dp_cSum[i - 1] + dp[i];
        mp[cSum[i]] += dp[i].val();
    }

    cout << dp[N].val() << endl;
    
    return 0;
}
