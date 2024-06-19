#include<bits/stdc++.h>

using namespace std;

int n,v,d_in[1010],tempo[1010];
vector<int> g[1010];


int main(){
    while(cin >> n){
        
        for(int i=1;i<n;i++){
            g[i].clear();
            d_in[i] = 0;
            tempo[i] = 0;
        }

        queue<int> fila;

        for(int i=1;i<=n;i++){
            cin >> d_in[i];
            for(int j=0;j<d_in[i];j++){
                cin >> v;
                g[v].push_back(i);
            }
            if(d_in[i] == 0){
                fila.push(i);
                tempo[i] = 1;
            }
        }

        while(!fila.empty()){
            int u = fila.front();
            fila.pop();

            for(int v: g[u]){
                d_in[v]--;
                if(d_in[v] == 0){
                    fila.push(v);
                    tempo[v] = tempo[u]+1;
                }
            }
        }

        int resp = 0;
        for(int i=1;i<=n;i++){
            if(tempo[i] == 0){
                resp = -1;
                break;
            }
            resp = max(resp,tempo[i]);
        }

        cout << resp << "\n";
        
    }
}