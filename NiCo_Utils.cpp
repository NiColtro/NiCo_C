#include <iostream>
using namespace std;

/*
 * NiCo Utils in C++ per Liste e Code
 * Ver: 1.0-DEV
 */

struct NODE {
    int key;
    NODE *next;
};

struct TAIL {
    NODE *front;
    NODE *rear;
};

class Utils { public:
    class List { public:

        static NODE *newList (int key) {
            NODE *p = new NODE;

            p->key = key;
            p->next = NULL;

            return p;
        }

        static NODE *getLastNode (NODE *list) {
            NODE *p = list;

            while (p->next != NULL)
                p = p->next;

            return p;
        }

        static void insertTop (int key, NODE *&list) {
            NODE *newNode = new NODE;

            newNode->key = key;
            newNode->next = list;
            list = newNode;
        }

        static void insertBottom(int key, NODE *list) {

            NODE *newNode = new NODE;
            NODE *lastNode = getLastNode(list);

            lastNode->next = newNode;
            newNode->key = key;
            newNode->next = NULL;
        }

        static void printList(NODE *list) {
            while (list != NULL) {
                printf("%i\n", list->key);
                list = list->next;
            }
        }
    };

    class Tile { public:

        static void initTail(TAIL *p) {
            p->front = p->rear = NULL;
        }

        static bool isTailEmpty(TAIL *p) {
            if (p->front == NULL)
                return true;
            else
                return false;
        }

        static void enQueue(TAIL *p, int key) {
            NODE *newNode = new NODE;
            newNode->key = key;
            newNode->next = NULL;

            if (isTailEmpty(p))
                p->rear = p->front = newNode;
            else {
                p->rear->next = newNode;
                p->rear = newNode;
            }
        }

        static bool deQueue(TAIL *p) {
            NODE *temp = new NODE;

            if (isTailEmpty(p))
                return false;
            else {
                temp = p->front;

                p->front = p->front->next;
                free(temp);
                if (p->front == NULL)
                    p->rear = NULL;

                return true;
            }
        }

        static void printTail(TAIL *p) {
            TAIL *temp = p;

            if (isTailEmpty(temp))
                cout << "Coda vuota.";
            else {
                if (temp->front == NULL) cout << "Errore.";

                while (temp->front != NULL) {
                    cout << temp->front->key << endl;
                    temp->front = temp->front->next;
                }
            }
        }
    };
};

