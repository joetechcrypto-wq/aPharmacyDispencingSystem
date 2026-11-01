//A Pharmacy Dispensing Terminal

#include <stdio.h>
#include <stdbool.h>
int main() {
  int menu;
  bool active = true;
  int patientAge;
  float weight;
  float dosePerKg;
  float maxDose;
  float dose;
  int noOfPatients = 0;
  int medicine;
  int quantity;
  float priceM = 2.50;
  float priceP = 4.75;
  float priceZ = 3.20;
  float payment1;
  float payment2;
  float payment3;
  float discount;
  float paymentAmount;
  int availableUnitM = 50;
  int availableUnitP = 30;
  int availableUnitZ = 40;
  int successCount = 0;
  int failedCount = 0;
  int totalRevenue = 0;
  char confirm;
  bool checkerFour;
  bool checkerFive;

  do 
  {
    printf("Press 1 to Assess a patient \n");
    printf("Press 2 to dispense medicine \n");
    printf("Press 3 to view stock \n");
    printf("Press 4 for session report \n");
    printf("Press 5 to exit \n");

    scanf("%d", &menu);

    switch (menu)
    {
      case 1:
        bool checkerOne;
        bool checkerTwo;
      
       do
       {
        printf("Enter patient age and weight: \n");
        scanf("%d %f", &patientAge, &weight);

        if(patientAge <= 0 || patientAge >= 120)
        {
          printf("Invalid patient age \n");
        }

        else if(weight <= 2.0 || weight >= 250)
        {
          printf("Invalid weight input \n");
        }

        checkerOne = (patientAge <= 0 || patientAge >= 120);
        checkerTwo = (weight <= 2.0 || weight >= 250);
       } while (checkerOne || checkerTwo);

       noOfPatients++;

       if(patientAge < 2)
       {
        printf("Infant \n");
        dosePerKg = 5;
        maxDose = 100;
       }

       else if(patientAge >= 2 && patientAge <= 11)
       {
        printf("Child \n");
        dosePerKg = 10;
        maxDose = 400;
       }

       else if(patientAge >= 12 && patientAge <= 17)
       {
        printf("Teen \n");
        dosePerKg = 8;
        maxDose = 600;
       }

       else if(patientAge >= 18 && patientAge <= 64)
       {
        printf("Adult \n");
        dosePerKg = 7;
        maxDose = 1000;
       }

       else if(patientAge >= 65)
       {
        printf("Senior \n");
        dosePerKg = 5;
        maxDose = 800;
       }

       dose = weight * dosePerKg;
       printf("Dose per kg = %f\n", dosePerKg);
       printf("Maximum single dose = %f\n", maxDose);

       if(dose > maxDose)
       {
        printf("Dose capped \n");
       }
       break;

      case 2:
        if(noOfPatients == 0)
        {
          printf("Assess a patient \n");
          break;
        } 

        else if(noOfPatients > 0)
        {
          bool checkerThree;

          do
          {
            printf("List of available drugs: \n");
            printf("Press 4 for Medacin \n");
            printf("Press 5 for Paxolin \n");
            printf("Press 6 for Zyrelief \n");
            printf("Select drug: \n");
            scanf("%d", &medicine);

            if(medicine <= 0 || medicine > 6)
            {
              printf("Not available, enter a valid number\n");
            }

            checkerThree = (medicine <= 0 || medicine > 6);
            
          } while(checkerThree);

           switch(medicine)
            {
              case 4:
                printf("Medacin \n");
                printf("Price = $2.50 \n");
                printf("Available units =  %d\n", availableUnitM);

                do
                {
                  printf("Enter needed quantity of medacin: \n");
                  scanf("%d", &quantity);

                  if(quantity <= 0)
                  {
                    printf("Enter a valid number \n");
                  }

                  else if(quantity > availableUnitM)
                  {
                    printf("quantity can't be more than current stock, enter a number that is available \n");
                  }

                  checkerFour = quantity <= 0;
                  checkerFive = quantity > availableUnitM;
                } while (checkerFour || checkerFive);

                payment1 = quantity * priceM;
                printf("Payment amount = %f\n", payment1);

                if(patientAge >= 65)
                {
                  discount = 0.10 * payment1;
                  payment1 -= discount;
                  printf("updated payment amount = %f\n", payment1);
                }
                
                printf("enter payment amount: \n");
                scanf("%f", &paymentAmount);

                if(paymentAmount == payment1)
                {
                  printf("dispensing medacin....\n");
                  availableUnitM -= quantity;
                  successCount++;
                  totalRevenue += paymentAmount;
                }

                else
                {
                  printf("Payment failed \n");
                  failedCount++;
                }

                if(availableUnitM <= 5)
                {
                  printf("Low stock \n");
                  break;
                }

                
              break;

              case 5:
                printf("Paxolin \n");
                printf("Price = $4.75 \n");
                printf("Available units =  %d\n", availableUnitP);

                do
                {
                  printf("Enter needed quantity of paxolin: \n");
                  scanf("%d", &quantity);

                  if(quantity <= 0)
                  {
                    printf("Enter a valid number \n");
                  }

                  else if(quantity > availableUnitP)
                  {
                    printf("quantity can't be more than current stock, enter a number that is available \n");
                  }

                  else if(quantity % 2 == 0)
                  {
                    payment2 = quantity * priceP;
                    printf("payment amount = %f\n", payment2);

                    
                    if(patientAge >= 65)
                    {
                     discount = 0.10 * payment2;
                     payment2 -= discount;
                     printf("updated payment amount %f\n", payment2);
                    }
                
                    printf("enter payment amount: \n");
                    scanf("%f", &paymentAmount);

                    if(paymentAmount == payment2)
                    {
                      printf("dispensing paxolin....\n");
                      availableUnitP -= quantity;
                      successCount++;
                      totalRevenue += paymentAmount;
                    }

                    else
                    {
                      printf("Payment failed \n");
                      failedCount++;
                    }

                    if(availableUnitP <= 5)
                    {
                      printf("Low stock \n");
                      break;
                    }
                  }

                  else if(quantity % 2 == 1)
                  {
                    printf("paxolin is only sold in pairs \n");
                  }

                  checkerFour = quantity <= 0;
                  checkerFive = quantity > availableUnitP;
                } while (checkerFour || checkerFive || quantity % 2 == 1);
              break;

              case 6:
                printf("Zyrelief \n");
                printf("Price = $3.20 \n");
                printf("Available units =  %d\n", availableUnitZ);

                do
                {
                  printf("Enter needed quantity of zyrelief: \n");
                  scanf("%d", &quantity);

                  if(quantity <= 0)
                  {
                    printf("Enter a valid number \n");
                  }

                  else if(quantity > availableUnitZ)
                  {
                    printf("quantity can't be more than current stock, enter a number that is available \n");
                  }

                  else if(quantity % 2 == 0 && patientAge > 12)
                  {
                    payment3 = quantity * priceZ;
                    printf("payment amount = %f \n", payment3);

                    if(patientAge >= 65)
                    {
                     discount = 0.10 * payment3;
                     payment3 -= discount;
                     printf("updated payment amount = %f\n", payment3);
                    }

                    printf("enter payment amount: \n");
                    scanf("%f", &paymentAmount);

                    if(paymentAmount == payment3)
                    {
                      printf("dispensing zyrelief....\n");
                      availableUnitZ -= quantity;
                      successCount++;
                      totalRevenue += paymentAmount;
                    }

                    else
                    {
                      printf("Payment failed \n");
                      failedCount++;
                    }

                    if(availableUnitZ <= 5)
                    {
                      printf("Low stock \n");
                      break;
                    }
                  }

                  checkerFour = quantity <= 0;
                  checkerFive = quantity > availableUnitZ;
                } while (checkerFour || checkerFive);
               break;

              default:
                printf("Invalid input \n");
            }      
            break;
        }
      case 3:
        printf("Medacin \n");
        printf("Available units = %d\n", availableUnitM);

        if(availableUnitM <= 5)
        {
          printf("Low stock \n");
        }
                
        printf("Paxolin \n");
        printf("Available units = %d \n", availableUnitP);

        if(availableUnitP <= 5)
        {
          printf("Low stock \n");
        }

        printf("Zyrelief \n");
        printf("Available units = %d\n", availableUnitZ);

        if(availableUnitZ <= 5)
        {
          printf("Low stock \n");
        }
        break;

      case 4:
        printf("patient assessed = %d\n", noOfPatients);
        printf("number of successful dispenses = %d\n", successCount);
        
        break;

      case 5:
        printf("Are you sure you want to exit? (y/n) \n");
        scanf(" %c", &confirm);

        if(confirm == 'y' || confirm == 'Y')
        {
          active = false;
        }

        else
        {
          printf("Returning to main menu \n");
        }
        break;

      default:
        printf("Invalid input \n");
    }
  } while(active);
  
 return 0;  
}
