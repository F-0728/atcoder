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

bool is_intersect(pll a, pll b, pll c, pll d) {
	ll s, t;
	s = (a.first - b.first) * (c.second - a.second) - (a.second - b.second) * (c.first - a.first);
	t = (a.first - b.first) * (d.second - a.second) - (a.second - b.second) * (d.first - a.first);
	if (s * t > 0)
		return false;

	s = (c.first - d.first) * (a.second - c.second) - (c.second - d.second) * (a.first - c.first);
	t = (c.first - d.first) * (b.second - c.second) - (c.second - d.second) * (b.first - c.first);
	if (s * t > 0)
		return false;
	return true;
}

int main() {
    ll Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    ll N;
    cin >> N;
    vpll v(N);
    rep(i, N) {
        cin >> v[i].first >> v[i].second;
    }
    pll OA = {Bx - Ax, By - Ay};

    ll count = 0;
    rep(i, N - 1) {
        if (is_intersect({Ax, Ay}, {Bx, By}, v[i], v[i + 1])) {
            count++;
        }
    }
    if (is_intersect({Ax, Ay}, {Bx, By}, v[N - 1], v[0])) {
        count++;
    }

    cout << count / 2 + 1 << endl;

    return 0;
}
