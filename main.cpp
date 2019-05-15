#include <iostream>
#include "q_time.h"
#include "queue.h"

using namespace std;

int main()
{
  int c;
  setlocale( LC_ALL, "Rus" );

  system( "cls" );
  cout << "Выберите задание: ";
  cin >> c;
  cin.ignore( 1, '\n' );

  if( c == 1 )
  {
    time t, t2;
    int choice;
  
    do
    {
      system( "cls" );
      cout << "Настоящее время (1): " << t.gethour() << ":" << t.getmin() << ":" << t.getsec() << endl;
      cout << "Настоящее время (2): " << t2.gethour() << ":" << t2.getmin() << ":" << t2.getsec() << endl << endl;
      cout << "Выберите действие:\n1. Увеличить выбранный показатель на единицу.\n2. Уменьшить выбранный показатель на единицу."
      << "\n3. Увеличить выбранный показатель на ваше значение.\n4. Уменьшить выбранный показатель на ваше значение.\n0. Выход.\nВаш выбор: ";
      cin >> choice;
      cin.ignore( 1, '\n' );

      switch( choice )
      {
      case 1:
        t2 = ++t;
        break;

      case 2:
        t2 = --t;
        break;

      case 3:
        t2 = t++;
        break;

      case 4:
        t2 = t--;
        break;
      }
    } while( choice != 0 );
  }
  else
  {
    queue q1, q2, q3;
    int choice, flag;
    int elem;
    int *p = new int;

    do
    {
      system( "cls" );
      cout << "Выберите действие:\n1. Добавить элемент в очередь.\n2. Извлечь элемент из очереди.\n3. Сложение двух очередей.\n";
      cout << "4. Вычитание очередей.\n5. Перемножение очередей.\n6. Деление очереди на число.\n0. Выход.\nВаш выбор: " << endl;
      cin >> choice;
      cin.ignore( 1, '\n' );

      if( choice != 3 && choice != 4 && choice != 5 && choice != 0 )
      {
        cout << "Выберите очередь для работы: ";
        cin >> flag;
        cin.ignore( 1, '\n' );
      }

      switch( choice )
      {
      case 1:
        cout << "Введите значение: ";
        cin >> elem;
        cin.ignore( 1,'\n' );

        if( flag == 1 )
          q1 += elem;
        else
          q2 += elem;
        break;

      case 2:
        if( flag == 1 )
          q1 = *p;
        else
          q2 = *p;
        break;

      case 3:
        q3 = q1 + q2;
        break;

      case 4:
        q3 = q1 - q2;
        break;

      case 5:
        q3 = q1 * q2;
        break;

      case 6:
        cout << "Введите значение: ";
        cin >> elem;
        cin.ignore( 1,'\n' );

        if( flag == 1 )
          q3 = q1 / elem;
        else
          q3 = q2 / elem;
        break;
      }
      
      getchar();
    } while( choice != 0 );
  }
  
  return 0;
}
