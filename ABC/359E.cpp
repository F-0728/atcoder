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

ll op (ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -INF;
}

ll currentH;
bool f(ll x) {
    return x < currentH; 
}

int main() {
    ll N;
    cin >> N;
    vll H(N);
    rep(i, N) cin >> H.at(i);
    segtree<ll, op, e> water(H);

    vll ans(N + 1, 0);
    ans.at(0) = 1;
    rep(i, N) {
        currentH = H.at(i);
        ll left = water.min_left<f>(i);
        ll res = currentH * (i - left + 1) + ans.at(left);
        ans.at(i + 1) = res;
    }
    rep(i, N) {
        cout << ans.at(i + 1) << " ";
    }

    return 0;
}
