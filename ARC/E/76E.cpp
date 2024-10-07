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
    ll R, C, N;
    cin >> R >> C >> N;

    vpll r0;
    vpll cC;
    vpll rR;
    vpll c0;
    
    vector<bool> used(N, false);

    rep(i, N) {
        ll r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 != 0 && r1 != R && c1 != 0 && c1 != C) continue;
        if (r2 != 0 && r2 != R && c2 != 0 && c2 != C) continue;

        if (r1 == 0) {
            r0.push_back({c1, i});
        } else if (c1 == C) {
            cC.push_back({r1, i});
        } else if (r1 == R) {
            rR.push_back({c1, i});
        } else if (c1 == 0) {
            c0.push_back({r1, i});
        }

        if (r2 == 0) {
            r0.push_back({c2, i});
        } else if (c2 == C) {
            cC.push_back({r2, i});
        } else if (r2 == R) {
            rR.push_back({c2, i});
        } else if (c2 == 0) {
            c0.push_back({r2, i});
        }
    }

    sort(r0.begin(), r0.end());
    sort(cC.begin(), cC.end());
    sort(rR.begin(), rR.end());
    sort(c0.begin(), c0.end());

    reverse(rR.begin(), rR.end());
    reverse(c0.begin(), c0.end());

    vll stack;
    rep(i, r0.size()) {
        if (stack.empty()) {
            stack.push_back(r0[i].second);
            used[r0[i].second] = true;
        } else {
            if (stack.back() == r0[i].second) {
                stack.pop_back();
            } else {
                if (used[r0[i].second]) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    stack.push_back(r0[i].second);
                    used[r0[i].second] = true;
                }
            }
        }
    }

    // outv(stack);

    rep(i, cC.size()) {
        if (stack.empty()) {
            stack.push_back(cC[i].second);
        } else {
            if (stack.back() == cC[i].second) {
                stack.pop_back();
            } else {
                if (used[cC[i].second]) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    stack.push_back(cC[i].second);
                    used[cC[i].second] = true;
                }
            }
        }
    }

    // outv(stack);

    rep(i, rR.size()) {
        if (stack.empty()) {
            stack.push_back(rR[i].second);
        } else {
            if (stack.back() == rR[i].second) {
                stack.pop_back();
            } else {
                if (used[rR[i].second]) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    stack.push_back(rR[i].second);
                    used[rR[i].second] = true;
                }
            }
        }
    }

    // outv(stack);

    rep(i, c0.size()) {
        if (stack.empty()) {
            stack.push_back(c0[i].second);
        } else {
            if (stack.back() == c0[i].second) {
                stack.pop_back();
            } else {
                if (used[c0[i].second]) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    stack.push_back(c0[i].second);
                    used[c0[i].second] = true;
                }
            }
        }
    }

    // outv(stack);

    cout << "YES" << endl;

    return 0;
}
