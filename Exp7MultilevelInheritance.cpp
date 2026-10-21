#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int roll;
    string name; // Using std::string instead of char array to avoid compilation/input issues

public:
    void getdata() {
        cout << "\n -----------------------------------------";
        cout << "\n Enter Roll No. : ";
        cin >> roll;
        cout << " Enter Student Name : ";
        cin.ignore(); // Clears input buffer before reading a string
        getline(cin, name); // Allows names with spaces
    }

    void putdata() {
        cout << "\n -----------------------------------------";
        cout << "\n ********** Student Marklist **********";
        cout << "\n -----------------------------------------";
        cout << "\n Roll No. : " << roll;
        cout << "\n Student Name : " << name << endl;
    }
};

// Class StudentExam derived from Class Student
class StudentExam : public Student {
public:
    int sub1, sub2, sub3, sub4, sub5, sub6;
    float per;

    void accept_data() {
        getdata();
        cout << " Enter Marks for Subject 1 : "; cin >> sub1;
        cout << " Enter Marks for Subject 2 : "; cin >> sub2;
        cout << " Enter Marks for Subject 3 : "; cin >> sub3;
        cout << " Enter Marks for Subject 4 : "; cin >> sub4;
        cout << " Enter Marks for Subject 5 : "; cin >> sub5;
        cout << " Enter Marks for Subject 6 : "; cin >> sub6;
    }

    void display_data() {
        putdata();
        cout << " Marks of Subject 1 : " << sub1 << endl;
        cout << " Marks of Subject 2 : " << sub2 << endl;
        cout << " Marks of Subject 3 : " << sub3 << endl;
        cout << " Marks of Subject 4 : " << sub4 << endl;
        cout << " Marks of Subject 5 : " << sub5 << endl;
        cout << " Marks of Subject 6 : " << sub6 << endl;
    }
};

// Class StudentResult derived from Class StudentExam
class StudentResult : public StudentExam {
public:
    void calculate() {
        per = (sub1 + sub2 + sub3 + sub4 + sub5 + sub6) / 6.0;
        cout << " Total Percentage : " << per << "%";
        cout << "\n ----------------------------------------- \n";
    }
};

int main() {
    int cnt, i;
    cout << "\n Enter No. of Students You Want? : ";
    cin >> cnt;

    // Use an array of objects to correctly handle multi-student tracking
    StudentResult* str = new StudentResult[cnt];

    for(i = 0; i < cnt; i++) {
        cout << "\n--- Entering Details for Student " << (i + 1) << " ---";
        str[i].accept_data();
    }

    for(i = 0; i < cnt; i++) {
        str[i].display_data();
        str[i].calculate();
    }

    delete[] str; // Free allocated memory
    return 0;
}
