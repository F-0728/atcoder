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
    ll N, x, y;
    cin >> N >> x >> y;
    x += 10001;
    y += 10001;
    vll moveX, moveY;
    rep(i, N) {
        ll A;
        cin >> A;
        if (i % 2 == 0) {
            moveX.push_back(A);
        } else {
            moveY.push_back(A);
        }
    }
    vector<vector<bool>> dpX(moveX.size() + 1, vector<bool>(20001, false));
    vector<vector<bool>> dpY(moveY.size() + 1, vector<bool>(20001, false));
    dpX.at(0).at(10001) = true;
    dpY.at(0).at(10001) = true;
    rep(i, moveX.size()) {
        if (i == 0) {
            dpX.at(i + 1).at(10001 + moveX.at(i)) = true;
            continue;
        }
        rep(j, 20001) {
            if (dpX.at(i).at(j)) {
                if (j + moveX.at(i) < 20001) {
                    dpX.at(i + 1).at(j + moveX.at(i)) = true;
                }
                if (j - moveX.at(i) >= 0) {
                    dpX.at(i + 1).at(j - moveX.at(i)) = true;
                }
            }
        }
    }
    rep(i, moveY.size()) {
        rep(j, 20001) {
            if (dpY.at(i).at(j)) {
                if (j + moveY.at(i) < 20001) {
                    dpY.at(i + 1).at(j + moveY.at(i)) = true;
                }
                if (j - moveY.at(i) >= 0) {
                    dpY.at(i + 1).at(j - moveY.at(i)) = true;
                }
            }
        }
    }
    if (dpX.at(moveX.size()).at(x) && dpY.at(moveY.size()).at(y)) {
        Yes;
    } else {
        No;
    }


    return 0;
}
