#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> adj[], int n) {
    vector<bool>visited(n,false);
    queue<int>q;

    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int node= q.front();
        q.pop();
        cout<<node<<endl;
        for(int neighbor : ads[node]){
            if(!visited[node]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
}

//make a visited array of size n initialize it with all false 
//visited array willl keep track if the array is visited while traversal or not 
// initilize a queue and push the first node into it ;

//then in the while loop take  the front element of the queue 
//expand it means travers every node connected to it and put it into the queue 
//make sure to pu the visited neighbor true 