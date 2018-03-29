#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int a, b;
    cin >> str >> a >> b;
    
	string s_a = to_string(a),
	    s_b = to_string(b);
	
	for (int i = 0; i < str.length(); i++) {
	    if (str[i] == s_a[0]) str[i] = s_b[0];
	}
	
	int start = -1;
	
	for (int i = 0; i < str.length(); i++) {
	    if (str[i] != '0') {
	        start = i;
	        break;
	    }
	}
	
	if (start == -1) { 
	    cout << 0;
	} else {
	    for (int i = start; i < str.length(); i++) {
    	    cout << str[i];
    	}   
	}
	
	return 0;
}