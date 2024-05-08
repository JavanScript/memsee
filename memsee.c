#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryBlock
{
  int process_id;
  char data_type[30];
  void *memory;
} MemoryBlock;

int main()
{
  int choice;
  printf("what u wanna do mate? \n1- allocate   2- re-allocate   3- deallocate   4- read   5- write   6- history\n");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("%d", choice);
    break;
  case 2:
    printf("%d", choice);
    break;
  case 3:
    printf("%d", choice);
    break;
  case 4:
    printf("%d", choice);
    break;
  case 5:
    printf("%d", choice);
    break;
  case 6:
    printf("%d", choice);
    break;
  default:
    printf("choose a valid option");
    break;
  }
  return (0);
}