#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 10000000
/*void permutation()
{
	for(int i=1;i<n;i++)
	 swap(a,i,n-1)
	 permutation()
	 swap(a,i,n-1)
}*/
void permutation(int a[25][25], int b[25], int n, int i, int *min_cost, int c[25])
{
	if(i==n-1)
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=a[j][b[j]];
		}

		if(sum<=*min_cost)
		{
			*min_cost=sum;

			for(int j=0;j<n;j++)
			{
				c[j]=b[j];
			}
		}
		return;
	}

	int temp;
	for(int j=i;j<n;j++)
	{
		temp=b[i];
		b[i]=b[j];
		b[j]=temp;

		permutation(a,b,n,i+1,min_cost,c);

		temp=b[i];
		b[i]=b[j];
		b[j]=temp;
	}
}

int main()
{
	int a[25][25];
	printf("Enter number of people to be assigned jobs: ");
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Enter cost of job %d for person %d: ",j+1,i+1);
			scanf("%d",&a[i][j]);
		}
	}

	int min_cost=INT_MAX;
	int flag=0;
	int c[25];
	int b[25];
	for(int i=0;i<n;i++)
	{
		b[i]=i;
	}
	int i=0;
	permutation(a,b,n,i,&min_cost,c);

	for(i=0;i<n;i++)
	{
		printf("Person %d should be assigned job %d\n", i+1,c[i]+1);
	}
	printf("The cost for this minimum assignment is: %d\n", min_cost);
}