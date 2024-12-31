#include "Sistema.hpp"
#include "Fila.hpp"
#include "Paciente.hpp"
#include <iostream>
using namespace std;
Sistema::Sistema()
{
    InicializeProcess();
    cin >> numPatients;
    initialTime = Time(0, 0, 0, 0);
    currentTime = Time(0, 0, 0, 0);
    escalonador = Escalonador(numPatients);
    preScreening = Fila(0);
    pacientes = new Paciente[numPatients];
    for (int i = 0; i < numPatients; i++)
    {
        Paciente paciente;
        string line;
        paciente = paciente.ReadLineToPaciente();
        pacientes[i] = paciente;
        Evento evento;
        evento = Evento(0, paciente.getId(), paciente.getCurrentTime(), screeningProcedimento.getDuration());
        escalonador.Insert(evento);
    }
    preScreening.OrderByTime();
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
        int filaId = evento.getFilaId();
        int pacienteId = GetPatientId(evento.getPacienteId());
        Paciente paciente = pacientes[pacienteId];
        if (paciente.getState() != State::HOSPITAL_DISCHARGED)
        {
            int nextFila = FindTheNextFila(filaId, paciente);
            int numUnit = isEmpityProcess(nextFila);
            if (numUnit != -1)
            {
                double duration = GetDuration(nextFila, paciente);
                AddServiceToProcedimento(nextFila, currentTime, duration, numUnit);
                Time newTime = currentTime;
                newTime.addTime(duration);
                evento = Evento(nextFila, paciente.getId(), newTime, duration);
                Paciente newPaciente = paciente;
                newPaciente.setCurrentTime(newTime);
                newPaciente.setState(GetNewState(nextFila, true));
                pacientes[pacienteId] = newPaciente;
                RemoveInFila(filaId);
                InstertInFila(newPaciente, nextFila);
            }
            else
            {
                Paciente newPaciente = paciente;

                pacientes[pacienteId] = newPaciente;
            }
            escalonador.Insert(evento);
        }
        if (!preScreening.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = preScreening.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    screening.Remove();
                    paciente.setState(State::IN_SCREENING);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                    escalonador.Insert(Evento(2, paciente.getId(), eventTime, medicalConsultationProcedimento.getDuration()));
                    medicalConsultation.Insert(paciente);
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!screening.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = screening.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    medicalConsultation.Remove();
                    paciente.setState(State::IN_MEDICAL_CONSULTATION);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                    escalonador.Insert(Evento(3, paciente.getId(), eventTime, medicalTreatmentProcedimento.getDuration()));
                    medicalTreatment.Insert(paciente);
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!medicalConsultation.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = medicalConsultation.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    medicalTreatment.Remove();
                    paciente.setState(State::IN_MEDICAL_TREATMENT);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                    escalonador.Insert(Evento(4, paciente.getId(), eventTime, testProcedimento.getDuration()));
                    test.Insert(paciente);
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!medicalTreatment.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = medicalTreatment.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    test.Remove();
                    paciente.setState(State::IN_TEST);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                    escalonador.Insert(Evento(5, paciente.getId(), eventTime, imagingTestProcedimento.getDuration()));
                    imagingTest.Insert(paciente);
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!test.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = test.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    imagingTest.Remove();
                    paciente.setState(State::IN_IMAGING_TEST);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                    escalonador.Insert(Evento(6, paciente.getId(), eventTime, medicineProcedimento.getDuration()));
                    medicine.Insert(paciente);
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!imagingTest.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = imagingTest.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    medicine.Remove();
                    paciente.setState(State::IN_MEDICINE);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                }
                else
                {
                    loop = false;
                }
            };
        }
        if (!medicine.IsEmpty())
        {
            bool loop = true;
            while (loop)
            {
                Paciente paciente = medicine.GetHead()->data;
                Evento currentEvent = escalonador.GetById(paciente.getId());
                Time eventTime = currentEvent.getTime();
                eventTime.addTime(currentEvent.getDuracao());
                if (currentTime.compareTime(eventTime) || currentTime.isEqual(eventTime))
                {
                    medicine.Remove();
                    paciente.setState(State::HOSPITAL_DISCHARGED);
                    paciente.setCurrentTime(eventTime);
                    escalonador.RemoveById(paciente.getId());
                }
                else
                {
                    loop = false;
                }
            };
        }
    }
    PrintPacientes();
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
        return preScreening.Remove();
    case 1:
        return screening.Remove();
    case 2:
        return medicalConsultation.Remove();
    case 3:
        return medicalTreatment.Remove();
    case 4:
        return test.Remove();
    case 5:
        return imagingTest.Remove();
    case 6:
        return medicine.Remove();
    default:
        break;
    }
}

int Sistema::GetPatientId(string id)
{
    for (int i = 0; i < numPatients; i++)
    {
        if (pacientes[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

double Sistema::GetDuration(int filaId, Paciente paciente)
{
    switch (filaId)
    {
    case 0:
        return screeningProcedimento.getDuration();
    case 1:
        return medicalConsultationProcedimento.getDuration();
    case 2:
        return medicalTreatmentProcedimento.getDuration() * paciente.getNumOfMedicalTreatment();
    case 3:
        return testProcedimento.getDuration() * paciente.getNumOfTests();
    case 4:
        return imagingTestProcedimento.getDuration() * paciente.getNumOfImagingTests();
    case 5:
        return medicineProcedimento.getDuration() * paciente.getNumOfMedicines();
    default:
        break;
    }
    return 0;
}

void Sistema::InicializeProcess()
{
    double screeningDutation;
    int screeningCapacity;
    double medicalConsultationDuration;
    int medicalConsultationCapacity;
    double medicalTreatmentDuration;
    int medicalTreatmentCapacity;
    double testDuration;
    int testCapacity;
    double imagingTestDuration;
    int imagingTestCapacity;
    double medicineDuration;
    int medicineCapacity;
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

    screeningProcedimento = Procedimento(screeningCapacity, screeningDutation);
    medicalConsultationProcedimento = Procedimento(medicalConsultationCapacity, medicalConsultationDuration);
    medicalTreatmentProcedimento = Procedimento(medicalTreatmentCapacity, medicalTreatmentDuration);
    testProcedimento = Procedimento(testCapacity, testDuration);
    imagingTestProcedimento = Procedimento(imagingTestCapacity, imagingTestDuration);
    medicineProcedimento = Procedimento(medicineCapacity, medicineDuration);
}

int Sistema::isEmpityProcess(int filaId)
{
    switch (filaId)
    {
    case 1:
        return screeningProcedimento.emptyUnit();
    case 2:
        return medicalConsultationProcedimento.emptyUnit();
    case 3:
        return medicalTreatmentProcedimento.emptyUnit();
    case 4:
        return testProcedimento.emptyUnit();
    case 5:
        return imagingTestProcedimento.emptyUnit();
    case 6:
        return medicineProcedimento.emptyUnit();
    default:
        break;
    }
    return 0;
}

void Sistema::AddServiceToProcedimento(int filaId, Time initialTime, double duracao, int numUnit)
{
    switch (filaId)
    {
    case 1:
        screeningProcedimento.addService(initialTime, duracao, numUnit);
        break;
    case 2:
        medicalConsultationProcedimento.addService(initialTime, duracao, numUnit);
        break;
    case 3:
        medicalTreatmentProcedimento.addService(initialTime, duracao, numUnit);
        break;
    case 4:
        testProcedimento.addService(initialTime, duracao, numUnit);
        break;
    case 5:
        imagingTestProcedimento.addService(initialTime, duracao, numUnit);
        break;
    case 6:
        medicineProcedimento.addService(initialTime, duracao, numUnit);
        break;
    default:
        break;
    }
}

State Sistema::GetNewState(int newFilaId, bool isDone)
{
    switch (newFilaId)
    {
    case 1:
        if (isDone)
        {
            return State::IN_SCREENING;
        }
        return State::SCREENING_QUEUE;
    case 2:
        if (isDone)
        {
            return State::IN_MEDICAL_CONSULTATION;
        }
        return State::MEDICAL_CONSULTATION_QUEUE;
    case 3:
        if (isDone)
        {
            return State::IN_MEDICAL_TREATMENT;
        }
        return State::MEDICAL_TREATMENT_QUEUE;
    case 4:
        if (isDone)
        {
            return State::IN_TEST;
        }
        return State::TEST_QUEUE;
    case 5:
        if (isDone)
        {
            return State::IN_IMAGING_TEST;
        }
        return State::IMAGING_TEST_QUEUE;
    case 6:
        if (isDone)
        {
            return State::IN_MEDICINE;
        }
        return State::MEDICINE_QUEUE;
    default:
        return State::HOSPITAL_DISCHARGED;
    }
}

void Sistema::PrintPacientes()
{
    for (int i = 0; i < numPatients; i++)
    {
        cout << pacientes[i].getId() << " ";
        pacientes[i].getInitialTime().printTime();
        cout << " ";
        pacientes[i].getCurrentTime().printTime();
        cout << " " << (pacientes[i].getCurrentTime().getTotalHours() - pacientes[i].getInitialTime().getTotalHours()) << " " << pacientes[i].getTimeOfService() << pacientes[i].getTimeOfWaiting() << endl;
    }
}