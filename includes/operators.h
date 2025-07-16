#ifndef OPERATORS_H
#define OPERATORS_H

#include<stdbool.h>

#define TERM true
#define NONTERM false

typedef struct Node
{
  enum {UNARY, BINARY} type;
  struct Node *node1, *node2;
  char *prefix, *suffix;
  char *operator;
  void *(*to_string)(struct Node *);

  //if it's an atom
  char * code;
  int *action; 
  bool *term;

}Node;

Node *STAR(Node *node);
Node *UN(Node *node);
Node *UNION(Node *node1, Node *node2);
Node *CONCAT(Node *node1, Node *node2);


Node *ATOM(char* str, int *act, bool term);

#endif