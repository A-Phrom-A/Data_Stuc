#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class G {
public:
    int E[100][100];
    int V;

    G(int n) {
        V = n;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                E[i][j] = 0;
            }
        }
    }

    void add(int x, int y, int w) {
        E[x][y] = w;  // Assuming directed graph; if undirected, add E[y][x] = w as well.
    }

    void BFT(int S) {
        vector<bool> V_BFT(V, false);
        V_BFT[S] = true;
        queue<int> q;
        q.push(S);

        while (!q.empty()) {
            S = q.front();
            q.pop();
            cout << S << " ";

            for (int y = 0; y < V; y++) {  // Loop over all vertices
                if (!V_BFT[y] && E[S][y] > 0) {
                    V_BFT[y] = true;
                    q.push(y);
                }
            }
        }
        cout << endl;  // New line for better output formatting
    }

    void S_DFT(int S, vector<bool>& V_DFT) {
        cout << S << " ";
        V_DFT[S] = true;

        for (int y = 0; y < V; y++) {  // Loop over all vertices
            if (!V_DFT[y] && E[S][y] > 0) {
                S_DFT(y, V_DFT);
            }
        }
    }

    void DFT(int S) {
        vector<bool> V_DFT(V, false);
        S_DFT(S, V_DFT);
        cout << endl;  // New line for better output formatting
    }
};

int main() {
	bool exit = false;
	int n;
	int x,y,w;
	cin  >> n;
	G g(n);
	do{
		char c;
		cin >> c;
	switch(c) {
		case 'e':
			cin >> x;
			cin >> y;
			cin >> w;
			g.add(x,y,w);
			break;
		case 's':
			do{
			
			char C;
			int S ;
			cin  >> C;
			cin >> S;
			switch(C){
				case 'd':
					g.DFT(S);
					break;
				case 'b':
					g.BFT(S);
					break;
				case 'q':
					exit = true;
					break;	
			}
			
			
		}while(!exit);
		
		case 'q':
			exit = true;
			break;
	}
		
	}while(!exit);
	

   /* G graph(5);
    graph.add(0, 1, 1);
    graph.add(0, 2, 1);
    graph.add(1, 3, 1);
    graph.add(2, 3, 1);
    graph.add(3, 4, 1);

    cout << "BFT starting from vertex 0: ";
    graph.BFT(0);

    cout << "DFT starting from vertex 0: ";
    graph.DFT(0);

    return 0;*/
}

