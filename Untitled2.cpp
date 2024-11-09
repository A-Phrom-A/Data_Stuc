#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class node{
	public :
	int D;
	int W;
	
	node(int d,int w = 1) : D(d) ,W(w){}
};

class G{
	public :
		int n;
		vector<list<node > > adj;
		bool C ;
		
		G(int V) : n(V),adj(V),C(false) {};
		
	void add(int S, int D, int W = 1){
		adj[S].push_back(node(D, W));
		if(!C){
			adj[D].push_back(node(S, W));
		}
	}	
	
	void P(){
		for(int i = 0;i < n;i++){
			cout << i << " : ";
			for(list<node>::iterator it = adj[i].begin(); it != adj[i].end();++it){
				cout << it->D << "[" << it->W << "] ";
			}
			cout << endl;
		}
	}
	
	void BFS(int S){
		vector<bool> vis(n,false);
		queue<int> q;
		
		vis[S] = true;
		q.push(S);
		
		while(!q.empty()){
			int i =q.front();
			q.pop();
			
			cout << i << " ";
			for(list<node>::iterator it = adj[i].begin(); it != adj[i].end();++it){
				if(!vis[it->D]){
					vis[it->D] = true;
					q.push(it->D);			}
			}
		}
		
	}
	
	void DFS_H(int i,vector<bool>& vis){
		vis[i] = true;
		cout << i << " ";
		
		for(list<node>::iterator it = adj[i].begin(); it != adj[i].end();++it){
				if(!vis[it->D]){
					DFS_H(it->D,vis);		
				}
			}
		
	}
	
	void DFS(int S){
		vector<bool> vis(n,false);
		DFS_H(S,vis);
	}
};

int main() {
    G graph(5); // ?????????????? 5 ????

    // ???????? (?????????????????????????)
    graph.add(0, 1);
    graph.add(0, 4);
    graph.add(4, 0);
    graph.add(1, 2);
    graph.add(1, 3);
    graph.add(1, 4);
    graph.add(2, 3);
    graph.add(3, 4);

    cout << "Adjacency List Representation:\n";
    graph.P();

    int startNode = 2;

    cout << "BFS Traversal starting from vertex " << startNode << ": ";
    graph.BFS(startNode);
    cout << endl;

    cout << "DFS Traversal starting from vertex " << startNode << ": ";
    graph.DFS(startNode);
    cout << endl;

    return 0;
}
