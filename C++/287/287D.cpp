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
    string S, T;
    cin >> S >> T;
    ll n = S.size(), m = T.size();
    vector<bool> forward(m + 1, true), backward(m + 1, true);

    rep(i, m) {
        char p = S[i], s = S[n - i - 1];
        if (T[i] != p) {
            if (S[i] != '?' && T[i] != '?') {
                forward[i] = false;
            }
        }
        if (i > 0 && forward[i - 1] == false) {
            forward[i] = false;
        }

        if (T[m - i - 1] != s) {
            if (S[n - i - 1] != '?' && T[m - i - 1] != '?') {
                backward[i] = false;
            }
        }
        if (i > 0 && backward[i - 1] == false) {
            backward[i] = false;
        }
    }

    if (backward[m - 1]) {
        Yes;
    } else {
        No;
    }

    rep(i, m - 1) {
        if (forward[i] && backward[m - i - 2]) {
            Yes;
        } else {
            No;
        }
    }

    if (forward[m - 1]) {
        Yes;
    } else {
        No;
    }

    return 0;
}
