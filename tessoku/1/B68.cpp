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
    vll P(N);
    rep(i, N) {
        cin >> P[i];
        P[i] = 150 - P[i];
    }

    // outv(P);

    vector<vpll> G(N + 2);
    rep(i, N) {
        G[i + 1].push_back({N + 1, P[i]});
        G[0].push_back({i + 1, 150});
    }

    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        G[A].push_back({B, inf});
    }

    mf_graph<ll> mf(N + 2);
    rep(i, N + 2) {
        for (auto g : G[i]) {
            mf.add_edge(i, g.first, g.second);
        }
    }

    ll flow = mf.flow(0, N + 1);
    // cout << flow << endl;
    cout << 150 * N - flow << endl;

    return 0;
}
