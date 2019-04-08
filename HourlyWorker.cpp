#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "HourlyWorker.h"
using namespace std;

HourlyWorker::HourlyWorker(const string& first, const string& last, const string& ssn, double hour, double hwages)
	: Employee(first, last, ssn)
{
	setWage(hwages);
	setHours(hour);
}

void HourlyWorker::setOverTime(double hour)
{
	overtime = hour - 40;
}

double HourlyWorker::getOverTime() const { return overtime; }

void HourlyWorker::setHours(double hour)
{
	if (hour < 0.0)
	{
		throw invalid_argument("Pieces must be >= 0");
	}

	if (hour > 40)
	{
		hours = hour;
		setOverTime(hour);
	}
	hours = hour;
}

double HourlyWorker::getHours() const { return hours; }

void HourlyWorker::setWage(double hwages)
{
	if (hwages < 0.0)
	{
		throw invalid_argument("Wage must be >= 0.0");
	}

	wage = hwages;
}

double HourlyWorker::getWage() const { return wage; }

double HourlyWorker::earnings() const { return (getHours() - getOverTime())*getWage() + (1.5*getWage()*getOverTime()); }

string HourlyWorker::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2);
	output << "Hourly Employee: "
		<< Employee::toString()
		<< "\nHours Worked: " << getHours()
		<< "\nWage: " << getWage();
	return output.str();
}