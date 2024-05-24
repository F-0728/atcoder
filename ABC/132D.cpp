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

vector<mint> comb(int n) {
    vector<vector<mint>> v(n + 1, vector<mint>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v[n];
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<mint> comb1 = comb(N - K + 1);
    vector<mint> comb2 = comb(K - 1);
    for (ll i = 1; i <= K; i++) {
        mint ans = 1;
        if (N - K + 1 < i) {
            cout << 0 << endl;
            continue;
        }
        ans *= comb1[i];
        ans *= comb2[i - 1];
      