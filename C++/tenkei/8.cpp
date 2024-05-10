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
    string S;
    cin >> N >> S;
    vector<mint> atcoder(7, 0);
    rep(i, N) {
        if (S[i] == 'a') {
            atcoder[0] += 1;
        }
        else if (S[i] == 't') {
            atcoder[1] += atcoder[0];
        }
        else if (S[i] == 'c') {
            atcoder[2] += atcoder[1];
        }
        else if (S[i] == 'o') {
            atcoder[3] += atcoder[2];
        }
        else if (S[i] == 'd') {
            atcoder[4] += atcoder[3];
        }
        else if (S[i] == 'e') {
            atcoder[5] += atcoder[4];
        }
        else if (S[i] == 'r') {
            atcoder[6] += atcoder[5];
        }
    }

    cout << atcoder[6].val() << endl;

    return 0;
}
