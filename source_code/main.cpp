final code
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
 
int main() 
{ 
    int n, e; 
 
    cout << "Enter number of courses: "; 
    cin >> n; 
 
    vector<string> course(n); 
    vector<vector<int>> adj(n); 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << "Enter course name: "; 
        cin >> course[i]; 
    } 
 
    cout << "Enter number of prerequisite links: "; 
    cin >> e; 
 
    for (int i = 0; i < e; i++) 
    { 
        string from, to; 
        int u = -1, v = -1; 
 
        cout << "Enter course and linked course: "; 
        cin >> from >> to; 
 
        for (int j = 0; j < n; j++) 
        { 
            if (course[j] == from) 
                u = j; 
 
            if (course[j] == to) 
                v = j; 
        } 
 
        if (u != -1 && v != -1) 
            adj[u].push_back(v); 
        else 
            cout << "Invalid course name!\n"; 
    } 
 
    cout << "\nCourse Adjacency List:\n"; 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << course[i] << " -> "; 
 
        for (int j : adj[i]) 
            cout << course[j] << " "; 
 
        cout << endl; 
    } 
 
    string selected; 
    cout << "\nEnter course to display linked courses: "; 
    cin >> selected; 
 
    int index = -1; 
 
    for (int i = 0; i < n; i++) 
    { 
        if (course[i] == selected) 
            index = i; 
    } 
 
    if (index != -1) 
    { 
        cout << "Directly linked courses of " 
             << selected << ": "; 
 
        if (adj[index].empty()) 
            cout << "None"; 
 
        for (int j : adj[index]) 
            cout << course[j] << " "; 
} 
else 
{ 
} 
cout << "Course not found!"; 
cout << endl; 
return 0; 
}


output
Enter number of courses: 4
Enter course name: C
Enter course name: Cpp
Enter course name: Java
Enter course name: Python
Enter number of prerequisite links: 3
Enter course and linked course: C Cpp
Enter course and linked course: Cpp Java
Enter course and linked course: Cpp Python

Course Adjacency List:
C -> Cpp
Cpp -> Java Python
Java ->
Python ->

Enter course to display linked courses: Cpp
Directly linked courses of Cpp: Java Python



