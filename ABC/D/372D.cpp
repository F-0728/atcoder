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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll op (ll a, ll b) { return max(a, b); }
ll e () { return 0; }

ll now = 0;
bool f(ll x) {
    return x <= now;
}

int main() {
    ll N;
    cin >> N;
    vll H(N);
    rep(i, N) cin >> H[i];

    segtree<ll, op, e> seg(H);
    vll ansCSum(N, 0);

    ll count = 0;
    for (ll i = N - 1; i >= 0; i--) {
        now = seg.get(i);
        ll left = seg.min_left<f>(i);
        if (left != 0) left--;
        ansCSum.at(left)++;
        ansCSum.at(i)--;
        // cout << left << " " << i << endl;
    }

    vll ans(N, 0);
    ans.at(0) = ansCSum.at(0);
    rep(i, N - 1) {
        ans.at(i + 1) = ans.at(i) + ansCSum.at(i + 1);
    }

    outv(ans);

    return 0;
}
