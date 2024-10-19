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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vvll countOSum(H, vll(W + 1, 0));
    vvll countISum(H + 1, vll(W, 0));

    vll countO(H, 0), countI(W, 0);
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'O') {
                countO[i]++;
            }
            if (S[i][j] == 'I') {
                countI[j]++;
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            countOSum[i][j + 1] = countOSum[i][j] + (S[i][j] == 'O');
        }
    }

    rep(j, W) {
        rep(i, H) {
            countISum[i + 1][j] = countISum[i][j] + (S[i][j] == 'I');
        }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'J') {
                ans += (countOSum[i][W] - countOSum[i][j + 1]) * (countISum[H][j] - countISum[i + 1][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
