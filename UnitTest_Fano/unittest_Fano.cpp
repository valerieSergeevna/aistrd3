#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sh_Fano/Shen_Fano.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Fano
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(encode_test_translit)
		{
			string stri = "bit' ili ne bit'";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "1010010011000100110100011110111101101001001100";
			Assert::AreEqual(check, str.get_code_fano());
		}

		TEST_METHOD(encode_test_eng)
		{
			string stri = "be or not to be";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "1101010001111000111101100001000100110101";
			Assert::AreEqual(check, str.get_code_fano());
		}

		TEST_METHOD(encode_test_numb)
		{
			
			string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "00011";
			Assert::AreEqual(check, str.get_code_fano());
		}


		TEST_METHOD(decode_test_translit)
		{
			string stri = "bit' ili ne bit'";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_fano());
		}

		TEST_METHOD(decode_test_eng)
		{
			string stri = "be or not to be";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_fano());
		}

		TEST_METHOD(decode_test_numb)
		{

			string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_fano());
		}

		TEST_METHOD(encode_test_translit_codes)
		{
			string stri = "bit' ili ne bit'";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check[8] = {"00", "01", "100","101","1100","1101","1110","1111"};
			for (size_t i = 0; i < 8; i++) {
				Assert::AreEqual(check[i], str.get_codes_fano_list(i));
			}
		}

		TEST_METHOD(encode_test_eng_codes)
		{
			string stri = "be or not to be";
			//string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check[7] = { "00", "01", "100","101","110","1110","1111" };
			for (size_t i = 0; i < 7; i++) {
				Assert::AreEqual(check[i], str.get_codes_fano_list(i));
			}
		}

		TEST_METHOD(encode_test_numb_codes)
		{

			string stri = "123";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check[3] = { "00", "01", "1" };
			for (size_t i = 0; i < 3; i++) {
				Assert::AreEqual(check[i], str.get_codes_fano_list(i));
			}
		}

	};
}