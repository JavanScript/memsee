#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryBlock
{
  int process_id;
  int data_type;
  int size;
  void *memory;
} MemoryBlock;

MemoryBlock *blocks[100];
int numBlocks = 0;

MemoryBlock *allocate()
{
  int process_id;
  int data_type;
  int blockSize;
  printf("enter a process id (number) \n");
  scanf("%d", &process_id);
  printf("choose a data type: \n 1-int   2-float   3-char\n");
  scanf("%d", &data_type);
  printf("How many bytes u need?\n");
  scanf("%d", &blockSize);
  printf("%d %d %d \n", process_id, data_type, blockSize);

  if (data_type < 1 || data_type > 3)
  {
    printf("invalid data type\n");
  }

  MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
  if (numBlocks < 101)
  {
    blocks[numBlocks] = newBlock;
    numBlocks++;
  }
  else
  {
    printf("Maximum number of blocks reached\n");
    free(newBlock->memory);
    free(newBlock);
    return NULL;
  }

  newBlock->process_id = process_id;
  newBlock->data_type = data_type;
  newBlock->size = blockSize;
  newBlock->memory = malloc(blockSize);
  memset(newBlock->memory, 0, blockSize);
  return newBlock;
}

void reallocate()
{
  int blockNum;
  int blockSize;
  printf("Enter block number (index)\n");
  scanf("%d", &blockNum);
  printf("Enter desired size\n");
  scanf("%d", &blockSize);
  void *newMem = realloc(blocks[blockNum]->memory, blockSize);
  blocks[blockNum]->memory = newMem;
  blocks[blockNum]->size = blockSize;
}

void displayBlocks()
{
  printf("Data types: 1-int   2-float   3-char\n");
  for (int i = 0; i < numBlocks; i++)
  {
    printf("----------------\n");
    printf("Block %d:\n", i);
    printf("Process ID: %d\n", blocks[i]->process_id);
    printf("Size: %d\n", blocks[i]->size);
    printf("Data Type: %d\n", blocks[i]->data_type);
  }
}

int main()
{
  int choice;
  do
  {

    printf("what u wanna do mate? \n1-allocate   2-re-allocate   3-deallocate   4-read   5-write   6-history\npress 0 to close\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      allocate();
      break;
    case 2:
      displayBlocks();
      reallocate();
      break;
    case 3:
      printf("%d", choice);
      break;
    case 4:
      displayBlocks();
      break;
    case 5:
      printf("%d", choice);
      break;
    case 6:
      printf("%d", choice);
      break;
    case 0:
      break;
    default:
      printf("choose a valid option\n");
    }
  } while (choice != 0);

  return (0);
}