#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Treque{
    deque<int> first;
    deque<int> second;
public:
    int &operator[](int i){
        if (i >= first.size() + second.size()) throw out_of_range("Index out of bounds");
        if (i < first.size()) return first[i];
        return second[i - first.size()];
    }

    void push_front(int i){
        first.emplace_front(i);
        if (first.size() > second.size() + 1){
            second.emplace_front(first.back());
            first.pop_back();
        }
    }

    void push_back(int i){
        second.emplace_back(i);
        if(second.size() > first.size()){
            first.emplace_back(second.front());
            second.pop_front();
        }
    }

    void push_middle(int i){
        if(first.size() > second.size()){
            second.emplace_front(i);
        }
        else{
            first.emplace_back(i);
        }
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Treque test;
    int commands = 0;
    cin >> commands;
    string output;
    string comm;
    int val = 0;

    for(int i = 0; i < commands; i++){
        cin >> comm >> val;
        if (comm == "push_back") test.push_back(val);
        else if (comm == "push_front") test.push_front(val);
        else if (comm == "push_middle") test.push_middle(val);
        else output += to_string(test[val]) + "\n";
    }

    cout << output;
}
