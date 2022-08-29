#include<bits/stdc++.h>
using namespace std;

#define f_input freopen("inputs/second_second_friend_input/second_second_friend_input.txt", "r", stdin)
#define f_output freopen("inputs/second_second_friend_input/second_second_friend_output.txt", "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"

vector<vector<char>> arr(5002, vector<char>(5002)), arr1(5002, vector<char>(5002));
vector<vector<int>> s(5002, vector<int>(5002));
int r, c;


void dfs(int x, int y){
	stack<pair<int, int>> A;
	A.push({x,y});
	while(!A.empty()){
		pair<int, int> P = A.top(); A.pop();
		int x=P.first, y=P.second;
		if(x<1 || x>r || y<1 || y>c || arr[x][y]=='#') continue;
		arr[x][y]='#';
		s[x-1][y]--; if(s[x-1][y] < 2) A.push({x-1, y});
		s[x+1][y]--; if(s[x+1][y] < 2) A.push({x+1, y});
		s[x][y-1]--; if(s[x][y-1] < 2) A.push({x, y-1});
		s[x][y+1]--; if(s[x][y+1] < 2) A.push({x, y+1});
	}
}

void process(){
	int r, c;
	cin >> r >> c;
	
	
	for(int i=0; i<=r+1; i++){
		for(int j=0; j<=r+1; j++){
			arr[i][j]='.';
			s[i][j]=0;
		}
	}
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j];
			if(arr[i][j]!='#'){
				s[i-1][j]++;
				s[i+1][j]++;
				s[i][j-1]++;
				s[i][j+1]++;
			}
		}
	}
	
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(s[i][j] < 2) dfs(i, j);
		}
	}
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(arr[i][j]=='#' && arr1[i][j]=='^'){
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	cout << "Possible" << endl;
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(arr[i][j]!='#') cout << '^';
			else cout << arr1[i][j];
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
