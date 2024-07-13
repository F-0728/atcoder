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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vvll D(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            cin >> D[i][j];
        }
    }

    vll carDist(N, INF);
    vll trainDist(N, INF);
    carDist.at(0) = 0;
    trainDist.at(N - 1) = 0;
    priority_queue<pll, vpll, greater<pll>> carQue;
    priority_queue<pll, vpll, greater<pll>> trainQue;
    carQue.push({0, 0});
    trainQue.push({0, N - 1});
    while (!carQue.empty()) {
        auto [dist, v] = carQue.top();
        carQue.pop();
        if (carDist.at(v) < dist) {
            continue;
        }
        rep(i, N) {
            if (carDist.at(i) > dist + A * D.at(v).at(i)) {
                carDist.at(i) = dist + A * D.at(v).at(i);
                carQue.push({carDist.at(i), i});
            }
        }
    }
    while (!trainQue.empty()) {
        auto [dist, v] = trainQue.top();
        trainQue.pop();
        if (trainDist.at(v) < dist) {
            continue;
        }
        rep(i, N) {
            if (trainDist.at(i) > dist + B * D.at(v).at(i) + C) {
                trainDist.at(i) = dist + B * D.at(v).at(i) + C;
                trainQue.push({trainDist.at(i), i});
            }
        }
    }
    ll ans = INF;
    rep(i, N) {
        ans = min(carDist.at(i) + trainDist.at(i), ans);
    }
    cout << ans << endl;

    return 0;
}
