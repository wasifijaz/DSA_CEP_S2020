#include<iostream>
#include <string.h>
#include <queue>
#include <fstream>

using namespace std;

typedef struct DataStructuresStudent
{
    string firstName;
    string lastName;
    int enterTime;
    int numQuestions;
    int numAnswered;
    int number;
    int laptop = 0;
    int count;
} Student;

int main()
{
    queue <Student> s;
    queue <Student> qQA;
    ifstream inputFile;
    int numOfTA = 0;
    int numOfStudentsPerDay = 0;
    int i, j;
    Student student[300];
    Student currStu = {"","",0,0,0,0,0,0};
    int time;
    int closetime = 240;
   
    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        time = 0;
        inputFile >> numOfStudentsPerDay;
        for (j = 0; j < numOfStudentsPerDay; j++)
        {
            inputFile >> student[j].enterTime >> student[j].firstName >> student[j].lastName >> student[j].numQuestions;
            student[j].numAnswered = 0;
            student[j].number = j;
            student[j].count = 0;
        }
        while (time != closetime)
        {
            //cout << time << endl;
            for (i = 0; i < numOfStudentsPerDay; i++)
            {
                if (time >= student[i].enterTime)
                {
                    if (time == student[i].enterTime)
                    {
                        cout << time << "\t" << student[i].firstName << " has arrived in TA#007." << endl;
                    }
                    if (student[i].count == 2 && student[i].laptop == 0)
                    {
                        student[i].laptop = i + 10000;
                        cout << time << "\t" << student[i].firstName << " has borrowed laptop " << student[i].laptop << " and moved to the TA line" << endl;
                        s.push(student[i]);
                    }
                    student[i].count++;
                }
                else
                {
                    break;
                }
            }

            if (!s.empty() && currStu.firstName == "")
            {
                qQA.push(s.front());
                currStu = qQA.front();
                qQA.pop();
                s.pop();
                cout << time << "\t" << currStu.firstName << " is getting help from Charles." << endl;
                currStu.count = 0;
            }
            else if (!s.empty() && currStu.firstName != "")
            {
                if (s.front().enterTime == time)
                {
                    cout << time << "\t" << s.front().firstName << " has arrived in TA#007." << endl;
                    qQA.push(s.front());
                    s.pop();
                }
            }
            if (currStu.firstName != "")
            {
                if (currStu.count  == 5)
                {
                    currStu.numAnswered++;
                    if (currStu.numQuestions >= currStu.numAnswered)
                    {
                        cout << time << "\t" << currStu.firstName << " has had one question answered and gotten back in line." << endl;
                        currStu.count = 0;
                        currStu.enterTime = time;
                        qQA.push(currStu);
                    }
                    else
                    {
                        cout << time << "\t" << currStu.firstName << " returned home happy" << endl;
                        currStu = { "","",0,0,0,0,0,0 };
                    }
                }
                currStu.count++;
            }
            time++; 
        }
    }
    else
    {
        cout << "ERROR READING FILE!" << endl;
    }

    return 0;
}