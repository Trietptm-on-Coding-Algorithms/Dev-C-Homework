#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Profile
{
	string ID;
	bool Sex;
	float Kg;
	float Height;
	float BMI;
};
int main()
{
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) exit(0);
	
	Profile UserList[100] = Profile();
	float KgRecord(0),HeightRecord(0),MaxBMI(0);
	int pos(0),MaleCount(0),MaxHeightPos(0);
	
	for(; pos < 100 ; pos++)
	{
		if (!(fileInput >> UserList[pos].ID >> UserList[pos].Sex >> UserList[pos].Kg >> UserList[pos].Height)) break;
		UserList[pos].BMI = UserList[pos].Kg *100 *100/ (UserList[pos].Height * UserList[pos].Height);
		KgRecord += UserList[pos].Kg; 
		HeightRecord += UserList[pos].Height;
		MaxBMI =  (UserList[pos].BMI > MaxBMI ? UserList[pos].BMI : MaxBMI);
		MaxHeightPos = (UserList[pos].Height > UserList[MaxHeightPos].Height ? pos : MaxHeightPos);
		MaleCount += UserList[pos].Sex;
		cout << "[" << (pos + 1) << "] ,ID:" << UserList[pos].ID << "\t�ʧO:" << (UserList[pos].Sex ? "�k��":"�k��");
		cout << "\t����" << UserList[pos].Height << "\t�魫:" << UserList[pos].Kg << "\tBMI:" << UserList[pos].BMI <<endl;
	}
	cout << "��������:" << (HeightRecord/(pos)) << ", �����魫:" << (KgRecord/(pos)) << endl;
	cout << "�̤jBMI:" << MaxBMI << ", �̰��̪��s��:" << UserList[MaxHeightPos].ID << endl;
	cout << "�k�k�H�Ƥ� " << MaleCount << ":" << (pos - MaleCount) <<endl;
	fileInput.close();
	system("PAUSE");
	return 0;
}

