#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pLevel(a) (int)((char)(70 - (a/20)))
using namespace std;

template <class T>
class StudentScore 
{
    public:
    string ID;
    T Score;
    StudentScore(string nID,T nScr){ID = nID, Score = nScr;}
    StudentScore(){}
};

template <class T>
bool cmp_pattern( StudentScore<T> lhs, StudentScore<T> rhs){ return lhs.Score<rhs.Score ;} 

vector< StudentScore<int> > numScores;
vector< StudentScore<char> > levelScores;

void SetIDNumScore(string ID,int Score)
{
     for (int i = 0; i < numScores.size() ; i++)
     {
             if (numScores[i].ID == ID)
             {
                numScores[i].Score = Score;           
                return;
             }
     }
     numScores.push_back(StudentScore<int>(ID,Score));
}

void SetIDNumLevel(string ID,char Level)
{
     for (int i = 0; i < levelScores.size() ; i++)
     {
             if (levelScores[i].ID == ID)
             {
                levelScores[i].Score = Level;            
                return;
             }
     }
     levelScores.push_back(StudentScore<char>(ID,Level));
}

int GetIDNumScore(string ID)
{
    for (int i = 0; i < numScores.size() ; i++) if (numScores[i].ID == ID) return numScores[i].Score;
    return (-1);
}

char GetIDNumLevel(string ID)
{
    for (int i = 0; i < levelScores.size() ; i++) if (levelScores[i].ID == ID) return levelScores[i].Score;
    return (0x00);
}

void RemoveIDData(string ID)
{
    for (int i = 0; i < levelScores.size() ; i++)if (levelScores[i].ID == ID) levelScores.erase(levelScores.begin() + i );
    for (int i = 0; i < numScores.size() ; i++)  if (numScores[i].ID == ID) numScores.erase(numScores.begin() + i );
}
void SortScore()
{
    sort(numScores.begin(),numScores.end(),cmp_pattern<int>);
    sort(levelScores.begin(),levelScores.end(),cmp_pattern<char>);
}
void ShowCurrentData()
{
     SortScore();
     for(int i = 0; i < numScores.size() ; i++) cout << numScores[i].ID 
                                                     << "\t" << numScores[i].Score 
                                                     << "\t" << GetIDNumLevel(numScores[i].ID) 
                                                     << endl;
}

void ReadInData()
{
    fstream fileInput;
    fileInput.open("data.txt",ios::in);
    if (!fileInput) return;
    string TempID;
    int TempScore;
    char TempLevel;
    cout << "��e�ǥ͸�Ʀp�U:" << endl; 
    for (;fileInput >> TempID >> TempScore >> TempLevel;
          SetIDNumScore(TempID,TempScore),SetIDNumLevel(TempID,TempLevel));
}

void OutputData()
{
    fstream fileOutput;
    fileOutput.open("data.txt",ios::out);
    if (!fileOutput) return;
    for(int i = 0; i < numScores.size() ;fileOutput << numScores[i].ID
                                                    << " " << numScores[i].Score 
                                                    << " " << GetIDNumLevel(numScores[i].ID) 
                                                    << endl, i++);
}

int main()
{
    ReadInData();
    for(int Choise(-1); Choise != (4);)
    {
       system("CLS");
       ShowCurrentData();
       string TempID;
       int TempScore;
       cout << "�п��:\n[1]�s�W�ǥ͸��\n[2]�����ǥ͸��\n[3]��M�ǥ͸��\n[4]���}�{��\n";
       cin >> Choise;
       switch(Choise)
       {
          case 1:
            cout << "�п�J�ǥ�ID:"; cin >> TempID;
            cout << "�п�J�ǥͤ���:"; cin >> TempScore;
            SetIDNumScore(TempID,TempScore);
            SetIDNumLevel(TempID,pLevel(TempScore));
            break;
          case 2:
            cout << "�п�J�ǥ�ID:"; cin >> TempID;
            RemoveIDData(TempID);
            break;
          case 3:
            cout << "�п�J�ǥ�ID:"; cin >> TempID;
            cout << "���Ƭ�" <<  GetIDNumScore(TempID) << " �ŧO��" <<  GetIDNumLevel(TempID) << endl;
            system("PAUSE");
            break;
       }
    }
    OutputData();
    return 0;
}
