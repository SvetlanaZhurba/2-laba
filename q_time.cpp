#include <iostream>
#include "q_time.h"

using namespace std;

time::time(): 
hour(0), min(0), sec(0)
{}

time::~time()
{}

time::time( int h, int m, int s )
{
  hour = h % 24;
  min = m % 24;
  sec = s % 24;
}

int time::gethour()
{
  return hour;
}

int time::getmin()
{
  return min;
}

int time::getsec()
{
  return sec;
}

time& operator++ ( time &ob )
{
  setlocale( LC_ALL, "Rus" );
  int num;

  cout << "\nВыберите значения для правки:\n1. Часы.\n2. Минуты.\n3. Секунды.\nВаш выбор: ";
  cin >> num;
  cin.ignore( 1, '\n' );

  switch( num )
  {
  case 1:
    ob.hour++;
    break;

  case 2:
    ob.min++;
    break;

  case 3:
    ob.sec++;
    break;
  }

  if( ob.sec > 59 )
  {
    ob.sec = 0;
    ob.min++;
  }

  if( ob.min > 59 )
  {
    ob.min = 0;
    ob.hour++;
  }

  if( ob.hour > 23 )
    ob.hour = 0;

  return ob;
}

time& operator-- ( time &ob )
{
  setlocale( LC_ALL, "Rus" );
  int num;

  cout << "\nВыберите значения для правки:\n1. Часы.\n2. Минуты.\n3. Секунды.\nВаш выбор: ";
  cin >> num;
  cin.ignore( 1, '\n' );

  switch( num )
  {
  case 1:
    ob.hour--;
    break;

  case 2:
    ob.min--;
    break;

  case 3:
    ob.sec--;
    break;
  }

  if( ob.sec < 0 )
  {
    ob.sec = 59;
    ob.min--;
  }

  if( ob.min < 0 )
  {
    ob.min = 59;
    ob.hour--;
  }

  if( ob.hour < 0 )
    ob.hour = 23;

  return ob;
}

time time::operator++ ( int )
{
  setlocale( LC_ALL, "Rus" );
  int num, x, tmp;

  cout << "\nВыберите значения для правки:\n1. Часы.\n2. Минуты.\n3. Секунды.\nВаш выбор: ";
  cin >> num;
  cin.ignore( 1, '\n' );

  cout << "Введите значение: ";
  cin >> x;
  cin.ignore( 1, '\n' );

  switch( num )
  {
  case 1:
    hour = (hour + x) % 24;
    break;

  case 2:
    if( (min + x) > 59 )
    {
      tmp = (min + x) / 60;
      min = (min + x) % 60;
      hour += tmp;
    }
    else
      min += x;
    break;

  case 3:
    if( (sec + x) > 59 )
    {
      tmp = (sec + x) / 60;
      sec = (sec + x) % 60;
      min += tmp;
    }
    else
      sec += x;
    break;
  }

  if( min > 59 )
  {
    tmp = min / 60;
    min = min % 60;
    hour += tmp;
  }

  if( hour > 23 )
    hour = hour % 24;

  return *this;
}

time time::operator-- ( int )
{
  setlocale( LC_ALL, "Rus" );
  int num, x, tmp;

  cout << "\nВыберите значения для правки:\n1. Часы.\n2. Минуты.\n3. Секунды.\nВаш выбор: ";
  cin >> num;
  cin.ignore( 1, '\n' );

  cout << "Введите значение: ";
  cin >> x;
  cin.ignore( 1, '\n' );

  switch( num )
  {
  case 1:
    hour = 24 + (hour - x) % 24;
    if( hour == 24 )
      hour = 0;
    break;

  case 2:
    if( (min - x) < 0 )
    {
      tmp = (min - x) / 60;
      if( (min - x) % 60 )
        tmp--;

      min = 60 + (min - x) % 60;
      hour = 24 + tmp;
      if( min == 60 )
        min = 0;
    }
    else
      min -= x;
    break;

  case 3:
    if( (sec - x) < 0 )
    {
      tmp = (sec - x) / 60;

      if( (sec - x) % 60 )
        tmp--;

      if( (min + tmp) < 0 )
      {
        hour--;
        if( (min + tmp) < 60 )
          hour += (min + tmp) / 60;
      }

      sec = 60 + (sec - x) % 60;
      min = 60 + tmp;
      if( sec == 60 )
        sec = 0;
    }
    else
      sec -= x;
    break;
  }

  if( hour < 0 )
    hour = 24 + hour % 24;

  if( min < 0 )
    min = 60 + min % 60;

  return *this;
}
