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

ll op(ll x, ll y) { return max(x, y); }
ll e() { return 0; }

int main() {
    ll N;
    cin >> N;
    vll height(N);
    rep(i, N) cin >> height.at(i);
    vll beauty(N);
    rep(i, N) cin >> beauty.at(i);
    ll pow = 1;
    while (pow < N) {
        pow *= 2;
    }
    segtree<ll, op, e> kukanMax(pow * 2);
    vll dp(N); 
    rep(i, N) {
        dp.at(i) = kukanMax.prod(0, height.at(i)) + beauty.at(i);
        kukanMax.set(height.at(i), dp.at(i));
    }
    ll ans = 0;
    rep(i, N) {
        ans = max(ans, dp.at(i));
    }
    cout << ans << endl;
    return 0;
}
