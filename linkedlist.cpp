#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int val;
        Node *next;

        Node(int data){
            val = data;
            next = NULL;
        }
};

void insertNodeAtHead( Node* &head , int data ) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printNode( Node* &head){
    Node* temp = head;
    while( temp != NULL ){
        cout << temp->val;
        temp = temp->next;
    }
}

void insertNodeAtTail( Node* &head , int data ){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertNodeAt(Node* &head , int data , int position){
    if(position == 0){
        insertNodeAtHead(head,data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    int currentPosition = 0;
    while(currentPosition != position - 1){
        currentPosition++;
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void updateNodeAt( Node* &head , int data , int position){
    Node* temp = head;
    int currentPosition = 0;
    while(currentPosition != position){
        currentPosition++;
        temp = temp->next;
    }
    temp->val = data;
}

void deleteNodeAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteNodeAt( Node* &head , int position){
    if(position == 0){
        deleteNodeAtHead(head);
        return;
    }
    Node* temp = head;
    int currentPosition = 0;
    while(currentPosition != position - 1){
        currentPosition++;
        temp=temp->next;
    }
    Node* nodeToBeDeleted = temp->next;
    temp->next = nodeToBeDeleted->next;
    free(nodeToBeDeleted);
}

int main() {
    Node* head = NULL;
    insertNodeAtHead( head, 1);
    insertNodeAtHead( head, 2);
    insertNodeAtHead( head, 3);
    insertNodeAtTail(head,4);
    insertNodeAt(head,9,1);
    updateNodeAt(head,7,1);
    deleteNodeAtHead(head);
    deleteNodeAt(head,0);
    printNode(head);
    return 0;
}
