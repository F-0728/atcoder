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

vvll selected;
vll combination;
void dfs(int depth, int size, int min, int max) {
    if (depth == size) {
        selected.push_back(combination);
    } else {
        for (int i = min; i <= max; i++) {
            combination[depth] = i;
            dfs(depth + 1, size, i + 1, max);
        }
    }
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvll edges(M);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v, w};
    }

    combination.resize(N - 1);
    dfs(0, N - 1, 0, M - 1);
    ll ans = INF;
    for (auto& s : selected) {
        ll sum = 0;
        dsu d(N);
        for (auto& i : s) {
            d.merge(edges[i][0], edges[i][1]);
            sum += edges[i][2];
        }
        if (d.groups().size() != 1) continue;
        ans = min(ans, sum % K);
    }
    cout << ans << endl;

    return 0;
}
