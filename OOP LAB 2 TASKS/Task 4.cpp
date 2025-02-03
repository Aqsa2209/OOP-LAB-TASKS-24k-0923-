#include<iostream>
#include<string>
using namespace std;
struct Employee{
	int employee_id;
	string name;
	double salary;
};
struct Organisation{
	string organisation_name;
	string organisation_number;
	Employee emp;
};
int main(int argc, char *argv[]){
	if(argc < 6)
{
	cout<< "Usage: " << argv[0] << "<organisation_name> <organisation_number> <employee_id> <employee_name> <employee_salary>" <<endl;
	return 1;
} 
    Organisation org;
    org.organisation_name= argv[1];
    org.organisation_number= argv[2];
    org.emp.employee_id= stoi(argv[3]);
    org.emp.name= argv[4];
    org.emp.salary=stod(argv[5]);
    
    cout << "The size of structure organisation : " << sizeof(org) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;

    return 0;
}
