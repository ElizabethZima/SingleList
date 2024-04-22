#include <iostream>

template <typename T>
class SinglyLinkedList {
public:
    // Конструктор по умолчанию
    SinglyLinkedList();

    // Деструктор
    ~SinglyLinkedList();

    // Проверка пустоты списка
    bool isEmpty() const;

    // Вставка элемента в конец списка
    void insertAtEnd(const T& data);

    // Вставка элемента в начало списка
    void insertAtFront(const T& data);

    // Удаление элемента из списка по значению
    void remove(const T& data);

    // Поиск элемента в списке по значению
    bool find(const T& data) const;

    // Печать всего списка
    void printList() const;

private:
    // Структура узла списка
    struct Node {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    // Указатель на головной узел списка
    Node* head;
};

// Реализация методов класса SinglyLinkedList

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::insertAtEnd(const T& data) {
    Node* newNode = new Node(data);

    if (isEmpty()) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtFront(const T& data) {
    Node* newNode = new Node(data, head);
    head = newNode;
}

template <typename T>
void SinglyLinkedList<T>::remove(const T& data) {
    if (isEmpty()) {
        return;
    }

    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
}

template <typename T>
bool SinglyLinkedList<T>::find(const T& data) const {
    if (isEmpty()) {
        return false;
    }

    Node* current = head;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }

    return current != nullptr;
}

template <typename T>
void SinglyLinkedList<T>::printList() const {
    if (isEmpty()) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main(){
    SinglyLinkedList<int> list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtFront(5);

    std::cout << "List: ";
    list.printList();

    std::cout << "Remove element 20..." << std::endl;
    list.remove(20);

    std::cout << "Updated list: ";
    list.printList();

    std::cout << "Searching for item 15..." << std::endl;
    if (list.find(15)) {
        std::cout << "Element 15 found" << std::endl;
    } else {
        std::cout << "Element 15 not found" << std::endl;
    }
}
