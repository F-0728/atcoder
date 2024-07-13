#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<pair<ll, ll>>> cities(N + 1);
    vpll ans(M);
    rep(i, M) {
        ll P, Y;
        cin >> P >> Y;
        cities[P].push_back({Y, i});
    }
    rep(i, N + 1) {
        sort(cities[i].begin(), cities[i].end());
        rep(j, cities[i].size()) {
            ans[cities[i][j].second] = {i, j + 1};
        }
    }

    rep(i, M) {
        cout << setfill('0') << setw(6) << ans[i].first;
        cout << setfill('0') << setw(6) << ans[i].second << endl;
    }

    return 0;
}
