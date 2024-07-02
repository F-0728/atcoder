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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    string S, T;
    cin >> S >> T;
    if (S == T) {
        Yes;
        return 0;
    }
    ll N = S.size();
    rep(s, N) {
        if (s == 0) continue;
        vector<string> substrs;
        ll idx = 0;
        while (idx < N) {
            substrs.push_back(S.substr(idx, min(s, N - idx)));
            idx += s;
        }
        // if (substrs.back().size() < s) {
        //     substrs.pop_back();
        // }
        if (substrs.size() < T.size()) continue;
        rep(c, substrs.back().size()) {
            bool ok = true;
            rep(i, substrs.size()) {
                // cout << s << endl;
                // cout << substrs[i][c] << " " << T[i] << endl;
                if (substrs[i][c] != T[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                Yes;
                return 0;
            }
        }
        substrs.pop_back();
        if (substrs.size() < T.size()) continue;
        rep(c, substrs.back().size()) {
            bool ok = true;
            rep(i, substrs.size()) {
                // cout << s << endl;
                // cout << substrs[i][c] << " " << T[i] << endl;
                if (substrs[i][c] != T[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                Yes;
                return 0;
            }
        }
    }
    No;

    return 0;
}
