#include <iostream>
#include <string>
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

string Record(string div[], string sp, int l, string random)
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
    return (r.comune + sp + r.prov + sp + r.reg + sp + r.tip + sp + r.stelle + sp + r.den + sp + r.ind + sp + r.cap + sp + r.local + sp + r.fraz + sp + r.tel + sp + r.fax + sp + r.posel + sp + r.web + sp + r.ces + sp + r.cam + sp + r.pls + sp + r.pla + sp + random + sp + r.c + ']'), setw(l), "##\r\n";

}

public bool ContrAgg()
{
    int a;
    bool b = false;
    var file = new FileStream("belotti.csv", FileMode.Open, FileAccess.ReadWrite, FileShare.Read);
    BinaryReader rd = new BinaryReader(file);
    file.Seek(301, SeekOrigin.Begin);
    a = rd.Read();
    if (a == 35)
    {
        b = true;
    }
    rd.Close();
    file.Close();
    return b;
}

int main()
{
    
}

