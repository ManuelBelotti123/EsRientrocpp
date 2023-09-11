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
    char* a = new char[1];
    bool b = false;
    ifstream file("belotti.csv");
    file.seekg(301);
    file.read(a, 1);
    if (a[0] == '#')
    {
        b = true;
    }
    file.close();
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
    lung = lung + 17;
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
            div[campo] = modifica;
        }
        app << Record(div, ";", 300, div[18], m.length(), true);
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
    Ricompatta();
    
    return 0;
}