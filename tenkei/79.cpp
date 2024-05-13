#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    vector<vector<ll>> diff(H, vector<ll>(W));
    ll ans = 0;
    rep(i, H) {
        rep(j, W) { cin >> A[i][j]; }
    }
    rep(i, H) {
        rep(j, W) {
            cin >> B[i][j];
            diff[i][j] = B[i][j] - A[i][j];
        }
    }

    rep(i, H - 1) {
        rep(j, W - 1) {
            A[i][j] += diff[i][j];
            A[i][j + 1] += diff[i][j];
            A[i + 1][j] += diff[i][j];
            A[i + 1][j + 1] += diff[i][j];

            diff[i][j+1] -= diff[i][j];
            diff[i+1][j] -= diff[i][j];
            diff[i+1][j+1] -= diff[i][j];
            
            if (diff[i][j] != 0) {
                ans += abs(diff[i][j]);
            }
        }
        if (A[i][W - 1] != B[i][W - 1]) {
            No;
            return 0;
        }
    }
    rep(i, W - 1) {
        if (A[H-1][i] != B[H-1][i]) {
            No;
            return 0;
        } 
    }
    Yes;
    cout << ans << endl;

    return 0;
}
