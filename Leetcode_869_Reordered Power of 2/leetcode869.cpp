#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<pair<int, unordered_map<int, int>>> power2Digits;
        for(long long i = 1; i <= INT_MAX; i *= 2){
            unordered_map<int, int> digits;
            long long num = i, dig = 0;
            while(num > 0){
                digits[num % 10]++;
                dig++;
                num /= 10;
            }

            power2Digits.push_back({dig, digits});
        }

        unordered_map<int, int> target;
        int dig = 0;
        while(n > 0){
            target[n % 10]++;
            dig++;
            n /= 10;
        }

        for(int i = 0; i < power2Digits.size(); i++){
            if(power2Digits[i].first < dig) continue;
            else if(power2Digits[i].first > dig) break;
            else{
                bool find = true;
                for(auto t : power2Digits[i].second){
                    if(target[t.first] != t.second){
                        find = false;
                        break;
                    }
                }
                if(find) return true;
            }
        }

        return false;
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