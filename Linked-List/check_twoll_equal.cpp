#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Single insert_last function for both lists
void insert_last(Node*& head, int data) {
    Node* newnode = new Node(data);

    if (head == NULL) {  // Special case: Empty list
        head = newnode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {  // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newnode;  // Add the new node at the end
}

// Function to check if two linked lists are identical
bool check(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data != ptr2->data) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return (ptr1 == NULL && ptr2 == NULL);
}

// Function to display a linked list
void display(Node* head) {
    Node* temp = head;  
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head1 = NULL;
    insert_last(head1, 1);
    insert_last(head1, 2);
    insert_last(head1, 3);
    insert_last(head1, 4);
    insert_last(head1, 5);
    
    display(head1);

    cout << endl;

    Node* head2 = NULL;
    insert_last(head2, 1);
    insert_last(head2, 2);
    insert_last(head2, 3);
    insert_last(head2, 4);
    insert_last(head2, 5);
    
    display(head2);

    cout << "Are the linked lists identical? " << (check(head1, head2) ? "Yes" : "No") << endl;

    return 0;
}
