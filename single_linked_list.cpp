#include <iostream>
using namespace std;

struct Nodo
{
    int data;
    Nodo *next;
    Nodo *prev;
};

class List
{
public:
    Nodo *head;
    Nodo *tail;
    template <class T>
    T front()
    {
        return head->data;
    }
    template <class T>
    T back()
    {
        return tail->data;
    }

    template <class T>
    void push_front(T num)
    {
        Nodo *nodo = new Nodo;
        nodo->data = num;
        nodo->next = head;
        head = nodo;
    }
    template <class T>
    void push_back(T numero)
    {
        Nodo *nodo = new Nodo;
        nodo->data = numero;
        Nodo *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nodo;
        nodo->next = NULL;
    }
};

int main()
{
    List lista;
    lista.head = nullptr;
    lista.tail = nullptr;

    Nodo *nodo1 = new Nodo;
    nodo1->data = 5;
    nodo1->next = nullptr;
    nodo1->prev = nullptr;
    lista.head = nodo1;
    lista.tail = nodo1;

    Nodo *nodo2 = new Nodo;
    nodo2->data = 22;
    nodo2->next = nullptr;
    nodo2->prev = lista.tail;
    lista.tail->next = nodo2;
    lista.tail = nodo2;

    Nodo *nodo3 = new Nodo;
    nodo3->data = 18;
    nodo3->next = nullptr;
    nodo3->prev = lista.tail;
    lista.tail->next = nodo3;
    lista.tail = nodo3;

    Nodo *nodo4 = new Nodo;
    nodo4->data = 13;
    nodo4->next = nullptr;
    nodo4->prev = lista.tail;
    lista.tail->next = nodo4;
    lista.tail = nodo4;

    Nodo *nodo5 = new Nodo;
    nodo5->data = 7;
    nodo5->next = nullptr;
    nodo5->prev = lista.tail;
    lista.tail->next = nodo5;
    lista.tail = nodo5;

    Nodo *nodo6 = new Nodo;
    nodo6->data = 12;
    nodo6->next = nullptr;
    nodo6->prev = lista.tail;
    lista.tail->next = nodo6;
    lista.tail = nodo6;

    // Primera pregunta
    cout << "El primer elemento de la lista es: " << lista.front<int>() << endl;
    // Segunda pregunta
    cout << "El ultimo elemento de la lista es: " << lista.back<int>() << endl;
    // Tercera pregunta
    lista.push_front(4);

    Nodo *temp = lista.head;
    int i = 1;
    while (temp != NULL)
    {
        if (i != 1)
        {
            cout << " , ";
        }
        cout << temp->data;

        temp = temp->next;
        i++;
    }
    cout<<endl;
    // Cuarta pregunta
    lista.push_back(77);
    Nodo *temp2 = lista.head;
    int k = 1;
    while (temp2 != NULL)
    {
        if (k != 1)
        {
            cout << " , ";
        }
        cout << temp2->data;

        temp2 = temp2->next;
        k++;
    }

    return 0;
}
