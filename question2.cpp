#include "question2.h"
using namespace std;

// function to check if both the versions are equal or not. It takes the 2 strings as input and return the string as an output
string checkNumbers(string s1, string s2){
    // below condition is used to check if there is any negetive sign inside string then through error
    if((s1.find('-')!= string::npos) || (s2.find('-')!= string::npos))
        return "versions can't be negetive";
    
    int l1 = s1.length();
    int l2 = s2.length();
    int i = 0;
    int j = 0;
    while(i<l1 || j<l2){
        int n1 = 0;
        int n2 = 0;
        while(i<l1 && s1[i]!='.'){
            n1 = n1*10 + (s1[i] - '0');
            i++;
        }
        while(j<l2 && s2[j]!='.'){
            n2 = n2*10 + (s2[j] - '0');
            j++;
        }
        if (n1>n2){
            return "s1 is greater than s2";
        }
        else if (n2>n1){
            return "s2 is greater than s1";
        }
        i++;
        j++;
    }
    return "s1 and s2 are equal";
}

//function to test checkNumbers function. It takes both the string and expected outcome as an input and returns whether test passed or failed
void test(string s1, string s2, string expected){
    string ans = checkNumbers(s1, s2);
    if(ans == expected)
        cout << "test passed\n";
    else
        cout << "test failed\n";
}

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    
    // returning ans based on user input
    string ans = checkNumbers(s1, s2);
    cout << ans << "\n";
    
    // running the test cases
    test("1.1", "1.2", "s2 is greater than s1");
    test("1.2", "1.1", "s1 is greater than s2");
    test("1.001", "1.01", "s1 and s2 are equal");
    test("1.0.0", "1.0", "s1 and s2 are equal");
    test("123.1", "123.01", "s1 and s2 are equal");
    test("0.0.1", "0.0.0001", "s1 and s2 are equal");
    test("-1.0", "1.0", "versions can't be negetive");
    
    
    
    return 0;
}