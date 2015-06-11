#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

/*
1.�г]�p�@�Ӱ�¦���OPerson�A�Ӭ����@�ӤH���m�W�P�~��
2.�г]�p�@�Ӱ�¦���OCourse�A�ӰO���@�Ӭ�ت������һP�����Ҧ��Z
3.�г]�p�@���~�Ӱ�¦���OPerson�P��¦���OCourse���l�����OStudent�A�Ӭ����@�Ӿǥͪ��m�W�B�~�֡B�Ǹ��B�~�ŻP���Z
4.�Шϥ����OStudent�AŪ���ɮ�record�A�N�Ҧ��ǥͥH�������ư��C�Ƨǫ��X

PS�G�Цۦ�]�p�Ҧ����O�һݪ������ܼơB������ơB�غc�l�P�B��l����*/
class Person
{
	public:
		string Name;
		int Old;
		Person(string nName,int nOld){Name = nName, Old = nOld;}
		Person(){Name = "null", Old = 0;}
};

class Course
{
	public:
		float MidExam;
		float FinalExam;
		float Average;
		float GetAvg(){ Average = (MidExam+FinalExam)/2;}
		Course(float nMidExam,float nFinalExam){ MidExam = nMidExam, FinalExam = nFinalExam,GetAvg();}
		Course(){ MidExam = 0,FinalExam = 0,Average = 0;}
};

class Student: public Course,public Person
{
	public:
		string SID;
		int SGrade;
		Student(string nName,int nOld,string nSID,int nSGrade,float nMidExam,float nFinalExam):
		Course(nMidExam ,nFinalExam) ,
		Person(nName, nOld)
		{
			this->SID = nSID; 
			this->SGrade = nSGrade; 
		}
		Student() : Person(),Course(){SID = "null", SGrade = 1;}
		friend ostream& operator<< (ostream& out,Student d) 
		{
			out << d.Name << "\t" << d.Old << "\t" << d.SID << "\t" << d.SGrade << "\t" << d.MidExam << "\t" << d.FinalExam <<"\t" << d.Average;
			return out;
		}  
};

int main()
{ 
	Student DataArray[100] ;
	
	int Count;
	fstream Fin("record.txt",ios::in);
	if (!Fin) exit(0);
	cout << "��e�ǥ͸�ơG" << endl;
	for(Count = 0;
		(Fin >> DataArray[Count].Name 
		     >> DataArray[Count].Old 
	         >> DataArray[Count].SID 
	         >> DataArray[Count].SGrade 
	         >> DataArray[Count].MidExam 
	         >> DataArray[Count].FinalExam) && (Count < 100);
		DataArray[Count].GetAvg(),cout << DataArray[Count] << endl, Count++);
	Fin.close();
	
	cout << "�g�Ƨǫᵲ�G�G" << endl;
	for(int i(0); i < Count; i++)
	{
		for(int j(i+1); j < Count; j++)
		{
			if (DataArray[j].Average > DataArray[i].Average)
			{
				Student Temp = DataArray[i];
				DataArray[i] = DataArray[j];
				DataArray[j] = Temp;
			}
		}
	}
	
	for(int i(0); i < Count; cout << DataArray[i] << endl, i++); 
	
	return 0; 
}


