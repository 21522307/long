#include "CKOOP.h"

Normal_Run::Normal_Run()
{
    strcpy(this->name, "");
    this->date.day = 0;
    this->date.month = 0;
    this->date.year = 2020;
    strcpy(this->location, "");
    this->distance = 0;
    this->fees = 0;
}
Normal_Run::Normal_Run(char name[], int day, int month, int year, char location[], int distance, int fees)
{
    strcpy(this->name, name);
    this->date.day = day;
    this->date.month = month;
    this->date.year = year;
    strcpy(this->location, location);
    this->distance = distance;
    this->fees = fees;
}
void Normal_Run::set()
{
    cout << "Input Name: ";
    cin.getline(name, 30);
    cout << "Input Date of Organization :";
    cin >> date.day >> date.month;
    cout << "Input Location: ";
    cin >> location;
    cout << "Input Distance: ";
    cin >> distance;
    cout << "Fee: ";
    cin >> fees;
}
void Normal_Run::get()
{
    cout << "\nName: " << name;
    cout << "\nDate of Organization :" << date.day << "/" << date.month << "/" << date.year;
    cout << "\nLocation: " << location;
    cout << "\nDistance: " << distance;
    cout << "\nFees: " << fees;
}
Non_Competitive::Non_Competitive() : Normal_Run()
{
}
Non_Competitive::Non_Competitive(char name[], int day, int month, int year, char location[], int distance) : Normal_Run(name, day, month, year, location, distance, fees)
{
}
void Non_Competitive::set()
{
    cout << "Input Name: ";
    cin.getline(name, 30);
    cout << "Input Date of Organization :";
    cin >> date.day >> date.month;
    cout << "Input Location: ";
    cin >> location;
    cout << "Input Distance: ";
    cin >> distance;
}
void Non_Competitive::get()
{
    cout << "\nName: " << name;
    cout << "\nDate of Organization :" << date.day << "/" << date.month << "/" << date.year;
    cout << "\nLocation: " << location;
    cout << "\nDistance: " << distance;
}
Trail::Trail() : Normal_Run()
{
}
Trail::Trail(char name[], int day, int month, int year, char location[], int distance, int fees) : Normal_Run(name, day, month, year, location, distance, fees)
{
}
void Trail::set()
{
    Normal_Run::set();
}
void Trail::get()
{
    Normal_Run::get();
}
List::List()
{
    this->numberOfRunning = 0;
}
List::List(int numberOfRunning)
{
    this->numberOfRunning = numberOfRunning;
}
void List::setList()
{
    cout << "\nInput the number of Running Competitive: ";
    cin >> numberOfRunning;
    for (int i = 0; i < numberOfRunning; i++)
    {
        string typeOfRunning;
        cout << "\nInput type of Running Competitive: ";
        cin.ignore();
        getline(cin, typeOfRunning);
        if (!(typeOfRunning.compare("Normal_Run")))
        {
            listOfRunning[i] = new Normal_Run;
            listOfRunning[i]->set();
        }
        else if (!(typeOfRunning.compare("Non_Competitive")))
        {
            listOfRunning[i] = new Non_Competitive;
            listOfRunning[i]->set();
        }
        else if (!(typeOfRunning.compare("Trail")))
        {
            listOfRunning[i] = new Trail;
            listOfRunning[i]->set();
        }
    }
}
void List::getList()
{
    cout << "\nThe list of Running Competitive: ";
    for (int i = 0; i < numberOfRunning; i++)
    {
        listOfRunning[i]->get();
    }
}
void List::Solution()
{
    Normal_Run *s[100];
    int k = 0;
    int n, time = 14, totalFee = 0;
    cout << "Chon so cuoc thi: ";
    cin >> n;
    int check[n] = {1};
    if (n >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            char name1[30];
            cout << "Ten cuoc thi thu" << i;
            cin.getline(name1, 30);
            int culy;
            cout << "Cu ly da len ke hoach: ";
            cin >> culy;
            for (int j = 0; j < numberOfRunning; j++)
            {
                if (!(strcmp(name1, listOfRunning[j]->name)))
                {
                    if (culy == listOfRunning[j]->distance)
                    {
                        time -= listOfRunning[j]->date.day;
                        totalFee += listOfRunning[j]->fees;
                        if (time < 14)
                        {
                            s[k] = listOfRunning[j];
                            k++;
                        }
                    }
                }
                else
                {
                    cout << "\nKhong co ten cuoc thi trong danh sach";
                }
            }
            if (time < 14)
            {
                check[i] = 0;
            }
        }
        cout << "\nTong le phi tham gia ma Runner phai dong: " << totalFee;
        for (int i = 1; i < n; i++)
        {
            if (check[i] == 0)
            {
                cout << "\nCac cuoc thi khong hop le: ";
                for (int i = 0; i < k; i++)
                {
                    cout << s[i]->name;
                    cout << s[i]->date.day << "/" << s[i]->date.month << "/" << s[i]->date.year;
                }
                break;
            }
        }
    }
    else
    {
        cout << "Chon khong du 3 cuoc thi";
    }
}
