#include <iostream>
using namespace std;

/*
 
 my plan
 
 1. hardcode list of processes
 2. enqueue into queue by type of process - user or system processes - by sorting
 3. kira burst time apa semua tu
 4. dequeue system process first pastu user system
 
 */

struct Process
{
    int pid;
    int burstTime;
    int priority;
    int type; // 1 means system process and 0 means user system;
};

struct Node
{
    Process* process;
    Node* next;
    Node* prev;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(Process process_in)
{
    Node* temp = new Node();
    temp -> process = new Process();
    temp -> process -> pid = process_in.pid;
    temp -> process -> burstTime = process_in.burstTime;
    temp -> process -> priority = process_in.priority;
    temp -> process -> type = process_in.type;
    temp -> next = nullptr;
    temp -> prev = nullptr;
    
    if (front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp -> next = front;
        front -> prev = temp;
        front = temp;
    }
}

void dequeue()
{
    if (rear == nullptr)
        cout << "no processes detected" << endl;
    
    else if (front == rear) {
        Node* temp = rear;
        front = nullptr;
        rear = nullptr;
        cout << "the process with pid " << temp -> process -> pid << " was executed" << endl;
        delete temp;
    }
    
    else{
        Node* temp = rear;
        rear = rear -> prev;
        rear -> next = nullptr;
        cout << "the process with pid " << temp -> process -> pid << " was executed" << endl;
        delete temp;
    }
}

void display(Process list[], int n)
{
    cout << "\n\n-----------list of processes-------------\n"<< endl;
    cout << "\tPID\t\tPRIORITY\t PROCESS TYPE" << endl;
    
    for (int i=0; i<n; i++)
    {
        cout << "\t " << list[i].pid << "\t\t\t" << list[i].priority << "\t\t";
        if (list[i].type == 1)
            cout << "System Process" << endl;
        else
            cout << "User Process" << endl;
    }
    
    cout << "\n------------------------------------------\n"<< endl;
}

bool comparison(Process a, Process b)
{
    return (a.priority > b.priority && a.type >= b.type);
}

void priorityScheduling(Process list[], int n)
{
    sort(list, list + n, comparison);
    
    for (int i=0; i<n; i++) {
        enqueue(list[i]);
    }
}

int main()
{
    Process list[] = {{1, 10, 2, 1}, {2, 5, 3, 1}, {3, 8, 1, 1}, {4, 7, 1, 0}, {5, 9, 3, 0}, {6, 6, 2, 0}};
    int n = sizeof list / sizeof list[0];
    
    display(list, n);
    priorityScheduling(list, n);
    
    cout << "Executing processes in order of priority..." << endl;
    while (rear != nullptr) {
        dequeue();
    }
}
