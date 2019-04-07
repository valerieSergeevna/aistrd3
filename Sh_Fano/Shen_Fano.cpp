#include "Shen_Fano.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

Shen_Fano_code::Shen_Fano_code(string &str)
{
	map < char, size_t> Map;

	size_t i = 0;
	while (i != str.length())
	{
		Map.insert(str[i]);
		i++;
	}
	sort = Map.get_keys();
	sort.sorting(sort.get_front(), sort.get_back());
}

void Shen_Fano_code::encode()
{
	
}


