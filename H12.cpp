/*******************************************

Aleksejs Gerasimovs ag21275

H12. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura glabājas datumi, un kura ieraksta struktūra ir sekojoša:
    gads (int),
    mēnesis (int),
    diena (int),
    ieraksta statuss (0 vai 1).
Programmai katrs jauns ieraksts jāieliek faila beigās.
Ja failā tāds datums jau eksistē, tas nav jāpieliek.
Jāparedz iespēja:
    (1) izmest faila komponenti (loģiski atzīmējot kā izmestu),
    (2) izdrukāt failā esošos datumus uz ekrāna,
    (3) izmest loģiski izmestas komponentes fiziski."

Programma izveidota: 23.06.2022.

********************************************/

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct datums
{
    int gads = 0;
    int menesis = 0;
    int diena = 0;
    bool statuss = true;
    datums() {}
    datums(int gads, int menesis, int diena) : gads(gads), menesis(menesis), diena(diena) {}
    int compare(const datums& dat)
    {
        return gads == dat.gads && menesis == dat.menesis && diena == dat.diena;
    }
};

int adddatums(const string& path) //pievieno datus
{
    cout << "Gads: ";
    int gads;
    cin >> gads;
    if (!gads) return 0;

    cout << "Menesis: ";
    int menesis;
    cin >> menesis;
    if (!menesis) return 0;

    cout << "Diena: ";
    int diena;
    cin >> diena;
    if (!diena) return 0;

    datums dat(gads, menesis, diena);

    int contains = 0;

    fstream f(path, ios::in | ios::binary);
    f.seekg(0, ios::beg);
    datums _dat;
    f.read((char*)&_dat, sizeof(datums));
    while (f.good())
    {
        if (dat.compare(_dat))
        {
            contains = 1;
            break;
        }
        f.read((char*)&_dat, sizeof(datums));
    }
    f.close();

    if (!contains)
    {
        f.open(path, ios::app | ios::binary);
        f.write((char*)&dat, sizeof(datums));
        f.close();
    }

    return 1;
}

void printdatums(const datums& dat) //drukā datus
{
    cout << "gads: " << dat.gads << ", menesis: " << dat.menesis << ", diena: " << dat.diena << ", statuss: " << dat.statuss << endl;
}

int main()
{
    int continue_ = 1;
    while (continue_)
    {
        cout << "Enter mode: create/append (0), read(1), edit (2), delete (3): ";
        int mode;
        cin >> mode;
        if (mode == 0)
        {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            while (adddatums(filename))
            {
                cout << "More? yes (1), no (0): ";
                int more;
                cin >> more;
                if (!more) break;
            }
        }
        else if (mode == 1) //izvada faila datus
        {
            cout << "Enter file path: ";
            string path;
            cin >> path;
            ifstream f(path, ios::in | ios::binary);
            datums dat;
            f.read((char*)&dat, sizeof(datums));
            while (f.good())
            {
                printdatums(dat);
                f.read((char*)&dat, sizeof(datums));
            }
            f.close();
        }
        else if (mode == 2) //izmet datus fiziski vai loģiski
        {
            cout << "Enter file path: ";
            string path;
            cin >> path;
            cout << "Enter edit mode: delete logically (0), delete physically (1): ";
            int editmode;
            cin >> editmode;
            if (editmode == 0)
            {
                cout << path << ": " << endl;
                fstream f(path, ios::in | ios::out | ios::binary);
                datums dat;
                f.read((char*)&dat, sizeof(datums));
                int line = 0;
                while (f.good())
                {
                    cout << "[" << line++ << "] ";
                    printdatums(dat);
                    f.read((char*)&dat, sizeof(datums));
                }
                f.close();

                cout << "Enter komponent number: ";
                int num;
                cin >> num;

                f.open(path, ios::in | ios::out | ios::binary);
                f.seekg(num * sizeof(datums), ios::beg);
                f.read((char*)&dat, sizeof(datums));
                f.seekp(num * sizeof(datums), ios::beg);
                dat.statuss = false;
                f.write((char*)&dat, sizeof(datums));
                f.close();
            }
            else if (editmode == 1)
            {
                list<datums> datumi;
                ifstream in(path, ios::binary);
                datums dat;
                in.read((char*)&dat, sizeof(datums));
                int line = 0;
                while (in.good())
                {
                    if (dat.statuss)
                    {
                        datumi.push_back(dat);
                    }
                    in.read((char*)&dat, sizeof(datums));
                }
                in.close();
                remove(path.c_str());
                ofstream out(path, ios::binary);
                for (auto it = datumi.begin(); it != datumi.end(); ++it)
                {
                    out.write((char*)&*it, sizeof(datums));
                }
                out.close();
            }
        }
        else if (mode == 3)
        {
            cout << "Enter file path: ";
            string path;
            cin >> path;
            remove(path.c_str());
        }
        cout << "Continue? no (0), yes (1): ";
        cin >> continue_;
    }
}

/*************************************
        TESTA PLĀNS

        Goal                Result


druká datus                  +
pievieno datus beigás        +
neatkārto datus              +
izmet loģiski                +

*************************************/