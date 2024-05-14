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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    string S, T;
    cin >> S >> T;

    ll n = S.size();

    string doubleS = S + S;
    rep(i, n) {
        if (doubleS.substr(i, n) == T) {
            Yes;
            return 0;
        }
    }
    No;

    return 0;
}
