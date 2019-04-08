#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "PieceWorker.h" 
#include "HourlyWorker.h"  
using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main() {
   cout << fixed << setprecision(2);

   PieceWorker pieceWorker{
      "John", "Smith", "111-11-1111", 40, 800};
   HourlyWorker hourlyWorker{
	  "Sue", "Jones", "333-33-3333", 60, 50 };

   cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
	   << pieceWorker.toString()
	   << "\nearned $" << pieceWorker.earnings() << "\n\n"
	   << hourlyWorker.toString()
	   << "\nearned $" << hourlyWorker.earnings() << "\n\n";
     
   vector<Employee *> employees{&pieceWorker, &hourlyWorker};

   cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

   for (const Employee* employeePtr : employees) {
      virtualViaPointer(employeePtr);
   }

   cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

   for (const Employee* employeePtr : employees) {
      virtualViaReference(*employeePtr);
   }
}
             
void virtualViaPointer(const Employee* const baseClassPtr) {
   cout << baseClassPtr->toString()
      << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}
              
void virtualViaReference(const Employee& baseClassRef) {
   cout << baseClassRef.toString()
      << "\nearned $" << baseClassRef.earnings() << "\n\n";
   system("pause");
}
