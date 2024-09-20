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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vvll G(N);
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vll index(N - 1);
    rep(i, N - 1) {
        index[i] = i + 1;
    }
    ll ans = 0;
    do {
        ll now = 0;
        bool ok = true;
        rep(i, N - 1) {
            ll next = index[i];
            if (find(G[now].begin(), G[now].end(), next) == G[now].end()) {
                ok = false;
                break;
            }
            now = next;
        }
        if (ok) {
            ans++;
        }
    } while (next_permutation(index.begin(), index.end()));

    cout << ans << endl;

    return 0;
}
