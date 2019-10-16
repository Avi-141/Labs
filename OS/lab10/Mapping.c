#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define in(x) scanf(" %d",&x);
#define out(x) printf("%d ",x);

void decToBinary(int n) 
{ 
    int binaryNum[8]; 
  
    int i = 0; 
    while (n > 0) { 
  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    }
    printf("Page Number is\n");
    for(int j=i-1;j>i-4;j--)
      printf("%d",binaryNum[j]);

  int dec= 4*binaryNum[i-1] + 2*binaryNum[i-2]+binaryNum[i-3];
   printf("=\t%d",dec);

}

int main(int argc, char const *argv[])
{
	int pg_size = 32;
	int pg_tot = 8;
	int mem_size = pg_size*pg_tot;
	int page_table[pg_tot];
	printf("Populate page table\n");
	for(int i = 0;i<pg_tot;i++){
		printf("page%d->frame ? :",i+1);
		in(page_table[i]);
	}
	int l_add;
	printf("Enter logical address:\n");
	in(l_add);
	int frame_number = (l_add / pg_size) +1;
	int offset = l_add % pg_size;
	int p_add = page_table[frame_number]*pg_size + offset;

	printf("Frame number: %d\n",frame_number);
	printf("offset: %d\n",offset);
	printf("Physical address: %d\n",p_add);
	decToBinary(l_add);
	return 0;
}