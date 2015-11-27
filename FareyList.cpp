#include <iostream>
using namespace std;

class Node
{
public:
    int n, d;
    Node *next;
    Node(int ni, int di, Node* p = NULL) { d = di; n = ni; next = p; }
};

class FareyList
{
public:
    FareyList();
    ~FareyList() {}
    //void Insert()
    void Insert(Node*, int, int);
    void Output();
    void LevelUP();
private:
    Node* head;
    int level;
};

FareyList::FareyList()
{
    head = new Node(0, 1);
    head->next = new Node(1, 1);
    level = 1;
}

void FareyList::Output()
{
    Node* p = head;
    cout << "The current level of the Farey list is " << level << endl;
    while(p != NULL)
    {
        cout << p->n << "/" << p->d << " ";
        p = p->next;
    }
    cout << endl;
}

void FareyList::Insert(Node* p, int n, int d)
{
    Node* tmp = new Node(n, d);
    tmp->next = p->next;
    p->next = tmp;
}

void FareyList::LevelUP()
{
    Node *p = head, *q = head->next;
    while(q != NULL)
    {
        if( p->d + q->d <= level + 1)
        {
            Insert(p, p->n + q->n, p->d + q->d);
            //Node* tmp = new Node(p->n + q->n, p->d + q->d);
            /*p->next = tmp;
            tmp->next = q;
            */
            p = q;
            q = q->next; 
        }
    }
    level++;
}

int main()
{
    FareyList A;
    A.Output();
    //cout << endl;
    //A.LevelUP();
    //A.Output();
    int l;
    cout << "Farey Level:";
    cin >> l;
    for(int i = 1; i < l; i++)
        A.LevelUP();
    A.Output();
    return 0;
}
