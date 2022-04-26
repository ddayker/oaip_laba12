#include <locale.h>
#include "functions.h"

using namespace std;

/* Cтэк на основе структуры из лабораторной работы 9.
   Сформировать бинарный файл из элементов, заданной в варианте структуры, распечатать его содержимое, выполнить добавление элементов в соответствии со своим вариантом и поиск по одному из параметров (например, по фамилии, по государственному номеру, по году рождения и т.д.). Формирование, печать, добавление, поиск элементов оформить и выбор желаемого действия оформить в виде функций.
 */


int main()
{
    
    setlocale (LC_ALL, "Rus");
    bool flag = true;
    while (flag) {
        
        switch (menu())
        {
        case 1:
                cout << "Добавление читателя:" << endl;
                push();
            break;
        case 2:
            print();
            break;
        case 3:
            search();
            break;
        case 4:
            change();
            break;
        case 5:
            pop();
            break;
            
        case 0:
            flag = false;
                cout <<"ПРОГРАММА ЗАВЕРШЕНА"<< endl;
            break;
        default:
            printf("\nНеизвестная операция!\n");
            break;
        }
    }
    return 0;
}




