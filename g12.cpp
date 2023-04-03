/*******************************************
Aleksejs Gerasimovs ag21275

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos :
1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Abās programmās :
a) jābūt iespējai ievadīt saraksta elementus(izveidot patvaļīgu sarakstu),
b) jāpielieto uzrakstītā funkcija sarakstam,
c) jāizdrukā saraksts pēc funkcijas darbības.
d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).
Sīkākas prasības sk.Laboratorijas darbu noteikumos.

G12.Uzrakstīt funkciju, kas pārvieto saraksta n - to elementu uz saraksta beigām.Darbība jāveic, pārkabinot saites, nevis pārrakstot elementu vērtības.

* *******************************************/

#include <iostream>
using namespace std;
struct node
{
    int num;
    struct node* next;
};

void push(struct node** head, int node_data)
{
    struct node* newNode = new node;
    newNode->num = node_data;
    newNode->next = (*head);
    (*head) = newNode;
}

void append(struct node** head, int node_data)
{
    struct node* newNode = new node;
    struct node* last = *head;
    newNode->num = node_data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void printList(node* node)
{
    while (node != NULL)
    {
        cout << node->num << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(struct node** head)
{
    node* current = *head;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void moven(node*& head, int n)
{
    node* tmp = head;
    for (int i = 0; i < n && tmp->next; ++i)
    {
        tmp = tmp->next;
    }
    node* ttmp = head;
    if (tmp != head)
    {
        while (ttmp->next)
        {
            if (tmp == ttmp->next)
            {
                ttmp->next = tmp->next;
                break;
            }
            ttmp = ttmp->next;
        }
    }
    else {
        head = head->next;
    }
    ttmp = head;
    while (ttmp->next)
    {
        ttmp = ttmp->next;
    }
    ttmp->next = tmp;
    tmp->next = NULL;
}

void fillList(struct node** head)
{
    int input;
    cin >> input;
    while (input)
    {
        append(head, input);
        cin >> input;
    }
}

int main()
{
    node* head = NULL;
    int x, k=0;

        cout << "Ievadiet saraksta elementus(o lai pabeigt):" << endl;
        fillList(&head);
        if (&head->num != NULL) {
            printList(head);
            cout << "Ievadiet saraksta n-to elementu" << endl;
            cin >> x;
            moven(head, x);
            printList(head);
            deleteList(&head);
        }
        else {
            cout << "Obligāti jāievāda skaitlis " << endl;
        }
        
    
    return 0;
}

/*************************************
        TESTA PLĀNS

    Input data             expect               Result
1 2 3 4 5 0; 3           1 2 3 5 4                +
1 2 3 4 5 0; 4           1 2 3 4 5                +
1 2 3 4 5 0; 0           1 2 3 4 5			  +
0                 Obligāti jāievāda skaitlis      +
*************************************/