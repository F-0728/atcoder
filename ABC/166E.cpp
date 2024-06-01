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
    vll sum;
    vll diff;
    rep(i, N) {
        ll A;
        cin >> A;
        sum.push_back(i + A);
        diff.push_back(i - A);
    }
    sort(diff.begin(), diff.end());
    ll ans = 0;
    rep(i, sum.size()) {
        ll M = upper_bound(diff.begin(), diff.end(), sum.at(i)) - diff.begin();
        ll m = lower_bound(diff.begin(), diff.end(), sum.at(i)) - diff.begin();
        ans += M - m;
    }
    cout << ans << endl;

    

    return 0;
}
