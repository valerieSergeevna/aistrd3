#include "Shen_Fano.h"
#include <iostream>
#include <conio.h>

using namespace std;
void main() 
{
	string stri = "be or not to be";
	//string stri = "123";
	Shen_Fano_code str(stri);
	str.encode(stri);
	str.decode();
	str.get_table();
	_getch();
}