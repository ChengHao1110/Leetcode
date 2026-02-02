#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int maxRank = ranks[ranks.size() - 1];
        
        long long low = 1, high = (long long)maxRank * cars * cars, mid = 0;
        while(low <= high){
            mid = (low + high) / 2;
            //cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
            // total cars
            int sum = 0;
            for(int i = 0; i < ranks.size(); i++){
                int num = (int)sqrt(mid / (double)ranks[i]);
                sum += num;
                if(sum >= cars){
                    // too much time
                    high = mid - 1;
                    break;
                }
            }
            if(sum < cars){
                //too less time
                low = mid + 1;
            }
        }
        return low;
    }
};


int main(){
    /*
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
    */
    Solution sol;
    vector<int> a = {4,2,3,1}, b = {5, 1, 8};
    cout << sol.repairCars(a, 10) << endl;
    cout << sol.repairCars(b, 6) << endl;
    return 0;
}