using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
class DFS{
public:
    vector<vector<int>> alist;
    bool *visited;
    int v;

    DFS()
    {
        cout << "Enter the number of nodes: ";
        cin >> v;
        visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
    }
   

    void DFSs(){
    	for(int i=0;i<v;i++){
    			if(visited[i]==false){
    				DFSrec(i,visited);
    			}
    		}
    	
    
    }
    void DFSrec(int s, bool vis[]){
    	visited[s]=true;
    	cout<<s<<endl;
    	 for (int i = 0; i < alist[s].size(); i++)
        {
    		if(visited[alist[s][i]]==false){
    			DFSrec(alist[s][i],visited);		
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
	
	DFS obj;
    obj.input();
	
  //obj.print(v);
	
  obj.DFSs();
  return 0;
	
}




