#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <random>
#include <time.h>
#include <fstream>
using namespace std;
void Clear_Screen()
{
	// If Windows
	//system("CLS");
	// If Linux
	system("clear");
}
std::string Trunk_The_Key(string x)
{
	string y = "";
	for (int i = 0; i < 10; ++i)
	{
		y = y + x[i];
	}
	return y;
}
std::string Padding(string x)
{
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		
		
		x = x + to_string(rand() % 10);
		
	}
		
	
	return x;
}
void Send_To_File(string x, string y)
{
	std::ofstream file{ "XxPre_SetxX.cfg" };
	fstream Pre_Set;
	Pre_Set.open("XxPre_SetxX.cfg");
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0) { Pre_Set << x << std::endl; }
		if (i == 1) { Pre_Set << y << std::endl; }
	}
	Pre_Set.close();
}
std::string Set_To_Basic(string Level_Of_Security)
{
	string Hold_Option;
	while (Hold_Option != "2")
	{
		Clear_Screen();
		std::cout << "The Basic Level Of Security Will Set A Random Seed With A Fixed Calcualtor. (Will Not Stop Brute Force Attacks!)" << std::endl;
		std::cout << "[1] Enable Basic Security" << std::endl;
		std::cout << "[2] Back" << std::endl;
		cin >> Hold_Option;
		if (Hold_Option == "1")
		{
			Level_Of_Security = "Basic";
		}
	}
	return Level_Of_Security;
}	
std::string Set_To_Intermediate(string Level_Of_Security)
{
	string Hold_Option;
	while (Hold_Option != "2")
	{
		Clear_Screen();
		std::cout << "The Intermediate Level Of Security Will Set A Random Seed With A Random Calcualtor. (Will Not Stop Brute Force Attacks!)" << std::endl;
		std::cout << "[1] Enable Intermediate Security" << std::endl;
		std::cout << "[2] Back" << std::endl;
		cin >> Hold_Option;
		if (Hold_Option == "1")
		{
			Level_Of_Security = "Intermediate";
		}
	}
	return Level_Of_Security;
}
std::string Set_To_Advanced(string Level_Of_Security)
{
	string Hold_Option;
	while (Hold_Option != "2")
	{
		Clear_Screen();
		std::cout << "The Advanced Level Of Security Will Set A Random Seed With A Random Calcualtor While Taking Some Of The File And Moving It To The Key." << std::endl;
		std::cout << "[1] Enable Advanced Security" << std::endl;
		std::cout << "[2] Back" << std::endl;
		cin >> Hold_Option;
		if (Hold_Option == "1")
		{
			Level_Of_Security = "Advanced";
		}
	}
	return Level_Of_Security;
}
std::string Set_Level_Of_Secutriy(string Level_Of_Security)
{
	
	string Hold_Option;
	
	while (Hold_Option != "4")
	{
		Clear_Screen();
		std::cout << "Current Level Of Security Set To =======> [" << Level_Of_Security << "]\n";
		std::cout << "There are three levels of secutriy. Please Select Once!\n[By Default, Encription Security Will Be Set To Intermediate Upon Leaving This Menu]\n";
		std::cout << "[1] Basic" << std::endl;
		std::cout << "[2] Intermediate" << std::endl;
		std::cout << "[3] Advanced" << std::endl;
		std::cout << "[4] Back" << std::endl;
		cin >> Hold_Option;
		if (Hold_Option == "1")
		{
			Level_Of_Security = Set_To_Basic(Level_Of_Security);
		}
		if (Hold_Option == "2")
		{
			Level_Of_Security = Set_To_Intermediate(Level_Of_Security);
		}
		if (Hold_Option == "3")
		{
			Level_Of_Security = Set_To_Advanced(Level_Of_Security);
		}
		if (Hold_Option == "4")
		{
			return Level_Of_Security;
		}
	}
	
	
}
void Print_Converted_Encription_Key(string x)
{
	Clear_Screen();
	std::cout << x << endl;
	std::cout << "Enter a character to continue;" << endl;
	string i = "";
	cin >> i;
}
void Print_Standard_Encription_Key(string x)
{
	Clear_Screen();
	std::cout << x << endl;
	std::cout << "Enter a character to continue;" << endl;
	string i = "";
	cin >> i;
}
std::string Set_Seed_Func()
{
	Clear_Screen();
	string Seed = "";
	string True_Seed = "";
	std::cout << "Please Enter Seed Below\n";
	cin >> Seed;
	for (int i = 0; i < Seed.size() - 1; ++i)
	{
		True_Seed = (Seed + True_Seed[i]);
	}
	True_Seed = Padding(True_Seed);
	return Trunk_The_Key(True_Seed);

}
void Main_Menu()
{
	std::cout << "Welcome To The Encryption Software" << std::endl;
	std::cout << "[1] Set Seed" << std::endl;
	std::cout << "[2] Set Level Of Security" << std::endl;
	std::cout << "[3] Quit Program" << std::endl;
}
std::string Set_Seed(string x)
{
	string Absolute_Seed = "";
	string Option = "";
	string Encription_Block = x;
	while (Option != "2")
	{
		Clear_Screen();
		std::cout << "The Seed Will Randomize The Encription. If Left [Blank], One Will Be Generated For You." << std::endl;
		std::cout << "Current Encription Seed [" << Encription_Block[0] << "]" << "[" << Encription_Block[1] << "]" << "[" << Encription_Block[2] << "]" << "[" << Encription_Block[3] << "]" << "[" << Encription_Block[4] << "]" << "[" << Encription_Block[5] << "]" << "[" << Encription_Block[6] << "]" << "[" << Encription_Block[7] << "]" << "[" << Encription_Block[8] << "]" << "[" << Encription_Block[9] << "]";
		for (int i = 0; i < 2; ++i)
		{
			std::cout << "\n" << std::endl;
		}
		std::cout << "[1] Change Seed" << std::endl;
		std::cout << "[2] Back" << std::endl;
		cin >> Option;
		if (Option == "1")
		{
			Clear_Screen;
			Encription_Block = Set_Seed_Func();
		}
		if (Option == "2")
		{
			break;
		}
	}
	return Trunk_The_Key(Encription_Block);
	
	
}
std::string Conversion(string x)
{
	srand(time(NULL));
	string To_Hold = "";
	bool Is_Nothing = true;
	int Number_Hold = 0;
	std::map<char, int> Conversion;
	string Converted_Encription_Key = "";
	Conversion['A'] = 0; Conversion['a'] = 0; Conversion['B'] = 1; Conversion['b'] = 1; Conversion['C'] = 2; Conversion['c'] = 2;
	Conversion['d'] = 3; Conversion['D'] = 3; Conversion['E'] = 4; Conversion['e'] = 4; Conversion['F'] = 5; Conversion['f'] = 5;
	Conversion['G'] = 6; Conversion['g'] = 6; Conversion['H'] = 7; Conversion['h'] = 7; Conversion['I'] = 8; Conversion['i'] = 8;
	Conversion['J'] = 9; Conversion['j'] = 9; Conversion['K'] = 0; Conversion['k'] = 0; Conversion['L'] = 1; Conversion['l'] = 1;
	Conversion['M'] = 2; Conversion['m'] = 2; Conversion['N'] = 3; Conversion['n'] = 3; Conversion['O'] = 4; Conversion['o'] = 4;
	Conversion['P'] = 5; Conversion['p'] = 5; Conversion['Q'] = 6; Conversion['q'] = 6; Conversion['R'] = 7; Conversion['r'] = 7;
	Conversion['S'] = 8; Conversion['s'] = 8; Conversion['T'] = 9; Conversion['t'] = 9; Conversion['U'] = 0; Conversion['u'] = 0;
	Conversion['V'] = 1; Conversion['v'] = 1; Conversion['W'] = 2; Conversion['w'] = 2; Conversion['X'] = 3; Conversion['x'] = 3;
	Conversion['Y'] = 4; Conversion['y'] = 4; Conversion['Z'] = 5; Conversion['z'] = 5;
	for (int i = 0; i < x.size(); ++i)
	{
		
		int Random_Number = rand() % 10;
		Is_Nothing = true;
		string Convert_To_Int = to_string(x[i]);
		int CN = (stoi(Convert_To_Int) - 48);
		cout << CN;
		if (CN > -1 || CN < 10)
		{
			To_Hold = x[i];
		}
		else
             if (x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z')
		     {
			    Number_Hold = Conversion.at(x[i]);
			    To_Hold = to_string(Number_Hold);
		     }
			 else
			 {
				 Is_Nothing = false;
			 }
		if (Is_Nothing == 1)
		{
			To_Hold = to_string(Random_Number);
		}
		
		Converted_Encription_Key = Converted_Encription_Key + To_Hold;
		To_Hold.clear();
	}
	return Trunk_The_Key(Converted_Encription_Key);
}
int main()
{
	
	string Level_Of_Security = "Intermediate";
	string Absolute_Seed = "0000000000";
	string Option = "";
	bool is_Off = 0;
	
	while (is_Off != 1)
	{
		Clear_Screen();
		Main_Menu();
		//cin >> Option;
		Option = "3";
		if (Option == "1")
		{
			Absolute_Seed = Set_Seed(Absolute_Seed);
			
		}
		if (Option == "2")
		{
			Level_Of_Security = Set_Level_Of_Secutriy(Level_Of_Security);
		}
		if (Option == "3")
		{
			if (Absolute_Seed == "0000000000")
			{
				srand(time(NULL));
				Absolute_Seed.clear();
				for (int i = 0; i < 10; ++i)
				{
					Absolute_Seed = Absolute_Seed + to_string(rand() % 10);
				}
			}
			Absolute_Seed = Conversion(Absolute_Seed);
			Send_To_File(Absolute_Seed, Level_Of_Security);
			return 0;
		}
		if (Option == "-4")
		{
			Absolute_Seed = Conversion(Absolute_Seed);
		}
		if (Option == "-5")
		{
			Print_Standard_Encription_Key(Absolute_Seed);
		}
		
	}
}
