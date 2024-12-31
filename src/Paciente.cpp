#include "Paciente.hpp"
#include <sstream>

Paciente::Paciente() : id(""), isHospitalDischarged(false), time(Time(0, 0, 0, 0)), priority(Priority::GREEN), numOfMedicalTreatment(0), numOfTests(0), numOfImagingTests(0), numOfMedicines(0), timeOfService(0), timeOfWaiting(0), timeTotal(0) {}

Paciente::Paciente(string id, bool isHospitalDischarged, Time time, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, int timeOfService, int timeOfWaiting)
    : id(id), isHospitalDischarged(isHospitalDischarged), time(time), priority(priority), numOfMedicalTreatment(numOfMedicalTreatment), numOfTests(numOfTests), numOfImagingTests(numOfImagingTests), numOfMedicines(numOfMedicines), timeOfService(timeOfService), timeOfWaiting(timeOfWaiting), timeTotal(0) {}

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

Time Paciente::getTime()
{
    return time;
}

void Paciente::setTime(Time time)
{
    this->time = time;
}

Paciente Paciente::LineToPaciente(string line)
{
    string id;
    bool isHospitalDischarged;
    int yearOfService;
    int monthOfService;
    int dayOfService;
    int hourOfService;
    int priority;
    int numOfMedicalTreatment;
    int numOfTests;
    int numOfImagingTests;
    int numOfMedicines;
    std::istringstream iss(line);
    iss >> id >> isHospitalDischarged >> yearOfService >> monthOfService >> dayOfService >> hourOfService >> priority >> numOfMedicalTreatment >> numOfTests >> numOfImagingTests >> numOfMedicines;
    Time time = Time(yearOfService, monthOfService, dayOfService, hourOfService);
    return Paciente(id, isHospitalDischarged, time, Priority(priority), numOfMedicalTreatment, numOfTests, numOfImagingTests, numOfMedicines, 0, 0);
}