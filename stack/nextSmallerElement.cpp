#include<bits/stdc++.h>
using namespace std;
//closest nextsmaller to the left 
vector<int> nextSmallerElementToLeft(vector<int>&arr){
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top()>arr[i]){
            st.pop();
        }
        ans.push_back(!st.empty() ? st.top() :-1);

        st.push(arr[i]);
    }
    return ans;
}
//closest next smaller to the right 
vector<int>nextSmallerElementToRight(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    stack<int>st;
    int n = arr.size()-1;
    for(int i=n ;i>=0;i--){
        while(!st.empty() && st.top()>arr[i]){
            st.pop();
        }
            ans[i]=!st.empty()?st.top():-1;
        st.push(arr[i]);    
    }

    return ans;
}
int main(){
    vector<int>arr={4,5,2,10,8};
    vector<int>ans=nextSmallerElementToRight(arr);
  // vector<int>ans= nextSmallerElementToLeft(arr);
    for(int i : ans)cout<<i<<"  ";
    
}
