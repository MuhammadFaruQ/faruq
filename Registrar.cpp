#include <iostream>
#include <fstream>
using namespace std;
class BatchAdvisor
{
public:
    string a,b;
    string name,gpa,fee,batch,dep,roll;
    string S1,S2,S3,S4;
public:
 void login()
    {
        cout<<"Hey you need to enter the Username(admin): ";
        cin>>a;
        cout<<"Hey you need to enter the Password(admin): ";
        cin>>b;
        if((a=="admin" && b=="admin")||(a=="abc" && b=="abc"))
        {
            cout<<"Hey that's right.\n";cout << "\nAvailable operations: \n1. Enter Students Record(Batch Advisor Only!)\n2. View Registered Students(Batch Advisor Only!)\n3. View Fee Defaulters(Batch Advisor Only!)\n4. Search Students if they're registered(Batch Advisor Only!)\n5. View Offered Courses\n6. View Registered courses, Fee and CGPA\n7. Exit\nEnter option: ";
        }
        else
        {
            cout<<"Invalid!!! Sorry you Can't be proceed further.";
            exit(0);
        }
    }
    void viewregistered_students()
    {
        cout<<"List of Registered Students: "<<endl;
        ifstream ip("text.txt");
        while(ip.good())
        {
            getline(ip,name,',');
            getline(ip,roll,',');
            getline(ip,gpa,',');
            getline(ip,fee,',');
            getline(ip,batch,',');
            getline(ip,dep,',');
            getline(ip,S1,',');
            getline(ip,S2,',');
            getline(ip,S3,',');
            getline(ip,S4,'\n');
            cout<<"---------------------------------\n";
            cout<< "Name: "<<name<<'\n';
            cout<< "Roll Number: "<<roll<<'\n';
        }
    }
    void viewFeeDefaulters()
    {
        cout<<"List of Fee Defaulters: "<<endl;
        ifstream ip("text.txt");
        while(ip.good())
        {
            getline(ip,name,',');
            getline(ip,roll,',');
            getline(ip,gpa,',');
            getline(ip,fee,',');
            getline(ip,batch,',');
            getline(ip,dep,',');
            getline(ip,S1,',');
            getline(ip,S2,',');
            getline(ip,S3,',');
            getline(ip,S4,'\n');
            cout<<"---------------------------------\n";
            if(fee=="no" || fee=="No" || fee=="NO")
            { cout<< "Name: "<<name<<'\n';
                cout<< "Roll Number: "<<roll<<'\n';}
        }
    }
    void courses()
    {
        ofstream outfile;
        outfile.open("text.txt",ios::app);
        cout << "Enter Student's Name: ";
        cin >> name;
        outfile <<"\n"<< name << ",";
        cout << "Enter Student's Roll Number: ";
        cin >> roll;
        outfile << roll << ",";
        cout << "Enter Student's GPA: ";
        cin >> gpa;
        outfile << gpa << ",";
        cout << "Fee is Cleared???: ";
        cin >> fee;
        outfile << fee<<",";
        cout<<"Enter Student's Batch: ";
        cin>>batch;
        outfile<<batch<< ",";
        cout<<"Enter Student's Department: ";
        cin>>dep;
        outfile<<dep<< ",";
        if(batch=="11" && dep=="CS")
        {
            cout<<"Enter Student's Grade in Introduction to Computing: ";
            cin>>S1;
            outfile<<S1<< ",";
            cout<<"Enter Student's Grade in Islamic Studies I: ";
            cin>>S2;
            outfile<<S2<< ",";
            cout<<"Enter Student's Grade in Calculus I: ";
            cin>>S3;
            outfile<<S3<< ",";
            cout<<"Enter Student's Grade in Writing Workshop: ";
            cin>>S4;
            outfile<<S4;
        }
        if(batch=="11" && dep=="SE")
        {
            cout<<"Enter your Student's in English I: ";
            cin>>S1;
            outfile<<S1<< ",";
            cout<<"Enter your Student's in Communication Skills: ";
            cin>>S2;
            outfile<<S2<< ",";
            cout<<"Enter your Student's in Applied Mechanics: ";
            cin>>S3;
            outfile<<S3<< ",";
            cout<<"Enter your Student's in Linear Algebra: ";
            cin>>S4;
            outfile<<S4;
        }
    }
    void search()
    {
        string search;
        int offset = 0;
        string line;
        int i=0;
        ifstream myfile;
        myfile.open("text.txt");
        cout<<"Enter Name Or ID: "<<endl;
        cin>>search;
        if(myfile.is_open())
        {
            while(!myfile.eof())
            {
                getline(myfile,line);
                if((offset=line.find(search, 0))!=string ::npos)
                {
                    cout<<"This Student is registered!!!"<<endl;
                    i=1;
                }
            }
            if(i!=1)
                cout<<"This Student is not registered!!!"<<endl;
            myfile.close();
        }
        else
            cout<<"Could not open file "<<endl;
    }
};
class Student
{
public:
    string name,gpa,fee,batch,dep,roll;
    string S1,S2,S3,S4;
public:
    void viewcourse_offered()
    {
        cout<< "Enter your Batch : ";
        cin>>batch;
        cout<<"Enter your Department: ";
        cin>>dep;
                if(batch=="11" && dep=="CS")
                {cout<<"\n---------------------------------";
                    cout<<"\nYou can Take these courses: \n* Programming Fundamentals\n* Calculus II\n* Electricity and Magnetism\n* Chemistry for Engineers"<<endl;}
                else if(batch=="11" && dep=="SE")
                {cout<<"\n---------------------------------";
                    cout<<"\nYou can Take these courses: \n* English II\n* Software Construction\n* Probability and Statistics\n* Data structures and Algorithms"<<endl;}
                else
                    cout<<"Wrong input!!"<<endl;
        }
    void registercourses()
    {
        ifstream ip("text.txt");
        while(ip.good())
        {
            getline(ip,name,',');
            getline(ip,roll,',');
            getline(ip,gpa,',');
            getline(ip,fee,',');
            getline(ip,batch,',');
            getline(ip,dep,',');
            getline(ip,S1,',');
            getline(ip,S2,',');
            getline(ip,S3,',');
            getline(ip,S4,'\n');
            cout<<"\n\n---------------------------------\n";
            cout<< "Name: "<<name<<'\n';
            cout<< "Roll Number: "<<roll<<'\n';
            cout<< "GPA: "<<gpa<<'\n';
            if(gpa <="1.75" && gpa>="0"){cout<<"You can take 6 credit hours course.\n";}
            if(gpa<"0"){cout<<"Invalid Value.";}
            if(gpa >="2.5" && gpa<="4"){cout<<"You can take 18 credit hours course.\n";}
            if(gpa>"4"){cout<<"Invalid Value.";}
            if(gpa >"1.75" && gpa<"2.5")cout<<"You can take In between 6 & 18 credit hours!!!\n";
            cout<<"---------------------------------\n";
            cout<< "Your Batch is: "<<batch<<" \nDepartment is: "<<dep<<'\n';
            if(fee=="yes" || fee=="YES" || fee=="Yes")
            {
                if(batch=="11" && dep=="CS")
                {
                    
                    if((S1=="A" || S1=="a" || S1=="B" || S1=="b" || S1=="C" || S1=="c" || S1=="D" || S1=="d") &&
                       (S2=="A" || S2=="a" || S2=="B" || S2=="b" || S2=="C" || S2=="c" || S2=="D" || S2=="d")
                       && (S3=="A" || S3=="a" || S3=="B" || S3=="b" || S3=="C" || S3=="c" || S3=="D" || S3=="d") &&
                       (S4=="A" || S4=="a" || S4=="B" || S4=="b" || S4=="C" || S4=="c" || S4=="D" || S4=="d"))
                    {
                        cout<<"\nSince your fee is Cleared. And Passed in Every course. You can Take these courses: \n* Programming Fundamentals\n* Calculus II\n* Electricity and Magnetism\n* Chemistry for Engineers"<<endl;
                    }
                    else
                    {
                        if(S1=="F" || S1=="f")
                        {cout<<"Failed in Introduction to Computing. You Can't take Programming Fundamentals.";}
                        if(S2=="F" || S2=="f" )
                        {cout<<"\nFailed in Islamic Studies. You Can't take Electricity and Magnetism.";}
                        if(S3=="F" || S3=="f" )
                        {cout<<"\nFailed in Calculus I. You Can't take Calculus II";}
                        if(S4=="F" || S4=="f" )
                        {cout<<"\nFailed in Writing Workshop. You Can't take Chemistry for Engineers"<<endl;}
                    }
                    
                    
                }
            }
            else
            {cout<<"This Student is fee defaulter. Can't proceed to registration."<<endl;}
            if(fee=="yes" || fee=="YES" || fee=="Yes")
            {
                if(batch=="11" && dep=="SE")
                {
                    
                    if((S1=="A" || S1=="a" || S1=="B" || S1=="b" || S1=="C" || S1=="c" || S1=="D" || S1=="d") &&
                       (S2=="A" || S2=="a" || S2=="B" || S2=="b" || S2=="C" || S2=="c" || S2=="D" || S2=="d")
                       && (S3=="A" || S3=="a" || S3=="B" || S3=="b" || S3=="C" || S3=="c" || S3=="D" || S3=="d") &&
                       (S4=="A" || S4=="a" || S4=="B" || S4=="b" || S4=="C" || S4=="c" || S4=="D" || S4=="d"))
                    {
                        cout<<"\nSince your fee is Cleared. And Passed in Every course. You can Take these courses: \n* English II\n* Software Construction\n* Probability and Statistics\n* Data structures and Algorithms"<<endl;
                    }
                    else
                    {
                        if(S1=="F" || S1=="f")
                        {cout<<"Failed in English I. You Can't take English II.";}
                        if(S2=="F" || S2=="f" )
                        {cout<<"\nFailed in Communication Skills. You Can't take Software Construction.";}
                        if(S3=="F" || S3=="f" )
                        {cout<<"\nFailed in Applied Mechanics. You Can't take Probability and Statistics.";}
                        if(S4=="F" || S4=="f" )
                        {cout<<"\nFailed in Linear Algebra. You Can't take Data structures and Algorithms."<<endl;}
                    }
                }
            }
        }
    }
    void operations()
    {
        cout << "\nAvailable operations: \n1. Enter Students Record(Batch Advisor Only!)\n2. View Registered Students(Batch Advisor Only!)\n3. View Fee Defaulters(Batch Advisor Only!)\n4. Search Students if they're registered(Batch Advisor Only!)\n5. View Offered Courses\n6. View Registered courses, Fee and CGPA\n7. Exit\nEnter option: ";
    }
};
int main()
{
    BatchAdvisor A;
    Student B;
    A.login();
    while(1)
    {
    int op;
    cin>>op;
    if(op==1)
        A.courses();
    if(op==2)
        A.viewregistered_students();
    if(op==3)
        A.viewFeeDefaulters();
    if(op==4)
        A.search();
    if(op==5)
        B.viewcourse_offered();
    if(op==6)
        B.registercourses();
    if(op==7)
        exit(0);
    B.operations();
    }
}
