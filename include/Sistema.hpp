#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include "Fila.hpp"
#include "Escalonador.hpp"
#include "Evento.hpp"
#include "Procedimento.hpp"

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
    Procedimento screeningProcedimento;
    Procedimento medicalConsultationProcedimento;
    Procedimento medicalTreatmentProcedimento;
    Procedimento testProcedimento;
    Procedimento imagingTestProcedimento;
    Procedimento medicineProcedimento;
    Time initialTime;
    Time currentTime;
    int numPatients;
    Escalonador escalonador;
    Paciente *pacientes;
    Sistema();
    ~Sistema();
    int FindTheNextFila(int filaId, Paciente paciente);
    void InstertInFila(Paciente paciente, int filaId);
    Paciente RemoveInFila(int filaId);
    int GetPatientId(string id);
    double GetDuration(int filaId, Paciente paciente);
    void InicializeProcess();
    int isEmpityProcess(int filaId);
    void AddServiceToProcedimento(int filaId, Time initialTime, double duracao, int numUnit);
    State GetNewState(int newFilaId, bool isDone);
    void PrintPacientes();
};

#endif