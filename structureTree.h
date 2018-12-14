#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#ifndef STRUCTURETREE_H
#define STRUCTURETREE_H
struct qnode {
  int level;
  double xy[2];
  int flag;
  struct qnode *child[4];
};
typedef struct qnode Node;
#endif 
