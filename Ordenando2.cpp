#include <stdio.h>

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct List {
    Node* first;
    Node* last;
    int c;

    List() {
        first = NULL;
        last = NULL;
        c = 0;
    }

    bool empty() {
        return first == NULL;
    }

    void pushBack(int value) {
        Node* n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void print() {
        Node* aux = first;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    void sort() {
        if (first == NULL) return;
        Node* i = first;
        while (i != NULL) {
            Node* j = i->next;
            while (j != NULL) {
                if (i->value > j->value) {
                    int temp = i->value;
                    i->value = j->value;
                    j->value = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    List l;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        l.pushBack(x);
    }

    for (int i = 0; i < m; ++i) {
        int y;
        scanf("%d", &y);
        l.pushBack(y);
    }

    l.sort();
    l.print();

    return 0;
}
