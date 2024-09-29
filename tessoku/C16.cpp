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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvll flights(M);
    vvll time;
    rep(i, M) {
        ll A, S, B, T;
        cin >> A >> S >> B >> T;
        A--;
        B--;
        T += K;
        flights[i] = {A, S, B, T};
        time.push_back({S, 2, i});
        time.push_back({T, 1, i});
    }
    sort(time.begin(), time.end());

    vll aIdx(M, -1);
    vll maxFlights(2 * N + 2 * M, 0);

    vvll G(N);
    rep(i, 2 * M) {
        ll type = time[i][1];
        ll idx = time[i][2];

        if (type == 2) {
            ll A = flights[idx][0];
            if (G[A].empty()) {
                maxFlights[N + i] = 0;
            } else {
                maxFlights[N + i] = maxFlights[G[A].back()];
            }
            G[A].push_back(N + i);
            aIdx[idx] = N + i;
        } else {
            ll A = flights[idx][0];
            ll B = flights[idx][2];
            if (G[B].empty()) {
                maxFlights[N + i] = maxFlights[aIdx[idx]] + 1;
            } else {
                maxFlights[N + i] = max(maxFlights[aIdx[idx]] + 1, maxFlights[G[B].back()]);
            }
            G[B].push_back(N + i);
        }
    }
    ll ans = -INF;
    rep(i, N) {
        if (G[i].empty()) continue;
        ans = max(ans, maxFlights[G[i].back()]);
    }

    cout << ans << endl;
    

    return 0;
}
