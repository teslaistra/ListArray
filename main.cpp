#include "main.h"
#include <iostream>

using namespace std;

StackL::StackL(const StackL& a)
{
    if (!is_empty()) {
        //*this->~StackL;
        delete(head);
        head = nullptr;
    }
    *this = operator=(a);



}

StackL::~StackL()
{
    Node* t = head;
    while (t != nullptr)
    {
        t = head->next;
        delete(head);
        head = t;
    }
}

StackL& StackL::operator=(const StackL&a)
{
    if (a.head == nullptr) { delete head; head = nullptr;  return *this; }
    if (a.head == head) return *this;
    head = new Node{ a.head->value,nullptr };
    Node* curHere = head;
    Node* curThere = a.head->next;

    while (curThere != nullptr) {
        curHere->next = new Node{ curThere->value,nullptr };
        curHere = curHere->next;
        curThere = curThere->next;
    }
    return *this;
}

void StackL::pop()
{
    if (!is_empty()) {
        Node* t = head;
        head = head->next;
        delete(t);
        current--;
    }
}
StackL::StackL() {
    head = nullptr;
}

void StackL::push(const float v) {
    current++;
    head = new Node {v, head};
}

bool StackL::is_empty() const {
    return nullptr == head;

}

float& StackL::top() {
    if (is_empty()) {
        throw new std::exception("stack is empty");
    }
    return head->value;
}

const float& StackL::top() const {
    if (is_empty()) {
        throw new std::exception("stack is empty");
    }
    return head->value;
}

float &StackL::at(int at) {
    Node* curHere = head;

    for (int i = 0; i < current-at-1; ++i) {
        if(nullptr == curHere) break;
        curHere = curHere->next;
    }

    return curHere->value;
}

void StackL::insertAt(int at,float value) {
    Node* curHere = head;
    Node* prev;
    for (int i = 0; i < current-at; ++i) {
        if(nullptr == curHere) break;
        prev = curHere;
        curHere = curHere->next;
    }

    Node* new_Node = new Node{value, curHere};
    prev->next =new_Node;
    current++;
}

void StackL::deleteAt(int at) {
    Node* curHere = head;
    Node* prev = head;

    for (int i = 0; i < current-at-1; ++i) {
        if(nullptr == curHere) break;
        prev = curHere;
        curHere = curHere->next;
    }
    current--;
    prev->next = curHere->next;
}


int main(){

    system("chcp 65001");


    StackL a;

    a.push(4);
    a.push(6);
    a.push(2);

    cout << "Тестирую доступ по номеру. В стеке сейчас лежит(в порядке добавления туда) 4, 6, 2.\n";
    cout << "Получим доступ к нулевому элементу, то есть первому добавленному\n";
    cout << "stack.at(0) = " << a.at(0) << endl << endl;

    cout << "Вставим на место первого элемента 1. Сейчас там a.at(1) = "<<a.at(1)<<"\n";
    a.insertAt(1,1);
    cout << "a.insertAt(1,1);\n";
    cout<<"Теперь посмотрим что на месте первого a.at(1) = " << a.at(1) <<"\n" ;

    cout << "Выведем все элементы стека с нулевого: " <<  a.at(0) << " " << a.at(1) << " " << a.at(2) << " "<< a.at(3) << "\n";
    cout << "Теперь протестируем удаление элемента. Удалим элемент на первой позиции, то есть который недавно добавили туда.\n";
    cout << "a.deleteAt(1);\n";
    a.deleteAt(1);
    cout << "Выведем все элементы стека с нулевого: " <<  a.at(0) << " " << a.at(1) << " " << a.at(2) <<  "\n";
    cout << "Стек, в который можно добавить, удалить или получать элемент по конкретному номеру реализован. Ефимов Д. БПМ-18-2";
    return 0;
}
