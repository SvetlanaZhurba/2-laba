#pragma once

class time
{
private:
  int hour;
  int min;
  int sec;
public:
  time();
  ~time();
  explicit time( int h, int m, int s );
  int gethour();
  int getmin();
  int getsec();
  friend time& operator++ ( time &ob );
  friend time& operator-- ( time &ob );
  time operator++ ( int );
  time operator-- ( int );
};
