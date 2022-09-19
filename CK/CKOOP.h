#pragma once
#include <bits/stdc++.h>

using namespace std;

struct Date
{
    int day, month, year;
};
class Normal_Run
{
protected:
    char name[30];
    Date date;
    char location[40];
    int distance;
    int fees;

public:
    Normal_Run();
    Normal_Run(char name[], int day, int month, int year, char location[], int distance, int fees);
    virtual void set();
    virtual void get();
    friend class List;
};
class Non_Competitive : public Normal_Run
{
public:
    Non_Competitive();
    Non_Competitive(char name[], int day, int month, int year, char location[], int distance);
    void set();
    void get();
    friend class List;
};
class Trail : public Normal_Run
{
public:
    Trail();
    Trail(char name[], int day, int month, int year, char location[], int distance, int fees);
    void set();
    void get();
    friend class List;
};
class List
{
    int numberOfRunning;
    Normal_Run *listOfRunning[100];

public:
    List();
    List(int numberOfRunning);
    void setList();
    void getList();
    void Solution();
};