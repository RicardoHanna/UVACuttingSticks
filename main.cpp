#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

#define INT_MAX 9999999

int l, n, c[55], memo[55][55];

int minCost(int left, int right){
    if(left+1 == right) return 0;
    if(memo[left][right] != -1) return memo[left][right];
    int res = 9999999;
    for(int i=left+1;i<right;i++)
        res = min(res, minCost(left,i)+minCost(i,right)+(c[right]-c[left]));
    return memo[left][right] = res;
}
int main()
{
    int cost;
    ifstream fin;
    vector<int>v;
    fin.open("uvacuttingsticks.txt");
    if(!fin){
        cerr<<"error"<<endl;
        return 1;
    }


    while(fin>>l){
        if(l==0) break;
        c[0]=0;
        fin>>n;
        for(int i=1;i<=n;i++){
                fin>>c[i];
                v.push_back(c[i]);
        }
        c[n+1]=l;
        memset(memo,-1,sizeof memo);
       cost=minCost(0,n+1);
       cout<<"The minimum cutting is: "<<cost<<endl;
    }

    return 0;
}
