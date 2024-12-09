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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }

    set<string> T;
    rep(i, M) {
        string s;
        cin >> s;
        T.insert(s);
    }

    vll underScore(N - 1, 1);
    ll rem = 16;
    rep(i, N) {
        rem -= S[i].size();
    }

    queue<vll> q;
    q.push(underScore);
    while (!q.empty()) {
        vll v = q.front();
        q.pop();
        ll sum = 0;
        rep(i, N - 1) {
            sum += v[i];
        }
        if (sum > rem) continue;
        vll order(N);
        rep(i, N) {
            order[i] = i;
        }
        do {
            string s = "";
            rep(i, N - 1) {
                s += S[order[i]];
                rep(j, v[i]) {
                    s += "_";
                }
            }
            s += S[order[N - 1]];
            if (T.find(s) == T.end()) {
                if (s.size() >= 3) {
                    cout << s << endl;
                    return 0;
                }
            }
        } while (next_permutation(order.begin(), order.end()));
        rep(i, N - 1) {
            vll w = v;
            w[i]++;
            q.push(w);
        }
    }

    cout << -1 << endl;

    return 0;
}
