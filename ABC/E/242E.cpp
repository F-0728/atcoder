#include <atcoder/all>
#include <bitset>
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
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll N;
        cin >> N;
        string S;
        cin >> S;
        mint ans = 0;
        if (N % 2 == 1) {
            rep(j, N / 2) {
                ll rem = N / 2 + 1;
                ll c = S[j] - 'A';
                ans += pow_mod(26, rem - j - 1, 998244353) * c;
            }
            ll c = S[N / 2] - 'A';
            ans += c;
            bool ok = true;
            rep(i, N / 2) {
                if (S[N / 2 - 1 - i] > S[N / 2 + i + 1]) {
                    ok = false;
                    break;
                } else if (S[N / 2 - 1 - i] < S[N / 2 + i + 1]) {
                    break;
                }
            }
            if (ok) {
                ans += 1;
            }
        } else {
            rep(j, N / 2) {
                ll rem = N / 2;
                ll c = S[j] - 'A';
                ans += pow_mod(26, rem - j - 1, 998244353) * c;
                // cout << ans.val() << endl;
            }
            bool ok = true;
            rep(i, N / 2) {
                if (S[N / 2 - 1 - i] > S[N / 2 + i]) {
                    ok = false;
                    break;
                } else if (S[N / 2 - 1 - i] < S[N / 2 + i]) {
                    break;
                }
            }
            if (ok) {
                ans += 1;
            }
        }
        cout << ans.val() << endl;
    }

    return 0;
}
