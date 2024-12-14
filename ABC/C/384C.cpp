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
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vll score = {a, b, c, d, e};

    map<string, ll> mp;
    rep(i, 1 << 5) {
        if (i == 0) continue;
        ll count = 0;
        string s = "";
        rep(j, 5) {
            if (i & (1 << j)) {
                count += score[j];
                s += 'A' + j;
            }
        }
        // cout << s << " " << count << endl;
        mp[s] = count;
    }

    vector<string> vec;
    for (auto [k, v] : mp) {
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end(), [&](string a, string b) {
        if (mp[a] == mp[b]) {
            return a < b;
        } else {
            return mp[a] > mp[b];
        }
    });

    rep(i, 31) {
        cout << vec[i] << endl;
    }

    return 0;
}
