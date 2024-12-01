#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createnode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

void traversal(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;  // Indicate end of the list
}

void insertatend(node*& head, int value) {  // Pass head by reference
    node* newnode = createnode(value);
    if (head == nullptr) {
        head = newnode;  // First node insertion
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newnode;  // Link new node at the end
}

void deletebyvalue(node*& head, int value) {  // Pass head by reference
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // Special case: Deleting the head node
    if (head->data == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {  // Value not found
        cout << "Value not found!" << endl;
        return;
    }

    // Delete the node
    node* nodetodelete = temp->next;
    temp->next = temp->next->next;
    delete nodetodelete;
}

bool search(node* head, int value) {
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << value << " was found in the list." << endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    node* head = nullptr;  // Initialize an empty list
    
    int choice, value;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertatend(head, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deletebyvalue(head, value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (!search(head, value))
                    cout << "Value not found." << endl;
                break;
            case 4:
                cout << "Linked List: ";
                traversal(head);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
