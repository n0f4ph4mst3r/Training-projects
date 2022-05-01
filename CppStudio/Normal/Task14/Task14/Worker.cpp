#include "Worker.h"

Worker::Worker(const std::string& n, const unsigned int e, const unsigned int hW, const unsigned int h) {
	name = std::move(n);
	exp = std::move(e);
	hWage = std::move(hW);
	hours = std::move(h);
	salary = hWage * hours;

	unsigned int prozent;
	switch (exp) {
	    case 0:
			prozent = 0;
		case 1: case 2: case 3:
			prozent = 5;
		case 4: case 5:
			prozent = 8;
		default:
			prozent = 15;
	}
	premy = salary * prozent / 100;
}

std::string Worker::GetName() {
	return name;
}

unsigned int Worker::GetExp() {
	return exp;
}

unsigned int Worker::GethWage() {
	return hWage;
}

unsigned int Worker::Gethours() {
	return hours;
}

unsigned int Worker::GetSalary() {
	return salary;
}

unsigned int Worker::GetPremy() {
	return premy;
}