#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include <string>
#include "Employee.h"
using namespace std;

class HourlyWorker : public Employee
{
public:
	HourlyWorker(const string&, const string&, const string&, double = 0.0, double = 0.0);
	virtual ~HourlyWorker() = default;

	void setHours(double);
	double getHours() const;
	
	void setOverTime(double);
	double getOverTime() const;

	void setWage(double);
	double getWage() const;

	virtual double earnings() const override;
	virtual string toString() const override;

private:
	double wage;
	double hours;
	double overtime;
};

#endif