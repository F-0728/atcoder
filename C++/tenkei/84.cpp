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
    ll N;
    string S;
    cin >> N >> S;
    ll ans = N * (N-1) / 2;
    ll streak = 1;
    rep(i, N) {
        if (i == N-1) {
            ans -= streak * (streak - 1) / 2;
            break;
        }
        if (S[i] == S[i+1]) {
            streak++;
        }
        else {
            ans -= streak * (streak - 1) / 2;
            streak = 1;
        }
    }
    cout << ans << endl;


    return 0;
}
