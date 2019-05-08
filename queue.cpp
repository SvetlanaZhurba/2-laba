#include <iostream>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue()
{
  end = nullptr;
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

queue& queue::operator = ( int &a )
{
  setlocale( LC_ALL, "Rus" );
  node *ptr = end;

  if( ptr != nullptr )
    while( ptr->getprev() != nullptr && ptr->getprev()->getprev() != nullptr )
      ptr = ptr->getprev();

  if( ptr != nullptr && ptr->getprev() != nullptr )
  {
    cout << endl << "Вы извлекли: " << ptr->getprev()->getval() << endl;
    a = ptr->getprev()->getval();
    delete ptr->getprev();
    ptr->setprev( nullptr );
  }
  else if( ptr != nullptr && ptr->getprev() == nullptr )
  {
    cout << endl << "Вы извлекли: " << ptr->getval() << endl;
    a = ptr->getval();
    delete end;
    end = nullptr;
  }
  else
    cout << endl << "Очередь пуста" << endl;

  return *this;
}

queue& queue::operator = ( queue &q )
{
  node *p1 = end;
  node *p2 = q.end;

  if( end == nullptr )
  {
    end = new node;
    p1 = end;
  }

  while( p2 )
  {
    p1->setval( p2->getval() );
    p2 = p2->getprev();
    if( p2 != nullptr )
    {
      p1->setprev( new node );
      p1 = p1->getprev();
    }
    else
      p1->setprev( nullptr );
  }

  return *this;
}

queue& queue::operator + ( queue &q )
{
  node *p1 = end;
  node *p2 = q.end;
  queue *qr = new queue;
  qr->end = new node;
  node *p = qr->end;
  
  show();
  cout << "------------------" << endl;
  q.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p->setval( p1->getval() + p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
    if( p1 != nullptr && p2 != nullptr )
    {
      p->setprev( new node );
      p = p->getprev();
    }
    else
      p->setprev( nullptr );
  }

  qr->show();
  return *qr;
}

queue& queue::operator * ( queue &q )
{
  node *p1 = end;
  node *p2 = q.end;
  queue *qr = new queue;
  qr->end = new node;
  node *p = qr->end;
  
  show();
  cout << "------------------" << endl;
  q.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p->setval( p1->getval() * p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
    if( p1 != nullptr && p2 != nullptr )
    {
      p->setprev( new node );
      p = p->getprev();
    }
    else
      p->setprev( nullptr );
  }

  qr->show();
  return *qr;
}

queue& queue::operator / ( int n )
{
  node *p1 = end;
  queue *qr = new queue;
  qr->end = new node;
  node *p = qr->end;
  
  show();
  cout << "------------------" << endl;

  while( p1 != nullptr )
  {
    p->setval( p1->getval() / n );
    p1 = p1->getprev();
    if( p1 != nullptr )
    {
      p->setprev( new node );
      p = p->getprev();
    }
    else
      p->setprev( nullptr );
  }

  qr->show();
  return *qr;
}

queue& operator - ( queue &q1, queue &q2 )
{
  node *p1 = q1.end;
  node *p2 = q2.end;
  queue *qr = new queue;
  qr->end = new node;
  node *p = qr->end;
  
  q1.show();
  cout << "------------------" << endl;
  q2.show();
  cout << "------------------" << endl;

  while( p1 != nullptr && p2 != nullptr )
  {
    p->setval( p1->getval() - p2->getval() );
    p1 = p1->getprev();
    p2 = p2->getprev();
    if( p1 != nullptr && p2 != nullptr )
    {
      p->setprev( new node );
      p = p->getprev();
    }
    else
      p->setprev( nullptr );
  }

  qr->show();
  return *qr;
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

  q1.show();
  return q1;
}
