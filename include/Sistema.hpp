#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include "Fila.hpp"

class Sistema
{
public:
    Fila preScreening;
    Fila screening;
    Fila medicalConsultation;
    Fila medicalTreatment;
    Fila test;
    Fila imagingTest;
    Fila medicine;
    double initialTime;
    double currentTime;
    double screeningDutation;
    double medicalConsultationDuration;
    double medicalTreatmentDuration;
    double testDuration;
    double imagingTestDuration;
    double medicineDuration;
    int screeningCapacity;
    int medicalConsultationCapacity;
    int medicalTreatmentCapacity;
    int testCapacity;
    int imagingTestCapacity;
    int medicineCapacity;
    int numPatients;
    Sistema();
    ~Sistema();
};

#endif