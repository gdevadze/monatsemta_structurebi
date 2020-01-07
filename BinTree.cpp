#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node* Left;
    Node* Right;
    Node() { Left = 0; Right = 0; }
};
class BinTree
{
private:
    Node* Top;

    void LO(Node *T)
    {
        if ((T->Left == 0) && (T->Right == 0))
        {
            cout << T->Value << " ";
        }
        if ((T->Left != 0) && (T->Right == 0))
        {
            LO(T->Left);
            cout << T->Value << " ";
        }
        if ((T->Left == 0) && (T->Right != 0))
        {
            cout << T->Value << " ";
            LO(T->Right);
        }
        if ((T->Left != 0) && (T->Right != 0))
        {
            LO(T->Left);
            cout << T->Value << " ";
            LO(T->Right);
        }
    }

    void RO(Node *T)
    {
        if ((T->Left == 0) && (T->Right == 0))
        {
            cout << T->Value << " ";
        }
        if ((T->Left != 0) && (T->Right == 0))
        {
            cout << T->Value << " ";
            RO(T->Left);
        }
        if ((T->Left == 0) && (T->Right != 0))
        {
            RO(T->Right);
            cout << T->Value << " ";
        }
        if ((T->Left != 0) && (T->Right != 0))
        {
            RO(T->Right);
            cout << T->Value << " ";
            RO(T->Left);
        }
    }

    // Finds the node with minimum value
    Node* minValueNode(Node* node)
    {
        Node* current = node;

        // Loop down to find the leftmost leaf
        while (current && current->Left != 0)
            current = current->Left;

        return current;
    }

public:
    BinTree() { Top = 0; }

    void Add(Node *Elem)
    {
        if (Top == 0) { Top = Elem; return; }
        Node *y = 0, *x = Top;
        while (x != 0)
        {
            y = x;
            if (x->Value < Elem->Value) x = x->Right;
            else
                if (x->Value > Elem->Value) x = x->Left;
                else return;

        }
        if (y->Value < Elem->Value) y = y->Right; else y = y->Left;
    }

    void AddKey(int k)
    {
        Node *Elem = new Node();
        Elem->Value = k;
        if (Top == 0) { Top = Elem; return; }
        Node *y = 0, *x = Top;
        while (x != 0)
        {
            y = x;
            if (x->Value < Elem->Value) x = x->Right;
            else
                if (x->Value > Elem->Value) x = x->Left;
                else return;

        }
        if (y->Value < Elem->Value) y->Right = Elem; else y->Left = Elem;
    }

    void Remove(int k)
    {
        // First find the node that needs to be removed
        Node *node = Top, *parent = 0;
        while (node)
        {
            if (k < node->Value) {
                parent = node;
                node = node->Left;
            }
            else if (k > node->Value) {
                parent = node;
                node = node->Right;
            }
            else
                break;
        }
        if (!node)
            return; // Not found

        // Node with only one child or no child
        if (node->Left == 0)
        {
            Node *child = node->Right;
            
            // Top level node?
            if (!parent)
            {
                Top = child;
            }
            else
            {
                if (node == parent->Left)
                    parent->Left = child;
                else if (node == parent->Right)
                    parent->Right = child;
            }
            delete node;
            return;
        }
        else if (node->Right == 0)
        {
            Node *child = node->Left;

            // Top level node?
            if (!parent)
            {
                Top = child;
            }
            else
            {
                if (node == parent->Left)
                    parent->Left = child;
                else if (node == parent->Right)
                    parent->Right = child;
            }
            delete node;
            return;
        }

        // Node has two children. Get the inorder successor i.e. the node
        // with the smallest value in the right subtree
        Node* minNode = minValueNode(node->Right);
        int minVal = minNode->Value;

        // Remove the inorder successor node
        Remove(minVal);

        // Assing the value from the inorder successor
        node->Value = minVal;
    }

    void LeftOrder()
    {
        if (Top)
            LO(Top);
    }

    void RightOrder()
    {
        if (Top)
            RO(Top);
    }
};

int main(int argc, char** argv) {
    BinTree *A = new BinTree();
    A->AddKey(7);
    A->AddKey(3);
    A->AddKey(10);
    A->AddKey(2);
    A->AddKey(4);
    A->RightOrder();
    cout << endl << endl;
    A->Remove(4);
    A->Remove(7);
    A->RightOrder();
    return 0;
}
