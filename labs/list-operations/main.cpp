/**
 * Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Linked List Operations
 */

#include <iostream>

//node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

//inline function to add an element to the front of the list
inline void addToFront(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

//inline function to add an element to the end of the list
inline void addToEnd(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//inline function to remove an element from the front of the list
inline void removeFromFront(Node** head) {
    if (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

//inline function to remove the last element from the list
inline void removeFromEnd(Node** head) {
    if (*head == nullptr) return;
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
    } else {
        Node* current = *head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

//inline function to search for an element by value
inline Node* searchElement(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return nullptr;
}

//inline function to reverse the list
inline void reverseList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;//store next node
        current->next = prev;//reverse current node's pointer
        prev = current;      //move prev up
        current = next;      //move to next node
    }
    *head = prev;            //update head
}

//inline function to sort the list in ascending order using bubble sort
inline void sortList(Node* head) {
    if (head == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                //swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

//node structure for doubly circular linked list
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

//inline function to convert singly linked list to doubly circular linked list
inline DNode* toTwoWayList(Node* head) {
    if (head == nullptr) return nullptr;
    auto* dHead = new DNode;
    dHead->data = head->data;
    dHead->prev = nullptr;
    dHead->next = nullptr;
    DNode* dCurrent = dHead;
    Node* sCurrent = head->next;
    while (sCurrent != nullptr) {
        auto* newNode = new DNode;
        newNode->data = sCurrent->data;
        newNode->prev = dCurrent;
        newNode->next = nullptr;
        dCurrent->next = newNode;
        dCurrent = newNode;
        sCurrent = sCurrent->next;
    }
    //make it circular
    dCurrent->next = dHead;
    dHead->prev = dCurrent;
    return dHead;
}

//inline function to clear the singly linked list
inline void clearList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

//inline function to print all elements of the singly linked list
inline void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

//inline function to print all elements of the doubly circular linked list
inline void printDoublyList(DNode* head) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    DNode* current = head;
    do {
        std::cout << current->data << " <-> ";
        current = current->next;
    } while (current != head);
    std::cout << "(back to head)" << std::endl;
}

//inline function to clear the doubly circular linked list
inline void clearDoublyList(DNode** head) {
    if (*head == nullptr) return;
    DNode* current = *head;
    do {
        DNode* temp = current;
        current = current->next;
        delete temp;
    } while (current != *head);
    *head = nullptr;
}

int main() {
    //create a singly linked list
    Node* head = nullptr;

    //adding elements to the front and end
    addToFront(&head, 10);
    addToEnd(&head, 5);
    addToFront(&head, 20);
    addToEnd(&head, 15);

    //Printing the list
    std::cout << "List after adding elements: ";
    printList(head);

    //removing an element from the front
    removeFromFront(&head);
    std::cout << "List after removing from front: ";
    printList(head);

    //removing an element from the end
    removeFromEnd(&head);
    std::cout << "List after removing from end: ";
    printList(head);

    //searching for an element
    int searchVal = 15;
    Node* foundNode = searchElement(head, searchVal);
    if (foundNode != nullptr) {
        std::cout << "Element " << searchVal << " found in the list." << std::endl;
    } else {
        std::cout << "Element " << searchVal << " not found in the list." << std::endl;
    }

    //adding more elements
    addToEnd(&head, 25);
    addToFront(&head, 30);
    addToEnd(&head, 5);

    // Printing the list before sorting
    std::cout << "List before sorting: ";
    printList(head);

    //sorting the list
    sortList(head);
    std::cout << "List after sorting: ";
    printList(head);

    // Reversing the list
    reverseList(&head);
    std::cout << "List after reversing: ";
    printList(head);

    //converting to doubly circular linked list
    DNode* dHead = toTwoWayList(head);
    std::cout << "Doubly circular linked list: ";
    printDoublyList(dHead);

    //clearing the singly linked list
    clearList(&head);
    std::cout << "Singly linked list after clearing: ";
    printList(head);

    //clearing the doubly circular linked list
    clearDoublyList(&dHead);
    std::cout << "Doubly circular linked list after clearing: ";
    printDoublyList(dHead);

    return 0;
}