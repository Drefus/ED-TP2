#include "Paciente.hpp"
#include <sstream>
#include <iostream>
using namespace std;

Paciente::Paciente() : id(""), isHospitalDischarged(false), initialTime(0, 0, 0, 0.0), currentTime(0, 0, 0, 0.0), priority(Priority::LOW), numOfMedicalTreatment(0), numOfTests(0), numOfImagingTests(0), numOfMedicines(0), timeOfService(0), timeOfWaiting(0), timeTotal(0), state(State::NOT_ARRIVED)
{
}

Paciente::Paciente(string id, bool isHospitalDischarged, Time initialTime, Time currentTime, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, double timeOfService, double timeOfWaiting)
    : id(id), isHospitalDischarged(isHospitalDischarged), initialTime(initialTime), currentTime(currentTime), priority(priority), numOfMedicalTreatment(numOfMedicalTreatment), numOfTests(numOfTests), numOfImagingTests(numOfImagingTests), numOfMedicines(numOfMedicines), timeOfService(timeOfService), timeOfWaiting(timeOfWaiting), timeTotal(0), state(State::NOT_ARRIVED) {}

string Paciente::getId()
{
    return id;
}

void Paciente::setId(string &id)
{
    this->id = id;
}

bool Paciente::getIsHospitalDischarged()
{
    return isHospitalDischarged;
}

void Paciente::setIsHospitalDischarged(bool isHospitalDischarged)
{
    this->isHospitalDischarged = isHospitalDischarged;
}

Time Paciente::getInitialTime()
{
    return initialTime;
}

void Paciente::setInitialTime(Time initialTime)
{
    this->initialTime = initialTime;
}

Time Paciente::getCurrentTime()
{
    return currentTime;
}

void Paciente::setCurrentTime(Time currentTime)
{
    this->currentTime = currentTime;
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

double Paciente::getTimeOfService()
{
    return timeOfService;
}

void Paciente::setTimeOfService(double timeOfService)
{
    this->timeOfService = timeOfService;
}

double Paciente::getTimeOfWaiting()
{
    return timeOfWaiting;
}

void Paciente::setTimeOfWaiting(double timeOfWaiting)
{
    this->timeOfWaiting = timeOfWaiting;
}

double Paciente::getTimeTotal()
{
    return timeTotal;
}

void Paciente::setTimeTotal(double timeTotal)
{
    this->timeTotal = timeTotal;
}

State Paciente::getState()
{
    return state;
}

void Paciente::setState(State state)
{
    this->state = state;
}

Paciente Paciente::ReadLineToPaciente()
{
    string id;
    int isHospitalDischarged;
    int yearOfService;
    int monthOfService;
    int dayOfService;
    double hourOfService;
    int priority;
    int numOfMedicalTreatment;
    int numOfTests;
    int numOfImagingTests;
    int numOfMedicines;

    cin >> id;
    cin >> isHospitalDischarged;
    cin >> yearOfService;
    cin >> monthOfService;
    cin >> dayOfService;
    cin >> hourOfService;
    cin >> priority;
    cin >> numOfMedicalTreatment;
    cin >> numOfTests;
    cin >> numOfImagingTests;
    cin >> numOfMedicines;

    Time time = Time(yearOfService, monthOfService, dayOfService, hourOfService);
    cout << "id: " << id << " isHospitalDischarged: " << isHospitalDischarged << " yearOfService: " << yearOfService << " monthOfService: " << monthOfService << " dayOfService: " << dayOfService << " hourOfService: " << hourOfService << " priority: " << priority << " numOfMedicalTreatment: " << numOfMedicalTreatment << " numOfTests: " << numOfTests << " numOfImagingTests: " << numOfImagingTests << " numOfMedicines: " << numOfMedicines << endl;
    return Paciente(id, isHospitalDischarged == 1, time, time, Priority(priority), numOfMedicalTreatment, numOfTests, numOfImagingTests, numOfMedicines, 0, 0);
}