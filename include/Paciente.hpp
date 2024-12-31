#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include <string>
#include "Time.hpp"

using namespace std;

enum Priority
{
    GREEN = 0,
    YELLOW = 1,
    RED = 2
};

class Paciente
{
private:
    string id;
    int isHospitalDischarged;
    Time time;
    Priority priority;
    int numOfMedicalTreatment;
    int numOfTests;
    int numOfImagingTests;
    int numOfMedicines;
    double timeOfService;
    double timeOfWaiting;
    double timeTotal;

public:
    Paciente();
    Paciente(string id, bool isHospitalDischarged, Time time, Priority priority, int numOfMedicalTreatment, int numOfTests, int numOfImagingTests, int numOfMedicines, int timeOfService, int timeOfWaiting);

    string getId();
    void setId(string id);
    bool getIsHospitalDischarged();
    void setIsHospitalDischarged(int isHospitalDischarged);
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
    int getTimeOfService();
    void setTimeOfService(int timeOfService);
    int getTimeOfWaiting();
    void setTimeOfWaiting(int timeOfWaiting);
    int getTimeTotal();
    void setTimeTotal(int timeTotal);
    Time getTime();
    void setTime(Time time);

    static Paciente LineToPaciente(string line);
};

#endif;