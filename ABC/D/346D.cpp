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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vll cost(N);
    rep(i, N) {
        cin >> cost.at(i);
    }
    vll start0(N, 0);
    vll start1(N, 0);
    vll end0(N, 0);
    vll end1(N, 0);

    rep(i, N) {
        if (i == 0) {
            if (S.at(i) == '0') {
                start0.at(i) = 0;
                start1.at(i) = cost.at(i);
            } else {
                start1.at(i) = 0;
                start0.at(i) = cost.at(i);
            }
            continue;
        }
        if (S.at(i) == '0') {
            if (i % 2 == 0) {
                start0.at(i) = start0.at(i - 1);
                start1.at(i) = start1.at(i - 1) + cost.at(i);
            } else {
                start1.at(i) = start1.at(i - 1);
                start0.at(i) = start0.at(i - 1) + cost.at(i);
            }
        } else {
            if (i % 2 == 0) {
                start1.at(i) = start1.at(i - 1);
                start0.at(i) = start0.at(i - 1) + cost.at(i);
            } else {
                start0.at(i) = start0.at(i - 1);
                start1.at(i) = start1.at(i - 1) + cost.at(i);
            }
        }
    }

    for (ll i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            if (S.at(i) == '0') {
                end0.at(i) = 0;
                end1.at(i) = cost.at(i);
            } else {
                end1.at(i) = 0;
                end0.at(i) = cost.at(i);
            }
            continue;
        }
        if (S.at(i) == '0') {
            if ((N - 1 - i) % 2 == 0) {
                end0.at(i) = end0.at(i + 1);
                end1.at(i) = end1.at(i + 1) + cost.at(i);
            } else {
                end1.at(i) = end1.at(i + 1);
                end0.at(i) = end0.at(i + 1) + cost.at(i);
            }
        } else {
            if ((N - 1 - i) % 2 == 0) {
                end1.at(i) = end1.at(i + 1);
                end0.at(i) = end0.at(i + 1) + cost.at(i);
            } else {
                end0.at(i) = end0.at(i + 1);
                end1.at(i) = end1.at(i + 1) + cost.at(i);
            }
        }
    }

    // outv(start0);
    // outv(start1);
    // outv(end0);
    // outv(end1);

    ll ans = INF;
    if (N % 2 == 0) {
        rep(i, N - 1) {
            ans = min(ans, start0.at(i) + end0.at(i + 1));
            ans = min(ans, start1.at(i) + end1.at(i + 1));
        }
    } else {
        rep(i, N - 1) {
            ans = min(ans, start0.at(i) + end1.at(i + 1));
            ans = min(ans, start1.at(i) + end0.at(i + 1));
        }
    }

    cout << ans << endl;

    return 0;
}
