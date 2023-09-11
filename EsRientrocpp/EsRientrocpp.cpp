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

string Record(string div[], string sp, int l, string random, int llinea)
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
    r.c = "1";
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
        getline(file, m, ']');
        cout << m << endl;
    }
    cout << endl;
    file.close();
}

void Ricopia(string file1, string file2)
{
    string m;
    ifstream file(file1);
    ofstream app(file2);
    while (getline(file, m))
    {
        app << m << endl;
    }
    file.close();
    app.close();
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
    int r = 0;
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
        div[1] = m.substr(pos[0] + 1, pos[1] - pos[0]);
        div[2] = m.substr(pos[1] + 1, pos[2] - pos[1]);
        div[3] = m.substr(pos[2] + 1, pos[3] - pos[2]);
        div[4] = m.substr(pos[3] + 1, pos[4] - pos[3]);
        div[5] = m.substr(pos[4] + 1, pos[5] - pos[4]);
        div[6] = m.substr(pos[5] + 1, pos[6] - pos[5]);
        div[7] = m.substr(pos[6] + 1, pos[7] - pos[6]);
        div[8] = m.substr(pos[7] + 1, pos[8] - pos[7]);
        div[9] = m.substr(pos[8] + 1, pos[9] - pos[8]);
        div[10] = m.substr(pos[9] + 1, pos[10] - pos[9]);
        div[11] = m.substr(pos[10] + 1, pos[11] - pos[10]);
        div[12] = m.substr(pos[11] + 1, pos[12] - pos[11]);
        div[13] = m.substr(pos[12] + 1, pos[13] - pos[12]);
        div[14] = m.substr(pos[13] + 1, pos[14] - pos[13]);
        div[15] = m.substr(pos[14] + 1, pos[15] - pos[14]);
        div[16] = m.substr(pos[15] + 1, pos[16] - pos[15]);
        div[17] = m.substr(pos[16] + 1, pos[17] - pos[16]);
        div[18] = m.substr(pos[17] + 1, pos[18] - pos[17]);
        app << Record(div, ";", 300, random, m.length());
        r++;
    }
    file.close();
    app.close();
}

int main()
{
    aggiusta();
    return 0;
}