#pragma once
#include <iostream>
#include <List.cpp>
#include <map.cpp>

using namespace std;
class Shen_Fano_code
{
private:
	//string  str;
	List <char> sort;
	void make_group();
public:
	Shen_Fano_code(string&);
	~Shen_Fano_code() {};
	void encode();
	void decode();
	void get_table();
	


};