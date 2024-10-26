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
    ll N, M;
    cin >> N >> M;
    vpll RL(N);
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        RL[i] = {r, l};
    }

    sort(RL.begin(), RL.end(), [](auto a, auto b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    });

    vll maxL(N + 1, 0);
    rep(i, N) {
        maxL[i + 1] = max(maxL[i], RL[i].second);
    }
    // outv(maxL);

    ll ans = 0;
    for (ll R = 1; R <= M; R++) {
        ll idx = lower_bound(RL.begin(), RL.end(), make_pair(R, 0LL)) - RL.begin();
        if (idx == N) {
            ans += R - maxL[N];
            continue;
        }
        if (RL[idx].first == R) {
            ans += R - maxL[idx + 1];
        } else {
            ans += R - maxL[idx];
        }
    }

    cout << ans << endl;

    return 0;
}
