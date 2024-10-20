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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ans = 0;

    vll leftJ(N, 0);
    vll rightI(N, 0);
    rep(i, N - 1) {
        leftJ[i + 1] = leftJ[i] + (S[i] == 'J');
    }
    for (ll i = N - 2; i >= 0; i--) {
        rightI[i] = rightI[i + 1] + (S[i + 1] == 'I');
    }

    // outv(leftJ);
    // outv(rightI);

    ll res = 0;
    rep(i, N) {
        if (S[i] == 'O') {
            res += (leftJ[i] + 1) * rightI[i];
        }
    }
    ans = max(ans, res);

    res = 0;
    rep(i, N) {
        if (S[i] == 'O') {
            res += leftJ[i] * (rightI[i] + 1);
        }
    }
    ans = max(ans, res);

    res = 0;
    rep(i, N - 1) {
        res = max(res, leftJ[i + 1] * rightI[i]);
    }
    ll sum = 0;
    rep(i, N) {
        if (S[i] == 'O') {
            sum += leftJ[i] * rightI[i];
        }
    }
    ans = max(ans, sum + res);

    cout << ans << endl;

    return 0;
}
