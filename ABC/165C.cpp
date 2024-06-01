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

vll combination(15);
vvll enumeration;
void dfs(ll depth, ll size, ll min, ll max) {
    if (depth == size) {
        enumeration.push_back(combination);
    } else {
        for (ll i = min; i <= max; i++) {
            combination.at(depth) = i;
            dfs(depth + 1, size, i, max);
        }
    }
}

int main() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vvll query(Q, vll(4));
    rep(i, Q) {
        rep(j, 4) { cin >> query.at(i).at(j); }
    }
    ll ans = 0;
    dfs(0, N, 1, M);
    for (vll v : enumeration) {
        ll score = 0;
        rep(i, Q) {
            if (v.at(query.at(i).at(1) - 1) - v.at(query.at(i).at(0) - 1) ==
                query.at(i).at(2)) {
                score += query.at(i).at(3);
            }
        }
        ans = max(ans, score);
    }
    cout << ans << endl;

    return 0;
}
