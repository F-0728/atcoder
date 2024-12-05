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

ll N, K;

vll done;
void solve(ll n, vll& index, vll& A) {
    // cout << "n: " << n << " K: " << K << endl;
    // outv(A);
    if (n == 0) {
        for (ll i = 0; i < done.size(); i++) {
            cout << done[i] + 1 << " ";
        }
        cout << endl;
        exit(0);
    }
    ll sum = 0;
    ll i = 0;
    while (sum < K) {
        if (index[i] != -1) {
            if (index[i] == N - n) sum += N + (n - 1) * (n - 2) / 2;
            else sum++;
        }
        if (sum >= K) break;
        i++;
    }
    if (sum == K) {
        rep(i, done.size()) {
            cout << done[i] + 1 << " ";
        }
        ll idx = index[i];
        // cout << "idx: " << idx << endl;
        // cout << "n: " << n << endl;
        // outv(A);
        for (ll j = n - (N - idx); j >= 0; j--) {
            cout << A[j] + 1 << " ";
        }
        for (ll j = n - (N - idx) + 1; j < n; j++) {
            cout << A[j] + 1 << " ";
        }
        cout << endl;
        exit(0);
    }
    done.push_back(A[0]);
    index[A[0]] = -1;
    A.erase(A.begin());
    sum -= N + (n - 1) * (n - 2) / 2;
    K -= sum;
    solve(n - 1, index, A);
}

int main() {
    cin >> N >> K;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    vll index(N);
    rep(i, N) { index[A[i]] = i; }

    solve(N, index, A);

    return 0;
}
