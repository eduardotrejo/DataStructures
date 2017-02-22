// ListNode : C Struct : Linked List

#include <iostream>
using namespace std;

// todo : struct
struct ListNode {
    int value;
    ListNode *next;
};

// todo : add
ListNode * add(ListNode *l, int v) {
    ListNode * rn = 0;
    if (l == 0) {
        ListNode *n = new ListNode;
        n->value = v;
        n->next = 0;
        l = n;
        rn = n;
    } else {
        ListNode * last = l;
        while (last->next != 0) {
            last = last-> next;
        }
        ListNode *n = new ListNode;
        n->value = v;
        n->next = 0;
        last->next = n;
        rn = n;
    }
    return rn;
}

// todo : get
ListNode * get(ListNode *l, int index) {
    ListNode *rn = l;
    int c = 0;
    while ((rn->next != 0) && (c++ < index)) {
        rn = rn->next;
    }
    return rn;
}

ListNode * last(ListNode *l) {
    ListNode *rn = l;
    if (l != 0) {
        while (rn->next != 0) {
            rn = rn->next;
        }
    }
    return rn;
}

ListNode * listNode(int v) {
    ListNode *n = new ListNode;
    n->value = v;
    return n;
}

// todo : insert
ListNode * insert(ListNode *l, int v, int index) {
    ListNode *rn = 0;
    if (index == 0) {
        ListNode *n = listNode(v);
        n->next = l->next;
        l->next = n;
        rn = n;
    } else {
        ListNode *n = get(l, index - 1);
        ListNode *nn = listNode(v);
        nn->next = n->next;
        n->next = nn;
        rn = nn;
    }
    return rn;
}


// todo : remove (lab)
ListNode * remove(ListNode *l, int index){
    ListNode *rn = l;
    ListNode *n = get(l, index);
    rn->next = n->next;
    delete n;
    return l;
}

// todo : show
void show(ListNode *l) {
    cout << "(";
    if (l == 0) {
        cout << "<empty>";
    } else {
        ListNode *ln = l;
        int c = 0;
        while (ln != 0) {
            if (c++ > 0) cout << ", ";
            cout << ln->value;
            ln = ln->next;
        }
    }
    cout << ")" << endl;
}

int main(int argc, const char * argv[])
{
    ListNode *list = NULL;
    show(list);
    list = add(list, 1);
    show(list);
    // add(list, 33);
    show(list);
    for (int i = 1; i < 5; i++) {
        add(list, i * 2);
    }
    show(list);
    
    cout << "list[4] = " << get(list, -46666666)->value << endl;
    
    insert(list, 42, 2);
    
    show(list);
    
 
    remove(list, 3);
    show(list);
    
    return 0;
}