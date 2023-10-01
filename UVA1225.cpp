    //UVa1225 - Digit Counting
    //题目：输出1~N所有数字中，统计0~9出现的总次数.
    //已AC
    #include<stdio.h>
    #include<string.h>
    int main(){
    	//freopen("data.in","r",stdin);
    	int T;
    	scanf("%d",&T);
    	while(T--){
    		int n,s[10];
    		memset(s,0,sizeof(s));
    		scanf("%d",&n);
    		for(int i = 1;i <= n; i++){//暴力枚举....
    			int a = i;
    			while(a > 0){ s[(a%10)]++; a /= 10;}
    		}
    		for(int j =0; j <= 8; j++) printf("%d ",s[j]);
    		printf("%d",s[9]);//最后一个不能有空格，不然PE
    		printf("\n");//最后一行必须有换行，不然WA
    	}
    	return 0;
    }
     