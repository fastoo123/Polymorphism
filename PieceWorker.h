#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include <string>
#include "Employee.h"
using namespace std;

class PieceWorker : public Employee
{
public:
	PieceWorker(const string&, const string&, const string&, double = 0.0, double = 0.0);
	virtual ~PieceWorker() = default;

	void setPieces(double);
	double getPieces() const;

	void setWage(double);
	double getWage() const;

	virtual double earnings() const override;
	virtual string toString() const override;

private:
	double wage;
	double pieces;
};

#endif