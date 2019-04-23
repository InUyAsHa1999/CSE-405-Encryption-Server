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
	system("CLS");
	// If Linux
	//system("clear");
}
string Create_Random_Number_String()
{
	srand(time(NULL));
	string Random_Name;
	for (int i = 0; i < 10; ++i)
	{
		Random_Name = Random_Name + to_string(rand() % 10);
	}
	return Random_Name;
}
vector<string> Get_Config_Information()
{
	string Really_Temp;
	string Line;
	vector<string> Hold_Cfg;
	std::ifstream Conf_File;
	Conf_File.open("XxPre_SetxX.cfg");
	while (getline(Conf_File, Line)) {
		Really_Temp = Line;
		Hold_Cfg.push_back(Really_Temp);
		Really_Temp.clear();
	}
	return Hold_Cfg;
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
void Print_Vector(vector<int> &x)
{
	Clear_Screen();
	for (int i = 0; i < x.size(); ++i)
	{
		std::cout << x[i] << std::endl;
	}
	int i;
	cin >> i;
	Clear_Screen();
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
int Conversion_Table(char i)
{
	std::map<char, int> Conversion;
	Conversion['A'] = 0; Conversion['a'] = 1; Conversion['B'] = 2; Conversion['b'] = 3; Conversion['C'] = 4; Conversion['c'] = 5;
	Conversion['D'] = 6; Conversion['d'] = 7; Conversion['E'] = 8; Conversion['e'] = 9; Conversion['F'] = 10; Conversion['f'] = 11;
	Conversion['G'] = 12; Conversion['g'] = 13; Conversion['H'] = 14; Conversion['h'] = 15; Conversion['I'] = 16; Conversion['i'] = 17;
	Conversion['J'] = 18; Conversion['j'] = 19; Conversion['K'] = 20; Conversion['k'] = 21; Conversion['L'] = 22; Conversion['l'] = 23;
	Conversion['M'] = 24; Conversion['m'] = 25; Conversion['N'] = 26; Conversion['n'] = 27; Conversion['O'] = 28; Conversion['o'] = 29;
	Conversion['P'] = 30; Conversion['p'] = 31; Conversion['Q'] = 32; Conversion['q'] = 33; Conversion['R'] = 34; Conversion['r'] = 35;
	Conversion['S'] = 36; Conversion['s'] = 37; Conversion['T'] = 38; Conversion['t'] = 39; Conversion['U'] = 40; Conversion['u'] = 41;
	Conversion['V'] = 42; Conversion['v'] = 43; Conversion['W'] = 44; Conversion['w'] = 45; Conversion['X'] = 46; Conversion['x'] = 47;
	Conversion['Y'] = 48; Conversion['y'] = 49; Conversion['Z'] = 50; Conversion['z'] = 51;

	return Conversion.at(i);
}
std::string Vetor_Seed_2_String(vector<string> &x)
{
	std::string carry;
	for (int i = 0; i < x.size(); ++i)
	{
		carry = carry + x[i];
	}
	return carry;
}
int main()
{
	
	std::fstream New_File;
	std::vector<string> V_CFV;
	std::vector<string> Vector_Seed;
	std::vector<int> True_Seed;
	string Security_Level;
	int shifting = 0;
	int spacing = 0;
	bool Is_Random = true;
	V_CFV = Get_Config_Information();
	Security_Level = (V_CFV[1]);
	//Print_Vector(V_CFV);
	Vector_Seed = String_2_Vector(V_CFV[0]);
	//Print_Vector(Vector_Seed);
	Security_Level = V_CFV[1];
	True_Seed = Set_True_Seed(Vector_Seed);
	//Print_Vector(True_Seed);
	ifstream Old_File;
	Old_File.open("Working_With.txt");
	string File_Name = "ECR.vvn";
	ofstream file{ File_Name };
	New_File.open(File_Name);
	if (!Old_File.is_open())
	{
		cout << "Fuck!" << std::endl;
	}
	New_File << Vetor_Seed_2_String(Vector_Seed);
	New_File << endl;
	char char_data_hold;
	
	
	
	 while (Old_File.get(char_data_hold))
	{
		 
		if (char_data_hold >= 'a' && char_data_hold <= 'z' || char_data_hold >= 'A' && char_data_hold <= 'Z')
		{
			char b = '\0';
			New_File << b;
			New_File << Conversion_Table(char_data_hold) + True_Seed[1];
			New_File << b;
			cout << char_data_hold;
			
		}
		else
		    if (char_data_hold == ' ')
		    {
			New_File << " ";
			cout << " ";
		    }
		    else
		       if (char_data_hold == '\n')
		       {
			New_File << endl;
			cout << endl;
		       }
			else
			{
				New_File << char_data_hold;
				cout << char_data_hold;
			}
		
		
	}
	 New_File.close();

}
