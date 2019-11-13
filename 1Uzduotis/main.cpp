#include <iostream>
#include <fstream>

using namespace std;
ifstream in ("duom1.txt");
ofstream out ("rez1.txt");

int nuskaitytiDuomenis();
int rastiSunkiausia();
int rastiDvigubaiLengvesnius(int sunkiausias);
void isvestiDuomenis(int sunkiausias, int dvigubaiLengvesni);

int main()
{
    int sunkiausias = rastiSunkiausia();
    int dvigubaiLengvesni = rastiDvigubaiLengvesnius(sunkiausias);
    isvestiDuomenis(sunkiausias, dvigubaiLengvesni);

    in.close();
    out.close();

    return 0;
}

int nuskaitytiDuomenis()
{
    int element;
    in >> element;

    return element;
}

int rastiSunkiausia()
{
    int sunkiausias = nuskaitytiDuomenis();

    while(!in.eof()) {
        int temp = nuskaitytiDuomenis();
        if(temp > sunkiausias){
            sunkiausias = temp;
        }
    }
    in.seekg(0);

    return sunkiausias;
}

int rastiDvigubaiLengvesnius(int sunkiausias)
{
    int dvigubaiLengvesni = 0;

    while(!in.eof()) {
        int current = nuskaitytiDuomenis();
        if (current <= sunkiausias * .5){
            dvigubaiLengvesni++;
        }
    }

    return dvigubaiLengvesni;
}

void isvestiDuomenis(int sunkiausias, int dvigubaiLengvesni)
{
    out << sunkiausias << " " << dvigubaiLengvesni;
}