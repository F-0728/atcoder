#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

// cumulative sum

int main() {
    int sum1;
    int sum2;
    sum1 = sum2 = 0;
    int N;
    cin >> N;
    vector<vector<int>> scores(N+1, vector<int>(2));
    scores[0] = {0, 0};
    for (int i = 0; i < N; i++) {
        int C, P;
        cin >> C >> P;
        if (C == 1) {
            sum1 += P;     
        } else {
            sum2 += P;
        }
        scores[i+1] = {sum1, sum2};
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        int ans1, ans2;
        ans1 = scores[R][0] - scores[L-1][0];
        ans2 = scores[R][1] - scores[L-1][1];
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
