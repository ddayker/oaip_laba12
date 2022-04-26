#include "iostream"

/*
 5.    Создать стек для символов и стек для чисел. Максимальный размер стеков вводится с экрана. Создать функции для ввода и вывода элементов стека. Вводить символы с экрана. Символ попадает в первый стек, а его численное представление – во второй.
 */

int max;

typedef struct data{
    char symbol;
    struct data *next;
}Data;

typedef struct num{
    int number;
    struct num *next;
}Number;

Data *c_top= NULL;
Number *n_top = NULL;


void display();
int StackIsFull();

void push(){
    char a;
    if( StackIsFull() ) return;
    
    std::cout<<"Введите символ:\n--> ";
    std::cin >> a;
    
    Data *t = new Data;
    t->symbol = a;
    t->next = c_top;
    c_top = t;
    
    Number *p = new Number;
    p->number = (int)a;
    p->next = n_top;
    n_top = p;
    
    display();
}



void pop(){
    Data *t;
    if (c_top == NULL){std::cout <<"Стек пуст!\n"; return;}
    t = c_top;
    c_top = c_top->next;
    delete(t);
    
    Number *p;
    p = n_top;
    n_top = n_top->next;
    delete(p);
    
    display();
}



void display(){
    if (c_top == NULL){std::cout <<"Стек пуст!\n"; return;}
    std::cout <<"\nСтек символов:\n";
    std::cout <<"--------------------------------\n";
    Data *t = c_top;
    while (t!=NULL){
        printf("%c ",t->symbol);
        t= t->next;
    }
    std::cout <<"\n--------------------------------\n";
    std::cout <<"\nСтек чисел:\n";
    std::cout <<"--------------------------------\n";
    Number *p = n_top;
    while(p!=NULL){
        printf("%d ",p->number);
        p = p->next;
    }
    std::cout <<"\n--------------------------------\n\n";
}

int StackIsFull(){
    int i=0;
    Data *t = new Data;
    
    t = c_top;
    while(t!=NULL){
        t = t->next;
        i++;
    }
    
    if (i==max){
        std::cout <<"\nCТЕК ПЕРЕПОЛНЕН!\n\n";
        return 1;
    }
    else return 0;
}

int input(int a, int b){
    int input;
    
    while(true){
        std::cout << "--> ";
        std::cin >> input;
        if (std::cin.fail())
    {
        std::cout << "\nНекорректно, повторите ввод:" << std::endl;
        std::cin.clear();
        while(std::cin.get()!='\n');
        
    }
        else if ( input<a || input>b) std::cout << "\nНекорректно, повторите ввод:" << std::endl;
     else break;
    }
    
    return input;
}

int main(){
    int choice;
    std::cout <<"Введите максимальный размер стеков:\n";
    max = input(1,1000);
    while(1){
        std::cout <<"1 - Добавить элемент.\n2 - Удалить элемент.\n3 - Вывести все элементы.\n4 - Выход.\n";
            choice = input(1,4);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                std::cout<<"Программа завершена...\n";
                return 0;
        }
    }
}
