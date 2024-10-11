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
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    ll ans = 0;
    rep(i, 1 << N) {
        vll count(26);
        rep(j, N) {
            if (i & (1 << j)) {
                rep(k, S[j].size()) {
                    count[S[j][k] - 'a']++;
                }
            }
        }
        ll res = 0;
        rep(j, 26) {
            if (count[j] == K) {
                res++;
            }
        }
        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}
