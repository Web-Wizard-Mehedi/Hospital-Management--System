#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstring>
using namespace std;

struct Patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    string blood;
    char gender;
    Patient *next;
};

class LinkedQueue
{
    Patient *head, *last;

public:
    LinkedQueue(); // constructor
    Patient input();
    void insertAtEnd();
    void insertAtBeg();
    void getPatientOut();
    void listOfPatients();
    void takePatientToDoctor();
    int search(long long);
    char departmentName[50];
};

LinkedQueue::LinkedQueue() // constructor
{
    head = nullptr;
    last = nullptr;
}

int LinkedQueue::search(long long item)
{
    if (head == nullptr)
        return false;
    else
    {
        int flag = 0;
        Patient *p = head;
        while (p->next != nullptr && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
}

int readNumber()
{
    int number;
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

Patient LinkedQueue::input()
{
    int flag = 0;
    Patient *p = new Patient();
    cout << "\n Please enter data for patient\n";
    cout << "\n First name : ";
    getline(cin, p->firstname);
    cout << " Last name : ";
    getline(cin, p->lastname);
again:
    cout << " Blood Group : ";
    cin >> p->blood;
    // Blood group validation
    if (p->blood != "A+" && p->blood != "a+" && p->blood != "A-" && p->blood != "a-" &&
        p->blood != "B+" && p->blood != "b+" && p->blood != "B-" && p->blood != "b-" &&
        p->blood != "O+" && p->blood != "o+" && p->blood != "O-" && p->blood != "o-" &&
        p->blood != "AB+" && p->blood != "ab+" && p->blood != "AB-" && p->blood != "ab-")
    {
        cout << "\n Invalid Blood Group. Try Again.\n\n";
        goto again;
    }

    cout << " Gender (m/f) : ";
    cin >> p->gender;
    cout << " Age : ";
    cin >> p->age;
    cout << " Mobile number : ";
    cin >> p->ID;

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n Data not valid. Operation cancelled.";
    }
    return *p;
}

void output(Patient *p)
{
    cout << "\n ------------------------------------";
    cout << "\n Patient data:\n";
    cout << "\n First Name : " << p->firstname;
    cout << "\n Last Name : " << p->lastname;
    cout << "\n Gender : " << p->gender;
    cout << "\n Age : " << p->age;
    cout << "\n Blood Group : " << p->blood;
    cout << "\n Mobile Number : " << p->ID;
    cout << "\n ------------------------------------";
}

void LinkedQueue::insertAtBeg()
{
    Patient *p = new Patient();
    *p = input();
    if (p->ID == 0)
        return;
    if (head == nullptr)
    {
        head = p;
        last = p;
        p->next = nullptr;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void LinkedQueue::insertAtEnd()
{
    Patient *p = new Patient();
    *p = input();
    if (p->ID == 0)
        return;
    if (head == nullptr)
    {
        head = p;
        last = p;
        p->next = nullptr;
    }
    else
    {
        p->next = nullptr;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n ------------------------------------";
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n ------------------------------------";
    cout << "\n ----------PATIENT ADDED-----------";
    output(p);
}

void LinkedQueue::getPatientOut()
{
    system("cls");
    if (head == nullptr)
    {
        cout << "\n No Patient to operate";
    }
    else
    {
        Patient *p = head;
        head = head->next;
        cout << "\n Patient to operate:";
        output(p);
    }
}

void LinkedQueue::listOfPatients()
{
    if (head == nullptr)
    {
        cout << "\n No patient";
    }
    system("cls");
    cout << "\n ------------------------------------";
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n ------------------------------------";
    Patient *p = head;
    while (p != nullptr)
    {
        cout << "\n Patient data:\n";
        cout << "\n First Name : " << p->firstname;
        cout << "\n Last Name : " << p->lastname;
        cout << "\n Gender : " << p->gender;
        cout << "\n Age : " << p->age;
        cout << "\n Blood Group : " << p->blood;
        cout << "\n Mobile Number : " << p->ID;
        cout << "\n ------------------------------------";
        p = p->next;
    }
    cout << "\n";
}

void LinkedQueue::takePatientToDoctor()
{
    cout << "\n Patient taken to the doctor. The doctor will see the patient's report soon.";
}

void departmentMenu(LinkedQueue *q)
{
    int choice = 0;
    while (choice != 6)
    {
        system("cls");
        cout << "\n ------------------------------------";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n ------------------------------------";
        cout << "\n\n " << q->departmentName;
        cout << "\n [1] Add normal patient\n";
        cout << " [2] Add critically ill patient\n";
        cout << " [3] Take patient to Doctor\n";
        cout << " [4] Display list\n";
        cout << " [5] Change department\n";
        cout << " [6] Exit\n";
        cout << "\n Please enter your choice : ";
        choice = readNumber();
        cout << "\n ------------------------------------";

        switch (choice)
        {
        case 1:
            q->insertAtEnd();
            cout << "\n Press any key";
            cin.get();
            break;
        case 2:
            q->insertAtBeg();
            cout << "\n Press any key";
            cin.get();
            break;
        case 3:
            q->takePatientToDoctor();
            cout << "\n Press any key";
            cin.get();
            break;
        case 4:
            system("cls");
            q->listOfPatients();
            cout << "\n Press any key";
            cin.get();
            break;
        }
    }
}

int main()
{
    int i, choice = 0;
    LinkedQueue departments[4];
    while (choice != 5)
    {
        strcpy(departments[0].departmentName, "GENERAL CLINIC\n");
        strcpy(departments[1].departmentName, "HEART CLINIC\n");
        strcpy(departments[2].departmentName, "LUNG CLINIC\n");
        strcpy(departments[3].departmentName, "PLASTIC SURGERY\n");
        system("cls");
        cout << "\n ------------------------------------";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n ------------------------------------";
        cout << "\n\n Main Menu\n\n";
        for (i = 0; i < 4; i++)
        {
            cout << " " << (i + 1) << ": " << departments[i].departmentName;
        }
        cout << " 5: Exit";
        cout << "\n\n Please enter your choice : ";
        choice = readNumber();
        if (choice >= 1 && choice <= 4)
        {
            departmentMenu(&departments[choice - 1]);
        }
    }
    if (choice == 5)
        cout << "\n\t\tThank you! \n";
    return 0;
}
