#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool finish;
    long long ans;
    int total, base, cnt, length;
    long long kMirror(int k, int n) {
        finish = false;
        ans = 0;
        cnt = 0; 
        length = 1;
        total = n;
        base = k;

        while(!finish){
            GeneratePalindromeNumbers();
            length++;
        }

        return ans;
    }

    void GeneratePalindromeNumbers(){
        if(length == 1){
            for(long long i = 1; i < 10; i++){
                if(finish) return;
                ans += ConvertToBaseK(i);
            }
        }
        else{
            int halfLen = length / 2;
            bool isOdd = (length % 2 == 0) ? false : true;
            long long start = (long long)pow(10, halfLen - 1), end = (long long)pow(10, halfLen);
            for(long long i = start; i < end; i++){
                if(finish) return;
                string part = to_string(i);
                string revPart = part;
                reverse(revPart.begin(), revPart.end());
                string number = "";
                if(isOdd){
                    for(long long i = 0; i < 10; i++){
                        if(finish) return;
                        number = part + to_string(i) + revPart;
                        ans += ConvertToBaseK(stoll(number));
                    }
                }
                else{
                    number = part + revPart;
                    ans += ConvertToBaseK(stoll(number));
                }
            }
        }
    }

    long long ConvertToBaseK(long long num){
        long long ori = num;
        vector<int> digits;
        while(num > 0){
            digits.push_back(num % base);
            num /= base;
        }
        for(int i = 0; i < digits.size() / 2; i++){
            if(digits[i] != digits[digits.size() - 1 - i]) return 0;
        }
        cnt++;
        if(cnt == total) finish = true;
        return ori;
    }
};

int main(){
    Solution sol;
    cout << sol.kMirror(2, 5) <<endl;
    cout << sol.kMirror(3, 7) <<endl;
    cout << sol.kMirror(7, 17) <<endl;
    return 0;
}