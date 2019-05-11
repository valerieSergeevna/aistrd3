#include "Shen_Fano.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

Shen_Fano_code::Shen_Fano_code(string &str)
{
	//map < char> Map;
	if (str.empty()) throw out_of_range("string is empty");
	size_t i = 0;
	while (i != str.length())
	{
		Map.insert(str[i]);
		i++;
	}
	sort = Map.get_keys();
	sort.sorting(sort.get_front(), sort.get_back());
	sort.make_group(sort.get_front(), sort.get_back());
	for (int j = 0; j < sort.get_size(); j++)
		Map.set_code(sort.get_code_list(j), sort.get_data_list(j));
}

int Shen_Fano_code::encode(string &str)
{
	
	size_t i = 0;
	while ( i != str.length())
	{
		code = code + Map.get_code(str[i]);
		i++;
	}
	std::cout << code << " memmory: " << size(code) <<'\n' ;
	return (size(code));
}

void Shen_Fano_code::decode()
{


	//for (int i = 0; i < sort.get_size(); i++)
	//{
	while (code.length() != 0)
	{
		for (int j = 0; j < sort.get_size(); j++)
		{
			int size = 0;
			if (sort.compare_str(code, sort.get_code_list(j), size))
			{
				std::cout << sort.get_data_list(j);
				decode_ += sort.get_data_list(j);
				code.erase(0, size);
			}
		}
	}
	//}
	std::cout << '\n' ;
}

void Shen_Fano_code::get_table()
{
	sort.print();
}

bool Shen_Fano_code::code_compare_for_test(string check_array, string code)
{
	if (code.length() != check_array.length()) return false;
	for (int i = 0; i < code.length(); i++)
	{
		if (check_array[i] != code[i])  return false;
	}
	return true;
}


