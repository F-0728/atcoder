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

int main() {
    ll N, M;
    cin >> N >> M;
    if (N < 1e6 && N * N < M) {
        cout << -1 << endl;
        return 0;
    }
    if (M <= N) {
        cout << M << endl;
        return 0;
    }

    ll ans = INF;
    rep(i, N + 1) {
        if (i == 0) continue;
        if (i > (M + i - 1) / i) break;
        if ((M + i - 1) / i <= N) {
            ans = min(ans, i * ((M + i - 1) / i));
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    

    return 0;
}
