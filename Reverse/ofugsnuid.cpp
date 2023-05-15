#include <iostream>
#include <string>

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int output[100000];
    int i = 0;
    for(; i < n; ++i){
        cin >> output[i];
    }
    i--;
    for(; i >= 0; i--){
        cout << output[i] << endl;
    }
    
}