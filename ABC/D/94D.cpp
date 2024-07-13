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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll first = A[N - 1];
    ll second;
    if (first % 2 == 0) {
        second = first / 2;
    } else {
        second = first / 2 + 1;
    }
    ll second_index = lower_bound(A.begin(), A.end(), second) - A.begin();
    if (A[second_index] - second < second - A[second_index - 1]) {
        cout << first << " " << A[second_index] << endl;
    } else {
        cout << first << " " << A[second_index - 1] << endl;
    }

    return 0;
}
