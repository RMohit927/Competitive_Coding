#include<bits/stdc++.h>
using namespace std;

#define f_input freopen("inputs/second_friend_input/second_friend_input.txt", "r", stdin)
#define f_output freopen("inputs/second_friend_input/second_friend_output.txt", "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"

void process(){
	int r, c;
	bool flag = false;
	cin >> r >> c;
	vector<vector<char>> arr(r, vector<char>(c));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
			if(arr[i][j]=='^') flag=true;
		}
	}
	if(r==1||c==1){
		if(flag){
			cout << "Impossible" << endl;
			return;
		}else{
			cout << "Possible" << endl;
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					cout << arr[i][j];
				}
				cout << endl;
			}
			return;
		}
	}
	cout << "Possible" << endl;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout << '^';
		}
		cout << endl;
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
		cout << "Case #" << i << ": ";
		process();
	}
	
	
	return 0;
}
