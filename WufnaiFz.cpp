#include<bits/stdc++.h>
using namespace std;

class abstractEmployee /// Abstraction
{
    virtual bool validForIncrement()= 0;
};

class employee: abstractEmployee /// Parent/Super class
{
protected:

    string name, email, birthDate;
    long long id;
    int salary, transactionBill, transportationBill, childrenEducation, rentBill;

public:

    employee(string _name, string _email, string _birthDate, long long _id, int _salary, int _transactionBill, int _transportationBill, int _childrenEducation, int _rentBill)
    {
        name= _name;
        email= _email;
        birthDate= _birthDate;
        id= _id;
        salary= _salary;
        transactionBill= _transactionBill;
        transportationBill= _transportationBill;
        childrenEducation= _childrenEducation;
        rentBill= _rentBill;
    }

    void showInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Birth date: "<<birthDate<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"TransactionBill: "<<transactionBill<<endl;
        cout<<"TransportationBill: "<<transportationBill<<endl;
        cout<<"ChildrenEducation: "<<childrenEducation<<endl;
        cout<<"RentBill: "<<rentBill<<endl;
    }

    void setSalary(int newSalary)
    {
        salary= newSalary;
    }

    int getSalary()
    {
        return salary;
    }

    /// Age calculator
    int findAge(int current_date, int current_month, int current_year, int birth_date, int birth_month, int birth_year)
    {
        int month[]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if(birth_date>current_date)
        {
            current_date= current_date + month[birth_month - 1];
            current_month= current_month - 1;
        }

        if (birth_month>current_month)
        {
            current_year= current_year - 1;
            current_month= current_month + 12;
        }

        return current_year - birth_year;
    }

    bool validForIncrement() /// Valid for increment if age is over 30
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int current_year= 1900 + ltm->tm_year;
        int current_month= 1 + ltm->tm_mon;
        int current_date= ltm->tm_mday;

        int birth_date= 0, birth_month= 0, birth_year= 0;

        for(int i=0; ; i++)
        {
            if(birthDate[i]!='/')birth_date= birth_date*10+(birthDate[i]-'0');
            else
            {
                for(int j=i+1; ; j++)
                {
                    if(birthDate[j]!='/')birth_month= birth_month*10+(birthDate[j]-'0');
                    else
                    {
                        for(int k=j+1; k<birthDate.size(); k++)
                        birth_year= birth_year*10+(birthDate[k]-'0');

                        break;
                    }
                }

                break;
            }
        }

        int age= findAge(current_date, current_month, current_year, birth_date, birth_month, birth_year);
        return age>=30;
    }

};

class developer: public employee /// Child/Sub class
{
public:

    string workingEnd;

    developer(string _name, string _email, string _birthDate, long long _id, int _salary, int _transactionBill, int _transportationBill, int _childrenEducation, int _rentBill, string _workingEnd)
    :employee(_name, _email, _birthDate, _id, _salary, _transactionBill, _transportationBill, _childrenEducation, _rentBill)
    {
        workingEnd= _workingEnd; /// Front end OR Back end
    }

    void function()
    {
        cout<<"My job is to:\n";
        cout<<"Reviewing the product code throughout the development lifecycle\n";
        cout<<"Taking part in the planning and design processes\n";
        cout<<"Being an advocate for the customer by ensuring that the product meets customer expectations\n";
        cout<<"Developing test tools that help testers\n";
        cout<<"Performing performance, functional, and regression testing\n";
        cout<<"Ensuring that the product is robust, reliable and scalable\n";
        cout<<"Preparing extensive test reports\n";
    }

};

class sqa: public employee /// Child/Sub class
{
public:

    sqa(string _name, string _email, string _birthDate, long long _id, int _salary, int _transactionBill, int _transportationBill, int _childrenEducation, int _rentBill)
    :employee(_name, _email, _birthDate, _id, _salary, _transactionBill, _transportationBill, _childrenEducation, _rentBill)
    {

    }

    void function()
    {
        cout<<"My job is to:\n";
        cout<<"Planing the testing process\n";
        cout<<"Allocating tests to various testers\n";
        cout<<"Deciding the testing schedule and the test budget\n";
        cout<<"Interacting with the development team to ensure that the testing is on track\n";
        cout<<"Creating reports that summarize the test results for the development team\n";
        cout<<"Creating test cases and test scenarios\n";
        cout<<"Reviewing the test to ensure that all the customer requirements are being met\n";
    }

};

int main()
{
    string name, email, birthDate, workingEnd;
    long long id;
    int salary, transactionBill, transportationBill, childrenEducation, rentBill;

    cout<<"Creating a developer:\n";
    cout<<"Name: ";cin>>name;
    cout<<"Email: ";cin>>email;
    cout<<"Birth date(d/m/y): ";cin>>birthDate;
    cout<<"ID: ";cin>>id;
    cout<<"Salary(per month): ";cin>>salary;
    cout<<"Transaction Bill: ";cin>>transactionBill;
    cout<<"Transportation Bill: ";cin>>transportationBill;
    cout<<"Children Education Fee: ";cin>>childrenEducation;
    cout<<"Rent Bill: ";cin>>rentBill;
    cout<<"Working end: ";cin>>workingEnd;
    developer d= developer(name, email, birthDate, id, salary, transactionBill, transportationBill, childrenEducation, rentBill, workingEnd);

    cout<<"\n";
    cout<<"\n";

    cout<<"Creating a sqa:\n";
    cout<<"Name: ";cin>>name;
    cout<<"Email: ";cin>>email;
    cout<<"Birth date(d/m/y): ";cin>>birthDate;
    cout<<"ID: ";cin>>id;
    cout<<"Salary(per month): ";cin>>salary;
    cout<<"Transaction Bill: ";cin>>transactionBill;
    cout<<"Transportation Bill: ";cin>>transportationBill;
    cout<<"Children Education Fee: ";cin>>childrenEducation;
    cout<<"Rent Bill: ";cin>>rentBill;
    sqa s= sqa(name, email, birthDate, id, salary, transactionBill, transportationBill, childrenEducation, rentBill);

    cout<<"\n";
    cout<<"\n";

    cout<<"Showing info of developer:\n";
    d.showInfo();
    d.function();
    cout<<"Working end: "<<d.workingEnd<<endl;
    cout<<"Can get increment? : ";
    if(d.validForIncrement())cout<<"yes!\n";
    else cout<<"no!\n";

    cout<<"\n";
    cout<<"\n";

    cout<<"Showing info of sqa:\n";
    s.showInfo();
    s.function();
    cout<<"Can get increment? : ";
    if(s.validForIncrement())cout<<"yes!\n";
    else cout<<"no!\n";

    return 0;
}
