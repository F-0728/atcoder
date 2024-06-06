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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N;
    cin >> N;
    vpll xy(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        xy.at(i) = make_pair(x, y);
    }
    vll sum(N);
    vll diff(N);
    rep(i, N) {
        sum.at(i) = xy.at(i).first + xy.at(i).second;
        diff.at(i) = xy.at(i).first - xy.at(i).second;
    }
    sort(sum.begin(), sum.end());
    sort(diff.begin(), diff.end());
    ll ans = max(sum.at(N - 1) - sum.at(0), diff.at(N - 1) - diff.at(0));
    cout << ans << endl;

    return 0;
}
