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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    string s, t;
    cin >> s >> t;
    ll S = s.size();
    ll T = t.size();
    vvll dp(S + 1, vll(T + 1, 0));
    rep(i, S) {
        rep(j, T) {
            if (s.at(i) == t.at(j)) {
                dp.at(i + 1).at(j + 1) = dp.at(i).at(j) + 1;
            } else {
                if (dp.at(i).at(j + 1) > dp.at(i + 1).at(j)) {
                    dp.at(i + 1).at(j + 1) = dp.at(i).at(j + 1);
                } else {
                    dp.at(i + 1).at(j + 1) = dp.at(i + 1).at(j);
                }
            }
        }
    }
    string ans = "";
    ll i = S;
    ll j = T;
    while (i > 0 && j > 0) {
        if (dp.at(i).at(j) == dp.at(i - 1).at(j)) {
            i--;
        } else if (dp.at(i).at(j) == dp.at(i).at(j - 1)) {
            j--;
        } else {
            ans = s.at(i - 1) + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
    

    return 0;
}
