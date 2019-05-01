#pragma once

typedef struct node
{
private:
  int val;
  node *prev;
public:
  int getval();
  node *getprev();
  void setval( int x );
  void setprev( node *prev_ptr );
} node;
