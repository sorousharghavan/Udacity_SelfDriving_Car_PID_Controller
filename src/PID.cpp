#include "PID.h"

using namespace std;

PID::PID() {
	p_error = i_error = d_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	i_error = cte + i_error;
	p_error = cte;
}

double PID::TotalError() {
	return -1 * (Kp*p_error + Ki*i_error + Kd*d_error);
}