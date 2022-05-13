#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct memoryBlocks
{
    bool isAllocated;
    int blockSize;
    int processSize;
    int internalFrag;
    string processName;
};

void printLines()
{
    for (int i = 0; i < 110; i++)
    {
        cout << "_";
    }
    cout << "\n";
}

void Display(vector<memoryBlocks> &memBlocks, int noOfBlocks, int internalFrag, int externalFrag, vector<pair<int, string>> &leftProcess)
{
    cout << "Memory Allocation Table Of Next Fit Allgorithm\n"
         << "\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "| Block No\t"
         << "Size Of Block\t"
         << "Proces Allocated\t"
         << "Internal Fragmentation  |\n";
    cout << "---------------------------------------------------------------------------------\n";
    for (int bindx = 0; bindx < noOfBlocks; bindx++)
    {
        if (memBlocks[bindx].isAllocated == false)
            cout << "|  " << bindx + 1 << "\t\t\t" << memBlocks[bindx].blockSize << "\t\t"
                 << "  ---  "
                 << "\t\t\t"
                 << "--"
                 << "\t\t|\n";

        else
            cout << "|  " << bindx + 1 << "\t\t\t" << memBlocks[bindx].blockSize << "\t\t"
                 << memBlocks[bindx].processSize << "[" << memBlocks[bindx].processName << "]"
                 << "\t\t\t" << memBlocks[bindx].internalFrag << "\t\t|\n";
    }
    cout << "---------------------------------------------------------------------------------\n";

    cout << "\n";
    printLines();
    printLines();
    if (!leftProcess.empty())
    {
        cout << "Process Whom Memory Is Not Allocated : \n";
        for (int lindx = 0; lindx < leftProcess.size(); lindx++)
        {
            cout << leftProcess[lindx].second << " " << leftProcess[lindx].first << "\n";
        }
    }

    printLines();
    cout << "\n\n";
    printLines();
    cout << "Total Internal Fragmentation = " << internalFrag << "\n";
    cout << "Total External Fragmentation = " << externalFrag << "\n";
    printLines();
}

void Next_Fit(vector<memoryBlocks> &memBlocks, int noOfBlocks, vector<pair<int, string>> &processSizes, int noOfProcess)
{
    vector<pair<int, string>> leftProcess;
    int memIter = -1;
    for (int pindx = 0; pindx < noOfProcess; pindx++)
    {
        bool isProcessMemAllocated = false;
        int bindx = memIter;
        // bindx = (bindx + 1) % noOfBlocks;
        bindx++;
        for (bindx; bindx != memIter; bindx = (bindx + 1) % noOfBlocks)
        {
            if (memBlocks[bindx].isAllocated == true || memBlocks[bindx].blockSize < processSizes[pindx].first)
                continue;

            isProcessMemAllocated = true;

            memBlocks[bindx].isAllocated = true;
            memBlocks[bindx].processName = processSizes[pindx].second;
            memBlocks[bindx].processSize = processSizes[pindx].first;
            memBlocks[bindx].internalFrag = memBlocks[bindx].blockSize - processSizes[pindx].first;
            break;
        }
        memIter = bindx;
        if (isProcessMemAllocated == false)
        {
            leftProcess.push_back(processSizes[pindx]);
        }
    }
    int externalFrag = 0, internalFrag = 0;
    if (leftProcess.empty() == false)
    {
        for (int bindx = 0; bindx < noOfBlocks; bindx++)
        {
            if (memBlocks[bindx].isAllocated == true)
                continue;
            externalFrag += memBlocks[bindx].blockSize;
        }
    }
    for (int bindx = 0; bindx < noOfBlocks; bindx++)
    {
        internalFrag += memBlocks[bindx].internalFrag;
    }
    Display(memBlocks, noOfBlocks, internalFrag, externalFrag, leftProcess);
}

int main()
{
    // system("cls");

    printLines();
    cout << "Vicky Gupta 20BCS070\n";
    cout << "Next Fit Memory Allocation Algorithm\n";
    printLines();
    printLines();

    int noOfBlocks;
    cout << "Enter The No Of Blocks Of Memory : ";
    cin >> noOfBlocks;

    printLines();
    int noOfProcess;
    cout << "Enter The No Of Process : ";
    cin >> noOfProcess;

    printLines();
    vector<memoryBlocks> memBlocks(noOfBlocks);
    cout << "Enter The Sizes Of Blocks : ";
    for (int i = 0; i < noOfBlocks; i++)
    {
        cin >> memBlocks[i].blockSize;
        memBlocks[i].isAllocated = false;
        memBlocks[i].processSize = 0;
        memBlocks[i].processName = "";
        memBlocks[i].internalFrag = 0;
    }

    printLines();
    vector<pair<int, string>> processSizes(noOfProcess);
    cout << "Enter The Sizes Of Process : ";
    for (int i = 0; i < noOfProcess; i++)
    {
        cin >> processSizes[i].first;
        processSizes[i].second = "P";
        processSizes[i].second += to_string(i + 1);
    }
    printLines();

    cout << "\n\n";
    printLines();
    printLines();
    Next_Fit(memBlocks, noOfBlocks, processSizes, noOfProcess);
    return 0;
}

/*
No Of Blocks -> 5
No Of Process -> 4

Blocks Sizes -> 100 500 200 450 600
Process Sizes -> 212 417 112 426

Block No   Size Of Block   Process Allocated   Internal Fragmentation
    1            200              200(p2)            0
    2            100              100(p3)            0
    3            300              250(p1)            50
    4            400              350(p4)            50
    5            500                ---              --

Total Internal Fragmentation = 100
Total External Fragmentation = 0


Porcess Sizes -> 450 210 210 250
450->500  Internal Frag 50
210->300  Internal Frag 90
110->400  Internal Frag 190

Now 250 Process Not Allocated To Due To External Frag 300
Now Internal Frag 330

5
4
100 500 200 450 600
426 417 112 200

5
4
50 150 300 350 600
300 25 125 50
*/