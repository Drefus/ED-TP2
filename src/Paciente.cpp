#include "Paciente.hpp"
#include <sstream>

Paciente::Paciente() : id(""), isHospitalDischarged(false), initialTime(0, 0, 0, 0.0), currentTime(0, 0, 0, 0.0), priority(Priority::LOW), numOfMedicalTreatment(0), numOfTests(0), numOfImagingTests(0), numOfMedicines(0), timeOfService(0), timeOfWaiting(0), timeTotal(0), state(State::NOT_ARRIVED) {}

Paciente::Paciente(string id, bool isHospitalDischarged, Time initialTime, Time currentTime, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, double timeOfService, double timeOfWaiting)
    : id(id), isHospitalDischarged(isHospitalDischarged), initialTime(initialTime), currentTime(currentTime), priority(priority), numOfMedicalTreatment(numOfMedicalTreatment), numOfTests(numOfTests), numOfImagingTests(numOfImagingTests), numOfMedicines(numOfMedicines), timeOfService(timeOfService), timeOfWaiting(timeOfWaiting), timeTotal(0), state(State::NOT_ARRIVED) {}

string Paciente::getId() const
{
    return id;
}

void Paciente::setId(const string &id)
{
    this->id = id;
}

bool Paciente::getIsHospitalDischarged() const
{
    return isHospitalDischarged;
}

void Paciente::setIsHospitalDischarged(bool isHospitalDischarged)
{
    this->isHospitalDischarged = isHospitalDischarged;
}

Time Paciente::getInitialTime() const
{
    return initialTime;
}

void Paciente::setInitialTime(const Time &initialTime)
{
    this->initialTime = initialTime;
}

Time Paciente::getCurrentTime() const
{
    return currentTime;
}

void Paciente::setCurrentTime(const Time &currentTime)
{
    this->currentTime = currentTime;
}

Priority Paciente::getPriority() const
{
    return priority;
}

void Paciente::setPriority(Priority priority)
{
    this->priority = priority;
}

int Paciente::getNumOfMedicalTreatment() const
{
    return numOfMedicalTreatment;
}

void Paciente::setNumOfMedicalTreatment(int numOfMedicalTreatment)
{
    this->numOfMedicalTreatment = numOfMedicalTreatment;
}

int Paciente::getNumOfTests() const
{
    return numOfTests;
}

void Paciente::setNumOfTests(int numOfTests)
{
    this->numOfTests = numOfTests;
}

int Paciente::getNumOfImagingTests() const
{
    return numOfImagingTests;
}

void Paciente::setNumOfImagingTests(int numOfImagingTests)
{
    this->numOfImagingTests = numOfImagingTests;
}

int Paciente::getNumOfMedicines() const
{
    return numOfMedicines;
}

void Paciente::setNumOfMedicines(int numOfMedicines)
{
    this->numOfMedicines = numOfMedicines;
}

double Paciente::getTimeOfService() const
{
    return timeOfService;
}

void Paciente::setTimeOfService(double timeOfService)
{
    this->timeOfService = timeOfService;
}

double Paciente::getTimeOfWaiting() const
{
    return timeOfWaiting;
}

void Paciente::setTimeOfWaiting(double timeOfWaiting)
{
    this->timeOfWaiting = timeOfWaiting;
}

double Paciente::getTimeTotal() const
{
    return timeTotal;
}

void Paciente::setTimeTotal(double timeTotal)
{
    this->timeTotal = timeTotal;
}

State Paciente::getState() const
{
    return state;
}

void Paciente::setState(State state)
{
    this->state = state;
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
    return Paciente(id, isHospitalDischarged, time, time, Priority(priority), numOfMedicalTreatment, numOfTests, numOfImagingTests, numOfMedicines, 0, 0);
}