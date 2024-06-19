#include<bits/stdc++.h>

using namespace std;

int t,s,a,v;

int MA[50][50];

int main(){
    cin >> t;

    while(t--){
        cin >> s;

        cin >> v >> a;

        for(int i=0;i<=v;i++){
            for(int j=0;j<=v;j++){
                MA[i][j] = 0;
            }
        }


        int ans = 0;
        for(int i=0;i<a;i++){
            int u,v;
            cin >> u >> v;

            if(u > v) swap(u,v);
            if(MA[u][v] == 0){
                MA[u][v] =1;
                ans+=2;
            }
        }

        cout << ans << "\n";

    }
}