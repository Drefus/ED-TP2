#include "Paciente.hpp"
#include <sstream>

Paciente::Paciente() : id(""), isHospitalDischarged(false), yearOfService(0), monthOfService(0), dayOfService(0), hourOfService(0), priority(Priority::LOW), numOfMedicalTreatment(0), numOfTests(0), numOfImagingTests(0), numOfMedicines(0), timeOfService(0), timeOfWaiting(0), timeTotal(0) {}

Paciente::Paciente(string id, bool isHospitalDischarged, int yearOfService, int monthOfService, int dayOfService, int hourOfService, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, int timeOfService, int timeOfWaiting)
    : id(id), isHospitalDischarged(isHospitalDischarged), yearOfService(yearOfService), monthOfService(monthOfService), dayOfService(dayOfService), hourOfService(hourOfService), priority(priority), numOfMedicalTreatment(numOfMedicalTreatment), numOfTests(numOfTests), numOfImagingTests(numOfImagingTests), numOfMedicines(numOfMedicines), timeOfService(timeOfService), timeOfWaiting(timeOfWaiting), timeTotal(0) {}

string Paciente::getId()
{
    return id;
}

void Paciente::setId(string id)
{
    this->id = id;
}

bool Paciente::getIsHospitalDischarged()
{
    return isHospitalDischarged;
}

void Paciente::setIsHospitalDischarged(int isHospitalDischarged)
{
    this->isHospitalDischarged = isHospitalDischarged;
}

int Paciente::getYearOfService()
{
    return yearOfService;
}

void Paciente::setYearOfService(int yearOfService)
{
    this->yearOfService = yearOfService;
}

int Paciente::getMonthOfService()
{
    return monthOfService;
}

void Paciente::setMonthOfService(int monthOfService)
{
    this->monthOfService = monthOfService;
}

int Paciente::getDayOfService()
{
    return dayOfService;
}

void Paciente::setDayOfService(int dayOfService)
{
    this->dayOfService = dayOfService;
}

int Paciente::getHourOfService()
{
    return hourOfService;
}

void Paciente::setHourOfService(int hourOfService)
{
    this->hourOfService = hourOfService;
}

Priority Paciente::getPriority()
{
    return priority;
}

void Paciente::setPriority(Priority priority)
{
    this->priority = priority;
}

int Paciente::getNumOfMedicalTreatment()
{
    return numOfMedicalTreatment;
}

void Paciente::setNumOfMedicalTreatment(int numOfMedicalTreatment)
{
    this->numOfMedicalTreatment = numOfMedicalTreatment;
}

int Paciente::getNumOfTests()
{
    return numOfTests;
}

void Paciente::setNumOfTests(int numOfTests)
{
    this->numOfTests = numOfTests;
}

int Paciente::getNumOfImagingTests()
{
    return numOfImagingTests;
}

void Paciente::setNumOfImagingTests(int numOfImagingTests)
{
    this->numOfImagingTests = numOfImagingTests;
}

int Paciente::getNumOfMedicines()
{
    return numOfMedicines;
}

void Paciente::setNumOfMedicines(int numOfMedicines)
{
    this->numOfMedicines = numOfMedicines;
}

int Paciente::getTimeOfService()
{
    return timeOfService;
}

void Paciente::setTimeOfService(int timeOfService)
{
    this->timeOfService = timeOfService;
}

int Paciente::getTimeOfWaiting()
{
    return timeOfWaiting;
}

void Paciente::setTimeOfWaiting(int timeOfWaiting)
{
    this->timeOfWaiting = timeOfWaiting;
}

int Paciente::getTimeTotal()
{
    return timeTotal;
}

void Paciente::setTimeTotal(int timeTotal)
{
    this->timeTotal = timeTotal;
}

Paciente Paciente::LineToPaciente(string line)
{
    string id;
    bool isHospitalDischarged;
    int yearOfService;
    int monthOfService;
    int dayOfService;
    int hourOfService;
    Priority priority;
    int numOfMedicalTreatment;
    int numOfTests;
    int numOfImagingTests;
    int numOfMedicines;
    std::istringstream iss(line);
    iss >> id >> isHospitalDischarged >> yearOfService >> monthOfService >> dayOfService >> hourOfService >> priority >> numOfMedicalTreatment >> numOfTests >> numOfImagingTests >> numOfMedicines;
    return Paciente(id, isHospitalDischarged, yearOfService, monthOfService, dayOfService, hourOfService, priority, numOfMedicalTreatment, numOfTests, numOfImagingTests, numOfMedicines, 0, 0);
}