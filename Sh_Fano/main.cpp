#include "Shen_Fano.h"
#include <iostream>
#include <conio.h>

using namespace std;
void main() 
{
	string stri = "123456789";
	Shen_Fano_code str(stri);
	str.encode();
	str.get_table();
	_getch();
}