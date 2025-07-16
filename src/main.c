#include<stdlib.h>
#include<stdio.h>
#include<test_header.h>

int main()
{

  Test_header *test = (Test_header*) malloc(sizeof(Test_header));
  test->size = 45;

  printf("hello world %d !\n", test->size);
  return 0;
}