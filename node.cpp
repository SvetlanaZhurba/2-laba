#include "node.h"

int node::getval()
{
  return val;
}

node *node::getprev()
{
  return prev;
}

void node::setval( int x )
{
  val = x;
}

void node::setprev( node *prev_ptr )
{
  prev = prev_ptr;
}
