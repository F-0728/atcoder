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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

ll countX(ll X, ll N, ll P, vvll fee) {
    vvll feeCurrent(N, vll(N));
    rep(j, N) {
        rep(k, N) {
            if (fee.at(j).at(k) == -1) {
                feeCurrent.at(j).at(k) = X;
            } else {
                feeCurrent.at(j).at(k) = fee.at(j).at(k);
            }
        }
    }
    rep(j, N) {
        rep(k, N) {
            rep(l, N) {
                feeCurrent.at(k).at(l) =
                    min(feeCurrent.at(k).at(l),
                        feeCurrent.at(k).at(j) + feeCurrent.at(j).at(l));
            }
        }
    }
    ll count = 0;
    rep(j, N) {
        rep(k, N) {
            if (k <= j) continue;
            if (feeCurrent.at(j).at(k) <= P) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ll N, P, K;
    cin >> N >> P >> K;
    vvll fee(N, vll(N));
    rep(i, N) {
        rep(j, N) { cin >> fee.at(i).at(j); }
    }
    ll left = 0;
    ll right = INF;
    while (right - left > 1) {
        ll X = (left + right) / 2;
        if (countX(X, N, P, fee) <= K) {
            right = X;
        } else {
            left = X;
        }
    }
    ll ans_left = right;

    left = 0;
    right = INF;
    while (right - left > 1) {
        ll X = (left + right) / 2;
        if (countX(X, N, P, fee) < K) {
            right = X;
        } else {
            left = X;
        }
    }
    ll ans_right = right;

    if (ans_left == INF) {
        cout << 0 << endl;
        return 0;
    }
    if (ans_right == INF) {
        cout << "Infinity" << endl;
        return 0;
    }

    cout << ans_right - ans_left << endl;

    return 0;
}
