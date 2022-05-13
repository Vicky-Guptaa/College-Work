#include <iostream>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

struct Fifo_State
{
    vector<int> state;
    bool isFault;
    int top;
};

void printLines()
{
    for (int i = 0; i < 120; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

void Print(vector<Fifo_State> &allStates, int pageFaults)
{
    printLines();
    cout << "Page Replacement Table\n";
    printLines();
    printLines();
    cout << "Page Reference\n";
    for (int state = 0; state < allStates.size(); state++)
    {
        cout << "|" << allStates[state].top << "|\t";
    }
    cout << "\n\n";

    for (int state = allStates[0].state.size() - 1; state >= 0; state--)
    {
        for (int i = 0; i < allStates.size(); i++)
        {
            if (allStates[i].state[state] == -1)
                cout << "|"
                     << "_"
                     << "|\t";
            else
                cout << "|" << allStates[i].state[state] << "|\t";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int state = 0; state < allStates.size(); state++)
    {
        if (allStates[state].isFault)
        {
            cout << "|"
                 << "Miss"
                 << "\t";
        }
        else
        {
            cout << "|"
                 << "Hit"
                 << "\t";
        }
    }
    cout << "\n";
    printLines();
    cout << "Total Page Faults : " << pageFaults << "\n";
    double averagePageFaults = pageFaults / (double)allStates.size();
    cout << "Average Page Faults : " << averagePageFaults << "\n";
    printLines();
}

void Page_Replacement_Fifo(int noOfPageFrames, vector<int> &pageReferences)
{
    vector<Fifo_State> allStates;
    vector<int> frame(noOfPageFrames, -1);
    int firstIndex = 0, pageFaults = 0, prIndex, top = 0;

    for (prIndex = 0; top != noOfPageFrames; prIndex++)
    {
        bool isFind = 0;
        for (int fIndex = 0; fIndex < top; fIndex++)
        {
            if (frame[fIndex] == pageReferences[prIndex])
            {
                isFind = true;
                break;
            }
        }
        Fifo_State newState;
        if (isFind)
        {
            newState.isFault = 0;
        }
        else
        {
            frame[top] = pageReferences[prIndex];
            newState.isFault = 1;
            pageFaults++;
            top++;
        }
        newState.top = pageReferences[prIndex];
        newState.state = frame;
        allStates.push_back(newState);
    }

    for (prIndex; prIndex < pageReferences.size(); prIndex++)
    {
        bool isFind = 0;
        for (int fIndex = 0; fIndex < noOfPageFrames; fIndex++)
        {
            if (frame[fIndex] == pageReferences[prIndex])
            {
                isFind = true;
                break;
            }
        }
        if (isFind)
        {
            Fifo_State newState;
            newState.isFault = 0;
            newState.top = pageReferences[prIndex];
            newState.state = frame;
            allStates.push_back(newState);
        }
        else
        {
            Fifo_State newState;
            newState.isFault = 1;
            pageFaults++;
            newState.top = pageReferences[prIndex];
            for (int fIndex = 0; fIndex <= noOfPageFrames; fIndex++)
            {
                if (frame[fIndex] == pageReferences[firstIndex])
                {
                    firstIndex++;
                    frame[fIndex] = pageReferences[prIndex];
                    break;
                }
            }
            newState.state = frame;
            allStates.push_back(newState);
        }
    }
    Print(allStates, pageFaults);
}

int main()
{
    system("cls");
    printLines();
    cout << "Vicky_Gupta_20BCS070\n";
    printLines();
    cout << "First In First Out Page Replacement Algorithm\n";
    printLines();
    printLines();
    int noOfPageFrames;

    cout << "Enter The No Of Page Frames \n";
    cin >> noOfPageFrames;

    int noOfPageReference;
    cout << "Enter The No Of Page Reference\n";
    cin >> noOfPageReference;

    vector<int> pageReferences(noOfPageReference);
    cout << "Enter The Page References\n";
    for (int i = 0; i < noOfPageReference; i++)
    {
        cin >> pageReferences[i];
    }

    Page_Replacement_Fifo(noOfPageFrames, pageReferences);
    return 0;
}

/*
3
7
1 3 0 3 5 6 3


4
12
0 2 1 6 4 0 1 0 3 1 2 1

4
13
7 0 1 2 0 3 0 4 2 3 0 3 2

3
10
4 7 6 1 7 6 1 2 7 2
*/