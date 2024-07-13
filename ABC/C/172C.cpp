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
    ll N, M, K;
    cin >> N >> M >> K;
    vll A(N), B(M);
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> B.at(i);
    vll sumA(N + 1, 0), sumB(M + 1, 0);
    rep(i, N) sumA.at(i + 1) = sumA.at(i) + A.at(i);
    rep(i, M) sumB.at(i + 1) = sumB.at(i) + B.at(i);
    ll ans = 0;
    rep(i, N + 1) {
        if (sumA.at(i) > K) break;
        ll j = upper_bound(sumB.begin(), sumB.end(), K - sumA.at(i)) - sumB.begin() - 1;
        ans = max(ans, i + j);
    }
    cout << ans << endl;

    return 0;
}
