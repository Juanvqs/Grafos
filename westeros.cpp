#include<bits/stdc++.h>

using namespace std;

int n,comp[1010];
string vizinhos[1010];
vector<int> casa[1010];

void dfs(int u){
    
    for(int i=0;i<n;i++){
        if(vizinhos[u][i] == 'S' && comp[i] == 0){
            comp[i] = comp[u];
            dfs(i);
        }
    }
}

int completeGraph(int x){
    for(int u: casa[x]){
        for(int v: casa[x]){
            if(vizinhos[u][v] == 'D' || vizinhos[u][v] == 'D') return 0;
        }
    }

    return 1;
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> vizinhos[i];
    }

    int cc = 0;
    for(int i=0;i<n;i++){
        if(comp[i] == 0){
            comp[i] = ++cc;
            dfs(i);
        }
        casa[comp[i]].push_back(i);
    }

    vector<int> resp;
    int invalid = 0;
    for(int i=1;i<=cc;i++){
        if(completeGraph(i)) resp.push_back(casa[i].size());
        else{
            invalid = 1;
            break;
        }
    }

    sort(resp.begin(), resp.end(), greater<int>());

    if(invalid){
        cout << "-1\n";
    }else{
        cout << resp.size() << "\n";
        for(int i=0;i<resp.size();i++){
            cout << resp[i];
            if(i<resp.size()-1) cout << " ";
        }
        cout << "\n";
    }
}