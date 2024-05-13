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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

ll addByDigit(ll N) {
    ll sum = 0;
    while (N > 0) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> num;
    ll counter = 0;
    num.push_back(N);
    ll loopFound;
    while (1) {
        N += addByDigit(N);
        N %= 100000;
        if (find(num.begin(), num.end(), N) != num.end()) {
            loopFound = find(num.begin(), num.end(), N) - num.begin();
            break;
        }
        num.push_back(N);
        counter++;
    }
    ll ansIdx;
    if (K < counter) {
        ansIdx = K;
    } else {
        ansIdx = ((K - loopFound) % (counter - loopFound + 1)) + loopFound;
    }
    cout << num[ansIdx] << endl;

    return 0;
}
