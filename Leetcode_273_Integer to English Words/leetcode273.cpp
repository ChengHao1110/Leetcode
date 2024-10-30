#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ans = "";
        vector<pair<int, string>> map{
            {1000000000, "Billion"},
            {1000000, "Million"},
            {1000, "Thousand"}
        };
        for(int i = 0; i < map.size(); i++){
            if(num >= map[i].first){
                int lessThousand = num / map[i].first;
                string number = UnderThousand(lessThousand);
                if(number != "") ans += number + " " + map[i].second;
                num %= map[i].first;
                if(num > 0) ans += " ";
            }
        }
        // < 1000
        string number = UnderThousand(num);
        if(number != "") ans += number;
        return ans;
    }

    string UnderThousand(int num){
        string ans = "";
        if(num == 0) return ans;
        unordered_map<int, string> map = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
            {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
        };
        int digit = 0;
        // handle hundred
        if(num >= 100){
            digit = num / 100;
            ans += map[digit] + " " + "Hundred";
            num %= 100;
            if(num > 0) ans += " ";
        }
        // handle ten
        if(num >= 10){
            digit = num / 10;
            if(digit > 1){
                // > 20
                ans += map[digit * 10];
                num %= 10;
                if(num > 0) ans += " ";
            }
            else{
                // 10 - 19
                ans += map[num];
                return ans;
            }
        }
        // handle 1 - 9
        if(num > 0){
            ans += map[num];
        }
        return ans;
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
        stringstream ss(input);
        int num;
        ss >> num;
        cout << sol.numberToWords(num) << endl;
    }
    testcase.close();
    return 0;
}