#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "Time.hpp"
using namespace std;

enum Priority
{
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2,
    RED = 3
};

enum State
{
    NOT_ARRIVED = 0,
    SCREENING_QUEUE = 1,
    IN_SCREENING = 2,
    MEDICAL_CONSULTATION_QUEUE = 3,
    IN_MEDICAL_CONSULTATION = 4,
    MEDICAL_TREATMENT_QUEUE = 5,
    IN_MEDICAL_TREATMENT = 6,
    TEST_QUEUE = 7,
    IN_TEST = 8,
    IMAGING_TEST_QUEUE = 9,
    IN_IMAGING_TEST = 10,
    MEDICINE_QUEUE = 11,
    IN_MEDICINE = 12,
    HOSPITAL_DISCHARGED = 13
};

class Paciente
{
private:
    string id;
    bool isHospitalDischarged;
    Time initialTime;
    Time currentTime;
    Priority priority;
    int numOfMedicalTreatment;
    int numOfTests;
    int numOfImagingTests;
    int numOfMedicines;
    double timeOfService;
    double timeOfWaiting;
    double timeTotal;
    State state;

public:
    Paciente();
    Paciente(string id, bool isHospitalDischarged, Time initialTime, Time currentTime, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, double timeOfService, double timeOfWaiting);
    ~Paciente();

    string getId();
    void setId(string &id);
    bool getIsHospitalDischarged();
    void setIsHospitalDischarged(bool isHospitalDischarged);
    Time getInitialTime();
    void setInitialTime(Time initialTime);
    Time getCurrentTime();
    void setCurrentTime(Time currentTime);
    Priority getPriority();
    void setPriority(Priority priority);
    int getNumOfMedicalTreatment();
    void setNumOfMedicalTreatment(int numOfMedicalTreatment);
    int getNumOfTests();
    void setNumOfTests(int numOfTests);
    int getNumOfImagingTests();
    void setNumOfImagingTests(int numOfImagingTests);
    int getNumOfMedicines();
    void setNumOfMedicines(int numOfMedicines);
    double getTimeOfService();
    void setTimeOfService(double timeOfService);
    double getTimeOfWaiting();
    void setTimeOfWaiting(double timeOfWaiting);
    double getTimeTotal();
    void setTimeTotal(double timeTotal);
    State getState();
    void setState(State state);

    Paciente ReadLineToPaciente();
};

#endif