#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int total_money = 0;
void SetTotalMoney(bool Paid,int Money)
{
	total_money = total_money + Money * (Paid? -1 : 1);
}

void ChkMoneySum()
{
	system("cls");
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) return;
	int Type(0),Money(0);
	char result[256];
	total_money = 0;
	while(fileInput >> Type>> Money >> result)
	{
		cout << (Type?"[��X]\t":"[���J]\t") << Money << "��\t��]: " << result << endl;
		SetTotalMoney(Type,Money);
	}
	fileInput.close();
	cout << "�ثe�z���`���B��: " << total_money << endl << endl;
}

int main()
{
	ChkMoneySum();
	fstream fileOutput;
	fileOutput.open("data.txt",ios::out|ios::app);
	if (!fileOutput)
	{
		cout << "cannot open file.";exit(0);
	}
	char result[256] = {};
	for(int choise(-1),Money(0);;)
	{
		cout << "�п�J�z�Q�O��:[0]���J [1]��X [2]���}? ";cin >> choise;
		if ( choise > 2 || choise < 0 ) continue;
		else if (choise == 2) break;
		cout << "�п�J�z�����B: ";cin >> Money;
		if ( Money < 1 ) continue;
		cout << "�п�J�����O�����z��(�̦h256�r��,���o���ť�): ";cin >> result;
		fileOutput << choise << " " << Money << " "<< result << endl;
		SetTotalMoney(choise,Money);
		ChkMoneySum();
	}
	fileOutput.close();
	return 0;
}
