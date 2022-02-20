#include <bits/stdc++.h>
using namespace std;
struct Process
{
    string pid;
    int bt, art, ct, tat, wt, bit, idx;
};
bool compt(Process p1, Process p2)
{
    return p1.art < p2.art;
}
int main()
{
    cout << "Give the size of the array" << endl;
    int n;
    cin >> n;
    vector<Process> pro(n);
    cout << "Give the details" << endl;
    int k = 0;
    getchar();
    for (auto &i : pro)
    {
        string s;
        getline(cin, s);
        i.pid = s;
        cin >> i.bt >> i.art;
        i.bit = i.bt;
        i.idx = k++;
        getchar();
    }
    cout << "Give the time quantum" << endl;
    int qt;
    cin >> qt;
    vector<string> res;
    vector<int> tim;
    int currIdx = 0, complete = 0, count = 0;
    queue<Process> q;
    // q.push(pro[0]);
    // count++;
    cout << "flag" << endl;
    (q.empty() && complete < n) ? cout << "Queue is empty" : cout << "Queue is not empty";
    while (complete < pro.size())
    {
        for (int i = currIdx; i < n; i++)
        {
            if (i < n && pro[i].art <= count)
            {
                q.push(pro[i]);
                currIdx++;
                cout << "flag" << endl;
            }
        }

        else
        {
            if (q.empty() && complete < n)
            {
                res.push_back("#");
                tim.push_back(count);
                count++;
                cout << "flag-------" << endl;
            }

            else
            {
                Process p1 = q.front();
                if (p1.bit == 0)
                {
                    q.pop();
                    complete++;
                }
                else if (count > 0 && count % qt == 0)
                {
                    q.pop();
                    q.push(p1);
                }
                else
                {

                    q.pop();
                    p1.bit--;
                    q.push(p1);
                    res.push_back(p1.pid);
                    tim.push_back(count);
                    count++;
                }

                cout << "flag?????????" << endl;
            }
        }
    }
    for (auto &i : res)
        cout << i << " ";
    cout << "\n";
    for (auto &i : tim)
        cout << i << " ";

    return 0;
}
// Processes  Burst time  Arrival time  Turn around time
//  p1        10     13         23
//  p2        5     10         15
//  p3        8     13         21
// Average waiting time = 12
// Average turn around time = 19.6667