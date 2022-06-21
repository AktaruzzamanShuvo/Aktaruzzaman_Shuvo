#include<iostream>
#include<vector>

using namespace std;

//This is a class to store Subject Information
class Subject
{
public:
    string subject_name;
    string Subject_Code;
    vector<double> quiz_marks;
    float final_marks;
    double term_final_marks;

    Subject()
    {
        final_marks = 0;
    }
   ~Subject()
    {
    //destructor is created because destructor is created above
    }

    // Subject Name, Quiz Calculation
    double subject_info()
    {
        cout<<"Enter Subject Name :";
        cin >> subject_name;

        cout<<"Enter Subject Code :";
        cin >> Subject_Code;

        float no_of_quiz, quiz_mark;
        cout<<"Enter No of Quiz :";
        cin >> no_of_quiz;

        for (int i = 0; i < no_of_quiz; i++)
        {
            cout<<"Mark for "<<subject_name<<" Quiz "<<i+1<<" : ";
            cin >> quiz_mark;
            quiz_marks.push_back(quiz_mark);
            final_marks += quiz_mark/(no_of_quiz);
        }
        cout<<"Enter term final marks:";
        cin>>term_final_marks;
//            print_marks();
        return final_marks;
    }

    void print_marks()
    {
        cout << "Subject Name : " << subject_name << endl;
        cout << "Subject Code : " << Subject_Code << endl;
        cout << "=== QUIZ MARKS of " << subject_name << "===" << endl;
        for (int i = 0; i < quiz_marks.size(); i++)
        {
            cout<<"Quiz"<<i + 1<<":"<< quiz_marks[i]<<"  ";
        }
        cout << endl;
        cout << "Term final marks: "<<term_final_marks<< endl;
        cout << "Total Marks from Course " << subject_name << " is : " << final_marks+term_final_marks << endl;
        cout << endl;

    }


};


class Student
{
    // Conatins:
    //Student Name
    // Roll Number
    //Subject Name
public:
    string student_name;
    int roll_number;


public:
    void set_student_name()
    {
        cout<<"Enter Student Name :";
        getline(cin, student_name);

    }

    void set_student_roll()
    {
        cout<<"Enter Student Roll Number :";
        cin >> roll_number;

    }

    string get_student_name()
    {
        return student_name;

    }

    int get_student_roll()
    {
        return roll_number;
    }


};


//derived class (Inherited from Student Class)
class StudentDemo : public Student
{
    Subject *course;
    int no_of_subject;


public:
    //Constructor
    StudentDemo()
    {

        no_of_subject = 0;


        //Inherited Methods from Student Class
        set_student_name();
        set_student_roll();
        get_subject_info();
    };
 ~StudentDemo()
 {
 //destructor is created because destructor is created above
 }
    void get_subject_info()
    {
        cout<<"Enter the Number of Subject: ";

        cin >> no_of_subject;
        course = new Subject[no_of_subject];

        for (int i = 0; i < no_of_subject; i++)
        {
           course[i].subject_info();
        }

        printAll();
    }

    void printAll()
    {
        cout<<" \t *********Marks Sheet********** ";
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << "Student Name : " << get_student_name() << endl;
        cout << "Roll : " << get_student_roll() << endl;
        cout << endl;

        for (int i = 0; i < no_of_subject; i++)
        {
            course[i].print_marks();
        }
    }



};


int main()
{
    StudentDemo *Marksheet = new StudentDemo();

     delete Marksheet;


}
