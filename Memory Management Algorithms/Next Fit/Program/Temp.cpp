#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    char Process[10];
    int Psize;
};

void table(struct Node proc[], int no_blocks, int block_size[], int block_fill[],
           int block_allocate_p[], int inter_frag[], int t_if, int t_ef, int no_process, int process_done[])
{
    printf("Block no \t Size of Block \t Process Allocated \t Internal Fragmentation \n");
    for (int i = 0; i < no_blocks; i++)
    {
        printf("%d \t\t %d \t\t\t", i + 1, block_size[i]);
        if (block_fill[i] == 1)
        {
            printf("%d(%s)\t\t\t", proc[block_allocate_p[i]].Psize, proc[block_allocate_p[i]].Process);
            inter_frag[i] = block_size[i] - proc[block_allocate_p[i]].Psize;
            printf("%d", inter_frag[i]);
        }
        else
        {
            printf("Process not Allocated");
            inter_frag[i] = 0;
            t_ef = t_ef + block_size[i];
            printf("\t\t %d", inter_frag[i]);
        }
    }
    for (int i = 0; i < no_blocks; i++)
    {
        t_if = t_if + inter_frag[i];
    }
    printf("\n Total Internal Fragmentation = %d\n", t_if);
    int yes = 0;
    for (int i = 0; i < no_process; i++)
    {
        if (process_done[i] == 0)
        {
            yes = 1;
            break;
        }
    }
    if (yes == 1)
    {
        printf("Total External Fragmentation = %d\n", t_ef);
    }
    else
    {
        printf("Total External Fragmentation is NULL");
    }
}

int main()
{
    int no_block, no_process, t_ef = 0, t_if = 0, k = 0;
    int i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &no_block);
    int block_size[no_block + 1], block_fill[no_block], block_allocate_p[no_block], inter_frag[no_block];
    for (i = 0; i < no_block; i++)
    {
        block_allocate_p[i] = -1;
        inter_frag[i] = 0;
        block_fill[i] = 0;
    }
    for (i = 0; i < no_block; i++)
    {
        printf("Enter size of %d block\n", i + 1);
        scanf("%d", &block_size[i]);
    }

    struct Node proc[no_process];
    int process_done[no_process];
    for (i = 0; i < no_process; i++)
    {
        process_done[i] = 0;
    }
    for (int i = 0; i < no_process; i++)
    {
        printf("enter size of %dth process\n", i + 1);
        scanf("%d", &proc[i].Psize);
        printf("enter name of %dth process\n", i + 1);
        fflush(stdin);
        scanf("%s", proc[i].Process);
    }
    for (i = 0; i < no_process; i++)
    {
        k = no_block;
        block_size[k] = INT_MAX;
    }
    for (j = 0; j < no_block; j++)
    {
        if (block_fill[j] == 0 && block_size[j] >= proc[i].Psize)
        {
            if (block_size[j] < block_size[k])
            {
                k = j;
            }
        }
    }
    if (k != no_block)
    {
        block_allocate_p[k] = i;
        block_fill[k] = 1;
        process_done[i] = 1;
    }
    table(proc, no_block, block_size, block_fill, block_allocate_p, inter_frag, t_if, t_ef, no_process, process_done);
}