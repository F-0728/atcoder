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
    ll N, K;
    cin >> N >> K;
    vll s(N);
    rep(i, N) cin >> s[i];

    if (count(s.begin(), s.end(), 0) > 0) {
        cout << N << endl;
        return 0;
    }

    ll mul = 1;
    ll l = 0, r = 0;
    ll ans = 0;
    ll count = 0;
    while (r < N) {
        while (r < N && mul * s[r] <= K) {
            mul *= s[r];
            r++;
        }
        ans = max(ans, r - l);
        if (r == l) {
            r++;
        } else {
            mul /= s[l];
        }
        l++;
    }

    cout << ans << endl;

    return 0;
}
