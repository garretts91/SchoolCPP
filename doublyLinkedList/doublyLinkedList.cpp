// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The linked list stores data in sequential storage, like arrays.Though the data are stored sequentially, the memory locations are not contiguous.
// Unlike an array, the linked list can store data of different data types.

#include <iostream>

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    // Default constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to delete the
    // node at given position
    void deleteNode(int nodeOffset) {
        if (head == NULL) {
            std::cout << "List empty." << std::endl;
            return;
        }

        Node* temp = head;
        int count = 1;

        // Find length of the linked-list.
        while (temp != NULL && count < nodeOffset) {
            temp = temp->next;
            count++;
        }


        if (temp == NULL) {
            std::cout << "Index out of range." << std::endl;
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            else {
                tail = NULL;
            }
        }
        else if (temp == tail) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
            else {
                head = NULL;
            }
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to print the
    // linked list.
    void printList() {
        Node* temp = head;

        if (head == NULL) {
            std::cout << "List empty." << std::endl;
            return;
        }

        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    std::cout << "Elements of the list are: ";
    list.printList();
    std::cout << std::endl;

    // Delete node at position 3.
    list.deleteNode(3);

    std::cout << "Elements of the list are: ";
    list.printList();
    std::cout << std::endl;

    return 0;
}
