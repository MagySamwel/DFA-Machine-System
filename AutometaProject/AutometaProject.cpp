#include <bits/stdc++.h>
using namespace std;

class DFA_DATA
{
public:
    int numOfStates;
    vector<string>States;
    int numOfSymbols;
    vector<char>Symbols;
    map<pair<string, char>, string>Transitions;
    string curState, s;
    int numOfAccStates;
    map<string, bool>AccStates;
    void Nodes();
    void Alphabets();
    void Transitions_Table();
    void Initial_State();
    void Final_States();
    bool isAccept(string s);
};

int main() 
{
    DFA_DATA machine = DFA_DATA();
    machine.Nodes();
    cout << "Please Enter Your String To Check If Accepted Or Not\n";
    string s;
    cin >> s;
    (machine.isAccept(s)) ? cout << "Accepted\n" : cout << "Rejected\n";
}

void DFA_DATA::Nodes()
{
    cout << "Please Enter The Number Of States In Your DFA Machine : \n";
    cin >> numOfStates;
    cout << "\nPlease Enter The States Of Your DFA Machine : \n";
    for (int i = 0; i < numOfStates; i++)
    {
        string state;
        cin >> state;
        States.push_back(state);
    }
    Alphabets();
}

void DFA_DATA::Alphabets()
{

    cout << "\nPlease Enter The Number Of Alphabets (Symbols) In Your DFA Machine : \n";
    cin >> numOfSymbols;
    cout << "\nPlease Enter The Alphabets (Symbols) Of Your DFA Machine : \n";
    for (int i = 0; i < numOfSymbols; i++)
    {
        char symbol;
        cin >> symbol;
        Symbols.push_back(symbol);
    }
    Transitions_Table();
}

void DFA_DATA::Transitions_Table()
{
    cout << "\nPlease Enter The Transitions To Build The Table : \n";
    for (int i = 0; i < numOfStates; i++)
    {
        cout << "For " << States[i] << " :\n";
        for (int j = 0; j < numOfSymbols; j++)
        {
            cout << "\tArrow With Character " << Symbols[j] << " Goes To State ";
            string nextState;
            cin >> nextState;
            Transitions[{States[i], Symbols[j]}] = nextState;
            cout << "\n";
        }
    }
    Initial_State();
}

void DFA_DATA::Initial_State()
{
    cout << "\nPlease Enter The Start State In Your DFA Machine : \n";
    string startState;
    cin >> startState;
    curState = startState;
    Final_States();
}

void DFA_DATA::Final_States()
{
    cout << "\nPlease Enter The Number Of Accept States In Your DFA Machine : \n";
    cin >> numOfAccStates;
    cout << "\nPlease Enter The Accept States Of Your DFA Machine : \n";
    for (int i = 0; i < numOfAccStates; i++)
    {
        string AcceptState;
        cin >> AcceptState;
        AccStates[AcceptState] = 1;
    }
}

bool DFA_DATA::isAccept(string s)
{
    bool check = 0;
    for (int i = 0; i < s.size(); i++)
    {
        check = AccStates[Transitions[{curState, s[i]}]];
        curState = Transitions[{curState, s[i]}];
    }
    return check;
}