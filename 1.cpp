//Jorge Martinez
//CPSC 121
// 11/28/18
#include<iostream>
#include<string>
#include <time.h>
#include <chrono>
#include <thread>
//note: this is a rough draft that dealt with the Gladiator as a struct, not a class
//I need to figure out how to use Gladiator as a class, using what was provided
//the class has been defined in the assignment's .cpp file
using namespace std;
//Define struct for Gladiator
struct Gladiator
{
     string name;
     float maxhealth;
     float currenthealth;
     float evasion;
     float critical;
     int mindamage;
     int damagerange;
};
//Define the function createGladiator().
Gladiator createGladiator(string name)
{
     Gladiator g;
     g.name = name;
     //Use the random function to assign the values.
     g.maxhealth = (3 + (rand() % (int)(5 - 3 + 1)))*50;
     g.evasion = (2 + (rand() % (int)(5))) * 2.5;
     g.critical = (2 + (rand() % (int)(6 - 2 + 1))) * 2.5;
     g.mindamage = (8 + (rand() % (int)(14 - 8 + 1)));
     g.damagerange = (16 + (rand() % (int)(22-16+1)));
     g.currenthealth = g.maxhealth;
     return g;
}
//Define the function showstats().
void showStats(Gladiator g)
{
     //Display the stats for the gladiator.
     cout << "The stats are as follows: \n";
     cout << "Name :" << g.name << endl;
     cout << "Max health: " << g.maxhealth << endl;
     cout << "Critical hit chance: " << g.critical << endl;
     cout << "Evasion Chance: " << g.evasion << endl;
     cout << "Damage range: " << g.damagerange << endl;
     cout << "Minimum damage: " << g.mindamage << endl;
     cout << "Current Health: " << g.currenthealth << endl;
}
//Define the function takeTurn().
void takeTurn(Gladiator &a, Gladiator &b)
{
     cout << endl;
     //Use the random function to set the values.
     int num1;
     int num = (1 + (rand() % (int)(100)));
     //Check the values.
     if (num <= b.evasion)
     {
          //Display the result.
          cout << b.name << " evaded!!" << endl;
     }
     else
     {
          //Use the random function to set the values.
          num = (a.mindamage + (rand() % (int)(a.damagerange - a.mindamage + 1)));
          num1 = (1 + (rand() % (int)(100)));
          //Compare the values.
          if (num1 <= a.critical)
          {
               //Update the current health.
               b.currenthealth=b.currenthealth-(num*2);
               //Display the result.
               cout << "critical attack by: " << a.name
                     << " (Damage = " << num * 2 << ")" << endl;
          }
          else
          {
               //Update the current health.
               b.currenthealth = b.currenthealth - num;
               //Display the result.
               cout << "Normal Hit by: " << a.name << " (Damage = " << num << ")" << endl;
          }
     }
     //Set the health to 0 if the health is less than 0.
     if (b.currenthealth<0)
     {
          b.currenthealth = 0;
     }
}
//Define the main() function.
int main()
{
     //Declare the required variables.
     string name;
     Gladiator g1;
     Gladiator g2;
     char same = 'n';
     char ar = 'r';
     char rematch = 'y';
     //Start the loop.
     while (rematch == 'y' || rematch == 'Y')
     {
          ar = 'r';
          //Check if same gladiator is used or not.
          if (same != 'y' && same != 'Y')
          {
               //Prompt the user to enter the values.
               cout << "Enter the name of the first gladiator: ";
               cin >> name;
               srand(time(NULL));
               //Call the function createGladiator()
// to assign the values.
               g1 = createGladiator(name);
               //Display the details.
               showStats(g1);
               //Start the loop if user enters reject.
               while (ar == 'r')
               {
                     //Prompt the user to enter
// the choice.
                     cout << "Accept or reject(a/r)??: ";
                     cin >> ar;
                     if (ar == 'r')
                     {
                          cout << "\nThe new gladiator is as follows:\n";
                          //Randomize the values.
                          srand(time(NULL));
                          //Set the details.
                          g1 = createGladiator(name);
                          //Display the values.
                          showStats(g1);
                     }
               }
               ar = 'r';
               //Prompt the user to enter the name of
// the second gladiator.
               cout << "\nEnter the name of the second gladiator: ";
               cin >> name;
               //Randomize the values.
               srand(time(NULL));
               //Set the values.
               g2 = createGladiator(name);
               //Display the values.
               showStats(g2);
               //Start the loop.
               while (ar == 'r')
               {
                     //Prompt the user to enter
// the choice.
                    cout << "Accept or reject(a/r)??: ";
                     cin >> ar;
                     if (ar == 'r')
                     {
                          cout << "\nThe new gladiator is as follows:\n";
                          //Randomize the values.
                          srand(time(NULL));
                          //Set the details.
                          g2 = createGladiator(name);
                          //Display the values.
                          showStats(g2);
                     }
               }
          }
          //Reset health if the same gladiator is used.
          else
          {
               g1.currenthealth = g1.maxhealth;
               g2.currenthealth = g2.maxhealth;
          }
          cout << "\n\nThe game begins now!\n\n";
          while(g1.currenthealth>0 && g2.currenthealth>0)
          {
               //Randomize the values.
               srand(time(NULL));
               //Pause the screen for 1 second.
               this_thread::sleep_for(chrono::seconds(1));// lets me have a timed delay so that the fight does not progress so fast
               //Call the function takeTurn().
               takeTurn(g1, g2);
               //Display the result.
               cout << "Current Health: ";
               cout << g1.name << ": " << g1.currenthealth;
               cout << " | " << g2.name << ": " << g2.currenthealth << endl;
               //Randomize the values.
               srand(time(NULL));
               this_thread::sleep_for(chrono::seconds(1));
               //Pause the screen for 1 second.
               if (g2.currenthealth > 0)
               {
                     //Call the function takeTurn().
                     takeTurn(g2, g1);
                     //Display the result.
                     cout << "Current Health: ";
                     cout << g1.name << ": " << g1.currenthealth;
                     cout << " | " << g2.name << ": " << g2.currenthealth << endl;
               }
               //Break the lopp if health is 0.
               else
               {
                     break;
               }
          }
          //Check the current health and display
// the result.
          if (g1.currenthealth>0)
          {
               cout << endl << g1.name << " wins!!"
<< endl;
          }
          else
          {
               cout << endl << g2.name << " wins!!"
<< endl;
          }
          //Prompt the user to enter the choice.
          cout << "\nDo you want rematch? (y/n): ";
          cin >> rematch;
          //Check the user input.
          if (rematch == 'y' || rematch == 'Y')
          {
               //Prompt the user to enter the choice.
               cout << "Do you want to continue with the same fighters? (y/n): ";
               cin >> same;
          }
     }
     //Use for Microsoft visual studio.
     system("pause");
     return 0;
}

