#include <bits/stdc++.h>
#include<string.h>
#include<map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v)
{
    parent[v] = v;
    size[v]=1;
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += b;
    }
}


int main()
{
    int nodes,e;
    cout<<"nodes & edges"<<endl;
    cin>>nodes>>e;
   vector<pair<int,pair<int,int>>>edges;
   int u,v,weight,totalCost=0;

   for(int i=0;i<e;i++){
    cin>>u>>v>>weight;
    edges.push_back({weight,{u,v}});
   }

   sort(edges.begin(),edges.end());
for(int i=1;i<=nodes;i++){
    make(i);
}
cout<<"(u & v)-> weight"<<endl;
   for(auto &edge:edges){
    weight=edge.first;
    u=edge.second.first;
    v=edge.second.second;
    if(find(u)==find(v)){
        continue;
    }
    Union(u,v);
totalCost+=weight;

cout<<u<<" "<<v<<" "<<"-> "<<weight<<endl;
   }
cout<<"minimum cost is: "<<totalCost<<endl;

    return 0;
}
