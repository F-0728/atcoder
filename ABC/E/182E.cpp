#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll H, W, N, M;
    cin >> H >> W >> N >> M;
    vpll light(N);
    vpll block(M);
    rep(i, N) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        light.at(i) = make_pair(A, B);
    }
    rep(i, M) {
        ll C, D;
        cin >> C >> D;
        C--;
        D--;
        block.at(i) = make_pair(C, D);
    }

    vector<vector<bool>> ans(H, vector<bool>(W, false));
    vector<vector<bool>> lighted(H, vector<bool>(W, false));
    vector<vector<bool>> blocked(H, vector<bool>(W, false));
    
    for (pair<ll, ll> b : block) {
        blocked.at(b.first).at(b.second) = true;
    }

    for (pair<ll, ll> l : light) {
        if (lighted.at(l.first).at(l.second)) {
            continue;
        }
        lighted.at(l.first).at(l.second) = true;
        ans.at(l.first).at(l.second) = true;
        ll i = l.first;
        ll j = l.second;
        while (i > 0) {
            i--;
            if (blocked.at(i).at(j)) {
                break;
            }
            lighted.at(i).at(j) = true;
            ans.at(i).at(j) = true;
        }
        i = l.first;
        while (i < H - 1) {
            i++;
            if (blocked.at(i).at(j)) {
                break;
            }
            lighted.at(i).at(j) = true;
            ans.at(i).at(j) = true;
        }
    }
    rep(i, H) {
        rep(j, W) {
            lighted.at(i).at(j) = false;
        }
    }
    for (pair<ll, ll> l : light) {
        if (lighted.at(l.first).at(l.second)) {
            continue;
        }
        lighted.at(l.first).at(l.second) = true;
        ans.at(l.first).at(l.second) = true;
        ll i = l.first;
        ll j = l.second;
        while (j > 0) {
            j--;
            if (blocked.at(i).at(j)) {
                break;
            }
            lighted.at(i).at(j) = true;
            ans.at(i).at(j) = true;
        }
        j = l.second;
        while (j < W - 1) {
            j++;
            if (blocked.at(i).at(j)) {
                break;
            }
            lighted.at(i).at(j) = true;
            ans.at(i).at(j) = true;
        }
    }
    ll res = 0;
    rep(i, H) {
        rep(j, W) {
            if (ans.at(i).at(j)) {
                res++;
            }
        }
    }
    cout << res << endl;

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << ans.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
