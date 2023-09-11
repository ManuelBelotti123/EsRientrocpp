#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

struct str {
    string comune;
    string prov;
    string reg;
    string tip;
    string stelle;
    string den;
    string ind;
    string cap;
    string local;
    string fraz;
    string tel;
    string fax;
    string posel;
    string web;
    string ces;
    string cam;
    string pls;
    string pla;
    string mval;
    string c;
};

string Record(string div[], string sp, int l, string random, int llinea, bool c)
{
    str r;
    r.comune = div[0];
    r.prov = div[1];
    r.reg = div[2];
    r.tip = div[3];
    r.stelle = div[4];
    r.den = div[5];
    r.ind = div[6];
    r.cap = div[7];
    r.local = div[8];
    r.fraz = div[9];
    r.tel = div[10];
    r.fax = div[11];
    r.posel = div[12];
    r.web = div[13];
    r.ces = div[14];
    r.cam = div[15];
    r.pls = div[16];
    r.pla = div[17];
    if (c) 
    {
        r.c = "1";
    }
    else 
    {
        r.c = "0";
    }
    //stabiliamo una lunghezza fissa per ogni record
    ostringstream rec;
    rec << r.comune << sp << r.prov << sp << r.reg << sp << r.tip << sp << r.stelle << sp << r.den << sp << r.ind << sp << r.cap << sp << r.local << sp << r.fraz << sp << r.tel << sp << r.fax << sp << r.posel << sp << r.web << sp << r.ces << sp << r.cam << sp << r.pls << sp << r.pla << sp << random << sp << r.c << ']' << setw(l - llinea) << "##\r\n";
    return rec.str();
}

void Visualizza(string nomefile)
{
    string m;
    ifstream file(nomefile);
    while (getline(file, m))
    {
        stringstream stream(m);
        getline(stream, m, '\n');
        cout << m << endl;
    }
    cout << endl;
    file.close();
}

void Ricopia(string lettura, string scrittura)
{
    string m;
    ifstream fin(lettura);
    ofstream fout(scrittura);
    while (getline(fin, m))
    {
        stringstream stream(m);
        getline(stream, m, '\n');
        fout << m << endl;
    }
    fin.close();
}

bool ContrAgg()
{
    int j = 0;
    bool b = false;
    string m;
    ifstream fin("belotti.csv");
    getline(fin, m);
    stringstream stream(m);
    getline(stream, m, '\n');
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == ';')
        {
            j++;
        }
    }
    if (j > 17) 
    {
        b = true;
    }
    fin.close();
    return b;
}

void aggiusta()
{
    string m;
    ifstream file("belotti.csv");
    ofstream app("app.csv");
    while (getline(file, m))
    {
        string random = to_string(rand() % 11 + 10);
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, '\n');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        app << Record(div, ";", 300, random, m.length(), true);
    }
    file.close();
    app.close();
}

int ContaCampi()
{
    ifstream file("belotti.csv");
    string m;
    int j = 0;
    getline(file, m);
    stringstream stream(m);
    getline(stream, m, '\n');
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == ';')
        {
            j++;
        }
    }
    file.close();
    return j + 1;
}

int LungMaxRec() 
{
    string m;
    ifstream file("belotti.csv");
    int max = 0;
    while (getline(file, m))
    {
        string random = to_string(rand() % 11 + 10);
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        if (m.length() > max) 
        {
            max = m.length();
        }
    }
    file.close();
    return max + 1;
}

void AggRec(string div[])
{
    int lung = 0;
    string rn = to_string(rand() % 11 + 10);
    ofstream file("belotti.csv", ios::app);
    for (int i = 0; i < 18; i++) 
    {
        lung = lung + div[i].length();
    }
    lung = lung + 22;
    file << Record(div, ";", 300, rn, lung, true);
    file.close();
}

string* EstrapolaCampi(int a, int b, int c) 
{
    string m;
    string* arr = new string[1000000];
    string* div;
    int g = 0;
    ifstream file("belotti.csv");
    while (getline(file, m))
    {
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        arr[g] = div[a] + ';' + div[b] + ';' + div[c];
        cout << arr[g] << endl;
        g++;
    }
    return arr;
}

string* Ricerca(int campo, string ricerca)
{
    string m;
    string* arr = new string[1000000];
    string* div;
    int g = 0;
    ifstream file("belotti.csv");
    while (getline(file, m))
    {
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        if (div[campo] == ricerca)
        {
            arr[g] = m;
            g++;
        }
    }
    return arr;
}

void ModificaCampo(int campo, string ricerca, string modifica)
{
    string m;
    string* arr = new string[1000000];
    string* div;
    int g = 0, lung = 0;
    ifstream file("belotti.csv");
    ofstream app("app.csv");
    while (getline(file, m))
    {
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        if (div[campo] == ricerca)
        {
            div[campo] = modifica;
            lung = modifica.length() - div[campo].length();
            app << Record(div, ";", 300, div[18], m.length() + lung, true);
        }
        else 
        {
            app << Record(div, ";", 300, div[18], m.length(), true);
        }
    }
}

void CancRecLogica(int campo, string ricerca, bool cor)
{
    string m;
    string* arr = new string[1000000];
    string* div;
    int g = 0;
    ifstream file("belotti.csv");
    ofstream app("app.csv");
    while (getline(file, m))
    {
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        if (div[campo] == ricerca) 
        {
            if (cor)
            {
                app << Record(div, ";", 300, div[18], m.length(), true);
            }
            else
            {
                app << Record(div, ";", 300, div[18], m.length(), false);
            }
        }
        else 
        {
            app << Record(div, ";", 300, div[18], m.length(), true);
        }
    }
}

void Ricompatta()
{
    string m;
    string* arr = new string[1000000];
    string* div;
    int g = 0;
    ifstream file("belotti.csv");
    ofstream app("app.csv");
    while (getline(file, m))
    {
        int pos[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        string div[] = { "","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int j = 0;
        stringstream stream(m);
        getline(stream, m, ']');
        for (int i = 0; i < m.length(); i++)
        {
            if (m[i] == ';')
            {
                pos[j] = i;
                j++;
            }
        }
        int k = 0;
        int f = 1;
        div[0] = m.substr(0, pos[0]);
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0] - 1);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1] - 1);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3] - 1);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4] - 1);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5] - 1);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6] - 1);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7] - 1);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8] - 1);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9] - 1);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10] - 1);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11] - 1);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12] - 1);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13] - 1);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14] - 1);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15] - 1);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16] - 1);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17] - 1);
        div[19] = m.substr(pos[18] + 1, pos[19] - pos[18] - 1);
        if (div[19] != "0")
        {
            app << Record(div, ";", 300, div[18], m.length(), true);
        }
    }
}

int main()
{
    //dichiarazioni
    int scelta = 0, j = 0, campo;
    string* div;
    string* arr;
    string* ric;
    int* cvis;
    bool cor;
    string cli = "", ricerca, modifica;
    //menu a scelta
    do
    {
        system("CLS");
        //opzioni
        cout << "GESTIONE FILE CSV" << endl;
        cout << "1. Aggiusta il formato del file" << endl;
        cout << "2. Conta il numero dei campi del file" << endl;
        cout << "3. Lunghezza Massima tra i Record" << endl;
        cout << "4. Aggiunta di un record in coda" << endl;
        cout << "5. Visualizza tre campi a scelta" << endl;
        cout << "6. Ricerca in un campo" << endl;
        cout << "7. Modifica di un record" << endl;
        cout << "8. Cancellazione logica di un record" << endl;
        cout << "9. Recupero di un record" << endl;
        cout << "10. Ricompatta il file" << endl;
        cout << "11. Visualizza l'intero file" << endl;
        cout << "0. Esci dal programma" << endl;
        cin >> scelta;
        //scelta
        switch (scelta)
        {
            case 1:
                if (ContrAgg() == false)
                {
                    aggiusta();
                    Ricopia("app.csv", "belotti.csv");
                    cout << "File aggiustato correttamente" << endl;
                    cout << "Clicca un tasto per continuare..." << endl;
                    cin >> cli;
                }
                else
                {
                    cout << "Operazione già effettuata" << endl;
                    cout << "Clicca un tasto per continuare..." << endl;
                    cin >> cli;
                }
                break;
            case 2:
                cout << "I campi di questo file sono " << ContaCampi() << "." << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 3:
                cout << "La lunghezza massima dei record presenti è " << LungMaxRec() << " caratteri." << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 4:
                div = new string[18];
                cout << "Inserisci i campi del nuovo record che vuoi inserire:" << endl;
                getline(cin, div[0]);
                cout << "Comune:" << endl;
                getline(cin, div[0]);
                cout << "Provincia:" << endl;
                getline(cin, div[1]);
                cout << "Regione:" << endl;
                getline(cin, div[2]);
                cout << "Tipologia:" << endl;
                getline(cin, div[3]);
                cout << "Categoria(Stelle):" << endl;
                getline(cin, div[4]);
                cout << "Denominazione:" << endl;
                getline(cin, div[5]);
                cout << "Indirizzo:" << endl;
                getline(cin, div[6]);
                cout << "CAP:" << endl;
                getline(cin, div[7]);
                cout << "Località:" << endl;
                getline(cin, div[8]);
                cout << "Frazione:" << endl;
                getline(cin, div[9]);
                cout << "Telefono:" << endl;
                getline(cin, div[10]);
                cout << "FAX:" << endl;
                getline(cin, div[11]);
                cout << "Indirizzo Posta Elettronica:" << endl;
                getline(cin, div[12]);
                cout << "Sito Internet:" << endl;
                getline(cin, div[13]);
                cout << "Codice esercizio:" << endl;
                getline(cin, div[14]);
                cout << "Camere:" << endl;
                getline(cin, div[15]);
                cout << "Posti letto standard:" << endl;
                getline(cin, div[16]);
                cout << "Posti letto aggiuntivi:" << endl;
                getline(cin, div[17]);
                AggRec(div);
                cout << "Record aggiunto correttamente" << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 5:
                cvis = new int[3];
                cout << "Digita il numero corrispondente ai campi che vuoi visualizzare:" << endl;
                cout << "0. Comune" << endl;
                cout << "1. Provincia" << endl;
                cout << "2. Regione" << endl;
                cout << "3. Tipologia" << endl;
                cout << "4. Categoria(Stelle)" << endl;
                cout << "5. Denominazione" << endl;
                cout << "6. Indirizzo" << endl;
                cout << "7. CAP" << endl;
                cout << "8. Località" << endl;
                cout << "9. Frazione" << endl;
                cout << "10. Telefono" << endl;
                cout << "11. FAX" << endl;
                cout << "12. Indirizzo Posta Elettronica" << endl;
                cout << "13. Sito Internet" << endl;
                cout << "14. Codice esercizio" << endl;
                cout << "15. Camere" << endl;
                cout << "16. Posti letto standard" << endl;
                cout << "17. Posti letto aggiuntivi" << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "Inserisci il numero:" << endl;
                    cin >> cvis[i];
                }
                arr = EstrapolaCampi(cvis[0], cvis[1], cvis[2]);
                j = 0;
                while (arr[j] != "")
                {
                    cout << arr[j] << endl;
                    j++;
                }
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 6:
                ricerca;
                getline(cin, ricerca);
                cout << "Inserisci il termine che vuoi ricercare:" << endl;
                getline(cin, ricerca);
                cout << "Digita il numero corrispondente al campo in cui vuoi ricercare:" << endl;
                cout << "0. Comune" << endl;
                cout << "1. Provincia" << endl;
                cout << "2. Regione" << endl;
                cout << "3. Tipologia" << endl;
                cout << "4. Categoria(Stelle)" << endl;
                cout << "5. Denominazione" << endl;
                cout << "6. Indirizzo" << endl;
                cout << "7. CAP" << endl;
                cout << "8. Località" << endl;
                cout << "9. Frazione" << endl;
                cout << "10. Telefono" << endl;
                cout << "11. FAX" << endl;
                cout << "12. Indirizzo Posta Elettronica" << endl;
                cout << "13. Sito Internet" << endl;
                cout << "14. Codice esercizio" << endl;
                cout << "15. Camere" << endl;
                cout << "16. Posti letto standard" << endl;
                cout << "17. Posti letto aggiuntivi" << endl;
                campo;
                cin >> campo;
                ric = Ricerca(campo, ricerca);
                j = 0;
                while (ric[j] != "")
                {
                    cout << ric[j] << endl;
                    j++;
                }
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 7:
                modifica;
                getline(cin, ricerca);
                cout << "Inserisci il termine che vuoi modificare:" << endl;
                getline(cin, ricerca);
                cout << "Inserisci la modifica da effettuare:" << endl;
                getline(cin, modifica);
                cout << "Digita il numero corrispondente al campo in cui vuoi ricercare:" << endl;
                cout << "0. Comune" << endl;
                cout << "1. Provincia" << endl;
                cout << "2. Regione" << endl;
                cout << "3. Tipologia" << endl;
                cout << "4. Categoria(Stelle)" << endl;
                cout << "5. Denominazione" << endl;
                cout << "6. Indirizzo" << endl;
                cout << "7. CAP" << endl;
                cout << "8. Località" << endl;
                cout << "9. Frazione" << endl;
                cout << "10. Telefono" << endl;
                cout << "11. FAX" << endl;
                cout << "12. Indirizzo Posta Elettronica" << endl;
                cout << "13. Sito Internet" << endl;
                cout << "14. Codice esercizio" << endl;
                cout << "15. Camere" << endl;
                cout << "16. Posti letto standard" << endl;
                cout << "17. Posti letto aggiuntivi" << endl;
                cin >> campo;
                ModificaCampo(campo, ricerca, modifica);
                Ricopia("app.csv", "belotti.csv");
                cout << "Operazione completata" << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 8:
                cor = false;
                getline(cin, ricerca);
                cout << "Inserisci il termine nel campo del record che vuoi cancellare:" << endl;
                getline(cin, ricerca);
                cout << "Digita il numero corrispondente al campo in cui vuoi ricercare:" << endl;
                cout << "0. Comune" << endl;
                cout << "1. Provincia" << endl;
                cout << "2. Regione" << endl;
                cout << "3. Tipologia" << endl;
                cout << "4. Categoria(Stelle)" << endl;
                cout << "5. Denominazione" << endl;
                cout << "6. Indirizzo" << endl;
                cout << "7. CAP" << endl;
                cout << "8. Località" << endl;
                cout << "9. Frazione" << endl;
                cout << "10. Telefono" << endl;
                cout << "11. FAX" << endl;
                cout << "12. Indirizzo Posta Elettronica" << endl;
                cout << "13. Sito Internet" << endl;
                cout << "14. Codice esercizio" << endl;
                cout << "15. Camere" << endl;
                cout << "16. Posti letto standard" << endl;
                cout << "17. Posti letto aggiuntivi" << endl;
                cin >> campo;
                CancRecLogica(campo, ricerca, cor);
                Ricopia("app.csv", "belotti.csv");
                cout << "Operazione completata" << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 9:
                cor = true;
                getline(cin, ricerca);
                cout << "Inserisci il termine nel campo del record che vuoi recuperare:" << endl;
                getline(cin, ricerca);
                cout << "Digita il numero corrispondente al campo in cui vuoi ricercare:" << endl;
                cout << "0. Comune" << endl;
                cout << "1. Provincia" << endl;
                cout << "2. Regione" << endl;
                cout << "3. Tipologia" << endl;
                cout << "4. Categoria(Stelle)" << endl;
                cout << "5. Denominazione" << endl;
                cout << "6. Indirizzo" << endl;
                cout << "7. CAP" << endl;
                cout << "8. Località" << endl;
                cout << "9. Frazione" << endl;
                cout << "10. Telefono" << endl;
                cout << "11. FAX" << endl;
                cout << "12. Indirizzo Posta Elettronica" << endl;
                cout << "13. Sito Internet" << endl;
                cout << "14. Codice esercizio" << endl;
                cout << "15. Camere" << endl;
                cout << "16. Posti letto standard" << endl;
                cout << "17. Posti letto aggiuntivi" << endl;
                cin >> campo;
                CancRecLogica(campo, ricerca, cor);
                Ricopia("app.csv", "belotti.csv");
                cout << "Operazione completata" << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 10:
                Ricompatta();
                Ricopia("app.csv", "belotti.csv");
                cout << "Ricompattamento del file completato" << endl;
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 11:
                Visualizza("belotti.csv");
                cout << "Clicca un tasto per continuare..." << endl;
                cin >> cli;
                break;
            case 0:
                break;
            default:
                break;
            }
    } while (scelta != 0);
    return 0;
}