class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        int num = 0;
        while(n){
            num = pq.top();
            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);
            pq.pop();
            n--;
        }
        return num;
    }
};