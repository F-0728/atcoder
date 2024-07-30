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
    string T;
    cin >> T;
    ll N;
    cin >> N;
    vector<vector<string>> S(N);
    string input;
    rep(i, N) {
        ll A;
        cin >> A;
        rep(j, A) {
            cin >> input;
            S.at(i).push_back(input);
        }
    }
    vvll dp(N + 1, vll(T.size() + 1, INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, T.size() + 1) {
            dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j));
            for (string s : S.at(i)) {
                ll M = s.size();
                if (j + M > T.size()) continue;
                if (T.substr(j, M) == s) {
                    dp.at(i + 1).at(j + M) = min(dp.at(i + 1).at(j + M), dp.at(i).at(j) + 1);
                }
            }
        }
    }
\
    if (dp.at(N).at(T.size()) == INF) {
        cout << -1 << endl;
    } else {
        cout << dp.at(N).at(T.size()) << endl;
    }
    return 0;
}
