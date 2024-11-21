#include <iostream>
#include <string>
using namespace std;
namespace Hospital {
    class Patient {
    protected:
        string name;
        int age;
        string medicalHistory;
    public:Patient(string n, int a, string mh) : name(n), age(a), medicalHistory(mh) {}
        virtual void viewDetails() {
            cout << "Patient Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Medical History: " << medicalHistory << endl;
        }
        virtual ~Patient() {}
    };
    class InPatient : public Patient {
        string roomNumber;
    public:
        InPatient(string n, int a, string mh, string room) : Patient(n, a, mh), roomNumber(room) {}
        void viewDetails() override {
            Patient::viewDetails();
            cout << "Room Number: " << roomNumber << endl;
        }
    };
    class OutPatient : public Patient {
        string appointmentTime;

    public:
        OutPatient(string n, int a, string mh, string time) : Patient(n, a, mh), appointmentTime(time) {}
        void viewDetails() override {
            Patient::viewDetails();
            cout << "Appointment Time: " << appointmentTime << endl;
        }
    };

    class Doctor {
        string name;
        string specialization;

    public:
        Doctor(string n, string spec) : name(n), specialization(spec) {}
        void viewDetails() {
            cout << "Doctor Name: " << name << endl;
            cout << "Specialization: " << specialization << endl;
        }
    };

    class Appointment {
        string date;
        Patient *patient;
        Doctor *doctor;

    public:
        Appointment(string d, Patient *p, Doctor *dctr) : date(d), patient(p), doctor(dctr) {}
        void schedule() {
            cout << "Appointment Scheduled on " << date << endl;
            cout << "With Doctor: ";
            doctor->viewDetails();
            cout << "For Patient: ";
            patient->viewDetails();
        }
        void cancel() {
            cout << "Appointment on " << date << " has been cancelled." << endl;
        }
    };

    class Billing {
        Patient *patient;
        float amount;

    public:
        Billing(Patient *p, float amt) : patient(p), amount(amt) {}
        void generateInvoice() {
            cout << "Invoice for Patient: ";
            patient->viewDetails();
            cout << "Total Amount Due: $" << amount << endl;
        }
    };
}

int main() {
    using namespace Hospital;

    InPatient inpatient("ABC", 30, "Diabetes", "A101");
    OutPatient outpatient("XYZ", 25, "Flu", "10:00 AM");
    Doctor doctor("Dr. Brown", "Cardiology");

    Appointment appointment("2024-11-20", &outpatient, &doctor);
    Billing billing(&inpatient, 500.0);

    cout << "InPatient Details:" << endl;
    inpatient.viewDetails();
    cout << endl;

    cout << "OutPatient Details:" << endl;
    outpatient.viewDetails();
    cout << endl;

    cout << "Doctor Details:" << endl;
    doctor.viewDetails();
    cout << endl;

    cout << "Scheduling Appointment:" << endl;
    appointment.schedule();
    cout << endl;

    cout << "Generating Billing Invoice:" << endl;
    billing.generateInvoice();

    return 0;
}
