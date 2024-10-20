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
    string S;
    cin >> S;
    ll N = S.size();
    vll mod2019(N, 0);

    vll digit(N, 1);
    rep(i, N - 1) {
        digit[i + 1] = (digit[i] * 10) % 2019;
    } 

    map<ll, ll> count;
    count[0] = 1;

    ll now = 0;
    for (ll i = N - 1; i >= 0; i--) {
        now += (S[i] - '0') * digit[N - 1 - i];
        now %= 2019;
        count[now]++;
    }

    ll ans = 0;
    for (auto& [key, value] : count) {
        ans += value * (value - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
