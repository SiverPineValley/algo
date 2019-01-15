// 11723
#include<cstdio>
#include<cstring>
using namespace std;
int S = 0;
int main(void)
{	
	int n, t;
	char o[111];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",o);
		if(!strcmp(o,"add"))
		{
			scanf("%d",&t);
			S = S | (1 << (t-1));
		}
		else if(!strcmp(o,"remove"))
		{
			scanf("%d",&t);
			S = S & ~(1 << (t-1));
		}
		else if(!strcmp(o,"toggle"))
		{
			scanf("%d",&t);
			S = S ^ (1 << (t-1));
		}
		else if(!strcmp(o,"all")) S = (1 << 20) - 1;
		else if(!strcmp(o,"empty")) S = 0;
		else if(!strcmp(o,"check")){
			scanf("%d",&t);
			printf("%d\n",(S & (1 << (t-1))));
		}
	}
	return 0;
}