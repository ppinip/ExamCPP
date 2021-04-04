#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double salary;
public:
    Employee(string name, double salary)
        : name(name), salary(salary) {}
    
    void RaiseSalary(double percent) {
        salary = salary + (salary * percent);
    }
    string GetName() const {
        return name;
    }
    double GetSalary() const {
        return salary;
    }
};

class Company {
private:
    string name;
    Employee **employees;
    int emp_size;
public:
    Company(string name) : name(name) {
        employees = new Employee*[5];
        emp_size = 0;
    }
    void AddEmployee(Employee *employee) {
        if (emp_size < 5)
            employees[emp_size++] = employee;
    }
    void RaiseAll(double percent) {
        int i;
        for (i = 0; i < emp_size; i++) {
            employees[i]->RaiseSalary(percent);
        }
    }
    double GetTotalSalary() const {
        double total = 0;
        int i;
        for (i = 0; i < emp_size; i++) {
            total += employees[i]->GetSalary();
        }
        return total;
    }
};

int main() {
    Company *ku = new Company("KU");

    Employee *usa = new Employee("Usa", 15000);
    Employee *chakrit = new Employee("Chakrit", 20000);

    ku->AddEmployee(usa);
    ku->AddEmployee(chakrit);

    cout << "Total Salary: " << ku->GetTotalSalary() << endl;

    ku->RaiseAll(0.1);

    cout << "Usa's new Salary: " << usa->GetSalary() << endl;
    cout << "Chakrit's new Salary: " << chakrit->GetSalary() << endl;
}