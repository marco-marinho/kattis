#include <iostream>
#include <deque>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Patient {
public:
    Patient(string iname, long long S, long long T, long long K) : name(std::move(iname)), S(S), T(T), K(K) {}

    void leave(){
        left = true;
    }
    string name;
    long long S;
    long long T;
    long long K;
    bool left = false;

};

class ComparePerson {
public:
    bool operator()(Patient* first, Patient *second)
    {
        long long const p1 = first->S - first->T * first->K;
        long long const p2 = second->S - second->T * second->K;

        if (p1 == p2) {
            int const res = second->name.compare(first->name);
            return res < 0;
        }

        return p1 < p2;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<Patient*, vector<Patient*>, ComparePerson> patients;
    map<string, Patient*> patient_list;

    int N;
    long long K;
    string output;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int Q = 0;
        long long T = 0;
        long long S = 0;
        string name;
        cin >> Q >> T;
        if (Q == 1) {
            cin >> name >> S;
            auto* temp = new Patient(name, S, T, K);
            patient_list[name] = temp;
            patients.push(temp);
        }
        else if (Q == 2) {
            if (patients.empty()) output += "doctor takes a break \n";
            else {
                auto next = patients.top();
                patients.pop();
                while (next->left && !patients.empty()){
                    next = patients.top();
                    patients.pop();
                }
                output += next->name + "\n";
            }
        }
        else if (Q == 3) {
            cin >> name;
            if (patient_list.count(name)) {
                patient_list[name]->leave();
            }
        }
    }

    cout << output;

}

