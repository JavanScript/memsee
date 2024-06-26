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
MemoryBlock *deallocatedBlocks[100];
int numDeallocatedBlocks = 0;

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
  printf("Enter block number\n");
  scanf("%d", &blockNum);
  printf("Enter desired size\n");
  scanf("%d", &blockSize);
  void *newMem = realloc(blocks[blockNum]->memory, blockSize);
  blocks[blockNum]->memory = newMem;
  blocks[blockNum]->size = blockSize;
}

void deallocate()
{
  int blockNum;
  printf("Enter block number\n");
  scanf("%d", &blockNum);
  if (blocks[blockNum] == NULL)
  {
    printf("block not found\n");
    return;
  }
  MemoryBlock *tempBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
  memcpy(tempBlock, blocks[blockNum], sizeof(MemoryBlock));
  deallocatedBlocks[blockNum] = tempBlock;
  numDeallocatedBlocks++;
  free(blocks[blockNum]->memory);
  free(blocks[blockNum]);
  // Jeeeesus
  for (int i = blockNum; i < numBlocks - 1; i++)
  {
    blocks[i] = blocks[i + 1];
  }
  numBlocks--;
}

void writeBlock()
{
  int blockNum;
  int index;
  int dataType;
  printf("Enter block number\n");
  scanf("%d", &blockNum);
  printf("Enter index (offset?)\n");
  scanf("%d", &index);
  dataType = blocks[blockNum]->data_type;
  printf("%d\n", dataType);

  switch (dataType)
  {
  case 1:
    if (index + sizeof(int) <= blocks[blockNum]->size)
    {
      int data;
      printf("enter data u wanna write\n");
      scanf("%d", &data);
      memcpy((int *)blocks[blockNum]->memory + index, &data, sizeof(int));
    }
    else
    {
      printf("they ain't payin my salary\n");
    }
    break;
  case 2:
    if (index + sizeof(float) <= blocks[blockNum]->size)
    {
      int data;
      printf("enter data u wanna write\n");
      scanf("%f", &data);
      memcpy((float *)blocks[blockNum]->memory + index, &data, sizeof(float));
    }
    else
    {
      printf("they ain't payin my salary\n");
    }
    break;
  case 3:
    if (index + sizeof(char) <= blocks[blockNum]->size)
    {
      int data;
      printf("enter data u wanna write\n");
      scanf(" %c", &data);
      memcpy((char *)blocks[blockNum]->memory + index, &data, sizeof(char));
    }
    else
    {
      printf("they ain't payin my salary\n");
    }
    break;
  default:
    printf("Invalid data type\n");
    break;
  }
}

void readBlock()
{
  int blockNum;
  int index;
  int dataType;
  printf("Enter block number\n");
  scanf("%d", &blockNum);
  printf("Enter index (offset?)\n");
  scanf("%d", &index);
  dataType = blocks[blockNum]->data_type;

  switch (dataType)
  {
  case 1:
    if (index + sizeof(int) <= blocks[blockNum]->size)
    {
      int data;
      memcpy(&data, (int *)blocks[blockNum]->memory + index, sizeof(int));
      printf("Data: %d\n", data);
    }
    else
    {
      printf("wrong index\n");
    }
    break;
  case 2:
    if (index + sizeof(float) <= blocks[blockNum]->size)
    {
      float data;
      memcpy(&data, (float *)blocks[blockNum]->memory + index, sizeof(float));
      printf("Data: %f\n", data);
    }
    else
    {
      printf("wrong index\n");
    }
    break;
  case 3:
    if (index + sizeof(char) <= blocks[blockNum]->size)
    {
      char data;
      memcpy(&data, (char *)blocks[blockNum]->memory + index, sizeof(char));
      printf("Data: %c\n", data);
    }
    else
    {
      printf("wrong index\n");
    }
    break;
  default:
    printf("Invalid data type\n");
    break;
  }
}

void displayBlocks()
{
  printf("Data types: 1-int   2-float   3-char\n");
  for (int i = 0; i < numBlocks; i++)
  {
    printf("----------------\n");
    printf("Block number: %d:\n", i);
    printf("Process ID: %d\n", blocks[i]->process_id);
    printf("Size: %d\n", blocks[i]->size);
    printf("Data Type: %d\n", blocks[i]->data_type);
  }
}

void history()
{
  printf("Data types: 1-int   2-float   3-char\n");
  for (int i = 0; i < numDeallocatedBlocks; i++)
  {
    printf("----------------\n");
    printf("Block number: %d:\n", i);
    printf("Process ID: %d\n", deallocatedBlocks[i]->process_id);
    printf("Size: %d\n", deallocatedBlocks[i]->size);
    printf("Data Type: %d\n", deallocatedBlocks[i]->data_type);
  }
}

int main()
{
  int choice;
  do
  {

    printf("what u wanna do mate? \n1-allocate   2-re-allocate   3-deallocate   4-read   5-write   6-history\nenter 0 to close\n");
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
      displayBlocks();
      deallocate();
      break;
    case 4:
      displayBlocks();
      readBlock();
      break;
    case 5:
      writeBlock();
      break;
    case 6:
      history();
      break;
    case 0:
      break;
    default:
      printf("choose a valid option\n");
    }
  } while (choice != 0);

  return (0);
}