#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string& a,const string& b){
    string ans;

    int i=a.size()-1;
    int j=b.size()-1;
    int carry=0;

    while(i>=0 ||j>=0 ||carry){
        int sum=carry;
        if(i>=0) sum+=a[i--]-'0';
        if(j>=0) sum+=b[j--]-'0';
        ans.push_back('0'+sum%10);
        carry=sum/10;
    }

    reverse(ans.begin(),ans.end());

    int pos=ans.find_first_not_of('0');
    if(pos==string::npos) return "0";
    return ans.substr(pos);

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    cout<<add(a,b)<<"\n";
}
