#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*
 -  функции добавления элемента(в алфавитном порядке)
 -  функция удаления элемента
 -  вывод всего списка на экран
 -   выход из программы
 */


struct name
{
    char familia[15];
    char imya[15];
    char otchestvo[15];
};

struct date
{
    int day;
    int month;
    int year;
};

struct chitatel
{
    char nomer[10];
    char kniga[60];
    struct name person;
    struct date data;
    struct chitatel *next;
    
};

typedef struct chitatel Node;
typedef Node* NodePtr;

int num;




int menu()
{
    int choice;
    printf( "Выберите операцию:\n");
    printf( "1) Добавление нового читателя \n");
    printf( "2) Вывод информации\n");
    printf( "3) Поиск читателя\n");
    printf( "4) Изменение информации о читателе\n");
    printf( "5) Удаление информации о читателе\n");
    printf( "0) Выход.\n");
    
    while(true){
    cout << "--> ";
    cin >> choice;
     if (cin.fail())
    {
           cout << "\nНекорректный ввод. Повторите выбор:" << endl;
        cin.clear();
        while(cin.get()!='\n');
        
    }
     else if ( choice<0 || choice>5) cout << "\nНекорректный ввод. Повторите выбор:" << endl;
     else break;
    
}
    return choice;
}

int input(int a, int b){
    int input;
    
    while(true){
    cout << "--> ";
    cin >> input;
     if (cin.fail())
    {
           cout << "\nНекорректно, повторите ввод:" << endl;
        cin.clear();
        while(cin.get()!='\n');
        
    }
     else if ( input<a || input>b) cout << "\nНекорректно, повторите ввод:" << endl;
     else break;
    }
    
    return input;
}


void new_chitatel(NodePtr* s)
{
    NodePtr newP, cur, prev;
    newP = (NodePtr)malloc(sizeof(Node));
    printf("Читатель №%d\n",num+1);
    cout << "Введите полное имя ( Фамилия, Имя, Отчество):" << endl;
    cout << "Фамилия: ";
    cin >> newP->person.familia;
    cout << "Имя: ";
    cin >> newP->person.imya;
    cout << "Отчество: ";
    cin >> newP->person.otchestvo;
        
    cout << "Введите номер билета: ";
    while(1){
    cin >> newP->nomer;
    prev=NULL;
    cur = *s;
        int flag=0;
    while (cur !=NULL)
{
    if (strcmp(cur->nomer, newP->nomer) == 0) {
        cout << "\nДанный номер уже занят. Повторите попытку:" << endl;
        flag++;
    }
    cur=cur->next;
}
    if (flag == 0) break;
}
       
        
    cout << "Введите название книги: ";
    getchar();
    gets(newP->kniga);
    cout << "Введите дату возврата (День,Месяц, Год):" << endl;
        cout << "День: ";
        newP->data.day = input(1, 31);
    
        cout << "Номер месяца: ";
        newP->data.month = input(1,12);
    
        cout << "Год: ";
        newP->data.year = input(2022, 2032);
        
    prev=NULL;
    cur = *s;
           while (cur != NULL)
           {
               
               if (strcmp(newP->person.familia, cur->person.familia)<0) break;
               if (strcmp(newP->person.familia, cur->person.familia)==0){
                   if (strcmp(newP->person.imya, cur->person.imya)<0) break;
                   if (strcmp(newP->person.imya, cur->person.imya)==0){
                       if (strcmp(newP->person.otchestvo, cur->person.otchestvo)<0)break;
                   }
               }
               
               prev = cur;
               cur = cur->next;
           }


           if (prev == NULL)
           {
               newP->next = *s;
               *s = newP;
           }
           else
           {
               prev->next = newP;
               newP->next = cur;
           }
    
           num++;
           
    cout << endl;
    return;
    
}


    void print(NodePtr* s){
    
        NodePtr current;
        current = *s;
        int i=0;
        if (current == NULL)
        {
            cout << "Список пуст. Введите данные.\n" << endl;
            return;
        }
        
        printf(" \n -----------------------------------------------------------------------------------------\n");
        printf(" |№|            ФИО                   |  Номер билета | Название книги | Дата возврата   |\n");
        printf(" |-+-------------------------------------------------------------------------------------|\n");

        while (current!=NULL)
        {
            printf(" |%d|%10s %10s %12s|%15s| %15s| %2d %2d %4d      |\n", i + 1,current->person.familia , current->person.imya,current->person.otchestvo , current->nomer,current->kniga,
                   current->data.day , current->data.month , current->data.year );
            current = current->next;
            i++;
        }
        printf(" -----------------------------------------------------------------------------------------\n");

    }


void delet(NodePtr* s)
{
    int ch;
    if (*s == NULL) {
        cout << "\nСписок пуст!";
        return;
    }

    cout << "Введите номер записи, которую хотите удалить: ";
    ch = input(1,num);
    

    NodePtr prev = NULL, cur = *s, temp;

    if (ch == 1)
    {
        temp = *s;
        *s = (*s)->next;
        cur = *s;
        free(temp);
        num--;
        cout << "Запись успешно удалена.\n\n";
        return;
    }
    
    int i = 1;
    while (i != ch)
    {
        prev = cur;
        cur = cur->next;
        i++;
    }

    temp = cur;
    prev->next = cur->next;
    cur = cur->next;
    
    free(temp);

    
    cout << "Запись успешно удалена.\n\n";
    num--;
}

void change(NodePtr* s)
{
    if (*s == NULL) {
        cout << "\nСписок пуст!";
        return;
    }
    
    int ch,choice;
    NodePtr cur = *s;
    
    cout << "Введите номер записи, которую хотите изменить:";
    ch = input(1,num);
    
    int i = 1;
    while (i != ch)
    {
        cur = cur->next;
        i++;
    }
    
    while (1) {
        cout << "Выберите параметр, который хотите изменить:" << endl;
        cout << "1) Номер билета;" << endl;
        cout << "2) ФИО;" << endl;
        cout << "3) Название книги;" << endl;
        cout << "4) Дата возврата;" << endl;
        cout << "5) Выход." << endl;
        choice = input(1,5);
        if (choice == 5)
        {
            cout << "Операция завершена!\n" << endl;
            return;
        }
       
        char str[60];
        char str2[60];
        char str3[60];
        switch (choice)
        {
        case 1:
                 cout << "Введите новый номер билета: ";
                
                while(1){
                cin >> str;
                    NodePtr cur1 = *s;
                    int flag=0;
                while (cur1 !=NULL)
            {
                if (strcmp(cur1->nomer, str) == 0) {
                    cout << "\nДанный номер уже занят. Повторите попытку:" << endl;
                    flag++;
                }
                cur1=cur1->next;
            }
                if (flag == 0) break;
            }
            strcpy(cur->nomer, str);
            break;
                
        case 2:
            {
            cout << "ФИО:" << endl;
            getchar();
            cout << "Фамилия: ";
            gets(str);
            cout << "Имя: ";
            gets(str2);
            cout << "Отчество: ";
            gets(str3);
            strcpy(cur->person.familia, str);
            strcpy(cur->person.imya, str2);
            strcpy(cur->person.otchestvo, str3);
            
                
                NodePtr newP=cur;
                NodePtr temp, prev = NULL, cur = *s;

                if (ch == 1)
                {
                    *s = (*s)->next;
                    cur = *s;
                    
                }
                
                else {
                    
                int i = 1;
                while (i != ch)
                {
                    prev = cur;
                    cur = cur->next;
                    i++;
                }

                temp = cur;
                prev->next = cur->next;
                cur = cur->next;
                }
                
                
                prev=NULL;
                cur = *s;
                
                       while (cur != NULL)
                       {
                           
                           if (strcmp(newP->person.familia, cur->person.familia)<0) break;
                           if (strcmp(newP->person.familia, cur->person.familia)==0){
                               if (strcmp(newP->person.imya, cur->person.imya)<0) break;
                               if (strcmp(newP->person.imya, cur->person.imya)==0){
                                   if (strcmp(newP->person.otchestvo, cur->person.otchestvo)<0)break;
                               }
                           }
                           
                           prev = cur;
                           cur = cur->next;
                       }


                       if (prev == NULL)
                       {
                           newP->next = *s;
                           *s = newP;
                       }
                       else
                       {
                           prev->next = newP;
                           newP->next = cur;
                       }
                
                    
                
                cout << endl;
        }
                break;
        
            case 3:
                cout << "Введите название книги: ";
                getchar();
                gets(str);
                strcpy(cur->kniga, str);
                break;
            case 4:
                cout << "Введите дату возврата (День,Месяц, Год):" << endl;
                
                cout << "День: ";
                cur->data.day = input(1, 31);
            
                cout << "Номер месяца: ";
                cur->data.month = input(1,12);
            
                cout << "Год: ";
                cur->data.year = input(2022, 2032);
                
                cout << endl;
                break;
        default:
            cout << "Неверная операция!" << endl;
            break;
        }

    }
    
}


void print1(NodePtr* s)
{
        NodePtr cur = *s;
        cout << "Полное имя: " << cur->person.familia<<" "<<
    cur->person.imya<<" "<<cur->person.otchestvo <<endl;
        cout << "Номер билета: "<< cur->nomer << endl;
        cout << "Название книги: " << cur->kniga << endl;
        cout << "Дата возврата (День, Месяц, Год):" <<cur->data.day <<
        "/"<< cur->data.month << "/"<< cur->data.year <<endl;
        cout << "------------------------------------------------------------"<< endl;
        cout << endl;

}

void search(NodePtr* s)
{
    if (*s == NULL) {
        cout << "\nСписок пуст!";
        return;
    }
    
    int choice;
    
    while (1) {
        cout << "Выберите параметр, по которому будет осуществлён поиск:" << endl;
        cout << "1) Номер билета;" << endl;
        cout << "2) ФИО;" << endl;
        cout << "3) Название книги;" << endl;
        cout << "4) Выход." << endl;
        choice = input(1,4);
        char str[60];
        char str2[60];
        char str3[60];
        int flag = 0;
        int i=0;
        NodePtr cur = *s;
 
        switch (choice)
        {
        case 1:
            cout << "Введите номер : ";
            getchar();
            flag = 0;
            cin >>str;

                while (cur !=NULL)
            {
                if (strcmp(cur->nomer, str) == 0) {
                    cout << "\nПараметр найден, это " << "читатель №" << i + 1 << endl;
                    print1(&cur);
                    flag++;
                }
                cur=cur->next;
                i++;
            }
            if (flag == 0)
            {
                cout << "\nЧитатель с такими параметрами не найден!" << endl;
            }
            break;
        
        case 2:
            cout << "Введите ФИО:" << endl;
            getchar();
            cout << "Фамилия: ";
            cin >> str;
            cout << "Имя: ";
            cin >> str2;
            cout << "Отчество: ";
            cin >> str3;
            flag = 0;
                while (cur !=NULL)
            {
                if (strcmp(cur->person.familia, str)==0 && strcmp(cur->person.imya ,str2)==0 && strcmp(cur->person.otchestvo,str3)==0)
                {
                    cout << "\nПараметр найден, это " << "читатель №" << i + 1 << endl;
                    print1(&cur);
                    flag++;
                }
                i++;
                cur=cur->next;

            }
            if (flag == 0)
            {
                cout << "\nЧитатель с такими параметрами не найден!" << endl;
            }
            break;
                
        case 3:
            cout << "Введите название книги: ";
            getchar();
            gets(str);
            flag = 0;
                while (cur !=NULL) {
                if (strcmp(cur->kniga, str)==0) {
                    cout << "\nПараметр найден, это " << "читатель №" << i + 1 << endl;
                    print1(&cur);
                    flag++;
                }
                    i++;
                    cur=cur->next;
            }
            if (flag == 0)
            {
                cout << "\nЧитатель с такими параметрами не найден!" << endl;
            }
            break;
        case 4:
            cout << "Поиск окончен!\n" << endl;
            return;
            break;
        default:
            cout << "Неверное действие!" << endl;
            break;
        }
    }
    

}

 


