#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define string char*
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int search(string pattern, string texttosearch) 
{ 
    int M = strlen(pattern); 
    int N = strlen(texttosearch); 
    int opcount=0;
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        for (j = 0; j < M; j++) 
        {
        	opcount+=1;
            if (texttosearch[i + j] != pattern[j]) 
                break; 
        }
  
        if (j == M) 
        {
        	printf("%s\n",pattern);
            printf("Matches at idx\t%d", i);
            printf("\n");
            printf("Opcount is\t%d", opcount);
            return opcount;
        }
    }
printf("Opcount is\t%d", opcount);
printf("Not found");
return opcount;

}


int main() 
{ 


    char texttosearch[] = "ABBAABBAA"; 
    char pattern[] = "ABB"; 
    search(pattern, texttosearch); 
} 

/*int main(int argc, char const *argv[])
{
	
    int i;
    char text[100];
    char pattern[20];
    int N,M;
    printf("Enter the length of text");
    scanf("%d",&N);
    printf("Enter the text\n");
    for(i=0;i<N;i++)
    	scanf("%c",&text[i]);
    printf("Enter the length of the patternter\n");
    scanf("%d",&M);
    printf("Enter the patternter\n");
    for(i=0;i<M;i++)
    	scanf("%c",&pattern[i]);

    if(M>N)
    {
    	printf("No match\n");
    	exit(0);
    }


    for(i=0;i<=N-M;i++)
    { 
    	int j;
    	for(j=0;j<=M;j++)
    		if(text[i+j]!=pattern[j])
    			break;
      if(j==M)
      {
      	printf("patterntern matches at %d\n",i);
      }
    }




	return 0;
}*/
