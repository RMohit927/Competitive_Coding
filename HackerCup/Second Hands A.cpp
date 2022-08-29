#include<bits/stdc++.h>
using namespace std;

#define f_input freopen("inputs/second_hands_input/second_hands_input.txt", "r", stdin)
#define f_output freopen("inputs/second_hands_input/second_hands_output.txt", "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"


void process(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int j=0; j<n; j++) cin >> arr[j];
	if(k*2 < n){
		cout << "NO";
		return;
	}
	map<int, int> m;
	for(int i=0; i<n; i++){
		m[arr[i]]++;
		if(m[arr[i]] == 3){
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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
		cout << "Case #" << i << ": ";
		process();
		cout << endl;
	}
	
	return 0;
}
