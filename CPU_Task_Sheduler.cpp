#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct proc{
    int entry;
    int ptime;
};

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

struct comparesjf{
    bool operator()(const proc& a, const proc& b) {
        return a.ptime > b.ptime;
    }
};

class Algorithms{
    
    public:
    
    void FCFS(vector<int> processes){
        
        queue<int> q;
        int n = processes.size();
        
        for(int num: processes){
            q.push(num);
        }
        
        int t = 0;
        cout << "\nFirst Come First Serve Schedule:\n" << endl;
        
        for(int i = 0; i < n; i++){
            int temp = q.front();
            cout << "process " << i+1 << " starts at " << t << " ends at " << t + temp << endl;
            q.pop();
            t += temp;
        }
        
    }
    
    void SJF(vector<int> processes){
        
        priority_queue<proc , vector<proc> , comparesjf> MinHeap;
        int c = 0;
        int n = processes.size();
        
        for(int i: processes){
            proc temp;
            temp.ptime = i;
            temp.entry = c+1;
            MinHeap.push(temp);
            c++;
        }
        
        cout << "\nShortest Job First Shedule:\n" << endl;
        int t = 0;
        
        for(int i = 0; i < n; i++){
            proc temp = MinHeap.top();
            cout << "process " << temp.entry << " starts at " << t << " ends at " << t + temp.ptime << endl;
            t += temp.ptime;
            MinHeap.pop();
        }
    }
    
    void RR(vector<int> processes, int quantum){
        queue<proc> q1;
        queue<proc> q2;
        
        int c = 0;
        int n = processes.size();
        
        for(int i: processes){
            proc temp;
            temp.ptime = i;
            temp.entry = c+1;
            q1.push(temp);
            c++;
        }
        
        cout << "\nRound Robin Shedule:\n" << endl;
        int t = 0;
        
        while((!q1.empty()) || (!q2.empty())){
        
            while(!q1.empty()){
            proc temp = q1.front();
            cout << "process " << temp.entry << " starts at " << t << " ends at " << t + min(temp.ptime, quantum) << endl;
            t += min(temp.ptime, quantum);
            temp.ptime -= quantum;
            if(temp.ptime > 0){
                q2.push(temp);
            }
            q1.pop();
            }
        
            while(!q2.empty()){
            proc temp = q2.front();
            cout << "process " << temp.entry << " starts at " << t << " ends at " << t + min(temp.ptime, quantum) << endl;
            t += min(temp.ptime, quantum);
            temp.ptime -= quantum;
            if(temp.ptime > 0){
                q1.push(temp);
            }
            q2.pop();
            }
        
        }
    }
};

int main()
{
    vector<int> arr;
    int n;
    int q;
    cout << "CPU TASK SHEDULING\n\n" << "Enter the number of process : ";
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "Enter duration of process " << i+1 << " : ";
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "\nEnter quantum for Round Robin : ";
    cin >> q;
    Algorithms A;
    A.FCFS(arr);
    A.SJF(arr);
    A.RR(arr, q);
    return 0;
}
