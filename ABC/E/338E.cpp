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

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

int main() {
    ll N;
    cin >> N;
    vpll chords(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) {
            swap(a, b);
        }
        chords[i] = {a, b};
    }

    segtree<ll, op, e> seg(2 * N);

    sort(chords.begin(), chords.end());

    rep(i, N) {
        ll a = chords[i].first;
        ll b = chords[i].second;
        ll prod = seg.prod(a, b + 1);
        if (prod == 0) {
            seg.set(a, 1);
            seg.set(b, 1);
        } else {
            Yes;
            return 0;
        }
    }

    No;

    return 0;
}
