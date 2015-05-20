#include <iostream>
using namespace std;
#define HourSec (60*60)
#define MinSec  (60)

class MyTime
{
	private:
	int Hour,Min,Sec;
	
	public:
	int CurrentAllSec() { return (Hour * HourSec + Min * MinSec + Sec);}
	MyTime(int NewHour,int NewMin,int NewSec) { Hour = NewHour,Min = NewMin,Sec = NewSec;FixCurrentTime();}
	MyTime() { MyTime( 0, 0, 0);}
	
	void FixCurrentTime()
	{
		int SecondSum = CurrentAllSec();
		Hour = SecondSum / HourSec;
		SecondSum -= Hour * HourSec;
		Min = SecondSum / MinSec;
		SecondSum -= Min * MinSec;
		Sec = SecondSum;
	}
	
	int GetHour() { return Hour;}
	int GetMin()  { return Min;}
	int GetSec()  { return Sec;}
	void SetHour(int NewHour) { Hour = NewHour;}
	void SetMin(int NewMin) { Min = NewMin;}
	void SetSec(int NewSec) { Sec = NewSec;}
	friend bool operator> (MyTime a,MyTime b){ return a.CurrentAllSec() > b.CurrentAllSec();}
	friend bool operator< (MyTime a,MyTime b){ return a.CurrentAllSec() < b.CurrentAllSec();}
	friend bool operator== (MyTime a,MyTime b){ return a.CurrentAllSec() == b.CurrentAllSec();}
	friend bool operator!= (MyTime a,MyTime b){ return a.CurrentAllSec() != b.CurrentAllSec();}
	friend MyTime operator+ (MyTime a,MyTime b){ return MyTime( 0, 0, a.CurrentAllSec() + b.CurrentAllSec());}
	friend MyTime operator- (MyTime a,MyTime b){ return MyTime( 0, 0, a.CurrentAllSec() - b.CurrentAllSec());}
	friend MyTime operator* (MyTime a,int b){ return MyTime( 0,0, a.CurrentAllSec() * b);}
	friend MyTime operator/ (MyTime a,int b){ return MyTime( 0,0, a.CurrentAllSec() / b);}
	friend float operator/ (MyTime a,MyTime b){ return ((float)a.CurrentAllSec() / (float)b.CurrentAllSec());}
		
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
};

int main() 
{
	MyTime n[2] = {};
	int Times(0);
	
	cout << "�п�J�Ĥ@���ɶ��� �p�� ���� ���: " ; 
	cin >> n[0];
	cout << "�п�J�ĤG���ɶ��� �p�� ���� ���: " ; 
	cin >> n[1];
	
	if (n[0] == n[1]) cout << "�ⵧ�ɶ��@�˪�\n";
	else cout << (n[0] > n[1] ? "�Ĥ@���ɶ�" : "�ĤG��") << "�ɶ�����\n"; 
	
	cout << "�ⵧ�ɶ����j�G\t" << (n[0] > n[1] ? n[0] - n[1] : n[1] - n[0]) << endl; 
	cout << "�ⵧ�ɶ��`�M�G\t" << n[0] + n[1] << endl; 
	cout << "�Ĥ@���P�ĤG���ɶ����ɶ����פ�Ҭ��G\t" << (n[0] / n[1])<< endl; 
	
	cout << "�п�J�@�ӭ��ơG";cin >> Times;
	cout << "�Ĥ@���ɶ����W" << Times << "���ᬰ�G\t" << n[0] * Times << endl; 
	cout << "�ĤG���ɶ����W" << Times << "���ᬰ�G\t" << n[1] * Times << endl; 	
	return 0;
}
