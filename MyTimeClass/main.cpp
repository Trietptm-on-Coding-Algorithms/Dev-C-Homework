#include <iostream>
using namespace std;
#define HourSec (60*60)
#define MinSec  (60)
/*
1.�г]�p�@�Ӵy�z�ɶ������OMyTime
   �����ܼơG��hour�B��min�B��sec
   �غc�l�P�������

2.�Э��s�w�qcin�Bcout�PMytime���ɦV�B��

3.�Э��s�w�qMyTime���[�k�B��

4.�Шϥ�MyTime�]�p�@�ӵ{���A�i��J��Ӯɶ��A��X��Ӯɶ��ۥ[���`�M
Hint�G�Ъ`�N�i��60sec=1min, 60min=1hour
*/
class MyTime
{
	private:
	int Hour,Min,Sec;
	public:
	void FixCurrentTime()
	{
		int SecondSum = Hour * HourSec + Min * MinSec + Sec;
		Hour = SecondSum / HourSec;
		SecondSum -= Hour * HourSec;
		Min = SecondSum / MinSec;
		SecondSum -= Min * MinSec;
		Sec = SecondSum;
	}
	
	MyTime(int NewHour,int NewMin,int NewSec) { Hour = NewHour,Min = NewMin,Sec = NewSec;FixCurrentTime();}
	MyTime() { MyTime( 0, 0, 0);}
	int GetHour() { return Hour;}
	int GetMin()  { return Min;}
	int GetSec()  { return Sec;}
	void SetHour(int NewHour) { Hour = NewHour;}
	void SetMin(int NewMin) { Min = NewMin;}
	void SetSec(int NewSec) { Sec = NewSec;}
	
	friend ostream& operator<< (ostream& out,MyTime d) 
	{
		out << d.Hour << " Hour " <<d.Min<<" Minute "<<d.Sec << " Second";      
		return out;
	}  
	friend istream& operator>> (istream& in,MyTime& d)
	{
		in >> d.Hour >> d.Min >> d.Sec;      
		return in;
	}

	friend MyTime operator+ (MyTime a,MyTime b)
	{
	   int Data[3] ={  a.GetHour() + b.GetHour() , 
					   a.GetMin()  + b.GetMin()  ,
					   a.GetSec()  + b.GetSec() };
	   return MyTime(Data[0],Data[1],Data[2]);
	}
};

int main() 
{
	MyTime n[2] ;
	cout << "�п�J�Ĥ@���ɶ��� �p�� ���� ���: " ; 
	cin >> n[0];
	cout << "�п�J�ĤG���ɶ��� �p�� ���� ���: " ; 
	cin >> n[1];
	cout << n[0]+n[1] ;
	return 0;
}
