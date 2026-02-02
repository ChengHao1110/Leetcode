#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long negCnt = 0, posCnt = 0, zeroNums1 = 0, zeroNums2 = 0, zeroCnt;
        vector<long long> NegNums1, PosNums1, NegNums2, PosNums2;
        for(int n : nums1){
            if(n < 0) NegNums1.push_back(-n);
            else if(n == 0) zeroNums1++;
            else PosNums1.push_back(n);
        }
        reverse(NegNums1.begin(), NegNums1.end());

        for(int n : nums2){
            if(n < 0) NegNums2.push_back(-n);
            else if(n == 0) zeroNums2++;
            else PosNums2.push_back(n);
        }
        reverse(NegNums2.begin(), NegNums2.end());

        negCnt = (long long)NegNums1.size() * PosNums2.size() + (long long)PosNums1.size() * NegNums2.size();
        zeroCnt = zeroNums1 * nums2.size() + zeroNums2 * nums1.size() - zeroNums1 * zeroNums2;
        posCnt = (long long)NegNums1.size() * NegNums2.size() + (long long)PosNums1.size() * PosNums2.size();

        long long low = 1, high = 1e10, mid, sign = 1;
        if(k <= negCnt){
            k = negCnt - k + 1; // 5個負數中第2小 = 5個正數中第4大再取負數 (5 - 2 + 1 = 4)
            sign = -1;
            swap(NegNums2, PosNums2);
        }
        else if(k <= negCnt + zeroCnt){
            return 0;
        }
        else{
            k = k - negCnt - zeroCnt;
        }

        while(low < high){
            mid = (low + high) / 2;
            if(NumberProductNoGreaterThan(NegNums1, NegNums2, mid) + NumberProductNoGreaterThan(PosNums1, PosNums2, mid) >= k){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return sign * low;
    }

    long long NumberProductNoGreaterThan(vector<long long> &A, vector<long long> &B, long long val){
        long long cnt = 0;
        int BIdx = B.size() - 1;
        for(long long ll : A){
            while(BIdx >= 0 && ll * B[BIdx] > val) BIdx--;
            cnt += BIdx + 1;
        }
        return cnt;
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