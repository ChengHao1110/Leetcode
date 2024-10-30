#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class AllOne {
public:
    class Node{
    public:
        string key;
        int value;
        Node *next, *pre;
        Node(string k, int v){
            key = k;
            value = v;
            next = nullptr;
            pre = nullptr;
        }
    };

    AllOne() {
        dict = unordered_set<string>();
        head = nullptr;
        tail = nullptr;
        curSize = 0;
    }
    
    void inc(string key) {
        if(curSize == 0){
            Node *node = new Node(key, 1);
            head = node;
            tail = node;
            dict.insert(key);
            curSize++;
        }
        else{
            if(dict.find(key) != dict.end()){
                Node *cur = head;
                vector<pair<int, Node*>> rec;
                int curVal = cur->value;
                rec.push_back({curVal, cur});
                while(cur->key != key){
                    if(cur->value != curVal){
                        curVal = cur->value;
                        rec.push_back({curVal, cur});
                    }
                    cur = cur->next;
                }
                cur->value++;
                for(int i = 0; i < rec.size(); i++){
                    if(cur->value > rec[i].first){
                        //swap
                        Swap(cur, rec[i].second);
                        break;
                    }
                }
            }
            else{
                // push back
                Node *node = new Node(key, 1);
                node->pre = tail;
                tail->next = node;
                tail = node;
                dict.insert(key);
                curSize++;
            }
        }
    }
    
    void dec(string key) {
        Node *cur = tail;
        vector<pair<int, Node*>> rec;
        int curVal = cur->value;
        rec.push_back({curVal, cur});
        while(cur->key != key){
            if(cur->value != curVal){
                curVal = cur->value;
                rec.push_back({curVal, cur});
            }
            cur = cur->pre;
        }
        cur->value--;
        for(int i = 0; i < rec.size(); i++){
            if(cur->value < rec[i].first){
                //swap
                Swap(cur, rec[i].second);
                break;
            }
        }

        if(tail->value == 0){
            dict.erase(tail->key);
            curSize--;
            if(curSize == 0){
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node *pre = tail->pre;
                pre->next = nullptr;
                Node *tmp = tail;
                tail = pre;
                delete tmp;
            }
        }
    }

    string getMaxKey() {
        if(curSize > 0) return head->key;
        else return "";
    }
    
    string getMinKey() {
        if(curSize > 0) return tail->key;
        else return "";
    }

    void Swap(Node *n1, Node *n2){
        int tempVal = n1->value;
        string tempStr = n1->key;
        n1->value = n2->value;
        n1->key = n2->key;
        n2->value = tempVal;
        n2->key = tempStr;
    }

private:
    unordered_set<string> dict;
    Node *head, *tail;
    int curSize;
};


int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    testcase.close();
    return 0;
}