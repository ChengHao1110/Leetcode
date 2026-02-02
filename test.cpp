#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_map>
#include<time.h>
#include <stdlib.h>

using namespace std;
//889, 128
class Solution {
public:

};

int main(){
    /*
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int*)(&a+1);
    cout << *(p) << endl;
    cout << *(p-1) << endl;
    cout << to_string(-15).length() << endl;

    unordered_map<int ,int> t;
    t[1] = 1;
    cout << t[2] << endl;

    unordered_map<int, unordered_map<int, int>> table;
    cout << table[0][1] << endl;

    int aaa = -1 % 5;
    cout << aaa << endl;
    */
    srand(time(NULL));
    string str = "";
    for(int i = 0; i < 1000; i++){
        int x = rand() % 3;
        if(x == 0){
            str += "R";
        }
        else if(x == 1){
            str += "L";
        }
        else{
            str += "S";
        }
    }
    cout << str <<endl;

    return 0;
}