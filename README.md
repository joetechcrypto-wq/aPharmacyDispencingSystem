# aPharmacyDispencingSystem

A menu-driven C program that assesses a patient, works out a safe dose, and dispenses medicine from a small pharmacy stock. It handles pricing, discounts, payment, and a session report. The medicines and rules are made up for practice.

- The menu

1. Assess a patient
2. Dispense medicine
3. View stock
4. Session report
5. Exit, with an “Are you sure?” check

The menu keeps coming back until the user confirms the exit. Any other input prints “Invalid choice.”

1. Assessing a patient

The user enters age and weight, and the program asks again until they’re valid (age 0 to 120, weight 2.0 to 250.0 kg).
It sorts the patient into an age group: Infant, Child, Teen, Adult, or Senior.
Each group has a dose per kg and a maximum single dose. The program multiplies weight by dose per kg and caps the result at the maximum, printing “Dose capped” when that happens.

2. Dispensing medicine

It won’t start until a patient has been assessed.
The user picks one of three medicines (Medacin, Paxolin, Zyrelief).
Three rules can decline the request, and every rule that fails is reported:
the quantity can’t be more than the current stock
Zyrelief can’t go to a patient under 12
Paxolin is sold in pairs only
Seniors get 10% off. The total is rounded to the nearest cent, and the user enters a payment.
Paying the wrong amount is declined. A successful sale reduces the stock and prints “Low stock” when 5 or fewer units remain.
Every attempt ends with “Status: Dispensed” or “Status: Declined”.

3. Viewing stock
For each medicine it shows the units left, and a LOW marker when stock is 5 or below.

5. Session report (shown on request and again on exit)

patients assessed
successful dispenses and declined attempts.
