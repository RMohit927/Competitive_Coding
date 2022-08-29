#include<bits/stdc++.h>
using namespace std;

#define f_input freopen("inputs/second_second_meaning_input/second_second_meaning_input.txt", "r", stdin)
#define f_output freopen("inputs/second_second_meaning_input/second_second_meaning_output.txt", "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"

bool helper(string a, string b){
	for(int i=0; i<(int)a.size(); i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}

void process(){
	int n;
	string s;
	cin >> n >> s;
	n--;
	for(int i=0; i<=1023; i++){
		string tmp;
		for(int j=0; j<10; j++){
			tmp += ((i>>j)&1?'.':'-');
		}
		if(!helper(s, tmp) && !helper(tmp, s)){
			n--;
			cout << tmp << endl;
			if(n==0)return;
		}
	}
}

int main(){
	fastio;

#ifndef ONLINE_JUDGE
	f_input;
	f_output;
#endif
	
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": " << endl;
		process();
	}
	
	return 0;
}
