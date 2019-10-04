#include <stdio.h>
int curr[5][5];
int maxclaim[5][5];
int avl[5];
int alloc[5] = {0, 0, 0, 0, 0};
int maxres[5];
int running[5];
int safe=0;
int count = 0, i, j, exec, r, p, k = 1;

int main()
{
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }

    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < r; i++) { 
        printf("\nEnter the resource for instance %d: ", k++);
        scanf("%d", &maxres[i]);
    }

    printf("\nEnter maximum resource table:\n");
    for (i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &maxclaim[i][j]);
        }
    }

    printf("\nEnter allocated resource table:\n");
    for (i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &curr[i][j]);
        }
    }

    printf("\nThe resource of instances: ");
    for (i = 0; i < r; i++) {
        printf("\t%d", maxres[i]);
    }

    printf("\nThe allocated resource table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            printf("\t%d", curr[i][j]);
        }

        printf("\n");
    }

    printf("\nThe maximum resource table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            printf("\t%d", maxclaim[i][j]);
        }

        printf("\n");
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            alloc[j] += curr[i][j];
        }
    }

    printf("\nAllocated resources:");
    for (i = 0; i < r; i++) {
        printf("\t%d", alloc[i]);
    }

    for (i = 0; i < r; i++) {
        avl[i] = maxres[i] - alloc[i];
    }

    printf("\nAvailable resources:");
    for (i = 0; i < r; i++) {
        printf("\t%d", avl[i]);
    }
    printf("\n");
    
    int store[10];
    int k=0;
    int req;
    int pno;
    int newr[r];
    printf("Do you want to enter another request?\n");
    puts("1(y)/0(n)");
    scanf("%d",&req);
     if(req==1){
        printf("Enter the process number\n");
        scanf("%d",&pno);
        for(int i=0;i<r;i++)
            scanf("%d",&newr[i]);
    }

    //if(req==1)
    while (count != 0) {
        safe = 0;
        for (i = 0; i < p; i++) {
            if (running[i]){
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (maxclaim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec){
                    printf("\nProcess%d is executing\n", i + 1);
                    store[k++]=i+1;
                    running[i] = 0;
                    count--;
                    safe = 1;

                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];

                    break;
                }
            }
        }
        if (!safe) {
            printf("\n!!UNSAFE!!\n");
            break;
        } else {
            printf("\nSAFE!");
            printf("\nSafe sequence is:");

            for (i = 0; i < k; i++) {
                printf("\tP[%d]", store[i]);
            }

            printf("\n");
        }
    }

}