#include <atcoder/all>
#include <chrono>
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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vll ansF(N, 1);
    vll ansB(N, 1);
    rep(i, N - 1) {
        if (S.at(i) == 'A') {
            ansF.at(i + 1) = ansF.at(i) + 1;
        }
    }
    for (ll i = N - 2; i >= 0; i--) {
        if (S.at(i) == 'B') {
            ansB.at(i) = ansB.at(i + 1) + 1;
        }
    }

    ll ans = 0;
    rep(i, N) {
        ans += max(ansF.at(i), ansB.at(i));
    }

    cout << ans << endl;


    return 0;
}
