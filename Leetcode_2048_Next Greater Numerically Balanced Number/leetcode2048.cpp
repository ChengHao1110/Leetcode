#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ans = n + 1, num;
        while(true){
            vector<int> freq(10, 0);
            num = ans;
            while(num > 0){
                freq[num % 10]++;
                num /= 10;
            }
            bool valid = true;
            for(int i = 0; i < 10; i++){
                if(freq[i] > 0 && freq[i] != i){
                    valid = false;
                    break;
                }
            }
            if(valid) return ans;
            ans++;
        }
        return -1;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}