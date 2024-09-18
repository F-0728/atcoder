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
    ll N, M;
    cin >> N >> M;

    vll pow2(65);
    pow2[0] = 1;
    rep(i, 64) pow2[i + 1] = pow2[i] * 2;

    mint ans = 0;
    rep(i, 60) {
        if (M & (1LL << i)) {
            ll p = (N + 1) / pow2[i + 1];
            ll q = (N + 1) % pow2[i + 1];
            mint count = p * pow2[i] + max(0LL, q - pow2[i]);
            ans += count;
            // cout << i << " " << count.val() << endl;
        }
    }
    cout << ans.val() << endl;

    return 0;
}
