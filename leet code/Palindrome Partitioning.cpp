

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.


    ***********************************************************
*/


class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool checkpalin(string s){
        for(int i = 0; i < s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]) return false;
        }
        return true;
    }
    
    void dff(int i, string s, vector<string> x){
        if(i==s.length()){
            ans.push_back(x);
        }
        for(int k = i; k < s.length(); k++){
            if(checkpalin(s.substr(i,k-i+1))){
                vector<string> z(x.begin(),x.end());
                cout << s.substr(i,k-i+1) <<" ";
                z.push_back(s.substr(i,k-i+1));
                dff(k+1,s,z);
            }
        }
    }
    
    void df(string s){
        for(int i = 0; i < s.length(); i++){
            if(checkpalin(s.substr(0,i+1))){
                vector<string> x;
                x.push_back(s.substr(0,i+1));
                cout << s.substr(0,i+1) <<" -> ";
                dff(i+1,s,x);
            }
            cout <<"\n";
        }
    }
    
    vector<vector<string>> partition(string s) {
        df(s);
        return ans;
    }
};