#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &v1, const vector<int> &v2){
            if(v1[0] < v2[0]) return true;
            else if(v1[0] > v2[0]) return false;
            else{
                if(v1[1] <= v2[1]) return true;
                else return false;
            }
        });

        vector<int> usedFreq(n, 0);
        priority_queue<int, vector<int>, greater<int>> notUsedRoom; //{room, starttime}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTime; //{endtime, room}
        for(int i = 0; i < n; i++) notUsedRoom.push(i);

        int roomId = notUsedRoom.top();
        notUsedRoom.pop();
        usedFreq[roomId]++;
        endTime.push({meetings[0][1], roomId});

        for(int i = 1; i < meetings.size(); i++){
            //check whether the starttime of meeting[i] is larger than the element in "endTime"(priority queue)
            if(meetings[i][0] >= endTime.top().first){
                while(!endTime.empty() && meetings[i][0] >= endTime.top().first){
                    notUsedRoom.push(endTime.top().second);
                    endTime.pop();
                }
                int roomId = notUsedRoom.top();
                notUsedRoom.pop();
                usedFreq[roomId]++;
                endTime.push({meetings[i][1], roomId});
            }
            //if any room is free -> yes: get new room, no: delay
            else{
                if(notUsedRoom.empty()){
                    auto[end, roomId] = endTime.top();
                    endTime.pop();
                    usedFreq[roomId]++;
                    endTime.push({end + (meetings[i][1] - meetings[i][0]), roomId});
                }
                else{
                    int roomId = notUsedRoom.top();
                    notUsedRoom.pop();
                    usedFreq[roomId]++;
                    endTime.push({meetings[i][1], roomId});
                }
            }
        }

        int ans = 0, maxUsedTime = usedFreq[0];
        for(int i = 1; i < n; i++){
            if(usedFreq[i] > maxUsedTime){
                maxUsedTime = usedFreq[i];
                ans = i;
            }
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

    }
    testcase.close();
    return 0;
}