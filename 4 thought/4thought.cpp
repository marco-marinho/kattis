#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int finish(vector<int> &vals, vector<int> &ops){
    int n = ops.size();
    if (n == 0) return vals[0];
    int buff = vals[0];
    for (int i = 0; i < n; i++){
        if(!ops[i]) buff += vals[i + 1];
        else buff -= vals[i + 1];
    } 
    return buff;
}


void eval(vector<int> &vals, vector<int> &ops, int depth, string &res, map<int, string> &ans){
    if (depth == 4){ 
        int val = finish(vals, ops);
        ans[val] = res + " = " + to_string(val);
        return;
    }
    
    vals.emplace_back(4);
    ops.emplace_back(0);
    res += " + 4";
    eval(vals, ops, depth + 1, res, ans);
    vals.pop_back();
    ops.pop_back();
    res.erase(res.end() - 4, res.end());
    
    vals.emplace_back(4);
    ops.emplace_back(1);
    res += " - 4";
    eval(vals, ops, depth + 1, res, ans);
    vals.pop_back();
    ops.pop_back();
    res.erase(res.end() - 4, res.end());
    
    int buff = vals.back();
    
    vals.back() = buff * 4;
    res += " * 4";
    eval(vals, ops, depth + 1, res, ans);
    res.erase(res.end() - 4, res.end());
    
    vals.back() = buff / 4;
    res += " / 4";
    eval(vals, ops, depth + 1, res, ans);
    res.erase(res.end() - 4, res.end());
    
    vals.back() = buff;
}

int main(){
    vector<int> rato = {4};
    vector<int> ops;
    map<int, string> res;
    string str = "4";
    eval(rato, ops, 1, str, res);
    int n;
    int nums[1000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    for(int i = 0; i < n; i++){
        if (nums[i] > 256 || nums[i] < -60 || !res.count(nums[i])){
            cout << "no solution" << endl;
        }
        else{
            cout << res[nums[i]] << endl;
        }
    }
}