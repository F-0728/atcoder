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
    ll N, M, K;
    cin >> N >> M >> K;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }

    if (M == K) {
        vll ans(N - M + 1);
        ll sum = 0;
        rep(i, M) {
           sum += A[i];
        }
        ans[0] = sum;
        rep(i, N - M) {
            sum -= A[i];
            sum += A[i + M];
            ans[i + 1] = sum;
        }
        outv(ans);
        return 0;
    }

    multiset<ll> m1, m2;
    rep(i, M) {
        m1.insert(A[i]);
    }
    rep(i, M - K) {
        m2.insert(*m1.rbegin());
        m1.erase(m1.find(*m1.rbegin()));
    }

    ll sum = 0;
    for (auto e : m1) {
        sum += e;
    }
    vll ans(N - M + 1);
    ans[0] = sum;
    rep(i, N - M) {
        ll prev = A[i];
        ll next = A[i + M];
        if (m1.count(prev)) {
            m1.erase(m1.find(prev));
            sum -= prev;
        } else {
            m2.erase(m2.find(prev));
        }
        if (m2.empty()) {
            if (*m1.rbegin() < next) {
                m2.insert(next);
            } else {
                m1.insert(next);
                sum += next;
                m2.insert(*m1.rbegin());
                sum -= *m1.rbegin();
                m1.erase(m1.find(*m1.rbegin()));
            }
        } else if (m1.empty()) {
            if (*m2.begin() > next) {
                m1.insert(next);
                sum += next;
            } else {
                m2.insert(next);
                m1.insert(*m2.begin());
                sum += *m2.begin();
                m2.erase(m2.find(*m2.begin()));
            }
        } else {
            if (*m1.rbegin() < next) {
                m2.insert(next);
            } else {
                m1.insert(next);
                sum += next;
                m2.insert(*m1.rbegin());
                sum -= *m1.rbegin();
                m1.erase(m1.find(*m1.rbegin()));
            }
        }
        if (m1.size() < K) {
            m1.insert(*m2.begin());
            sum += *m2.begin();
            m2.erase(m2.find(*m2.begin()));
        } else if (m1.size() > K) {
            m2.insert(*m1.rbegin());
            sum -= *m1.rbegin();
            m1.erase(m1.find(*m1.rbegin()));
        }
        ans[i + 1] = sum;
    }

    outv(ans);

    return 0;
}
