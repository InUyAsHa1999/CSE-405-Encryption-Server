#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <random>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;
void Clear_Screen()
{
	// If Windows
	//system("CLS");
	// If Linux
	//system("clear");
}
char Conversion_Table(int i)
{
	std::map<int, char> Conversion;
	Conversion[0] = 'A'; Conversion[1] = 'a'; Conversion[2] = 'B'; Conversion[3] = 'b'; Conversion[4] = 'C'; Conversion[5] = 'c';
	Conversion[6] = 'D'; Conversion[7] = 'd'; Conversion[8] = 'E'; Conversion[9] = 'e'; Conversion[10] = 'F'; Conversion[11] = 'f';
	Conversion[12] = 'G'; Conversion[13] = 'g'; Conversion[14] = 'H'; Conversion[15] = 'h'; Conversion[16] = 'I'; Conversion[17] = 'i';
	Conversion[18] = 'J'; Conversion[19] = 'j'; Conversion[20] = 'K'; Conversion[21] = 'k'; Conversion[22] = 'L'; Conversion[23] = 'l';
	Conversion[24] = 'M'; Conversion[25] = 'm'; Conversion[26] = 'N'; Conversion[27] = 'n'; Conversion[28] = 'O'; Conversion[29] = 'o';
	Conversion[30] = 'P'; Conversion[31] = 'p'; Conversion[32] = 'Q'; Conversion[33] = 'q'; Conversion[34] = 'R'; Conversion[35] = 'r';
	Conversion[36] = 'S'; Conversion[37] = 's'; Conversion[38] = 'T'; Conversion[39] = 't'; Conversion[40] = 'U'; Conversion[41] = 'u';
	Conversion[42] = 'V'; Conversion[43] = 'v'; Conversion[44] = 'W'; Conversion[45] = 'w'; Conversion[46] = 'X'; Conversion[47] = 'x';
	Conversion[48] = 'Y'; Conversion[49] = 'y'; Conversion[50] = 'Z'; Conversion[51] = 'z';

	return Conversion.at(i);
}
vector<int> Set_True_Seed(vector<std::string> &x)
{
	vector<int> True_Seed;
	for (int i = 0; i < x.size(); ++i)
	{
		True_Seed.push_back(stoi(x[i]));
	}
	int Spacing = (True_Seed[0] + True_Seed[1] * True_Seed[2] / True_Seed[3] * True_Seed[4]) % 100;
	int Shifting = (True_Seed[5] + True_Seed[6] * True_Seed[7] * True_Seed[8] + True_Seed[9]) % 1000;
	vector<int> Carry;
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0) { Carry.push_back(Spacing); }
		if (i == 1) { Carry.push_back(Shifting); }
	}
	return Carry;
}
vector<string> String_2_Vector(string &x)
{
	string Temp = x;
	vector<string> y;
	for (int i = 0; i < Temp.size(); ++i)
	{
		string x2;
		x2 = Temp[i];
		y.push_back(x2);
	}
	return y;
}
void Print_Vector(vector<string> &x)
{
	Clear_Screen();
	for (int i = 0; i < x.size(); ++i)
	{
		std::cout << x[i] << std::endl;
	}
	std::string i;
	cin >> i;
	Clear_Screen();
}


int main()
{
	fstream Extract_Seed;
	fstream Read_Encripted_File;
	fstream Write_Translated_File;
	std::ofstream XML{ "Translated.txt" };
	Extract_Seed.open("ECR.vvn");
	Write_Translated_File.open("Translated.txt");
	string seed;
	getline(Extract_Seed, seed);
	Extract_Seed.close();
	vector<string> Vector_Seed = String_2_Vector(seed);
	vector<int> True_Seed = Set_True_Seed(Vector_Seed);
	char Temp;
	string Number_Check;
	int Real_Value;
	string junk;
	Read_Encripted_File.open("ECR.vvn");
	getline(Read_Encripted_File, junk);
	while (Read_Encripted_File.good())
	{
		Read_Encripted_File.get(Temp);
		if (Temp == '\0')
		{
			Read_Encripted_File.get(Temp);
				while (Temp != '\0')
				{
					Number_Check = Number_Check + Temp;
					Read_Encripted_File.get(Temp);
				}
				Real_Value = stoi(Number_Check);
				Write_Translated_File << Conversion_Table(Real_Value - True_Seed[1]);
				Number_Check.clear();
		}
		else
			if (Temp == ' ')
			{
				Write_Translated_File << " ";
			}
			else
				if (Temp == '\n')
				{
					Write_Translated_File << "\n";

				}
				else
				{
					Write_Translated_File << Temp;
				}
		
	}
	Write_Translated_File.close();
	

}
