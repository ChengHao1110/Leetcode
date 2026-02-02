#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &m1, const vector<int> &m2){
            if(m1[0] < m2[0]) return true;
            else if(m1[0] > m2[0]) return false;
            else{
                if(m1[1] < m2[1]) return true;
                return false;
            }
        });
        int e = meetings[0][1], cnt = (meetings[0][0] == 1) ? 0 : meetings[0][0] - 1;
        for(int i = 1; i < meetings.size(); i++){
            if(meetings[i][0] > e){ // no meeting
                cnt += (meetings[i][0] - e) - 1;
            }
            e = max(e, meetings[i][1]);
        }
        cnt += days - e;
        return cnt;
    }
    /*
    int countDays(int days, vector<vector<int>>& meetings) {
        //MLE bad testcase days:1000000000
        vector<int> diff(days + 1, 0);
        for(auto m : meetings){
            diff[m[0]]++;
            diff[m[1] + 1]--;
        }
        vector<int> prefixSum(days + 1, 0);
        prefixSum[1] = diff[1];
        int ans = (prefixSum[1] > 0) ? 0 : 1;
        for(int i = 2; i < days + 1; i++){
            prefixSum[i] = prefixSum[i - 1] + diff[i]; 
            ans = ans + (prefixSum[i] > 0 ? 0 : 1);
        }

        return ans;
    }
        */
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