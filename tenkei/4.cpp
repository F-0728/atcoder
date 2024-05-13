#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<int> Sh(H);
    vector<int> Sw(W);
    for (int i = 0; i < H; i++) {
        for ( int j = 0; j < W; j++) {
            int a;
            cin >> a;
            A[i][j] = a;
            Sh[i] += a;
            Sw[j] += a;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << Sh[i] + Sw[j] - A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
