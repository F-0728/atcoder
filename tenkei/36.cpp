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
    ll N, Q;
    cin >> N >> Q;
    vll sum(N);
    vll diff(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        sum.at(i) = x + y;
        diff.at(i) = x - y;
    }
    ll sum_min = *min_element(sum.begin(), sum.end());
    ll sum_max = *max_element(sum.begin(), sum.end());
    ll diff_min = *min_element(diff.begin(), diff.end());
    ll diff_max = *max_element(diff.begin(), diff.end());
    rep(i, Q) {
        ll q;
        cin >> q;
        q--;
        ll ans = max({abs(sum.at(q) - sum_min), abs(sum.at(q) - sum_max), abs(diff.at(q) - diff_min), abs(diff.at(q) - diff_max)});
        cout << ans << endl;
    }
    return 0;
}
