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
    ll N, C;
    cin >> N >> C;
    vpll plan;
    rep(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        plan.push_back(make_pair(a, c));
        plan.push_back(make_pair(b + 1, -c));
    }
    sort(plan.begin(), plan.end());
    ll ans = 0;
    ll dailyPrice = 0;
    ll current = 0;
    for (pair<ll, ll> p : plan) {
        if (p.first != current) {
            ans += min(C, dailyPrice) * (p.first - current);
            current = p.first;
        }
        dailyPrice += p.second;
    }
    cout << ans << endl;

    return 0;
}
