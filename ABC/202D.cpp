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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

vvll comb(int n, int r) {
    vvll v(n + 1, vll(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    ll index = 0;
    string ans = "";
    vvll v = comb(A + B, A);
    while (A + B > 0) {
        if (A > 0) {
            if (K <= v[A + B - 1][A - 1]) {
                ans += "a";
                A--;
            } else {
                ans += "b";
                K -= v[A + B - 1][A - 1];
                B--;
            }
        } else {
            ans += "b";
            B--;
        }
    }
    cout << ans << endl;

    return 0;
}
