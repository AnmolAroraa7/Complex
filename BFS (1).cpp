using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
class BFS{
public:
    vector<vector<int>> alist;
    bool *visited;
    int v;

    BFS()
    {
        cout << "Enter the number of nodes: ";
        cin >> v;
        visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
    }
   

    void BFSs(int s){
    	
    	queue<int> q;
    	q.push(s);
    	visited[s] =true;
    	while(!q.empty()){
    		int u=q.front();
    		
    		q.pop();
    		cout<<u<<" ";
    		 for (int i = 0; i < alist[u].size(); i++)
        {
            if (visited[alist[u][i]] == false)
            {   visited[alist[u][i]] = true;
                q.push(alist[u][i]);
                
            }
        }
    		
    	}
    }
    void BFSdis(){
    	for(int i=0;i<v;i++){
    			if(visited[i]==false){
    				BFSs(i);
    			}
    		}
    		
    	}
    
    void input(){
   
    vector<int> adj;
    int node = 0;
        int a;
        int neighbors;
        for (int i = 0; i < v; i++)
        {
            cout << "Enter the number of neighbours of node " << node++ << " ";
            cin >> neighbors;
            cout << "Enter the nodes to which this node has an edge ";
            while (neighbors != 0)
            {
                cin >> a;
                adj.push_back(a);
                neighbors--;
            }
            alist.push_back(adj);
            adj.clear();
        }
    }
   
  };
int main(){
	
	BFS obj;
    obj.input();
	
  //obj.print(v);
	
  obj.BFSdis();
  return 0;
	
}




