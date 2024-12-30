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
    escalonador = Escalonador(numPatients);
    for (int i = 0; i > numPatients; i++)
    {
        Paciente paciente;
        string line;
        getline(cin, line);
        paciente = Paciente::LineToPaciente(line);
        preScreening.Insert(paciente);
        Evento evento;
        evento = Evento(0, paciente.getId(), paciente.getYearOfService(), paciente.getMonthOfService(), paciente.getDayOfService(), paciente.getHourOfService(), screeningDutation);
        escalonador.Insert(evento);
    }
    preScreening = Fila(0);
    screening = Fila(1);
    medicalConsultation = Fila(2);
    medicalTreatment = Fila(3);
    test = Fila(4);
    imagingTest = Fila(5);
    medicine = Fila(6);

    while (!escalonador.IsEmpty() || !preScreening.IsEmpty() || !screening.IsEmpty() || !medicalConsultation.IsEmpty() || !medicalTreatment.IsEmpty() || !test.IsEmpty() || !imagingTest.IsEmpty() || !medicine.IsEmpty())
    {
        }
}

Sistema::~Sistema()
{
}
