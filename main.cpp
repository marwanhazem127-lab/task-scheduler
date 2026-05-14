#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct task {
	string name;
	int priority;
};
struct compare {
	bool operator()(const task& a, const task& b) {
		return a.priority < b.priority;
	}
};
priority_queue<task, vector<task>, compare> pq;
void addtask() {
	task t;
	cout << "enter task name"<<endl;
	getline(cin >> ws, t.name);
	cout << "enter task priority between 1 and 10"<<endl;
	cin >> t.priority;
	while (t.priority<1 || t.priority>10) {
		cout << "invalid priority\n"<<"enter another number";
		cin >> t.priority;
	}
	pq.push(t);
	cout << "Task Entered Successfuly"<<endl;
	cout << "==========done our beloved user==========="<<endl;
	cout << endl;
}

void showtasks() {
	if (pq.empty()) {
		cout << "There are no tasks\n";
		return;
	}
	priority_queue<task, vector<task>, compare> copy = pq;
	int n = 1;
	while (!copy.empty()) {
		cout << n << ") Name: " << copy.top().name << " and priority= " << copy.top().priority << endl;
		copy.pop();
		++n;
	}
	cout << "==========done our beloved user===========" << endl;
	cout << endl;
}

void excutetask() {
	if (pq.empty()) {
		cout << "There are no tasks\n";
		return;
	}
	task now;
	now = pq.top();
	cout << "the task: " << now.name << " = " << now.priority << endl;
	cout << "==========excuted successfuly===========";
	pq.pop();
	cout << endl;
	
}

int main(){
	int choise;
	cout << "Welcome to the Task Scheduler\n";
	do {
		cout << "Choose from the following:\n";
		cout << "1) Add task\n" << "2) Show tasks\n" << "3) excute highest priority task\n" << "4) Exit" << endl;

		cin >> choise;
		switch (choise) {
		case 1:
			addtask();
			break;
		case 2:
			showtasks();
			break;
		case 3:
			excutetask();
			break;
		case 4:
			cout << "exit....";
			break;
		default:
			cout << "invalid value" << endl;
		}
	}
		while (choise != 4);


	return 0;
}