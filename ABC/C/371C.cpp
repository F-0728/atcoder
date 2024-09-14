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
    ll N;
    cin >> N;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    vector<vector<bool>> H(N, vector<bool>(N, false));

    ll Mg;
    cin >> Mg;
    rep(i, Mg) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u][v] = true;
        G[v][u] = true;
    }
    ll Mh;
    cin >> Mh;
    rep(i, Mh) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        H[u][v] = true;
        H[v][u] = true;
    }

    vvll A(N, vector<ll>(N, 0));
    rep(i, N - 1) {
        rep(j, N - i - 1) {
            cin >> A[i][i + j + 1];
            A[i + j + 1][i] = A[i][i + j + 1];
        }
    }

    vll permutation(N);
    rep(i, N) {
        permutation[i] = i;
    }

    ll ans = INF;

    do {
        ll res = 0;
        rep(i, N) {
            for (ll j = i + 1; j < N; j++) {
                if (G[i][j] != H[permutation[i]][permutation[j]]) {
                    res += A[permutation[i]][permutation[j]];
                }
            }
        }
        ans = min(ans, res);
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << ans << endl;

    return 0;
}
