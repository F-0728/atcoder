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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll steps(N, -1);
    vll candies(N, -1);
    ll nowIdx = 0;
    ll nowStep = 0;
    ll nowCandy = 0;
    while (steps[nowIdx] == -1) {
        nowStep++;
        steps[nowIdx] = nowStep;
        nowCandy += A[nowIdx];
        candies[nowIdx] = nowCandy;
        nowIdx = nowCandy % N;
    }
    ll cycleStep = nowStep - steps[nowIdx] + 1;
    ll cycleCandy = nowCandy - candies[nowIdx] + A[nowIdx];

    ll ans = 0;
    ll now = 0;
    while (now != nowIdx) {
        ans += A[now];
        now = ans % N;
        K--;
        if (K == 0) {
            cout << ans << endl;
            return 0;
        }
    }
    ans += (K / cycleStep) * cycleCandy;
    K %= cycleStep;
    now = nowIdx;
    rep(i, K) {
        ans += A[now];
        now = ans % N;
    }

    cout << ans << endl;

    return 0;
}
