#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    
    int **r = new int *[m];
    for (int i = 0; i < m; i++) {
        r[i] = new int [n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> r[j][n-i-1];
        }
    }
    
    cout << m << ' ' << n << endl;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           cout << r[i][j] << ' ';
        }
        cout << endl;
    }
    
    for (int i = 0; i < m; i++) {
        delete[] r[i];
    }
    delete[] r;
    
    return 0;
}