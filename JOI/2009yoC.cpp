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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vll color(N);
    rep(i, N) cin >> color[i];

    ll ans = INF;

    rep(i, N) {
        vll change;
        ll colorNow = color[i];
        if (colorNow == 1) {
            change = {2, 3};
        } else if (colorNow == 2) {
            change = {1, 3};
        } else {
            change = {1, 2};
        }

        rep(j, 2) {
            color[i] = change[j];
            vpll stack;
            rep(k, N) {
                if (stack.empty()) {
                    stack.push_back({color[k], 1});
                } else {
                    if (stack.back().first == color[k]) {
                        stack.back().second++;
                    } else {
                        if (stack.back().second >= 4) {
                            stack.pop_back();
                        }
                        if (stack.back().first == color[k]) {
                            stack.back().second++;
                        } else {
                            stack.push_back({color[k], 1});
                        }
                    }
                }
            }
            if (stack.back().second >= 4) {
                stack.pop_back();
            }
            ll sum = 0;
            for (auto [c, s] : stack) {
                sum += s;
            }
            ans = min(ans, sum);
            color[i] = colorNow;
        }
    }

    cout << ans << endl;

    return 0;
}
