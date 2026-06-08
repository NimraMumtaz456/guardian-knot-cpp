# Guardian Knot - C++ Personal Safety & Security Application

Guardian Knot is an automated personal safety system developed in C++ as a 2nd-semester computer programming project. It bridges the gap between software logic and real-world emergency response, acting as a digital "Dead Man's Switch" for user safety.

## 💡 What is the Core Idea? (Real-World Scenario)
Imagine a user is traveling alone or working in a high-risk environment. If something happens to them (e.g., they get stranded or kidnapped), they won't be able to call for help. **Guardian Knot** solves this passively:

1. **The 2-Day Safety Check (Dead Man's Switch):** The user must open the app and log a "Safety Tick" at least once every 2 days. 
2. **The Passive Emergency Trigger:** If 2 days pass and the user *fails* to check in, the system automatically flags that the user is in danger and triggers an emergency routine to alert their configured relatives/guardians.
3. **The Duress/Panic PIN:** If the user is forced by an attacker to unlock the app under pressure, they can enter a secret **Duress PIN**. The app pretends to function normally to keep the attacker calm, but secretly and immediately triggers an instant emergency alert to the relatives.

---

## 🚀 Key Features
* **Automated Safety Check-In:** Time-tracking logic that monitors user check-ins within a strict 48-hour window.
* **Duress PIN Mechanism:** A smart panic-trigger logic that executes covert safety routines and distress flags under pressure.
* **Emergency Contact Routing:** Logic designed to dispatch distress signals and user status to configured guardians during a breach or missing check-in.
* **Data Privacy:** Custom encryption to ensure that the user's emergency contacts and personal logs remain secure.

---

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Concepts Used:** Object-Oriented Programming (OOP), File Handling (for tracking timestamps and storing secure contact logs), Time/Date manipulation logic, and conditional security frameworks.
