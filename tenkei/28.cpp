#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> papers(1001, vector<ll>(1001, 0));
    rep(i, N) {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        papers[lx][ly]++;
        papers[rx][ly]--;
        papers[lx][ry]--;
        papers[rx][ry]++;
    }
    rep(i, 1001) {
        rep(j, 1000) {
            papers[i][j + 1] += papers[i][j];
        }
    }

    rep(i, 1000) {
        rep(j, 1001) {
            papers[i + 1][j] += papers[i][j];
        }
    }

    vector<ll> ans(N + 1, 0);
    rep(i, 1001) {
        rep(j, 1001) {
            if (papers[i][j] == 0) {
                continue;
            }
            ans[papers[i][j]]++;
        }
    }

    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
