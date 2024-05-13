#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() { 
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    rep(i, Q) {
        ll B;
        cin >> B;
        ll r;
        r = lower_bound(A.begin(), A.end(), B) - A.begin();
        if (r == 0) {
            cout << A[0] - B << endl;
        } else if (r == N) {
            cout << B - A[N - 1] << endl;
        } else {
            cout << min(A[r] - B, B - A[r - 1]) << endl;
        }

    }


    return 0;
}
