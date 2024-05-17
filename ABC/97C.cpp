#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    string S;
    ll K;
    cin >> S >> K;

    ll N = S.size();
    set<string> substrs;
    rep(i, N) {
        for (ll j = 1; j <= K; j++) {
            if (i + j <= N) {
                substrs.insert(S.substr(i, j));
            }
        }
    }
    auto itr = substrs.begin();
    rep(i, K - 1) {
        itr++;
    }
    cout << *itr << endl;

    return 0;
}
