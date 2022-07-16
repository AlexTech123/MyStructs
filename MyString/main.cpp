#include "MyString.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    MyString s1 = "qwe", s2 = "rty";
    cout << s1 + s2 << endl;
    cout << s1 << " " << s2;
    return 0;
}
