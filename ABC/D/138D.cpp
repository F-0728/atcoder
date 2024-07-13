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
    ll N, Q;
    cin >> N >> Q;
    vvll G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vll counter(N, 0);
    rep(i, Q) {
        ll p, x;
        cin >> p >> x;
        p--;
        counter[p] += x;
    }

    vll ans(N, -1);
    ans.at(0) = counter.at(0);
    vll stack;
    stack.push_back(0);
    while (!stack.empty()) {
        ll node = stack.back();
        stack.pop_back();
        for (ll next : G.at(node)) {
            if (ans.at(next) != -1) {
                continue;
            }
            ans.at(next) = ans.at(node) + counter.at(next);
            stack.push_back(next);
        }
    }
    rep(i, N) {
        cout << ans.at(i) << " ";
    }


    return 0;
}
