#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int res = s[0] - '0';
    int len = s.length();
    
    for (int i = 2; i < len; i += 2) {
        if (s[i-1] == '+') res += s[i] - '0';
        else res *= s[i] - '0'; 
    }
    
    cout << res;
    
    return 0;
}