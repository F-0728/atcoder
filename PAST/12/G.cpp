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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, L, K;
    cin >> N >> L >> K;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    ll ans = 0;
    vll order(L, 0);
    rep(i, K) order[i] = 1;
    sort(order.begin(), order.end());

    do {
        vector<char> T(L);
        vector<string> now(N, "");
        rep(i, N) {
            rep(j, L) {
                if (order[j] == 0) {
                    now[i] += S[i][j];
                }
            }
        }
        map<string, ll> count;
        rep(i, N) {
            count[now[i]]++;
        }
        ll res = 0;
        for (auto [k, v] : count) {
            res = max(res, v);
        }
        ans = max(ans, res);
    } while (next_permutation(order.begin(), order.end()));

    cout << ans << endl;

    return 0;
}
