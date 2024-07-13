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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);
    vector<vector<bool>> ableToStop(N, vector<bool>(M, false));
    vvll rocksH(N);
    vvll rocksV(M);
    rep(i, N) {
        rep(j, M) {
            if (S.at(i).at(j) == '#') {
                rocksH.at(i).push_back(j);
                rocksV.at(j).push_back(i);
            }
        }
    }
    queue<pll> q;
    q.push({1, 1});
    while (!q.empty()) {
        pll p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (S.at(x).at(y) == '#') continue;
        if (ableToStop.at(x).at(y)) continue;
        ableToStop.at(x).at(y) = true;
        q.push({*upper_bound(rocksV.at(y).begin(), rocksV.at(y).end(), x) - 1, y});
        q.push({rocksV.at(y).at(upper_bound(rocksV.at(y).begin(), rocksV.at(y).end(), x) - rocksV.at(y).begin() - 1) + 1, y});
        q.push({x, *upper_bound(rocksH.at(x).begin(), rocksH.at(x).end(), y) - 1});
        q.push({x, rocksH.at(x).at(upper_bound(rocksH.at(x).begin(), rocksH.at(x).end(), y) - rocksH.at(x).begin() - 1) + 1});
    }
    vector<vector<bool>> ableToPass(N, vector<bool>(M, false));
    vector<vector<bool>> ans(N, vector<bool>(M, false));
    rep(i, N) {
        rep(j, M) {
            if (ableToStop.at(i).at(j)) {
                if (ableToPass.at(i).at(j)) continue;
                ableToPass.at(i).at(j) = true;
                ans.at(i).at(j) = true;
                ll x = i;
                ll y = j;
                while (x > 0) {
                    x--;
                    if (S.at(x).at(y) == '#') break;
                    ableToPass.at(x).at(y) = true;
                    ans.at(x).at(y) = true;
                }
                x = i;
                while (x < N - 1) {
                    x++;
                    if (S.at(x).at(y) == '#') break;
                    ableToPass.at(x).at(y) = true;
                    ans.at(x).at(y) = true;
                }
            }
        }
    } 
    rep(i, N) {
        rep(j, M) {
            ableToPass.at(i).at(j) = false;
        }
    }
    rep(i, N) {
        rep(j, M) {
            if (ableToStop.at(i).at(j)) {
                if (ableToPass.at(i).at(j)) continue;
                ableToPass.at(i).at(j) = true;
                ans.at(i).at(j) = true;
                ll x = i;
                ll y = j;
                while (y > 0) {
                    y--;
                    if (S.at(x).at(y) == '#') break;
                    ableToPass.at(x).at(y) = true;
                    ans.at(x).at(y) = true;
                }
                y = j;
                while (y < M - 1) {
                    y++;
                    if (S.at(x).at(y) == '#') break;
                    ableToPass.at(x).at(y) = true;
                    ans.at(x).at(y) = true;
                }
            }
        }
    }
    ll cnt = 0;
    rep(i, N) {
        rep(j, M) {
            if (ans.at(i).at(j)) cnt++;
        }
    }
    // rep(i, N) {
    //     outv(ableToStop.at(i));
    // }
    // rep(i, N) {
    //     outv(ans.at(i));
    // }
    cout << cnt << endl;

    return 0;
}
