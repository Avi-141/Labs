#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define in(x) scanf(" %d",&x);
#define out(x) printf("%d ",x);

int MAX=9999;
int pg,frames;
int num_pages;
int pageref[100];
int page[100];
int hit=0,miss=0;
int pagefault=0;
int hitcount=0;

void input(){
    
   printf("Enter length of page ref seq");
   scanf("%d",&num_pages);
   printf("Enter the page sequence\n");
   for(int i=0;i<num_pages;i++)
     scanf("%d",&pageref[i]);
    printf("Enter number of frames\n");
    in(frames);
	
}
void init(){
    hitcount=0;
    pagefault=0;
	for(int i=0;i<num_pages;i++)
	  page[i]=MAX;
}
int isHit(int data)
{
    hit=0;
    for(int j=0; j<frames; j++)
    {
        if(page[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
 
int hitIndex(int data)
{
    int hitind;
    for(int k=0; k<frames; k++){
        if(pageref[k]==data){
            hitind=k;
            break;
        }
    }
    return hitind;
}

void dispPages()
{
    for (int k=0; k<frames; k++){
        if(page[k]!=9999)
             out(page[k]);
    }
 
}
void pagefaults(){
    printf("\n");
	printf("Total page faults are %3d",pagefault);
    printf("\n");
    printf("\nTotal hits are %3d",hitcount);
}

void fifo(){
	int k;
	init();
	for(int i=0;i<num_pages;i++){
	    printf("\nPage [%d]\t:",pageref[i]);
	   if(isHit(pageref[i])==0){
	    for(k=0;k<frames-1;k++)
	       page[k]=page[k+1];

	       page[k]=pageref[i];
	       pagefault++;
	       dispPages();
	       }
	      else{
            hitcount++;
	       printf("No page fault");
	      }

	}
	pagefaults();
}
void LRU()
{
    int i,j,k;
    init();
 
    int least[50];
    for(i=0; i<num_pages; i++)
    {
 
        printf("\nPage %d :",pageref[i]);
 
        if(isHit(pageref[i])==0){

            for(j=0; j<frames; j++){
                int pg=page[j];
                int found=0;
                for(k=i-1; k>=0; k--){

                    if(pg==pageref[k]){
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<frames; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            page[repindex]=pageref[i];
            pagefault++;
 
            dispPages();
        }
        else{
            hitcount++;
            printf("No page fault!");
        }
    }
    pagefaults();
}
void LFU(){
    int i,j,k;
    int usedcnt[100];
    int least,repin,sofarcnt=0,bn;
    init();
    memset(usedcnt,0,sizeof(int)*frames);

    for(i=0; i<num_pages; i++)
    {
 
        printf("\nPages[%d] :",pageref[i]);
        if(isHit(pageref[i]))
        {
            hitcount++;
            int hitind=hitIndex(pageref[i]);
            usedcnt[hitind]++;
            printf("No page fault!");
        }
        else
        {
            pagefault++;
            if(bn<frames)
            {
                page[bn]=pageref[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                least=9999;
                for(k=0; k<frames; k++)
                    if(usedcnt[k]<least)
                    {
                        least=usedcnt[k];
                        repin=k;
                    }
                page[repin]=pageref[i];
                sofarcnt=0;
                for(k=0; k<=i; k++)
                    if(pageref[i]==pageref[k])
                        sofarcnt=sofarcnt+1;
                usedcnt[repin]=sofarcnt;
            }
 
            dispPages();
        }
 
    }
    pagefaults();
}
/*void MFU()
{
    int i,j,k;
    int usedcnt[100];
    int most,repin,sofarcnt=0,bn;
    init();
    memset(usedcnt,0,sizeof(int)*frames);
    for(i=0; i<num_pages; i++)
    {
 
        printf("\nPages[%d] :",pageref[i]);
        if(isHit(pageref[i]))
        {
            hitcount++;
            int hitind=hitIndex(pageref[i]);
            usedcnt[hitind]++;
            printf("No page fault!");
        }
        else
        {
            pagefault++;
            if(bn<frames)
            {
                page[bn]=pageref[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                most=-1;
                for(k=0; k<frames; k++)
                    if(usedcnt[k]>most)
                    {
                        most=usedcnt[k];
                        repin=k;
                    }
                page[repin]=pageref[i];
                sofarcnt=0;
                for(k=0; k<=i; k++)
                    if(pageref[i]==pageref[k])
                        sofarcnt=sofarcnt+1;
                usedcnt[repin]=sofarcnt;
            }
 
            dispPages();
        }
 
    }
    pagefaults();
}*/

void Optimal()
{
    int i,j,k;
    init();
    int near[50];
    for(i=0; i<num_pages; i++)
    {
 
        printf("\nPage[%d] :",pageref[i]);
 
        if(isHit(pageref[i])==0)
        {
 
            for(j=0; j<frames; j++)
            {
                int pg=page[j];
                int found=0;
                for(k=i; k<num_pages; k++)
                {
                    if(pg==pageref[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<frames; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            page[repindex]=pageref[i];
            pagefault++;
 
            dispPages();
        }
        else{
            hitcount++;
            printf("No page fault");
        }
    }
    pagefaults();
}
void Secondchance()
{   int i,j,k;
    int usedbit[50];
    int victimptr=0;
    init();
    memset(usedbit,0,sizeof(int)*frames);
    for(i=0; i<num_pages; i++)
    {
        printf("\nFor %d:",pageref[i]);
        if(isHit(pageref[i]))
        {
            hitcount++;
            printf("No page fault!");
            int hitindex=hitIndex(pageref[i]);
            if(usedbit[hitindex]==0)
                usedbit[hitindex]=1;
            printf("%d\t%d",usedbit[hitindex],hitindex);
           // printf("\n");
        }
        else
        {
            pagefault++;
            if(usedbit[victimptr]==1)
            {
                do
                {
                    usedbit[victimptr]=0;
                    victimptr++;
                    printf("%d",victimptr);
                    if(victimptr==frames)
                        victimptr=0;
                }
                while(usedbit[victimptr]!=0);
            }
            if(usedbit[victimptr]==0)
            {
                page[victimptr]=pageref[i];
                usedbit[victimptr]=1;
                victimptr++;
            }
            dispPages();
 
        }
        if(victimptr==frames)
            victimptr=0;
    }
    pagefaults();
}
int main()
{
    int ch;
    while(1)
    {
        printf("\nPage Replacement\n1.Data\n2.FIFO\n3.LRU\n4.LFU\n5.Optimal\n6.Second chance\n7.eXIT\n");
        puts("Enter data :\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            input();
            break;
        case 2:
            fifo();
            break;
        case 3:
            LRU();
            break;
        case 4:
            LFU();
            break;
        case 5:
            Optimal();
            break;
        case 6: 
             Secondchance();
        default:
        return 0;
           break;
        }
    }
 }
 // 20
 // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 
 // 3 
