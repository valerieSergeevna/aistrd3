#include "Shen_Fano.h"
#include <iostream>
#include <conio.h>

using namespace std;
void main() 
{
	//string stri = "be or not to be";
	//string stri = "123";
	string stri = "qwqewqrwe";
	
	Shen_Fano_code str(stri);
	float size_code = str.encode(stri);
	str.decode();
	cout << "memmory " << size(stri)*8 << '\n';
	str.get_table();
	float k = size(stri) * 8 / size_code;
	cout << k;//coefficent
	_getch();
}