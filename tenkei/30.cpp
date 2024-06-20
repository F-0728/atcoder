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

vector<ll> furui(ll n) {
    vector<ll> res(n + 1, 0);
    for (ll i = 2; i <= n; i++) {
        if (res.at(i) == 0) {
            res.at(i) = 1;
            for (ll j = 2 * i; j <= n; j += i) {
                res.at(j) += 1;
            }
        }
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> res = furui(N);
    ll ans = 0;
    rep(i, N + 1) {
        if (res.at(i) >= K) {
            ans++;
        }
    }
    cout << ans << endl;
    // outv(res);
    return 0;
}
