#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool IsNumber(char i)
{
	return ((i > 47) && (i < 58));
}
bool IsUppercase(char i)
{
	return ((i > 64) && (i < 91));
}
bool IsLowercase(char i)
{
	return ((i > 96) && (i < 123));
}
bool IsSymbol(char i)
{
	return ((i > 31) && (i < 127)) && (!IsNumber(i)) && (!IsUppercase(i)) && (!IsLowercase(i));
}
int main()
{
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) exit(0);
	int NumberCount(0),UpperCount(0),LowerCount(0),Symbol(0);
	cout << "�ɮפ���r: ";
	for(char current_char;fileInput.get(current_char);)
	{
		NumberCount += IsNumber(current_char);
		UpperCount += IsUppercase(current_char);
		LowerCount += IsLowercase(current_char);
		Symbol += IsSymbol(current_char);	
		cout <<current_char;
	}
	cout << "\n\n�o�{�F�@�@ " << NumberCount << "�ӼƦr, " <<  UpperCount << "�Ӥj�g�r, " ;
	cout << LowerCount << "�Ӥp�g�r, " << Symbol << "�ӲŸ�,�@" << (UpperCount+LowerCount) << "�ӳ�r.\n"; 
	fileInput.close();
	system("pause");
	return 0;
}

