#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>



using namespace std;

class Solution {
public:

};

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int*)(&a+1);
    cout << *(p) << endl;
    cout << *(p-1) << endl;
    return 0;
}