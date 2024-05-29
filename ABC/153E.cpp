#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll H, N;
    cin >> H >> N;
    vpll magic(N);
    rep(i, N) cin >> magic[i].first >> magic[i].second;

    vll dp(H + 1, 1e9);
    dp.at(0) = 0;
    rep(i, N) {
        rep(j, H + 1) {
            dp.at(j) = min(dp.at(j), dp.at(max(0LL, j - magic.at(i).first)) + magic.at(i).second); 
        }
    }
    cout << dp.at(H) << endl;

    return 0;
}
