#include <iostream>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue()
{
  end = nullptr;
  cnt = 0;
}

queue::~queue()
{
  node *ptr = end;

  while( ( ptr = end ) != nullptr )
  {
    end = end->getprev();
    delete ptr;
    ptr = nullptr;
  }
  delete end;
  end = nullptr;
}

void queue::show()
{
  node *ptr = end;

  cout << "Конец очереди" << endl;

  while( ptr != nullptr )
  {
    cout << ptr->getval() << endl;
    ptr = ptr->getprev();
  }

  cout << "Начало очереди" << endl;
}

node* node::operator = ( queue &q )
{
  setlocale( LC_ALL, "Rus" );
  node *ptr = q.end;

  if( ptr != nullptr )
    while( ptr->getprev() != nullptr && ptr->getprev()->getprev() != nullptr )
      ptr = ptr->getprev();

  if( ptr != nullptr && ptr->getprev() != nullptr )
  {
    cout << endl << "Вы извлекли: " << ptr->getprev()->getval() << endl;
    delete ptr->getprev();
    ptr->setprev( nullptr );
    return ptr;
  }
  else if( ptr != nullptr && ptr->getprev() == nullptr )
  {
    cout << endl << "Вы извлекли: " << ptr->getval() << endl;
    delete end;
    end = nullptr;
    return ptr;
  }
  else
    cout << endl << "Очередь пуста" << endl;

  q.show();
  return nullptr;
}

queue& queue::operator + ( queue &q )
{
  node *p1 = end;
  node *p2 = q.end;

  show();
  cout << "------------------" << endl;
  q.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p1->setval( p1->getval() + p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
  }

  show();
  return *this;
}

queue& queue::operator * ( queue &q )
{
  node *p1 = end;
  node *p2 = q.end;

  show();
  cout << "------------------" << endl;
  q.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p1->setval( p1->getval() * p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
  }

  show();
  return *this;
}

queue& queue::operator / ( int n )
{
  node *p1 = end;

  show();
  cout << "------------------" << endl;
  
  while( p1 != nullptr )
  {
    p1->setval( p1->getval() / n );
    p1 = p1->getprev();
  }

  show();
  return *this;
}

queue& operator - ( queue &q1, queue &q2 )
{
  node *p1 = q1.end;
  node *p2 = q2.end;

  q1.show();
  cout << "------------------" << endl;
  q2.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p1->setval( p1->getval() - p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
  }

  q1.show();
  return q1;
}

queue& operator += ( queue &q1, int n )
{
  if( q1.end == nullptr )
  {
    q1.end = new node;
    q1.end->setprev( nullptr );
    q1.end->setval( n );
  }
  else
  {
    node *ptr = new node;
    ptr->setprev( q1.end );
    ptr->setval( n );
    q1.end = ptr;
  }
  q1.cnt++;

  q1.show();
  return q1;
}
