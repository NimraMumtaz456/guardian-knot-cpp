# Guardian Knot - C++ Security Application

Guardian Knot is a security application developed in C++ as a 2nd-semester computer programming project. It bridges the gap between software data encryption and real-world emergency logic.

## 💡 What is the Core Idea? (Real-World Scenario)
Imagine you have secure personal notes or passwords locked in an app. If someone forces you to open the app and enter your password, you are in a tough spot. 

This is where **Guardian Knot** comes in:
1. **Normal Access:** If you enter your regular PIN, the app unlocks normally and decrypts your secure data safely.
2. **Duress/Panic Access:** If you are forced to unlock the app under pressure, you enter a secret **Duress PIN**. The app pretends to work normally but secretly triggers an emergency response—it immediately wipes out/destroys the sensitive data files or encrypts them forever so no one can access them.

---

## 🚀 Key Features
* **AES-Inspired Encryption:** Custom lightweight cryptographic logic to secure and scramble user data files.
* **Duress PIN Mechanism:** A smart panic-trigger logic that executes data destruction routines if a specific distress PIN is entered.
* **Data Privacy:** Engineered with secure memory management and input validation principles to prevent unauthorized access.

---

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Concepts Used:** Object-Oriented Programming (OOP), file handling (to read/write encrypted files), structures, and logical security frameworks.
