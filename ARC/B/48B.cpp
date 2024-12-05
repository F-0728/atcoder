#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vpll p(N);
    rep(i, N) {
        ll R, H;
        cin >> R >> H;
        p[i] = {R, H};
    }

    vvll p2(3, vll(1e5 + 1, 0));
    rep(i, N) {
        p2[p[i].second - 1][p[i].first]++;
    }
    vll cSum(1e5 + 2, 0);
    rep(i, 1e5 + 1) {
        cSum[i + 1] = cSum[i] + p2[0][i] + p2[1][i] + p2[2][i];
    }

    // rep(i, 10) {
    //     cout << cSum[i] << " ";
    // }
    // cout << endl;

    rep(i, N) {
        ll win = cSum[p[i].first];
        ll lose = cSum[1e5 + 1] - cSum[p[i].first + 1];
        if (p[i].second == 1) {
            win += p2[1][p[i].first];
            lose += p2[2][p[i].first];
        } else if (p[i].second == 2) {
            win += p2[2][p[i].first];
            lose += p2[0][p[i].first];
        } else {
            win += p2[0][p[i].first];
            lose += p2[1][p[i].first];
        }
        cout << win << " " << lose << " " << N - win - lose - 1 << endl;
    }

    return 0;
}
