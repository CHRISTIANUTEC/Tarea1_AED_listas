#include <iostream>
using namespace std;

struct Nodo{
    int data;
    Nodo *next;
};

class List{
public:
    Nodo *head;
    Nodo *tail;
    template <class T>
    T front(){
        return head->data;
    }
    template <class T>
    T back(){
        return tail->data;
    }

    template <class T>
    void push_front(T num){
        Nodo *nodo = new Nodo;
        nodo->data = num;
        nodo->next = head;
        head = nodo;
    }
    template <class T>
    void push_back(T numero){
        Nodo *nodo = new Nodo;
        nodo->data = numero;
        Nodo *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nodo;
        nodo->next = NULL;
    }

    template <class T>
    void pop_front(){
        Nodo *temp = head;
        head = head->next;
        delete temp;
    }

    template <class T>
    void pop_back(){
        Nodo *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    template <class T>
    T& operator[](int pos){
        Nodo *temp = head;
        int i = 0;
        while (i < pos){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    bool empty(){
        if (head == NULL)
            return true;
        else
            return false;
    }

    int size(){
        Nodo *temp = head;
        int cont = 0;
        while (temp != NULL){
            temp = temp->next;
            cont++;
        }
        return cont;
    }

    void clear(){
        Nodo *temp = head;
        while (head != NULL){
            head = head->next;
            delete temp;
            temp = head;
        }
        cout<<"Se han eleminado todos los elementos de la lista"<<endl;
    }

    void imprimirLista(){
        Nodo *temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl<<endl;
    }

    void sort(){
        Nodo *temp = head;
        Nodo *temp2 = head;
        int aux;
        while (temp != NULL){
            while (temp2 != NULL){
                if (temp->data < temp2->data){
                    aux = temp->data;
                    temp->data = temp2->data;
                    temp2->data = aux;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
            temp2 = temp;
        }
    }

    void reverse(){
        Nodo *current = head;
        Nodo *next = nullptr;
        Nodo *newHead = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = newHead;
            newHead = current;
            current = next;
        }

        head = newHead;
    }

};




int main() {
    List lista;
    lista.head = nullptr;
    lista.tail = nullptr;

    Nodo *nodo1 = new Nodo;
    nodo1->data = 5;
    nodo1->next = nullptr;
    lista.head = nodo1;
    lista.tail = nodo1;

    Nodo *nodo2 = new Nodo;
    nodo2->data = 22;
    nodo2->next = nullptr;
    lista.tail->next = nodo2;
    lista.tail = nodo2;

    Nodo *nodo3 = new Nodo;
    nodo3->data = 18;
    nodo3->next = nullptr;
    lista.tail->next = nodo3;
    lista.tail = nodo3;

    Nodo *nodo4 = new Nodo;
    nodo4->data = 13;
    nodo4->next = nullptr;
    lista.tail->next = nodo4;
    lista.tail = nodo4;

    Nodo *nodo5 = new Nodo;
    nodo5->data = 7;
    nodo5->next = nullptr;
    lista.tail->next = nodo5;
    lista.tail = nodo5;

    Nodo *nodo6 = new Nodo;
    nodo6->data = 12;
    nodo6->next = nullptr;
    lista.tail->next = nodo6;
    lista.tail = nodo6;

    //Imprime el arreglo original
    cout << "Arreglo original: (Forward List)" << endl;
    lista.imprimirLista();

    // Primera pregunta
    cout << "Primera pregunta" << endl;
    cout << "El primer elemento de la lista es: " << lista.front<int>() << endl << endl;
    // Segunda pregunta
    cout << "Segunda pregunta" << endl;
    cout << "El ultimo elemento de la lista es: " << lista.back<int>() << endl << endl;
    // Tercera pregunta
    cout << "Tercera pregunta" << endl;
    cout << "Agrega un elemento al comienzo de la lista:" << endl;
    lista.push_front(4);

    lista.imprimirLista();

    // Cuarta pregunta
    cout << "Cuarta pregunta" << endl;
    cout << "Agrega un elemento al final de la lista:" << endl;
    lista.push_back(77);

    lista.imprimirLista();

    cout << "Quinta pregunta:" << endl;
    cout << "Remueve el elemento del comienzo de la lista:" << endl;
    lista.pop_front<int>();

    lista.imprimirLista();

    cout << "Sexta pregunta:" << endl;
    cout << "Remueve el elemento del final de la lista:" << endl;
    lista.pop_back<int>();

    lista.imprimirLista();

    cout << "Septima pregunta:" << endl;
    cout << "Retorna el elemento en la posicion indicada:" << endl << endl;
    cout << lista.operator[]<int>(5) << endl<<endl;

    cout << "Octava pregunta:" << endl;
    cout << "Retorna si la lista esta vacia o no: (0 es falso y 1 verdadero)" << endl;
    lista.imprimirLista();
    cout << "La lista esta vacia? : " << lista.empty() << endl << endl;

    cout << "Novena pregunta:" << endl;
    cout << "Retorna el tamano de la lista:" << endl;
    cout << "Lista actual: " << endl;
    lista.imprimirLista();
    cout << "El tamano de la lista es: " << lista.size() << endl << endl;

    cout << "Onceava pregunta:" << endl;
    cout << "Implemente un algoritmo de ordenacion con listas enlazadas:" << endl;
    cout<<"Lista ordenada (de mayor a menor): "<<endl;
    lista.sort();
    lista.imprimirLista();

    cout<<"Doceava pregunta:"<<endl;
    cout<<"Revierte la lista:"<<endl;
    lista.reverse();
    lista.imprimirLista();

    //Se ha colocado esta pregunta para poder constestar las demás preguntas.
    //Para al final utilizar el borrado completo de la lista
    cout << "Decima pregunta:" << endl;
    cout << "Elimina todos los elementos de la lista:" << endl;
    lista.clear();
    cout << "La lista esta vacia? : " << lista.empty() << endl << endl;

    return 0;
}
