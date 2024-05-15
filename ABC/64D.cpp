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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    ll pos = 0;
    ll neg = 0;
    rep(i, N) {
        char c = S[i];
        if (c == '(') {
            pos++;
        } else {
            if (pos > 0) {
                pos--;
            } else {
                neg++;
            }
        }
    }
    rep(i, neg) { cout << '('; }
    cout << S;
    rep(i, pos) { cout << ')'; }

    return 0;
}
