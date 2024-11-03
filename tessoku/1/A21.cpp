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
    vpll blocks(N);
    rep(i, N) {
        ll p, a;
        cin >> p >> a;
        blocks.at(i) = {p, a};
    }

    vvll dp(N, vll(N, 0));
    rep(block, N + 1) {
        if (block < 2) continue;
        rep(l, N) {
            if (l + block > N) break;
            ll r = l + block - 1;
            ll scoreL = 0;
            ll scoreR = 0;
            if (l <= blocks.at(l).first - 1 && blocks.at(l).first - 1 <= r) {
                scoreL = blocks.at(l).second;
            }
            if (l <= blocks.at(r).first - 1 && blocks.at(r).first - 1 <= r) {
                scoreR = blocks.at(r).second;
            }
            dp.at(l).at(r) = max(dp.at(l).at(r - 1) + scoreR, dp.at(l + 1).at(r) + scoreL);
        }
    } 
    // outv(dp.at(0));
    cout << dp.at(0).at(N - 1) << endl;


    return 0;
}
