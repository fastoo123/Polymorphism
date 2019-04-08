#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "PieceWorker.h"
using namespace std;

PieceWorker::PieceWorker(const string& first, const string& last, const string& ssn, double pces, double pwages)
: Employee (first, last, ssn) 
{
	setWage(pwages);
	setPieces(pces);
}

void PieceWorker::setPieces(double pces)
{
	if (pces < 0.0)
	{
		throw invalid_argument("Pieces must be >= 0");
	}

	pieces = pces;
}

double PieceWorker::getPieces() const { return pieces; }

void PieceWorker::setWage(double pwages)
{
	if (pwages < 0.0)
	{
		throw invalid_argument("Wage must be >= 0.0");
	}

	wage = pwages;
}

double PieceWorker::getWage() const { return wage; }

double PieceWorker::earnings() const { return getWage() * getPieces(); }

string PieceWorker::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2);
	output << "PieceWorker Employee: "
		<< Employee::toString()
		<< "\nPieces Made: " << getPieces()
		<< "\nWage: " << getWage();
	return output.str();
}