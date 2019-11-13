#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

ifstream in ("U1.txt");
ofstream out ("U1rez.txt");

void readRGB(int &r, int &g, int &b);
string covnertToHexadecimal(int decimal);
string getColorHex(int r, int g, int b);
void writeResult(int pictureHeight, int pictureWidth);

int main()
{
    int pictureHeight,
        pictureWidth;

    in >> pictureHeight;
    in >> pictureWidth;    

    writeResult(pictureHeight, pictureWidth);

    in.close();
    out.close();

    return 0;
}

void readRGB(int &r, int &g, int &b)
{
    in >> r >> g >> b;
}

string covnertToHexadecimal(int decimal)
{
    int firstPos = decimal / 16,
        secondPos = decimal % 16,
        hexCount = 2,
        pos[hexCount] = { firstPos, secondPos };

    string  hexSymbols = "";

    for (int i = 0; i < hexCount; i++)
    {
        switch (pos[i])
        {
        case 10:
           hexSymbols = "A";
            break;
        case 11:
            hexSymbols = "B";
            break;
        case 12:
            hexSymbols = "C";
            break;
        case 13:
            hexSymbols = "D";
            break;
        case 14:
            hexSymbols = "E";
            break;
        case 15:
            hexSymbols = "F";
            break;
        default:
            ostringstream convert;
            convert << firstPos;
            hexSymbols = convert.str();
            break;
        }

        hexSymbols += hexSymbols;
    }

    return hexSymbols;
}

string getColorHex(int r, int g, int b)
{
    string colorHex = "";
    int rgb[3] = { r, g, b };

    for (int i = 0; i < 3; i++)
    {
        colorHex += covnertToHexadecimal(rgb[i]);
    }
    

    return colorHex;
}

void writeResult(int pictureHeight, int pictureWidth)
{
    int r, g, b;
    string colorHex;

    for (int i = 0; i < pictureHeight; i++)
    {
        for (int i = 0; i < pictureWidth; i++)
        {
            readRGB(r, g, b);
            colorHex = getColorHex(r, g, b);
            out << colorHex;
            if (i != pictureWidth - 1) {
                out << ';';
            }           
        }
        out << '\n';   
    }
}