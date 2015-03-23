#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // contains prototype for function time
/*
�Эק�U�C�{���A�HWhile�j�魫���Y��ӻ�l�A�C�Y�@���N�L�X��ӻ�l�Y�X�����G
�p�G�X�{��Ӥ��P���Ʀr�A�~���Y��l�C
�p�G�Y��l�Y15���٨S�Y�X��l�A�ڭ̴N���n�A���U�h�A�����L�X�u�A���Ѫ����ܭI�@�I�v
�p�G�X�{��ӬۦP���Ʀr�A�L�X[���ߧA�]�p�^�b�Y�H����l���Y�X�F��l�I]�ð����Y��l
*/
int main()
{
	int sum; // sum of rolled dice
	int die1; // first die
	int die2; // second die
	srand(time(NULL));// randomize random number generator using current time
	
	int count = 15;
	while (count)
	{
		die1 = 1 + (rand() % 6); // pick random die1 value
		die2 = 1 + (rand() % 6); // pick random die2 value
		sum = die1 + die2; // sum die1 and die2
		count --;
		if (die1 == die2) break;
	}
	
	if (count) printf( "���ߧA�]�p�^�b�Y%d����l���Y�X�F��l�I\n", (15 - count));
	else printf( "�A���Ѫ����ܭI�@�I\n");
		
	// display results of this roll
	printf( "Player rolled %d + %d = %d\n", die1, die2, sum );
	system("pause");
	return 0;
} 
