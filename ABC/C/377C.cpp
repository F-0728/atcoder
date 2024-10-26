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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;

    ll ans = N * N;

    map<pll, ll> ng;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        vpll kouho = {{a, b}, {a + 2, b + 1}, {a + 1, b + 2}, {a - 1, b + 2}, {a - 2, b + 1}, {a - 2, b - 1}, {a - 1, b - 2}, {a + 1, b - 2}, {a + 2, b - 1}};
        for (auto [x, y] : kouho) {
            if (x < 1 || x > N || y < 1 || y > N) {
                continue;
            }
            ng[{x, y}] = 1;
        }
    }

    ll ngs = ng.size();
    cout << ans - ngs << endl;

    return 0;
}
