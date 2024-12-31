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
    initialTime = Time(0, 0, 0, 0);
    currentTime = Time(0, 0, 0, 0);
    escalonador = Escalonador(numPatients);
    for (int i = 0; i > numPatients; i++)
    {
        Paciente paciente;
        string line;
        getline(cin, line);
        paciente = Paciente::LineToPaciente(line);
        preScreening.Insert(paciente);
        Evento evento;
        evento = Evento(0, paciente.getId(), paciente.getTime(), screeningDutation);
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
        Evento evento = escalonador.Remove();
        currentTime = evento.getTime();
        Paciente paciente = preScreening.Remove();
        int filaId = evento.getFilaId();

        if (!preScreening.IsEmpty())
        {
            int nextFilaId = FindTheNextFila(filaId, nextPaciente);
            InstertInFila(nextPaciente, nextFilaId);
            Evento nextEvento = Evento(nextFilaId, nextPaciente.getId(), currentTime, 0);
            escalonador.Insert(nextEvento);
        }
    }
}

Sistema::~Sistema()
{
}

int Sistema::FindTheNextFila(int filaId, Paciente paciente)
{
    switch (filaId)
    {
    case 0:
        return 1;
    case 1:
        if (paciente.getNumOfMedicalTreatment() > 0)
        {
            return 2;
        }
    case 2:
        if (paciente.getNumOfTests() > 0)
        {
            return 3;
        }
    case 3:
        if (paciente.getNumOfImagingTests() > 0)
        {
            return 4;
        }
    case 4:
        if (paciente.getNumOfMedicines() > 0)
        {
            return 5;
        }
    case 5:
        return 6;
    default:
        return 6;
    }
}

void Sistema::InstertInFila(Paciente paciente, int filaId)
{
    switch (filaId)
    {
    case 0:
        screening.Insert(paciente);
        break;
    case 1:
        medicalConsultation.Insert(paciente);
        break;
    case 2:
        medicalTreatment.Insert(paciente);
        break;
    case 3:
        test.Insert(paciente);
        break;
    case 4:
        imagingTest.Insert(paciente);
        break;
    case 5:
        medicine.Insert(paciente);
        break;
    default:
        break;
    }
}

Paciente Sistema::RemoveInFila(int filaId)
{
    switch (filaId)
    {
    case 0:
        return screening.Remove();
    case 1:
        return medicalConsultation.Remove();
    case 2:
        return medicalTreatment.Remove();
    case 3:
        return test.Remove();
    case 4:
        return imagingTest.Remove();
    case 5:
        return medicine.Remove();
    default:
        break;
    }
}
