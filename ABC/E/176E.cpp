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
    ll H, W, M;
    cin >> H >> W >> M;

    vll row(H, 0), col(W, 0);
    set<pll> s;
    rep(i, M) {
        ll h, w;
        cin >> h >> w;
        h--; w--;
        row[h]++;
        col[w]++;
        s.insert({h, w});
    }

    ll maxR = -1;
    ll maxC = -1;
    vll maxRIdx, maxCIdx;
    rep(i, H) {
        if (row[i] > maxR) {
            maxR = row[i];
            maxRIdx.clear();
            maxRIdx.push_back(i);
        } else if (row[i] == maxR) {
            maxRIdx.push_back(i);
        }
    }
    rep(i, W) {
        if (col[i] > maxC) {
            maxC = col[i];
            maxCIdx.clear();
            maxCIdx.push_back(i);
        } else if (col[i] == maxC) {
            maxCIdx.push_back(i);
        }
    }

    ll ans = maxR + maxC - 1;
    for (ll h : maxRIdx) {
        for (ll w : maxCIdx) {
            if (s.find({h, w}) == s.end()) {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
