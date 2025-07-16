#include "operators.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

void copy(Node *src_node, Node *target_node)
{
  target_node->node1 = src_node->node1;
  target_node->node2 = src_node->node2;
  target_node->operator = src_node->operator;
  target_node->prefix = src_node->prefix;
  target_node->suffix = src_node->suffix;
  target_node->type = src_node->type;
}

void *to_string_unary(Node *node)
{
  printf("%s %p %s",node->prefix, node->node1, node->suffix);  
}
void *to_string_binary(Node *node)
{
  printf("%p %s %p", node->node1, node->operator, node->node2);
}
void *to_string_atom(Node *node)
{
  if(node->term)
    printf("\"%s\"", (node->code));
  else
    printf("%s", (node->code));
}

Node *STAR(Node* node)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->node1 = node;
  new_node->node2 = NULL;
  new_node->operator = NULL;
  new_node->prefix = "[";
  new_node->suffix = "]";
  new_node->type = UNARY;
  new_node->to_string = to_string_unary(new_node);
  return new_node;
}
Node *UN(Node* node)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->node1 = node;
  new_node->node2 = NULL;
  new_node->operator = NULL;
  new_node->prefix = "/";
  new_node->suffix = "/";
  new_node->type = UNARY;
  new_node->to_string = to_string_unary(new_node);
  return new_node;
}
Node *UNION(Node* node1, Node* node2)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->node1 = node1;
  new_node->node2 = node2;
  new_node->operator = "+";
  new_node->prefix = NULL;
  new_node->suffix = NULL;
  new_node->type = BINARY;
  new_node->to_string = to_string_binary(new_node);
  return new_node;
}
Node *CONCAT(Node* node1, Node* node2)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->node1 = node1;
  new_node->node2 = node2;
  new_node->operator = ".";
  new_node->prefix = NULL;
  new_node->suffix = NULL;
  new_node->type = BINARY;
  new_node->to_string = to_string_binary(new_node);
  return new_node;
}
Node *ATOM(char *str, int *act, bool term)
{
  Node *new_node = (Node *)calloc(1,sizeof(Node));
  new_node->action = act;
  new_node->code = str;
  new_node->term = &term;
  new_node->to_string = to_string_atom(new_node);
  return new_node;
}