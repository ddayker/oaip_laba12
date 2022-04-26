#include <stdio.h>
#include <stdlib.h>


/*
 Создать однонаправленный список для целых чисел в порядке возрастания.
 Написать следующие функции для работы со списком:
 - countList - подсчет числа элементов;
 - findMax - поиск максимального элемента списка;
 - findMin - поиск минимального элемента списка;
 – Удалить все повторения числа
 - Удалить все вхождения числа
 */

//ПРОВЕРКА НА ВВОД

struct list{
    int num;
    struct list *next;
};

typedef struct list ListNode;
typedef ListNode *ListNodePtr;

void menu(void){
    printf("1-Добавить число\n");
    printf("2-Подсчет числа элементов\n");
    printf("3-Поиск максимального элемента списка\n");
    printf("4-Поиск минимального элемента списка\n");
    printf("5-Удалить все повторения числа\n");
    printf("6-Удалить все вхождения числа\n");
    printf("7-Вывести список\n");
    printf("8-Выход\n");
}

void insert(ListNodePtr* ptr,int elem){
    ListNodePtr newP, previous, current;
    newP = (ListNodePtr) malloc (sizeof(ListNode));
    if (newP!=0){
        newP->num = elem;
        newP->next = NULL;
        previous = NULL;
        current = *ptr;
        while ( current!=NULL && elem > current->num){
            previous = current;
            current = current->next;
        }
        if (previous==NULL){
            newP->next = *ptr;
            *ptr = newP;
        }
        else {
            previous->next = newP;
            newP->next = current;
        }
    }
    else printf("Недостаточно памяти");
    
}

void print(ListNodePtr* ptr){
    ListNodePtr current;
    current = *ptr;
    if (current==NULL)printf("\nСписок пуст.\n");
    else {
    printf("\nСписок целых чисел:\n");
    while( current!=NULL){
        printf("| %d |",current->num);
        current = current->next;
    }
    printf("\n\n");
    }}

void del(ListNodePtr* ptr,int elem,int s){
    ListNodePtr previous, current, temp;
    int count=0;
    current = *ptr;
    previous = NULL;
    while( current!=NULL){
        if (current->num==elem) count++;
        current = current->next;
    }
    if (count==0){
        printf("Число %d не найдено в списке.\n",elem); return;
    }
    if (s==1 && count ==1){
        printf("Число %d не повторяется в списке.\n",elem); return;
    }
    
    current = *ptr;
    previous = NULL;
    while (count!=s) {
    while(current!= NULL && current->num!=elem){
        previous = current;
        current = current->next;
    }
    if (previous==NULL){
        temp = current;
        *ptr = current->next;
        current = current->next;
        free(temp);
        count--;
    }
    else if (current!=NULL) {
        temp = current;
        previous->next = current->next;
        current = current->next;
        free(temp);
        count--;
    }
    }
    if (s==1) printf("Все повторы числа %d были удалены из списка.\n",elem);
    else printf("Число %d было удаленно из списка.\n",elem);
}

void findMax(ListNodePtr *ptr) {
    ListNodePtr current = *ptr;
    while (current->next != NULL) {
        current = current->next; }
    printf("Максимальный элемент списка = %d\n\n",current->num);
     }

void findMin(ListNodePtr *ptr){
    ListNodePtr current = *ptr;
    printf("Минимальный элемент списка = %d\n\n",current->num);
    
}

void countList(ListNodePtr *ptr) {
    int count = 0;
    ListNodePtr current = *ptr;
    while (current != NULL) { count++;
        current = current->next; }
    printf("Количество элементов в списке = %d\n\n",count); }

int ListIsEmpty(ListNodePtr *ptr){
    if (*ptr==NULL){ printf("\nСписок пуст.\n\n");
        return 1;}
    else return 0;
    
}

int scanner(void){
    int res, a;
    do
      {
        res=scanf("%d",&a);
        fflush(stdin);
        if(res!=1) printf("Некорректный ввод! Введите число:\n");
      }
      while(res!=1);
    return a;
}

int main(int argc, const char * argv[]) {
    ListNodePtr start = NULL;
    int choice;
    int elem;
    
    while(1){
    menu();
        printf("\nСделайте выбор:\n");
        choice = scanner();
        switch(choice){
            case 1:
                printf("Введите число:\n");
                elem = scanner();
                insert(&start,elem);
                print(&start);
                break;
            case 2:
                if (ListIsEmpty(&start))break;
                countList(&start);
                break;
        
            case 3:
                if (ListIsEmpty(&start))break;
                findMax(&start);
                break;
                
            case 4:
                if (ListIsEmpty(&start))break;
                findMin(&start);
                break;
            case 5:
                if (ListIsEmpty(&start))break;
                printf("Введите число:\n");
                elem = scanner();
                del(&start,elem,1);
                print(&start);
                break;
            case 6:
                if (ListIsEmpty(&start))break;
                printf("Введите число:\n");
                elem = scanner();
                del(&start,elem,0);
                print(&start);
                break;
                
            case 7:
                if (ListIsEmpty(&start))break;
                print(&start);
                break;
                
            case 8: printf("\nПрограмма завершена!\n"); exit(0);
                break;
            default: printf("Некоректный ввод.\n"); break;
        }
    }
    return 0;
}

