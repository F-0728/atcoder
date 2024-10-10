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
    ll N, M;
    cin >> N >> M;
    vvll explode(M);
    rep(i, M) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--; B--; C--;
        explode[i] = {A, B, C};
    }

    ll ans = 0;

    rep(i, 1 << N) {
        vll notbit;
        rep(j, N) {
            if (!(i & (1 << j))) {
                notbit.push_back(j);
            }
        }
        if (notbit.size() > N - 2) continue;
        bool ok = true;
        vector<bool> nextExplode(N, false);
        rep(j, M) {
            ll count = 0;
            rep(k, 3) {
                if (i & (1 << explode[j][k])) {
                    count++;
                }
            }
            if (count == 3) {
                ok = false;
                break;
            }
            if (count == 2) {
                rep(k, 3) {
                    if (!(i & (1 << explode[j][k]))) {
                        nextExplode[explode[j][k]] = true;
                    }
                }
            }
        }
        ll nextCount = 0;
        rep(j, N) {
            if (nextExplode[j]) {
                nextCount++;
            }
        }
        if (ok) {
            ans = max(ans, nextCount);
        }
    }

    cout << ans << endl;

    return 0;
}
