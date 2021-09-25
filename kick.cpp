#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    
    int t;
    cin>>t;
    int cnt=0;
    while(t--){
        cnt++;
        int d,n,k;
        cin>>d>>n>>k;
        int start[n], end[n];
        int height[n];
        for(int i=0; i<n; i++){
            int h;
            int s,e;
            cin>>h>>s>>e;
            start[i]=s;
            end[i]=e;
            height[i]=h;
        }
        ll ans=(ll)0;
        for(int i=1; i<=d; i++){
            vector<int>days;
            for(int j=0; j<n; j++){
                if(i>=start[j] && i<=end[j]){
                    days.push_back(height[j]);
                }
            }
            sort(days.begin(),days.end());
            ll happ=0;
            int index=days.size()-1;
            int counter=k;
            while(index>=0 && counter>0){
                happ+=(ll)days[index];
                index--;
                counter--;
            }
            if(happ>ans){
                ans=happ;
            }
        }
        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
    }
    return 0;
}
