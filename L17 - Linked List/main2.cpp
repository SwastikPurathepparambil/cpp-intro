#include <iostream>
using namespace std;

// Challenge: Doubly Linked List
// WOW I DID IT PROPERLY FIRST TRY

struct Node {
    int data;
    Node* next;
    // Doubly
    Node* prev;
};

class DoublyLinkedList {
    public: 
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }   
        
        void printItems() {
            Node *p;
            p = head;
            while (p != nullptr) {
                cout << "Current Value: " << p->data << endl;
                cout << "Current address: " << p << endl;
                cout << "Previous: " << p->prev << endl;
                p = p->next;
            }
        }

        void addToFront(int data_param) {
            //Done
            Node *p;
            p = new Node;
            p->data = data_param;
            p->next = head;
            head = p;
            //Doubly
            p->prev = nullptr;
            if (tail == nullptr) {
                tail = p;
            }
        }

        void addToRear(int data_param) {
            //Done
            if (head == nullptr) {
                addToFront(data_param);
            } else {
                Node *new_node = new Node;
                new_node->data = data_param;
                tail->next = new_node;
                new_node->next = nullptr;
                // Doubly
                new_node->prev = tail;
                tail = new_node;

            }
        }

        void deleteItem(int data_param) {
            if (head == nullptr) return; 
            if (head->data == data_param) {
                Node *killMe = head;
                head = killMe->next;
                // Doubly
                head->prev = nullptr;
                delete killMe;
                return;
            }
            Node *p = new Node;
            p = head;
            while (p != nullptr) {
                if (p->next != nullptr && p->next->data == data_param) {
                    break;
                }
                p = p->next;
            }
            if (p != nullptr) {
                Node *killMe = p->next; 
                p->next = killMe->next; 
                // Doubly
                killMe->next->prev = p;
                delete killMe; 
            }   
        }

        bool findItem(int data_param) {
            Node *p = new Node;
            p = head;
            while (p != nullptr) {
                if (p->data == data_param) {
                    return true;
                }
                p = p->next;
            }
            return false;
        }

        ~DoublyLinkedList() {
            Node *p;
            p = head;
            while (p != nullptr) {
                Node *n = p->next;
                delete p;
                p = n;
            }
        }


    private:
        Node *head;
        Node *tail;
};


int main() {

    DoublyLinkedList mvla2;
    mvla2.addToFront(10);
    mvla2.addToRear(4);
    mvla2.addToRear(6);
    mvla2.addToRear(2);
    mvla2.addToRear(8);
    mvla2.printItems();
    cout << (mvla2.findItem(1) ? "Found specified item" : "Did not find item") << endl;

}