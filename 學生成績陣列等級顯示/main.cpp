/**
*�H������100�W�ǥͤ����B�^��B�ƾǡB�۵M�B���|����|�Ҧ��Z�A��
*�즨�Z>=90���䵥�Ŭ�A�A�p��90��>=80��B�A�p��80��>=70��C�A�p��70
*��>=60��D�A�p��60��F�CM�j�h��(�]�t)2��F�Y�������AK�j����>=60�Y��
*���A���@�տ�������h�H?�̫Უ�ͤU�C���
**/
#include<iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
char Level(int score)
{
	// 100 ~ 90 = A = 0x41
	// 90  ~ 80 = B = 0x42 = 0x41 + 1
	// 80  ~ 70 = C = 0x43 = 0x42 + 2
	// 70  ~ 60 = D = 0x44 = 0x43 + 3
	// 60 down  = E = 0x45 = 0x44 + 4
		 if (score <	60)	return 'F';
	else if (score >=	100)return 'A';
	return (char)('A' + (3-((score - 60)/10)));
}

int main()
{
	int array[100][5];
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 5; array[i][j] = (rand() % 100) + 1,++j);
    
	cout << "�m�W\t���\t����\t�^��\t����\t�ƾ�\t����\t�۵M\t����\t���|\t����\t����\tM�j����\tK�j����\n";
	int SumM(0),SumK(0);
    for (int i(0),M(0),sum(0); i < 100; ++i)
	{
		M = 0;
		sum = 0;
		cout << "A" << i << "\t";
		for (int j(0); j < 5; ++j)
		{
            sum += array[i][j];
			char levelTemp = Level(array[i][j]);
			M += (levelTemp == 'F');
			cout << array[i][j] << "\t" << levelTemp << "\t" ;
		}
		SumM += (M < 2);
		SumK += (sum >= 300);
		cout << (sum/5) << "\t" << (M > 1?"�_":"�O") << "\t" <<(sum >= 300? "�O":"�_") << "\n";
	}
	cout << "M�j�����F:\t" << SumM << "\n";
    cout << "K�j�����F:\t" << SumK << "\n";
    if (SumM == SumK) cout << "��j�ǿ����@�˦h�H\n"; 
    else cout << (SumM > SumK? "M":"K") << "�j�������h�H\n"; 
    system("PAUSE");
	return 0 ;
}
