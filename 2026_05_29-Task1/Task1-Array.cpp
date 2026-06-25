#include <iostream>
#include <string>
using namespace std;

struct Student{
        int id;
        string name;
        string course;
        int age;
    };

int main(){
    Student student[5] = {
        {24007271,"Reeyan", "IT", 26},
        {24007272, "Lewin", "CS", 20},
        {24007273, "Bob", "IS", 19},
        {24007274, "LeClair", "BM", 21},
        {24007275, "Hamilton", "EE", 23}
    };

    cout << "All Student Information: " << endl;
    for(int i = 0; i < 5; i++){
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Course: " << student[i].course << endl;
        cout << "Age: " << student[i].age << endl;
        cout << endl;
    }

    int searchId;
    cout << "Enter the ID of the student to search: ";
    cin >> searchId;

    int intIndex = -1; // Initialize index to -1 to indicate not found

    for(int i = 0; i<5; i++){
        if(student[i].id == searchId){
            intIndex = i; // Store the index of the found student
            break; // Exit the loop once the student is found
        }
    }
    if(intIndex != -1){
        cout <<endl;
        cout << "Student Found !!! " << endl;
        cout << "ID: " << student[intIndex].id << endl;
        cout << "Name: " << student[intIndex].name << endl;
        cout << "Course: " << student[intIndex].course << endl;
        cout << "Age: " << student[intIndex].age << endl;
        cout << endl;
        cout << "What do you want to change?" << endl;
        cin.ignore(); // Clear the input buffer
        cout << "Enter new name: ";
        cin >> student[intIndex].name;
        cout << "Enter new course: ";
        cin >> student[intIndex].course;
        cout << "Enter new age: ";
        cin >> student[intIndex].age;
        cout << endl;
        cout << "Student Information Updated: " << endl;
        cout << "ID: " << student[intIndex].id << endl;
        cout << "Name: " << student[intIndex].name << endl;
        cout << "Course: " << student[intIndex].course << endl;
        cout << "Age: " << student[intIndex].age << endl;
            
    }
    else{
        cout << "Student with ID " << searchId << " not found." << endl;
        }
    return 0;
    
}