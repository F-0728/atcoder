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
    ll N;
    cin >> N;
    vvll count(10, vll(10, 0));
    for (ll i = 1; i <= N; i++) {
        string s = to_string(i);
        count[s[0] - '0'][s[s.size() - 1] - '0']++;
    }
    ll ans = 0;
    rep(i, 10) {
        rep(j, 10) {
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}
