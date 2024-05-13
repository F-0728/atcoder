#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    vector<ll> nums(N);
    vector<vector<ll>> A(N, vector<ll>(N));
    vector<vector<ll>> B(N, vector<ll>(N, 0));
    rep(i, N) {
        nums[i] = i;
        rep(j, N) { cin >> A[i][j]; }
    }
    ll M;
    cin >> M;
    rep(i, M) {
        ll X, Y;
        cin >> X >> Y;
        B[X - 1][Y - 1] = B[Y - 1][X - 1] = 1;
    }
    ll ans = -1;

    do {
        ll sum = 0;
        bool flag = true;
        rep(i, N) {
            if (i == N - 1) {
                // ゴール
                if (flag) {
                    sum += A[nums[N - 1]][N - 1];
                    if (ans == -1 || ans > sum) {
                        ans = sum;
                    }
                }
            } else {
                if (B[nums[i]][nums[i + 1]] == 1) {
                    flag = false;
                } else {
                    if (flag) {
                        sum += A[nums[i]][i];
                    }
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << ans << endl;

    return 0;
}
