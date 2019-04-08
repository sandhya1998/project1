#include<stdio.h>
int main()
{
	int i, type[1000],a;
	int responsetime[1000];
	printf("Enter Number of processes: ");
	scanf("%d",&a);
	printf("Enter the responsetime\n");
	for(i=0;i<a;i++)
	{
		printf("Response time of P%d (in milliseconds): ",i);
		scanf("%d",&responsetime[i]);
		if(responsetime[i]<1000)
		{
			type[i]=1;
		}
		else
		{
			type[i]=0;
		}
	}
	printf("Process Number\tResponse Time\tType\t\t\tPriority");
	for(i=0;i<a;i++)
	{
		printf("\nP%d\t\t%dms\t\t",i,responsetime[i]);
		if(type[i]==1)
		{
			printf("Interactive process\tHigh");
		}
		else
		{
			printf("Non-Interactive process\tLow");
		}
	}
}
