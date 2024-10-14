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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

vector<vvld> dp;
ll N;
ld dp_mem(ll i, ll j, ll k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i > N || j > N || k > N) return 0;
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    ld from0 = 0, from1 = 0, from2 = 0;
    if (i > 0) from0 = dp_mem(i - 1, j, k) * i;
    if (j > 0 && i < N) from1 = dp_mem(i + 1, j - 1, k) * j;
    if (k > 0 && j < N) from2 = dp_mem(i, j + 1, k - 1) * k;
    dp[i][j][k] = (from0 + from1 + from2 + N) / (i + j + k);
    return dp[i][j][k];
}

int main() {
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    dp = vector<vvld>(N + 1, vvld(N + 1, vld(N + 1, -1)));
    ll count1 = 0, count2 = 0, count3 = 0;
    rep(i, N) {
        if (A[i] == 1) count1++;
        if (A[i] == 2) count2++;
        if (A[i] == 3) count3++;
    }
    dp[0][0][0] = 0;

    rep(i, N + 1) {
        rep(j, N + 1) {
            rep(k, N + 1) {
                if (i + j + k == 0) continue;
                if (i + j + k > N) break;
                ld from0 = 0, from1 = 0, from2 = 0;
                if (i > 0) from0 = dp_mem(i - 1, j, k) * i;
                if (j > 0) from1 = dp_mem(i + 1, j - 1, k) * j;
                if (k > 0) from2 = dp_mem(i, j + 1, k - 1) * k;
                dp[i][j][k] = (from0 + from1 + from2 + N) / (i + j + k);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[count1][count2][count3] << endl;

    return 0;
}
