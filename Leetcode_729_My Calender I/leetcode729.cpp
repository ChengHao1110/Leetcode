#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> books; 

    MyCalendar() {
        books.clear();
    }
    
    bool book(int start, int end) {
        for(pair<int, int> p : books){
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
        cout << "add: " << start << ", " << end << endl;

        if(books.empty()){
            books.push_back({start, end});
            return true;
        }
        else{
            int low = 0, high = books.size() - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(start == books[mid].first){
                    return false;
                }
                else if(start > books[mid].first){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            cout << "high: " << high << endl;

            if(high < 0){
                if(end <= books[0].first){
                    books.insert(books.begin(), {start, end});
                    return true;
                }
            }
            else if(high == books.size() - 1){
                if(start >= books[books.size() - 1].second){
                    books.push_back({start, end});
                    return true;
                }
            }
            else{
                if(start >= books[high].second && end <= books[high + 1].first){
                    books.insert(books.begin() + high + 1, {start, end});
                    return true;
                }
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
    MyCalendar myCalendar;
    while(getline(testcase, input)){
        stringstream ss(input);
        int s, e;
        while(ss >> s >> e){
            if(myCalendar.book(s, e)) cout << "T" << endl;
            else cout << "F" << endl;
        }
    }
    return 0;
}