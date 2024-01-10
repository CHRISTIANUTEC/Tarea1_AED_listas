#include <iostream>

using namespace std;

template <typename T>
class DoubleList{
private:
   struct Node{
       T data ;
       Node* next;
       Node* prev;
       Node(): next (nullptr) , prev(nullptr){}
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node head;
    Node* tail;
    int nodes;

public:
    DoubleList(): head (nullptr), tail(nullptr), nodes(0){}

     ~DoubleList() {
        clear();
    }
    T  front(){
       if (is_empty()){
         cout << "Lista vacia"<< endl;
      }
      return head -> data;
    }
    T  back(){
      if (is_empty()){
        cout << "Lista vacia"<< endl;

      }
      return tail-> data;
      
    } 
    void push_front(T data){
         Node* newNode = new Node(data);
        if (is_empty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        nodes++;
    }
    void push_back(T data)  {
        Node* newNode = new Node(data);
        if (is_empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        nodes++;
    }
    T pop_front()  {
        if (is_empty()) {
            cout << "Lista vacía"<< endl;
        }
        T frontData = head->data;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        nodes--;
        return frontData;
    }
    T pop_back() {
        if (is_empty()) {
            cout << "Lista vacia"<< endl;
        }
        T backData = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        nodes--;
        return backData;
    }
    bool insert(T data, int pos){
        if (pos < 0 || pos > size()) {
            throw std::out_of_range("Posición fuera de rango");
        }

        if (pos == 0) {
            push_front(data);
        } else if (pos == size()) {
            push_back(data);
        } else {
            Node* newNode = new Node(data);
            Node* temp = head;
            int i = 0;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            nodes++;
        }
        return true;
    }

    bool remove(int pos) {
        if (pos < 0 || pos >= size()) {
            cout << "Posición fuera de rango"<< ednl;
        }

        if (pos == 0) {
            pop_front();
        } else if (pos == size() - 1) {
            pop_back();
        } else {
            Node* temp = head;
            int i = 0;
            while (i < pos) {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            nodes--;
        }
        return true;
    }

    T& operator[](int pos)  {
        if (pos < 0 || pos >= size()) {
            cput << "Posición fuera de rango"<< endl;
        }

        Node* temp = head;
        int i = 0;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    bool is_empty()  {
        return head == nullptr || tail == nullptr;
    }

    int size()  {
        return nodes;
    }

    void clear()  {
        while (!is_empty()) {
            pop_front();
        }
    }
    void reverse()  {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }

        tail = head;
        head = prev;
    }

}:
