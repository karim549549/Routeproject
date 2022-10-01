
#pragma once
#include <iostream>
#include<vector>
#include "person.h"
using namespace std;


class Employee : public Person {
protected:
	double salary;
public:
	Employee() {
	}
	Employee(string name, string password, int id, double salary) :Person(name, password, id) {
		setSalary(salary);
	}
	//setter & getter
	void setSalary(double salary) {
		if (Validate::validateSalary(salary))
			this->salary = salary;
		else {
			cout << "Enter a new salary: ";
			double s;
			cin >> s;
			setSalary(s);
		}
	}
	double getSalary() {
		return salary;
	}
	//other functionalities
	/*Client addClient() {
		Client c;
		return c;
	}*/
	void display() {
		Person::display();
		cout << "Salary: " << getSalary();
	}
	void Addclient(Client s){
		ofstream clientFile;
		clientFile.open("clients.txt", fstream::app);
		clientFile << s.getName() << " " << s.getID() << " " << s.getBalance() << " " << s.getPassword() << endl;
		clientFile.close();
	}
	Client searchclient(int id) {
		ifstream clientFile;
		clientFile.open("clients.txt");
		string name;
		string pass;
		int oldid;
		double balance;
		Client returns;
		while (clientFile >>name>> pass >>oldid >>balance)
		{
			if (oldid == id) {
				returns.setName(name);
				returns.setPassword(pass);
				returns.setID(id);
				returns.setBalance(balance);
				return returns;
			}
		}
	}
	void listclient() {
		vector<Client>allClients;
		ifstream clientFiles("clients.txt");
		string name, password;
		double balance;
		int id;
		while (clientFiles >> name >> id >> balance >> password) {
			Client c(name, password, id, balance);
			allClients.push_back(c);
		}
		for (int i = 0;i < allClients.size(); i++) {
			Client s = allClients[i];
			cout << s.getName() << ' ' << s.getID() << ' ' << s.getPassword() << ' ' << s.getBalance() << endl;
		}
	}
	void editclient(string name, string pass, int id, double balance) {
		cout << "Enter The id Of The Client";
		int oldid;
		cin >> oldid;
		Client edit= searchclient(oldid);
		edit.setName(name);
		edit.setPassword(pass);
		edit.setID(id);
		edit.setBalance(balance);
	}

};