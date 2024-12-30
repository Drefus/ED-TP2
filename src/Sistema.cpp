#include "Sistema.hpp"
#include "Fila.hpp"
#include "Paciente.hpp"
#include <iostream>
Sistema::Sistema()
{
    cin >> screeningDutation;
    cin >> screeningCapacity;
    cin >> medicalConsultationDuration;
    cin >> medicalConsultationCapacity;
    cin >> medicalTreatmentDuration;
    cin >> medicalTreatmentCapacity;
    cin >> testDuration;
    cin >> testCapacity;
    cin >> imagingTestDuration;
    cin >> imagingTestCapacity;
    cin >> medicineDuration;
    cin >> medicineCapacity;
    cin >> numPatients;
    initialTime = 0;
    currentTime = 0;
    for (int i = 0; i > numPatients; i++)
    {
        Paciente paciente;
        int id;
        cin >> id;
        paciente.setId(id);
        cin >> paciente.isHospitalDischarged;
        cin >> paciente.yearOfService;
        cin >> paciente.monthOfService;
        cin >> paciente.dayOfService;
        cin >> paciente.hourOfService;
        cin >> paciente.priority;
        cin >> paciente.numOfMedicalTreatment;
        cin >> paciente.numOfTests;
        cin >> paciente.numOfImagingTests;
        cin >> paciente.numOfMedicines;
        cin >> paciente.timeOfService;
        cin >> paciente.timeOfWaiting;
        preScreening.Insert(paciente);
    }
}

Sistema::~Sistema()
{
}
