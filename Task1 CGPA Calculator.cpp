#include <iostream>
#include <vector>

using namespace std;

// Function to calculate GPA for a single semester
double calculateGPA(vector<double> grades, vector<int> credits) {
    double totalPoints = 0, totalCredits = 0;
    for (size_t i = 0; i < grades.size(); i++) {
        totalPoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    return totalCredits == 0 ? 0 : totalPoints / totalCredits;
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;
    
    double cumulativePoints = 0, cumulativeCredits = 0;
    
    for (int sem = 1; sem <= numSemesters; sem++) {
        int numCourses;
        cout << "\nEnter the number of courses for semester " << sem << ": ";
        cin >> numCourses;
        
        vector<double> grades(numCourses);
        vector<int> credits(numCourses);
        
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter grade points (0-4) for course " << i + 1 << ": ";
            cin >> grades[i];
            cout << "Enter credit hours for course " << i + 1 << ": ";
            cin >> credits[i];
        }
        
        double gpa = calculateGPA(grades, credits);
        cout << "GPA for semester " << sem << ": " << gpa << endl;
        
        // Update cumulative values
        for (int i = 0; i < numCourses; i++) {
            cumulativePoints += grades[i] * credits[i];
            cumulativeCredits += credits[i];
        }
    }
    
    double cgpa = cumulativeCredits == 0 ? 0 : cumulativePoints / cumulativeCredits;
    cout << "\nFinal CGPA: " << cgpa << endl;
    
    return 0;
}

