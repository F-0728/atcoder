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

ll N, K;
vll R;

void dfs(vll& v, ll idx, ll sum) {
    if (idx == N) {
        if (sum % K == 0) {
            outv(v);
        }
        return;
    }

    for (ll i = 1; i <= R.at(idx); i++) {
        v.at(idx) = i;
        dfs(v, idx + 1, sum + i);
    }
}

int main() {
    cin >> N >> K;
    R.resize(N);
    rep(i, N) cin >> R.at(i);

    vll v(N);
    rep(i, N) v.at(i) = 1;

    dfs(v, 0, 0);

    return 0;
}
