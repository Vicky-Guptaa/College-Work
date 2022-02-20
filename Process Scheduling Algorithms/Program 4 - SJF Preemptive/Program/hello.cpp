#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    unordered_map<int, int> umap;
    map<int, int> map;
    umap[1] = 2;
    map[1] = 2;
    map[100] = 200;
    umap[100] = 200;
    umap[7] = 8;
    map[7] = 8;
    map[-1] = 0;
    umap[-1] = 0;
    for (auto x : map)
    {
        cout << x.first << "\t" << x.second << "\n";
    }
    for (auto x : umap)
    {
        cout << x.first << "\t" << x.second << "\n";
    }
    return 0;
}