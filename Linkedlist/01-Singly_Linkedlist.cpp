#include <iostream>
#include <stdexcept>

class Node {
public:
    int Data;
    Node* Next;

    Node(int Data) {
        this->Data = Data;
        this->Next = nullptr;
    }

    ~Node() {
        if (this->Next != nullptr) {
            delete this->Next;
            this->Next = nullptr;
        }
    }
};

Node* Head = nullptr;
Node* Tail = nullptr;

class Singly {
public:
    void InsertAtHead(Node*& Head, Node*& Tail, int Data) {
        // Create a new node with the given data
        Node* Temp = new Node(Data);

        if (Head == nullptr) {
            // If the list is empty, the new node becomes both Head and Tail
            Head = Temp;
            Tail = Temp;
            return;
        }

        // Insert the new node at the head of the list
        Temp->Next = Head;
        Head = Temp;
    }

    void InsertAtTail(Node*& Head, Node*& Tail, int Data) {
        // Create a new node with the given data
        Node* Temp = new Node(Data);

        if (Tail == nullptr) {
            // If the list is empty, the new node becomes both Head and Tail
            Head = Temp;
            Tail = Temp;
            return;
        }

        // Insert the new node at the tail of the list
        Tail->Next = Temp;
        Tail = Temp;
    }

    void InsertAtMiddle(Node*& Head, Node*& Tail, int Position, int Data) {
        if (Position <= 0) {
            // Invalid position, throw an exception
            throw std::runtime_error("Invalid Position");
            return;
        }

        if (Position == 1) {
            // Insert at the head when Position is 1
            InsertAtHead(Head, Tail, Data);
            return;
        }

        int cnt = 1;
        Node* Temp = Head;
        while (cnt < Position - 1) {
            if (Temp == nullptr) {
                // Invalid position, throw an exception
                throw std::runtime_error("Invalid Position");
                return;
            }
            Temp = Temp->Next;
            cnt++;
        }

        // Create a new node with the given data
        Node* NTI = new Node(Data);
        NTI->Next = Temp->Next;
        Temp->Next = NTI;

        // Update the Tail if the new node is inserted at the end
        if (Temp == Tail) {
            Tail = NTI;
        }
    }

    void Print(Node* Head) {
        Node* Temp = Head;
        while (Temp != nullptr) {
            std::cout << Temp->Data << " --> ";
            Temp = Temp->Next;
        }

        std::cout << "NULL" << std::endl;
    }

    void DeleteNode(Node*& Head, Node*& Tail, int Position) {
        if (Position <= 0) {
            // Invalid position, throw an exception
            throw std::runtime_error("Invalid Position");
            return;
        }

        if (Position == 1) {
            if (Head == nullptr) {
                // Empty list, throw an exception
                throw std::runtime_error("List is empty");
                return;
            }

            // Delete the first node
            Node* Temp = Head;
            Head = Temp->Next;

            // Update the Tail if the list had only one node
            if (Tail == Temp) {
                Tail = nullptr;
            }

            Temp->Next = nullptr;
            delete Temp;
            return;
        }

        int cnt = 1;
        Node* Prev = nullptr;
        Node* Current = Head;
        while (cnt < Position) {
            if (Current == nullptr) {
                // Invalid position, throw an exception
                throw std::runtime_error("Invalid Position");
                return;
            }
            Prev = Current;
            Current = Current->Next;
            cnt++;
        }

        if (Current == nullptr) {
            // Invalid position, throw an exception
            throw std::runtime_error("Invalid Position");
            return;
        }

        // Update the Tail if the node to be deleted is the last node
        if (Current == Tail) {
            Tail = Prev;
        }

        Prev->Next = Current->Next;
        Current->Next = nullptr;
        delete Current;
    }

    void Getlen(Node* Head) {
        int cnt = 0;
        Node* Temp = Head;
        while (Temp != nullptr) {
            cnt++;
            Temp = Temp->Next;
        }

        std::cout << "The Length of Linked List is " << cnt << std::endl;
    }
};

// Unit test function
void unitTest() {
    Singly s1;
    s1.InsertAtHead(Head, Tail, 56);
    s1.InsertAtTail(Head, Tail, 58);
    s1.InsertAtMiddle(Head, Tail, 2, 57);

    // Print the initial linked list
    std::cout << "Initial Linked List: ";
    s1.Print(Head);

    // Delete the node at position 2
    s1.DeleteNode(Head, Tail, 2);

    // Print the modified linked list after deletion
    std::cout << "Linked List after Deletion: ";
    s1.Print(Head);

    // Get the length of the linked list
    s1.Getlen(Head);
}

int main() {
    unitTest();
    return 0;
}
