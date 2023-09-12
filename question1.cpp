#include <iostream>
using namespace std;

// a function that takes all 4 coordinates as input and return a string regarding whether it overlaps or not
string checkOverlap(double x1, double x2, double x3, double x4){
    string ans;
    // if a user input x1>x2 it will swap the numbers
    if(x1>x2)
        swap(x1,x2);
    // if a user input x3>x4 it will swap the numbers
    if(x3>x4)
        swap(x3, x4);
    
    // the below condition is used to sort the 2 points.
    if(x1>x3){
        swap(x1,x3);
        swap(x2,x4);
    }
        
    // if x3 lies between x1 and x2 or x4 lies between x1 and x2 then the lines overlap
    if((x3>x1 && x3<x2))
        ans = "lines overlap";
    else
        ans = "lines donot overlap";
    return ans;
} 

// function to test the overlap function. It takes coordinates and expected outcome as input and return whether the test passed or not
void test(double x1, double x2, double x3, double x4, string expected){
    string ans = checkOverlap(x1, x2, x3, x4);
    // if actual ans = expected then return true else false
    if(ans == expected)
        cout << "test passed\n";
    else
        cout << "test failed\n";
}

int main() {
    // declaring pair to get the coordinates (x1,x2) and (x3,x4)
    pair<double, double> one;
    pair<double, double> two;
    
    cin>> one.first >> one.second;
    cin>> two.first >> two.second;
    // if(one.first>two.first)
    //     swap(one, two);
    
    // getting the ans based on the user input
    string ans = checkOverlap(one.first, one.second, two.first, two.second);
    cout << ans <<"\n";
    
    // running the test cases
    
    // this is trival test case
    test(1,5,6,8, "lines donot overlap");
    test(1,5,2,6, "lines overlap");
    
    // In below 2 tests the value of x1 is greater than x2 and x3>x4
    test(5,1,6,2, "lines overlap");
    test(5,1,8,6, "lines donot overlap");
    
    // it tests the -ve values of x's
    test(-1,-4,-6,-2, "lines overlap");
    
    // if one of the point is common, it means that lines donot overlap
    test(0,4,4,8, "lines donot overlap");
    
    // here line lies between 1st and 2nd coordinate
    test(-1,4,0,2, "lines overlap");
    
    // if line 1 lies between line 2
    test(-1,4,-2,6, "lines overlap");
    

    return 0;
}
