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
    ll N, S, T;
    cin >> N >> S >> T;

    vvll line(N, vll(4));
    rep(i, N) {
        rep(j, 4) {
            cin >> line[i][j];
        }
    }

    vll order(N);
    rep(i, N) {
        order[i] = i;
    }

    double ans = INF;
    rep(j, 1 << N) {
        rep(i, N) {
            order[i] = i;
        }
        vvll line2 = line;
        rep(i, N) {
            if (j & (1 << i)) {
                swap(line2[i][0], line2[i][2]);
                swap(line2[i][1], line2[i][3]);
            }
        }
        do {
            double time = 0;
            pll now = {0, 0};
            rep(i, N) {
                ll d2 = (line2[order[i]][0] - now.first) * (line2[order[i]][0] - now.first) + (line2[order[i]][1] - now.second) * (line2[order[i]][1] - now.second);
                time += sqrt(d2) / S;
                now = {line2[order[i]][0], line2[order[i]][1]};
                d2 = (line2[order[i]][2] - now.first) * (line2[order[i]][2] - now.first) + (line2[order[i]][3] - now.second) * (line2[order[i]][3] - now.second);
                time += sqrt(d2) / T;
                now = {line2[order[i]][2], line2[order[i]][3]};
            }
            ans = min(ans, time);
        } while (next_permutation(order.begin(), order.end()));
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
