/*************************
FF12. Dots netukšs teksta fails.
Uzrakstīt programmu, kura failā izvada visus ieejas failā sastaptos skaitļus (par skaitli uzskatīt tikai tos vārdus,
kuri sastāv tikai no cipariem. Par vārdu uzskatīt patvaļīgu simbolu virkni,
kas atdalīta ar tukšumiem vai pieturas zīmēm
(punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).

Aleksejs Gerasimovs
ag21275
*******/



#include <iostream>
#include <fstream>

using namespace std;

bool isNumber (string word)              //Cheking is it a word or number
{
    for(int i=1; i < (word.size()); i++)
    {
        if (!(isdigit(word[i])))
        return false;
    }
    return true;
}

int findWord (string row, int index)       //Find word length and place
{
    for (int i = index; i < row.length(); i++)
    {
        if (row[i] == ' ' || row[i] == '!' || row[i] == '?' || row[i] == '.' || row[i] == ',' || row[i] == '(' || row[i] == ')')
        {
            return i;       
        }
    }
    return row.length();  
}
void searchWords (ifstream &fin, ofstream &fout)
{
    string row;
    string word="";
    char sym_before = ' ';             
    int j = 0;
    while(getline(fin,row))             
    {
        for (int i = 0; i < row.size(); i++){        
            if (row[i] <= '9' && row[i] >= '0' && (sym_before == ' ' || sym_before == '!' || sym_before == '?' || sym_before == '.' || sym_before == ',' || sym_before == '(' || sym_before == ')')) //Ja simbols ir skaitlis un ieprekšējais ir viena no rakstzīmēm
            {
                j = findWord(row, i);       
                word = row.substr(i, j - i);   
                if (isNumber(word))              
                {
                    fout << word << endl;
                }
            }
            sym_before = row[i];            
        }
        sym_before = ' ';          
    }
}

int main()                                                      //Realization
{
    ifstream fin ("FailsIn.txt");
    ofstream fout ("FailsOut.txt");
    if (fin.is_open()){                                      
                                                                
		searchWords(fin, fout);                             
	}
	else{
	    
		cout << "File not opened or doesn't exist!" << endl;
	}
    fin.close ();
    fout.close ();
    fin.open("FailsOut.txt", ios::in);
    cout << "Tiek atrasti tādi skaitļi:" << endl;
    string str;
    while(getline(fin,str)){                                    
        cout << str << endl;
    }
}

/********************************************
                    Test

Input data             Predicrion          Result

asasw asdawdsdaw 123!       123              +
!14312z 33.                  33              +
45                          45               +
123... 57! a3.              123 57           +
/./23                                        +
<|\]]123>                                    +
!!!678637868sdf.                             +
333# 567!? 1                567  1           +
********************************************/