#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    ll current = 0;
    mint ans = 1;
    while (current < N){
        char c1 = S1[current];
        char c2 = S2[current];
        if (c1 == c2) {
            if (current == 0) {
                ans *= 3;
            } else {
                if (S1[current - 1] == S2[current - 1]) {
                    ans *= 2;
                }
            }
            current++;
        } else {
            if (current == 0) {
                ans *= 6;
            } else {
                if (S1[current - 1] == S2[current - 1]) {
                    ans *= 2;
                } else {
                    ans *= 3;
                }
            }
            current += 2;
        }
    }
    cout << ans.val() << endl;

    return 0;
}
