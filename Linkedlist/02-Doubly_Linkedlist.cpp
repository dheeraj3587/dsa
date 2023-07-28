#include <iostream>

class Node {
public:
    int Data;
    Node* Prev;
    Node* Next;
    
    Node(int Data) {
        this->Data = Data;
        this->Prev = nullptr;
        this->Next = nullptr;
    }

    // Destructor to clean up the memory by recursively deleting nodes.
    ~Node() {
        if (this->Next != nullptr) {
            delete this->Next;
            this->Next = nullptr;
        }
    }
};

/////////////////////////
Node* Head = nullptr;
Node* Tail = nullptr;
/////////////////////////

class Doubly {
public:
    // Insert a new node at the head of the doubly linked list.
    void InsertAtHead(int Data) {
        if (Head == nullptr) {
            Node* Temp = new Node(Data);
            Head = Temp;
            Tail = Temp;
            return;
        }
        Node* Temp = new Node(Data);
        Temp->Next = Head;
        Head->Prev = Temp;
        Head = Temp;
    }

    // Insert a new node at the tail of the doubly linked list.
    void InsertAtTail(int Data) {
        if (Tail == nullptr) {
            Node* Temp = new Node(Data);
            Tail = Temp;
            Head = Temp;
            return;
        }
        Node* Temp = new Node(Data);
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
    }

    // Insert a new node at a specified position in the doubly linked list.
    // If the position is out of range, the node will be inserted at the tail.
    void InsertAtMiddle(int Position, int Data) {
        if (Position <= 1) {
            InsertAtHead(Data);
            return;
        }
        Node* Temp = Head;
        int cnt = 1;
        while (cnt < Position - 1 && Temp != nullptr) {
            Temp = Temp->Next;
            cnt++;
        }
        if (Temp == nullptr || Temp->Next == nullptr) {
            InsertAtTail(Data);
            return;
        }
        Node* NTI = new Node(Data);
        NTI->Next = Temp->Next;
        Temp->Next->Prev = NTI;
        Temp->Next = NTI;
        NTI->Prev = Temp;
    }

    // Delete the node at the specified position from the doubly linked list.
    void NodeDelete(int Position) {
        if (Position <= 1) {
            Node* Temp = Head;
            Head = Temp->Next;
            Temp->Next = nullptr;
            delete Temp;
            return;
        }
        int cnt = 1;
        Node* Previous = nullptr;
        Node* Current = Head;
        while (cnt < Position && Current != nullptr) {
            Previous = Current;
            Current = Current->Next;
            cnt++;
        }
        if (Current == nullptr) {
            // The position is out of range, do nothing.
            return;
        }
        if (Current->Next == nullptr) {
            // If the node to delete is the last node, update the Tail pointer.
            Previous->Next = nullptr;
            Tail = Previous;
        } else {
            Previous->Next = Current->Next;
            Current->Next->Prev = Previous;
        }
        Current->Prev = nullptr;
        Current->Next = nullptr;
        delete Current;
    }

    // Print the elements of the doubly linked list.
    void Print() {
        Node* Temp = Head;
        while (Temp != nullptr) {
            std::cout << Temp->Data << "--> ";
            Temp = Temp->Next;
        }
        std::cout << "NULL" << std::endl;
    }
};

// Unit Test
int main() {
    Doubly d1;
    
    // Insert elements into the doubly linked list.
    d1.InsertAtHead(56);
    d1.InsertAtHead(57);
    d1.InsertAtTail(58);
    d1.InsertAtTail(60);
    d1.InsertAtMiddle(2, 59);
    
    // Print the doubly linked list.
    std::cout << "Doubly Linked List: ";
    d1.Print();

    // Delete the node at position 3 (0-based indexing).
    d1.NodeDelete(3);
    
    // Print the doubly linked list after deletion.
    std::cout << "Doubly Linked List after deletion: ";
    d1.Print();
    
    // Display the Head and Tail elements.
    if (Head) {
        std::cout << "The Head is " << Head->Data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    if (Tail) {
        std::cout << "The Tail is " << Tail->Data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    // Clean up memory by deleting all the nodes.
    delete Head;
    Head = nullptr;
    Tail = nullptr;

    return 0;
}
