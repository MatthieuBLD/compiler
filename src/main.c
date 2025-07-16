#include<stdlib.h>
#include<stdio.h>
#include "operators.h"
#include "G0.h"
/*
  analyseG0 te dit si ton GPL est correcte
  scanG0 il recupere chaque token de ton GPL
  actionG0 il genere les regles de GPL et le met dans le tableau
  scanGPL il recupere les tokens de ton programme code
  analyseGPL te dit si ton programme est conforme au GPL
  actionGPL genere le PCODE
 */

int main()
{

  Node *N = ATOM("N", 0, NONTERM);
  Node *arrow = ATOM("->", 0, NONTERM);
  Node *E = ATOM("E", 0, NONTERM);
  Node *comma = ATOM(",", 0, TERM);
  Node *semi_col = ATOM(";", 0, TERM);
  Node *res = CONCAT(STAR(CONCAT(CONCAT(CONCAT(N,arrow),E),comma)), semi_col);

  res->to_string;
  printf("\n");
  free(N);
  free(arrow);
  free(E);
  free(comma);
  free(semi_col);
  free(res);
  return 0;
}