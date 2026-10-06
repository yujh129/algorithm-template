#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string multiply(string& a,string& b){
    int n=a.size();int m=b.size();
    vector<int> ans(n+m,0);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans[i+j]+=(a[i]-'0')*(b[j]-'0');
        }
    }

    for(int i=0;i<n+m-1;++i){
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }

    string res;
    int i=n+m-1;
    while(i>0 && ans[i]==0) --i;
    for(;i>=0;--i) res.push_back(ans[i]+'0');

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    cout<<multiply(a,b)<<"\n";
}
