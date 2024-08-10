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
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);

    ll maxLen = 0;
    rep(i, N) maxLen = max(maxLen, (ll)S.at(i).size());

    vector<string> T(maxLen);
    rep(i, N) {
        ll len = S.at(i).size();
        rep(j, len) {
            T.at(j) = S.at(i).at(j) + T.at(j);
        }
        rep(j, maxLen - len) {
            T.at(len + j) = "*" + T.at(len + j);
        }
    }
    rep(i, maxLen) {
        string s = T.at(i);
        ll idx = s.size() - 1;
        while (s.at(idx) == '*') {
            T.at(i).pop_back();
            idx--;
        }
    }
    rep(i, maxLen) {
        cout << T.at(i) << endl;
    }

    return 0;
}
