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
    string T;
    cin >> T;
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);
    vll forward(N), backward(N);
    rep(i, N) {
        ll m = S.at(i).size();
        ll idx = -1;
        rep(j, m) {
            if (idx == T.size() - 1) break;
            if (T.at(idx + 1) == S.at(i).at(j)) {
                idx++;
            }
        }
        forward.at(i) = idx + 1;
        idx = -1;
        rep(j, m) {
            if (idx == T.size() - 1) break;
            if (T.at(T.size() - 2 - idx) == S.at(i).at(m - 1 - j)) {
                idx++;
            }
        }
        backward.at(i) = idx + 1;
    }
    ll ans = 0;
    sort(backward.begin(), backward.end());
    rep(i, N) {
        ll lower = lower_bound(backward.begin(), backward.end(), T.size() - forward.at(i)) - backward.begin();
        ans += N - lower;
    }
    cout << ans << endl;

    return 0;
}
