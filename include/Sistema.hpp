#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include "Fila.hpp"
#include "Escalonador.hpp"
#include "Evento.hpp"

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
    Time initialTime;
    Time currentTime;
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
    Escalonador escalonador;
    Sistema();
    ~Sistema();
    int FindTheNextFila(int filaId, Paciente paciente);
    void InstertInFila(Paciente paciente, int filaId);
    Paciente RemoveInFila(int filaId);
};

#endif