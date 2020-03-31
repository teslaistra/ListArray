# ListArray

Стек, в который можно добавить, удалить или получить элмент по номеру. Нулевым элементом является элемент, добавленным первее всех.

Текст, выдаваемый при работе тестов:

Тестирую доступ по номеру. В стеке сейчас лежит(в порядке добавления туда) 4, 6, 2.
Получим доступ к нулевому элементу, то есть первому добавленному
stack.at(0) = 4

Вставим на место первого элемента 1. Сейчас там a.at(1) = 6
a.insertAt(1,1);
Теперь посмотрим что на месте первого a.at(1) = 1
Выведем все элементы стека с нулевого: 4 1 6 2

Теперь протестируем удаление элемента. Удалим элемент на первой позиции, то есть который недавно добавили туда.
a.deleteAt(1);
Выведем все элементы стека с нулевого: 4 6 2
Стек, в который можно добавить, удалить или получать элемент по конкретному номеру реализован. Ефимов Д. БПМ-18-2

Код трех основных методов, отличающих от обычного стека:
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

