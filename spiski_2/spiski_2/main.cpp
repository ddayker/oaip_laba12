#include <locale.h>
#include "functions.h"

using namespace std;

/* Cписок на основе структуры из лабораторной работы 9.
   Сформировать бинарный файл из элементов, заданной в варианте структуры, распечатать его содержимое, выполнить добавление элементов в соответствии со своим вариантом и поиск по одному из параметров (например, по фамилии, по государственному номеру, по году рождения и т.д.). Формирование, печать, добавление, поиск элементов оформить и выбор желаемого действия оформить в виде функций.
 */


int main()
{
    
    setlocale (LC_ALL, "Rus");
    NodePtr start = NULL;
    bool flag = true;
    while (flag) {
        
        switch (menu())
        {
        case 1:
                cout << "Добавление читателя:" << endl;
                new_chitatel(&start);
            break;
        case 2:
            print(&start);
            break;
        case 3:
                search(&start);
            break;
        case 4:
                change(&start);
                break;
        case 5:
                delet(&start);
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



