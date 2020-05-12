// CEP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Students.h"
#include "TAs.h"
#include "LDM.h"
#include "Time.h"
using namespace std;

string time;
Students s[2];
queue <Students> q, q1;
TAs ta;
TAs* teachersArray = new TAs[2];
Time t;
int i;

void getLaptops(ifstream&, int); //read laptop data from file
void getTA(ifstream&, int);      //read TA data from file
void getStudents(ifstream&, int);//read TA data from file
void assignTA(ifstream&, int, int);
void studentData();

//TAs availableTA(TAs*, int);

int main()
{
    ifstream inputFile;
    //string time;
    int totalLaps = 0;
    int totalTAs = 0;
    int totalStudents = 0;
    int numOfProgams = 0;
    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        inputFile >> totalLaps;
        getLaptops(inputFile, totalLaps);
        inputFile >> totalTAs;

        getTA(inputFile, totalTAs);
        inputFile >> numOfProgams;
        for (i = 0; i < 3; i++)
        {
            inputFile >> totalStudents;
            if (totalStudents > 300)
            {
                cout << "Lab Full! Too many students." << endl;
            }
            //getStudents(inputFile, totalStudents);
            else
            {
                //cout << totalStudents << endl;
                if (i == 0)
                {
                    cout << "\nMonday:"<<endl;
                    assignTA(inputFile, totalTAs, totalStudents);
                }
                //break;
                else if (i == 1)
                {
                    cout << "\nTuesday:" << endl;
                    assignTA(inputFile, totalTAs, totalStudents);
                }
                else
                {
                    //cout << "check 4" << endl;
                    cout << "\nWednesday:" << endl;
                    assignTA(inputFile, totalTAs, totalStudents);
                }
                //getStudents(inputFile, totalStudents);
            }
        }
    }
    inputFile.close();
    //cout << "\n\n" << issueLaptop(lap) << endl;
    while (!lap.empty())
    {
        cout << "\n" << lap.top();
        lap.pop();
    }

    
    return 0;
}

void getLaptops(ifstream& inputFile, int totalLaps)
{
    //reading laptops data form file
    int lapSerial;
    for (i = 0; i < totalLaps; i++)
    {
        inputFile >> lapSerial;
        lap.push(lapSerial);
    }
}

void getTA(ifstream& inputFile, int totalTAs)
{
    //reading TA data form file
    //TAs* teachersArray = new TAs[totalTAs];
    for (i = 0; i < totalTAs; i++)
    {
        inputFile >> teachersArray[i].name>>teachersArray[i].startTimes[0] >> teachersArray[i].endTimes[0] >> teachersArray[i].startTimes[1] >> teachersArray[i].endTimes[1] >> teachersArray[i].startTimes[2] >> teachersArray[i].endTimes[2];
       // cout << "\n" << teachersArray[i].startTimes[0] << "\t" << teachersArray[i].startTimes[1] << "\t" << teachersArray[i].startTimes[2] << endl;
    }
}

void getStudents(ifstream& inputFile, int totalStudents)
{
    //int intTime;
    //Students* s = new Students[totalStudents];
    
    //stu.sortStudents(s, totalStudents);
    /*for (int i = 0; i < totalStudents; i++)
    {
        s = q.front();
        q.pop();
        ta.studentWithTA = s;
        s.getHelp(ta, totalStudents);
    }*/
    Students s1;
    for (int i = 0; i < totalStudents; i++)
    {
        inputFile >> s1.enterTime >> s1.firstName >> s1.lastName >> s1.numQuestions;
        q.push(s1);
    }
    studentData();
    //Students stu;
    //for (i = 0; i < totalStudents - 1; i++)
    //{
        //s[0] = q.front();
        //q.pop();
        //for (int j = i; j < totalStudents; j++)
        //{
         //   s[1] = q.front();
           // if (s[0].enterTime <= s[1].enterTime)
            //{
                //q.push(s[0]);
                /*stu = q.front();
                q.pop();
                int intTime;
                ta.studentWithTA = stu;
                time = t.convertTime(stu.enterTime);
                cout << time << "\t" << stu.firstName << " " << stu.lastName << " has arrived in TA#007." << endl;
                if (lap.empty())
                {
                    cout << "\nLaptop Stack Empty" << endl;
                    break;
                }
                else
                {
                    stu.laptopSerialNum = issueLaptop();
                    intTime = timeToGetLaptop(stu.enterTime);
                    time = t.convertTime(intTime);
                    cout << time << "\t" << stu.firstName << " " << stu.lastName << " has borrowed laptop " << stu.laptopSerialNum << " and moved to the TA line." << endl;
                    if (intTime < q.front().enterTime)
                    {
                        cout << time << "\t" << stu.firstName << " " << stu.lastName << " is getting help from " << ta.name << "." << endl;
                    }
                    else
                    {

                    }*/

                    /*if (intTime < q.front().enterTime)
                    {
                        intTime = t.timeToGetAnswer(intTime);
                        if (intTime < q.front().enterTime)
                        {
                            time = t.convertTime(intTime);
                            cout << time << "\t" << stu.firstName << " " << stu.lastName << " has had one question answeredand gotten back in line." << endl;
                        }
                        else
                        {
                            studentData(q.front());
                            q.pop();
                        }
                    }*/
                //}
            //}
            //else
            //{
            //    //q.push(s[1]);
            //    stu = s[1];
            //    q.pop();
            //    int intTime;
            //    ta.studentWithTA = stu;
            //    time = t.convertTime(stu.enterTime);
            //    cout << time << "\t" << stu.firstName << " " << stu.lastName << " has arrived in TA#007." << endl;
            //    if (lap.empty())
            //    {
            //        cout << "\n\n\n\nLaptop Stack Empty" << endl;
            //    }
            //    else
            //    {
            //        stu.laptopSerialNum = issueLaptop();
            //        intTime = timeToGetLaptop(stu.enterTime);
            //        time = t.convertTime(intTime);
            //        cout << time << "\t" << stu.firstName << " " << stu.lastName << " has borrowed laptop " << stu.laptopSerialNum << " and moved to the TA line." << endl;
            //        cout << time << "\t" << stu.firstName << " " << stu.lastName << " is getting help from " << ta.name << "." << endl;
            //        if (intTime < q.front().enterTime)
            //        {
            //            intTime = t.timeToGetAnswer(intTime);
            //            if (intTime < q.front().enterTime)
            //            {
            //                time = t.convertTime(intTime);
            //                cout << time << "\t" << stu.firstName << " " << stu.lastName << " has had one question answeredand gotten back in line." << endl;
            //            }
            //            else
            //            {
            //                studentData(q.front());
            //                q.pop();
            //            }
            //        }
            //    }
            //}
       // }
   // }
    //    //cout<<s[i].enterTime << "\t" << s[i].firstName << "\t" << s[i].lastName << "\t" << s[i].numQuestions<<endl;
    //    //s[i].laptopSerialNum = lap.top();
    //    //lap.pop();
    //    //cout << "\t" << s[i].laptopSerialNum << endl;
    //}
}

void assignTA(ifstream& inputFile, int totalTAs, int totalStudents)
{
    string time;
    ta = ta.availableTA(teachersArray, i, totalTAs);
    time = t.convertTime(ta.startTimes[i]);
    cout << "\n" << time << "\t" << ta.name << " has begun lab hours." << endl;
    if (ta.startTimes[i] < ta.endTimes[i])
    {
        getStudents(inputFile, totalStudents);
    }
    else
    {
        cout << "\n\nTA not Available" << endl;
    }
}

void studentData()
{
    Students stu;
    while (!q.empty())
    {
        stu = q.front();
        q.pop();
        if (q1.empty())
        {
            q1.push(stu);
        }
        else
        {
            if (q.front().enterTime > q1.front().enterTime)
            {
                q1.push(stu);
            }
        }
        stu = q1.front();
        q1.pop();
        int intTime;
        ta.studentWithTA = stu;
        time = t.convertTime(stu.enterTime);
        cout << time << "\t" << stu.firstName << " " << stu.lastName << " has arrived in TA#007." << endl;
        if (lap.empty())
        {
            cout << "\nLaptop Stack Empty" << endl;
            break;
        }
        else
        {
            stu.laptopSerialNum = issueLaptop();
            intTime = timeToGetLaptop(stu.enterTime);
            time = t.convertTime(intTime);
            cout << time << "\t" << stu.firstName << " " << stu.lastName << " has borrowed laptop " << stu.laptopSerialNum << " and moved to the TA line." << endl;
            if (intTime < q.front().enterTime)
            {
                cout << time << "\t" << stu.firstName << " " << stu.lastName << " is getting help from " << ta.name << "." << endl;
                intTime = t.timeToGetAnswer(intTime);
                if (intTime < q.front().enterTime)
                {
                    time = t.convertTime(intTime);
                    cout << time << "\t" << stu.firstName << " " << stu.lastName << " has had one question answeredand gotten back in line." << endl;
                    stu.numQuestions--;
                    if (stu.numQuestions > 0)
                    {
                        stu.enterTime = intTime;
                        q1.push(stu);
                    }
                    else
                    {
                        cout << time << "\t" << stu.firstName << " " << stu.lastName << " has all questions answered." << endl;
                    }
                }
                else
                {
                    studentData();
                }
            }
            else
            {
                studentData();
            }
        }
    }
}

















    /*int intTime;
    ta.studentWithTA = stu;
    time = t.convertTime(stu.enterTime);
    cout << time << "\t" << stu.firstName << " " << stu.lastName << " has arrived in TA#007." << endl;
    if (lap.empty())
    {
        cout << "\n\n\n\nLaptop Stack Empty" << endl;
    }
    else
    {
        stu.laptopSerialNum = issueLaptop();
        intTime = timeToGetLaptop(stu.enterTime);
        time = t.convertTime(intTime);
        cout << time << "\t" << stu.firstName << " " << stu.lastName << " has borrowed laptop " << stu.laptopSerialNum << " and moved to the TA line." << endl;
        cout << time << "\t" << stu.firstName << " " << stu.lastName << " is getting help from " << ta.name << "." << endl;
        if (intTime < q.front().enterTime)
        {
            intTime = t.timeToGetAnswer(intTime);
            if (intTime < q.front().enterTime)
            {
                time = t.convertTime(intTime);
                cout << time << "\t" << stu.firstName << " " << stu.lastName << " has had one question answeredand gotten back in line." << endl;
            }
            else
            {
                studentData(q.front());
                q.pop();
            }
        }
    }*/




        /*if (stu.numQuestions != 0)
        {
            intTime = t.timeToGetAnswer(intTime);
            cout << time << "\t" << stu.firstName << " " << stu.lastName << " is getting help from " << ta.name << "." << endl;
            time = t.convertTime(intTime);
            cout << time << "\t" << stu.firstName << " " << stu.lastName << " has had one question answeredand gotten back in line." << endl;
            stu.numQuestions--;
            stu.numAnswered++;
            if (intTime < stu.enterTime)
            {
                q.push(stu);
            }
            else
            {
                q.push(stu);
            }
        }
        else
        {
            cout<<" ";
        }
    }
    time = t.convertTime((stu.enterTime + 5));*/


