Modified code
#include <iostream> 
#include <vector> 
#include <string> 
Using namespace std; 
 
Int main() 
{ 
    Int n, e; 
 
    Cout << “Enter number of courses: “; 
    Cin >> n; 
 
    Vector<string> course(n); 
    Vector<vector<int>> adj(n); 
    Vector<int> indegree(n, 0); 
 
    For (int i = 0; i < n; i++) 
    { 
        Cout << “Enter course name: “; 
        Cin >> course[i]; 
    } 
 
    Cout << “Enter number of prerequisite links: “; 
    Cin >> e; 
 
    For (int i = 0; i < e; i++) 
    { 
        String from, to; 
        Int u = -1, v = -1; 
 
        Cout << “Enter course and linked course: “; 
        Cin >> from >> to; 
 
        For (int j = 0; j < n; j++) 
        { 
            If (course[j] == from) 
                U = j; 
 
            If (course[j] == to) 
                V = j; 
        } 
 
        If (u != -1 && v != -1) 
        { 
            Adj[u].push_back(v); 
            Indegree[v]++; 
        } 
        Else 
        { 
            Cout << “Invalid course name!\n”; 
        } 
    } 
 
    Cout << “\nCourse Adjacency List:\n”; 
 
    For (int i = 0; i < n; i++) 
    { 
        Cout << course[i] << “ -> “; 
 
        For (int j : adj[i]) 
            Cout << course[j] << “ “; 
 
        Cout << endl; 
    } 
 
    Cout << “\nIn-degree and Out-degree:\n”; 
 
    For (int i = 0; i < n; i++) 
    { 
        Cout << course[i] 
             << “ : In-degree = “ << indegree[i] 
             << “, Out-degree = “ << adj[i].size() 
             << endl; 
    } 
 
    String selected; 
    Cout << “\nEnter course to display linked courses: “; 
    Cin >> selected; 
 
    Int index = -1; 
 
    For (int i = 0; i < n; i++) 
    { 
        If (course[i] == selected) 
            Index = i; 
    } 
 
    If (index != -1) 
    { 
        Cout << “Directly linked courses of “ 
             << selected << “: “; 
 
        If (adj[index].empty()) 
            Cout << “None”; 
 
        For (int j : adj[index]) 
            Cout << course[j] << “ “; 
    } 
    Else 
    { 
        Cout << “Course not found!”; 
    } 
 
    Cout << endl; 
    Return 0; 
}

output
Course Adjacency List:
C -> CPP
CPP -> DSA DBMS
DSA ->
DBMS ->

In-degree and Out-degree:
C : In-degree = 0, Out-degree = 1
CPP : In-degree = 1, Out-degree = 2
DSA : In-degree = 1, Out-degree = 0
DBMS : In-degree = 1, Out-degree = 0

Directly linked courses of CPP: DSA DBMS
