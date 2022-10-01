
#include <iostream>
#include <fstream>
#include "person.h"
#include "client.h"
#include "admin.h"
#include "employee.h"
#include "fileManager.h"
using namespace std;



int main() {
	Client s("karim", "khaled2323", 10, 5000);
	Employee z("karimzz", "khaled2231", 60, 10000);
	z.Addclient(s);	
	z.editclient("ahmed", "mohamed12", 100, 15000);
	z.listclient();

}