#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    mint ans = 0;
    rep(i, 60) {
        vll count1(N, 0);
        rep(j, N) {
            count1[j] = (A[j] >> i) & 1;
        }
        vll cSum1(N + 1, 0);
        rep(j, N) {
            cSum1[j + 1] = cSum1[j] + count1[j];
        }
        rep(j, N) {
            if (A[j] & (1LL << i)) {
                ans += mint(1LL << i) * (j + 1 - cSum1[j + 1]);
            } else {
                ans += mint(1LL << i) * cSum1[j + 1];
            }
        }
    }

    cout << ans.val() << endl;
    

    return 0;
}
