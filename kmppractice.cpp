#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	string text = "ABABDABACDABABCABAB";
	string pattern = "AB";
	int m = pattern.size();
	int n = text.size();
	int prefix[m];
	prefix[0]=0;
	int len=0, i=1;
	while(i<m){
		if(pattern[i]==pattern[len]){
			len++;
			prefix[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=prefix[len-1];
			}
			else{
				prefix[i]=0;
				i++;
			}
		}
	}
	for(int i=0; i<m; i++){
		cout<<prefix[i]<<" ";
	}
	cout<<endl;
	i=0;
	int j=0;
	while(i<n){
		if(pattern[j]==text[i]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=prefix[j-1];	
			}
			else{
				i++;
			}
		}
		if(j==m){
			cout<<i-j<<endl;
			j=prefix[j-1];
		}
	}
	
	
	return 0;
}
