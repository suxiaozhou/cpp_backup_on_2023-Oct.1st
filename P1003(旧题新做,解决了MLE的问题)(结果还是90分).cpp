#include <bits/stdc++.h>
using namespace std;

struct rug{
	int x1,y1,x2,y2,num;
}rli[10010];
int n,i,x,y;

int main(){
	cin>>n;
	for (i=0;i<n;i++){
		cin>>rli[i].x1>>rli[i].y1>>rli[i].x2>>rli[i].y2;//未解决：y1不一定小于y2,x1不一定小于x2!
		rli[i].num=i+1;
	}
	cin>>x>>y;
	for (i=n-1;i>=0;i--){
		if (rli[i].x1<=x&&rli[i].y1<=y&&rli[i].x2>=x&&rli[i].y2>=y){
			cout<<rli[i].num<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}