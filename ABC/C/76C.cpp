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
    ll m = T.size();
    if (n < m) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    vector<string> substrs(n - m + 1);
    rep(i, n - m + 1) { substrs[i] = S.substr(i, m); }

    vector<string> ansV;

    rep(i, n - m + 1) {
        rep(j, m) {
            if (substrs[i][j] != '?' && substrs[i][j] != T[j]) {
                break;
            }
            if (j == m - 1) {
                string ans = S;
                rep(k, m) { ans[i + k] = T[k]; }
                rep(k, n) {
                    if (ans[k] == '?') {
                        ans[k] = 'a';
                    }
                }
                ansV.push_back(ans);
            }
        }
    }

    sort(ansV.begin(), ansV.end());
    if (ansV.size() > 0) {
        cout << ansV[0] << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}
