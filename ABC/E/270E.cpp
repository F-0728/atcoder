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
    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll l = -1, r = 1e12 + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll count = 0;
        rep(i, N) {
            count += min(A[i], mid);
        }
        if (count >= K) {
            r = mid;
        } else {
            l = mid;
        }
    }

    ll now = 0;
    rep(i, N) {
        if (A[i] >= l) {
            now += l;
            A[i] -= l;
        } else {
            now += A[i];
            A[i] = 0;
        }
    }
    rep(i, N) {
        if (now == K) break;
        if (A[i] > 0) {
            now++;
            A[i]--;
        }
    }

    outv(A);

    return 0;
}
