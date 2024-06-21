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
    ll N, S;
    cin >> N >> S;
    vpll fukubukuro(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        fukubukuro.at(i) = make_pair(a, b);
    }
    vvll dp(N + 1, vll(S + 1, 0));
    dp.at(0).at(0) = 1;
    rep(i, N) {
        rep(j, S + 1) {
            ll a = fukubukuro.at(i).first;
            ll b = fukubukuro.at(i).second;
            if (dp.at(i).at(j) == 1) {
                if (j + a <= S) dp.at(i + 1).at(j + a) = 1;
                if (j + b <= S) dp.at(i + 1).at(j + b) = 1;
            }
        }
    }
    string ans = "";
    if (dp.at(N).at(S) == 1) {
        ll sum = S;
        for (ll i = N - 1; i >= 0; i--) {
            ll a = fukubukuro.at(i).first;
            ll b = fukubukuro.at(i).second;
            if (sum - a >= 0 && dp.at(i).at(sum - a) == 1) {
                ans += "A";
                sum -= a;
            } else {
                ans += "B";
                sum -= b;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
