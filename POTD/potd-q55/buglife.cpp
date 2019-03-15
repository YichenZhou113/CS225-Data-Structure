#include <vector>
using namespace std;
#define M 1 //masculino
#define F (-1) //femenino
#define U 0 //no marcado
#define PB push_back
// returns true if a counterexample is found
vector<int> adj[21000];
short int g[21000];

bool DFS(int r){
    bool res = true;
    for(int i = 0; i < adj[r].size(); i++){
        int v = adj[r][i];
        if(g[v] == g[r]) return false;
        if(g[v] == U){
            g[v] = -g[r];
            res = res and DFS(v);
        }
    }
    return res;
}

bool bugLife(int numBugs, vector<int> &b1, vector<int> &b2) {
    // code to make ignore the warning
    // delete and replace with your own.
    //int i = numBugs + b1[0] + b2[0];
    //if (i>0) return false; else return false;
    for(int i = 0; i < numBugs; i++){
            g[i] = U;
            adj[i].clear();
        }

    for( int i = 0; i < int(b1.size()); i++){
            adj[b1[i]].PB(b2[i]); adj[b2[i]].PB(b1[i]);
        }

    bool result = true;
          for(int i = 0; i < numBugs; i++){
              if(g[i] == U){
                  g[i] = M;
                  result = result and DFS(i);
              }
          }

    return result;
}
