#include "node.h"

class queue
{
private:
  node *end;
public:
  queue();
  ~queue();
  void show();
  queue& operator = ( int &a );
  queue& operator = ( queue &q );
  queue& operator + ( queue &q );
  queue& operator * ( queue &q );
  queue& operator / ( int n );
  friend queue& operator - ( queue &q1, queue &q2 );
  friend queue& operator += ( queue &q, int n );
};
