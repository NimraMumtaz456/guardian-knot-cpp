#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

// 1. Visual Feedback (Colors)
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 2. Encryption (Data Security)
string encrypt(string data) {
    for(int i = 0; i < data.length(); i++) data[i] += 2;
    return data;
}

// 3. Decryption
string decrypt(string data) {
    for (int i = 0; i < data.length(); i++) data[i] -= 2;
    return data;
}

int main() {
    system("cls");
    string filename = "user_config.txt";
    time_t now = time(0);
    char* dt = ctime(&now);
    long long currentTime = time(0);

    string name, password, duressPin, savedPass, savedDuress, savedName;
    long long savedTime;

    // Header
    setColor(11);
    cout << "===============================================" << endl;
    cout << "       GUARDIAN KNOT - SECURITY SYSTEM         " << endl;
    cout << "===============================================" << endl;
    setColor(7);

    ifstream inFile(filename);

    // --- REGISTRATION PHASE ---
    if (!inFile) {
        cout << "[NEW SYSTEM] Let's secure your life..." << endl;
        cout << "Enter Your Name: "; 
        getline(cin, name);
        cout << "Set Main Password: "; cin >> password;
        cout << "Set Emergency Duress PIN: "; cin >> duressPin;

        ofstream outFile(filename);
        outFile << name << endl << encrypt(password) << endl << encrypt(duressPin) << endl << currentTime;
        outFile.close();

        setColor(10);
        cout << "\n[SUCCESS] You are now protected. Monitoring Active." << endl;
        setColor(7);
    } 
    // --- MONITORING PHASE ---
    else {
        inFile >> savedName >> savedPass >> savedDuress >> savedTime;
        inFile.close();

        long long gap = currentTime - savedTime;
        cout << "Welcome back, " << savedName << "." << endl;
        
        string input;
        cout << "\nEnter Password/PIN to confirm you are safe: "; cin >> input;

        // SCENARIO 1: Silent Duress (Emotional Stealth)
        if (input == decrypt(savedDuress)) {
            setColor(10);
            cout << "\n[OK] System Identity Confirmed." << endl; // Fake success for intruder
            setColor(7);
            
            ofstream alertFile("EMERGENCY_LOG.txt", ios::app);
            alertFile << "\n--- SILENT CRY FOR HELP ---" << endl;
            alertFile << "Time of Event: " << dt;
            alertFile << "Condition: " << savedName << " is being forced to unlock the system." << endl;
            alertFile << "Note: They cannot call for help. Please reach out to them now!" << endl;
            alertFile << "-----------------------------------" << endl;
            alertFile.close();
            Beep(800, 150); 
        }
        // SCENARIO 2: Normal Login / Timeout Check
        else if (input == decrypt(savedPass)) {
            if (gap > 60) { // 60 Seconds Threshold
                setColor(12); // Red Alert
                cout << "\n[!!!] DANGER: EMERGENCY ALERT ACTIVATED! [!!!]" << endl;
                
                // Aggressive Siren Sound
                for(int i=0; i<5; i++) { 
                    Beep(2500, 800); // High Pitch & Long Duration
                    Sleep(50);
                }
                
                ofstream log("EMERGENCY_LOG.txt", ios::app);
                log << "\n--- CRITICAL ALERT: NO RESPONSE ---" << endl;
                log << "Time of Event: " << dt;
                log << "Alert: " << savedName << " has not checked in for " << gap << " seconds." << endl;
                log << "Fear: We are deeply worried for their safety. Please check on them!" << endl;
                log << "-----------------------------------" << endl;
                log.close();
            } else {
                setColor(10); // Green Safe
                cout << "\n[SAFE] It's so good to see you are okay, " << savedName << "!" << endl;
                
                ofstream history("activity_log.txt", ios::app);
                history << "Safe & Sound | " << savedName << " checked in at: " << dt;
                history.close();

                // Update check-in time
                ofstream outFile(filename);
                outFile << savedName << endl << savedPass << endl << savedDuress << endl << currentTime;
                outFile.close();
            }
            setColor(7);
        } else {
            setColor(12);
            cout << "\n[DENIED] Wrong credentials. Are you really " << savedName << "?" << endl;
            Beep(400, 1000);
            setColor(7);
        }
    }

    return 0; // Auto-exits after execution
}