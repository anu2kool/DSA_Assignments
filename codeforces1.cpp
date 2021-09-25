#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,r,s;
		cin>>n>>l>>r>>s;
		if(n==1){
			cout<<1<<endl;
		}
		else{
			int count=r-l+1;
			long long int maxsum=0;
			int cnt=count;
			int num=n;
			while(cnt>0){
				maxsum+=num;
				num--;
				cnt--;
			}
			if(((count*(count+1))/2)>s){
				cout<<-1<<endl;
			}
			
			else if(maxsum<s){
				cout<<-1<<endl;
			}
			else{
				vector<int>nums;
				int sum=0;
				for(int i=1; i<count; i++){
					nums.push_back(i);
					sum+=i;
				}
				nums.push_back(s-sum);
				int diff=nums[count-1]-n;
				int i=count-2;
				nums[count-1]=min(n,nums[count-1]);
				while(diff>0){
					if(i==-1){
						i=count-2;
					}
					nums[i]++;
					i--;
					diff--;			
				}
				/*cout<<"nums"<<endl;
				for(int i=0; i<nums.size(); i++){
					cout<<nums[i]<<" ";
				}
				cout<<endl;
				*/
				int hash[n+1];
				int possible=1;
				memset(hash,0,sizeof(hash));
				for(int i=0; i<nums.size(); i++){
					if(nums[i]<=n){
						hash[nums[i]]=1;
					}
					else{
						possible=0;
						break;
					}
				}
				if(!possible){
					cout<<-1<<endl;
				}
				else{
					int counter=0;
					for(int i=1; i<=n; i++){
						if(hash[i]==1){
							counter++;
						}
					}
					if(counter!=count){
						cout<<-1<<endl;
					}
					else{
						int h[n+1];
						vector<int>ans;
						for(int i=0; i<n; i++){
							ans.push_back(0);
						}
						l--;
						r--;
						int k=0;
						for(int i=l; i<=r; i++){
							ans[i]=nums[k++];
						}
						vector<int>leftones;
						for(int i=1; i<=n; i++){
							if(hash[i]!=1){
								leftones.push_back(i);
							}
						}
						k=0;
						for(int i=0; i<ans.size(); i++){
							if(i<l || i>r){
								ans[i]=leftones[k++];
							}
						}
						for(int i=0; i<n; i++){
							cout<<ans[i]<<" ";
						}
						cout<<endl;
					}
				}
				
			}
		}
		
	}
	return 0;
}
