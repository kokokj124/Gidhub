#include<bits/stdc++.h>
using namespace std;
#define FOR(a,b,c) for(ll a=b ; a<=c ; a++)
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define x first
#define y second
//                       Loren_Nam
//bool kt(vector<vector<int>> A, )

bool ktraHinhVuong(int h,int c, vector<vector<int>> A, int ktHinhVuong){
	if(h+ktHinhVuong > A.size() - 1 || c+ktHinhVuong > A[0].size() - 1) return false;
	for(int i = h;i < ktHinhVuong + h; i++)
		for(int j = c;j < ktHinhVuong + c; j++){
			if(A[i][j] == 0) return false;
		}
		return true;
}

bool ktVien(int h,int c, vector<vector<int>> A, int ktHinhVuong){
	if(h+ktHinhVuong+2 > A.size() || c+ktHinhVuong+2 > A[0].size()) return false;
	for(int i=0;i<ktHinhVuong+2;i++){
		if(A[h][c+i] == 1) return false;
		if(A[h+ktHinhVuong+1][c+i] == 1) return false;
		if(A[h+i][c] == 1) return false;
		if(A[h+i][c+ktHinhVuong+1] == 1) return false;
	} return true;
}

int main()
{
	int n,m,test;
	vector<int> countMang;
	cin>>test;
	while(test--){
		cin>>n>>m;
		vector<vector<int>> A(n+2,vector<int>(m+2,0));
		
		for(int i = 1;i<A.size()-1;i++){
			for(int j = 1;j<A[i].size()-1;j++){
				cin>>A[i][j];
			}
		}
		
		int count = 0;
		for(int ktHinhVuong = 5;ktHinhVuong >=2;ktHinhVuong--){
			for(int i = 1;i<A.size()-1;i++){
				for(int j = 1;j<A[i].size()-1;j++){
					if(ktVien(i-1,j-1,A,ktHinhVuong) && ktraHinhVuong(i,j,A,ktHinhVuong)){
						count++;
					}
				}
			}	
		}		
		countMang.push_back(count);
	}
	for(int x:countMang) cout<<x<<endl;
}


