#pragma once

#include "List.cpp"
#include "map.cpp"
#include <iostream>

using namespace std;
class Shen_Fano_code
{
private:
	string  code, decode_;
	List <char> sort;
	map < char> Map;

public:
	Shen_Fano_code(string&);
	~Shen_Fano_code() {};
	void encode(string &str);
	void decode();
	void get_table();
	bool code_compare_for_test(string check_array, string code);
	string get_code_fano() { return code; }
	string get_codes_fano_list(size_t index) { return sort.get_code_list(index); }
	string get_decode_fano() { return decode_; }

};