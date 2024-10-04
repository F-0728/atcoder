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

int main() {
    ll H, W, D;
    cin >> H >> W >> D;
    vvll A(H, vll(W));
    rep(i, H) rep(j, W) {
        cin >> A[i][j];
        A[i][j]--;
    }
    map<ll, pll> mp;
    rep(i, H) rep(j, W) mp[A[i][j]] = {i, j};

    vvll next(D, vll(H * W / D + 1, 0));
    rep(i, D) {
        for (ll j = i; j < H * W; j += D) {
            if (j + D < H * W) {
                next[i][j / D + 1] = next[i][j / D] + abs(mp[j].first - mp[j + D].first) + abs(mp[j].second - mp[j + D].second);
            }
        }
    }

    // rep(i, D) {
    //     outv(next[i]);
    // }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll L, R;
        cin >> L >> R;
        L--; R--;
        ll ans = next[L % D][R / D] - next[L % D][L / D];
        cout << ans << endl;
    }

    return 0;
}
