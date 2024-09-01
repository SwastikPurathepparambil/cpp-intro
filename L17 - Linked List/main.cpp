#include <iostream>
using namespace std;

// Singly LinkedList

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    public: 
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }   
        
        void printItems() {
            Node *p;
            p = head;
            while (p != nullptr) {
                cout << "Current Value: " << p->data << endl;
                p = p->next;
            }
        }

        void addToFront(int data_param) {
            // Quick Note: this works regardless of if there is no
            // items in the LinkedList
            Node *p;
            p = new Node;
            p->data = data_param;
            p->next = head;
            head = p;
            if (tail == nullptr) {
                tail = p; // Initialize tail if this is the first node
            }
        }

        void addToRear(int data_param) {
            // Two cases: No data already in list and data exists in list
            // Case 1: No data in list
            if (head == nullptr) {
                addToFront(data_param);
            } else {
            // Case 2: Data exists in list
                // Find last item in list (hint: done in printItems)
                // Node *p;
                // p = head;
                // stop at the last pointer 
                // while (p->next != nullptr) {
                //     p = p->next;
                // }
                // With Tail Pointer:
            
                Node *new_node = new Node;
                new_node->data = data_param;
                tail->next = new_node;
                new_node->next = nullptr;
                tail = new_node;

            }
        }

        void deleteItem(int data_param) {
            if (head == nullptr) return; // If there's nothing to delete, do nothing
            // Case 1: First Node is the one to be deleted
            if (head->data == data_param) {
                Node *killMe = head;
                head = killMe->next;
                delete killMe;
                return;
            }
            // Case 2: Other node has to be deleted
            Node *p = new Node;
            p = head;
            while (p != nullptr) {
                if (p->next != nullptr && p->next->data == data_param) {
                    break;
                }
                p = p->next;
            }
            // Check if we ever actually found an item to delete
            if (p != nullptr) {
                Node *killMe = p->next; //Set killMe to next item in List
                p->next = killMe->next; //Set next item in list to the item after the next item in the list
                delete killMe; // delete killMe
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

        ~LinkedList() {
            Node *p;
            p = head;
            while (p != nullptr) {
                Node *n = p->next;
                delete p;
                p = n;
            }
        }


    private:
        // just having the head is a singly linked list
        Node *head;
        // could add tail pointer
        Node *tail;
};


int main() {

    // Node *head, *second, *third; //Why? Because the Node* star is an address which points to something
    // // might need to go back and review dynamic memory allocation
    // head = new Node; // head pointer is the first item in the Linked List
    // second = new Node;
    // third = new Node;

    // head -> data = 2;
    // head -> next = second;
    // second -> data = 4;
    // second -> next = third;
    // third -> data = 6;
    // third -> next = nullptr;

    // Node *temp;
    // temp = head;

    // while (temp != nullptr) {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    // }
    

    // delete head;
    // delete second;
    // delete third;

    //Singly Linked List
    LinkedList mvla;
    mvla.addToFront(10);
    mvla.addToRear(4);
    mvla.printItems();
    cout << (mvla.findItem(1) ? "Found specified item" : "Did not find item") << endl;

    // Linked List with tail pointer
}