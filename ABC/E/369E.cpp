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
    vector<vpll> G(N);
    vvll bridges(M);
    rep(i, M) {
        ll U, V, T;
        cin >> U >> V >> T;
        U--; V--;
        G[U].push_back({V, T});
        G[V].push_back({U, T});
        bridges[i] = {U, V, T};
    }

    vvll dist(N, vll(N, INF));
    rep(i, N) {
        dist[i][i] = 0;
        for (pll p : G[i]) {
            dist[i][p.first] = min(dist[i][p.first], p.second);
        }
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // rep(i, N) {
    //     outv(dist[i]);
    // }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll K;
        cin >> K;
        vll queries(K);
        rep(j, K) {
            cin >> queries[j];
            queries[j]--;
        }

        ll ans = INF;
        
        rep(i, 1 << K) {
            vll order(K);
            rep(j, K) order[j] = j;
            do {
                vvll bridgesQ(K);
                rep(j, K) {
                    bridgesQ[j] = bridges[queries[order[j]]];
                    if (i >> j & 1) {
                        swap(bridgesQ[j][0], bridgesQ[j][1]);
                    }
                }
                ll cost = 0;
                ll now = 0;
                rep(j, K) {
                    cost += dist[now][bridgesQ[j][0]];
                    cost += bridgesQ[j][2];
                    now = bridgesQ[j][1];
                }
                cost += dist[now][N - 1];
                ans = min(ans, cost);
            } while (next_permutation(order.begin(), order.end()));
        }

        cout << ans << endl;
    }

    return 0;
}

