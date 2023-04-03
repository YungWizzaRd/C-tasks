/*******************************************

Aleksejs Gerasimovs ag21275

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Abās programmās:
  a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
  b) jāpielieto uzrakstītā funkcija sarakstam,
  c) jāizdrukā saraksts pēc funkcijas darbības.
  d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

G12. Uzrakstīt funkciju, kas pārvieto saraksta n-to elementu uz saraksta beigām. Darbība jāveic, pārkabinot saites, nevis pārrakstot elementu vērtības.

********************************************/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void printList(const std::list<int>& l)
{
    for_each(l.begin(), l.end(), [](int val) {cout << val << " "; });
    cout << endl;
}

void fillList(list<int>& l)
{
    int input;
    cin >> input;
    while (input)
    {
        l.push_back(input);
        cin >> input;
    }
}

void moven(list<int>& l, int n)
{
    auto it = l.begin();
    advance(it, n);
    int num = *it;
    l.erase(it);
    l.push_back(num);
}

int main()
{
    list<int> l;
    int x, k = 0;

    cout << "Ievadiet saraksta elementus(o lai pabeigt):" << endl;
    fillList(l);
    if (!l.empty()) {
        printList(l);
        cout << "Ievadiet saraksta n-to elementu" << endl;
        cin >> x;
        moven(l, x);
        printList(l);
        l.clear();
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