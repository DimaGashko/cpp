#include <iostream>
#include <string>

using namespace std;

int main() {
    const int start = 65,
        end = 90,
        len = end - start;
    
    string s, res;
    int k;
    
    cin >> s >> k;
    
    for (int i = 0; i < s.length(); i++) {
        int n = s[i] - start - k;
        
        if (n >= 0) res += n % len + start;
        else res += end + n + 1;
    }
    
    cout << res;
    
    return 0;
}