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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    vll reached(M, -1);
    vll mod;
    ll steps = 1;
    ll cur = X;
    while (reached.at(cur) == -1) {
        reached.at(cur) = steps;
        mod.push_back(cur);
        cur = cur * cur % M;
        steps++;
    }
    ll cycle = steps - reached.at(cur);
    ll cycle_sum = 0;
    rep(i, cycle) {
        cycle_sum += mod.at(mod.size() - i - 1);
    }
    ll ans = 0;
    // cycleが回る前に終わる
    if (N < steps) {
        rep(i, N) {
            ans += mod.at(i);
        }
        cout << ans << endl;
        return 0;
    }

    // cycle突入前
    rep(i, reached.at(cur) - 1) {
        ans += mod.at(i);
    }

    // cycle
    N -= reached.at(cur) - 1;
    ans += cycle_sum * (N / cycle);

    // 途中で終わるやつ
    N %= cycle;
    rep(i, N) {
        ans += mod.at(reached.at(cur) - 1 + i);
    }

    cout << ans << endl;
    return 0;
}
