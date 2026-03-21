#include <iostream>
#include <unistd.h>
#include "handle.h"
#include "rpginfo.h"

using namespace std;

void fightScenario(player &player1);
void fight(player &player1, monster &enemy);
void getPlayerInfo(player &player1);
void inBiome(player &player1);
void displayHud(player &player1, monster &enemy);
void holder();


int main(){
    string classChoice;
    string playerClass = "";
    string playerName = "";
    player player1;

    int tempMana = 0;
    int tempHp = 0;
    int tempSpeed = 0;
    int tempAttack = 0;
    int tempVigor = 100;

     system("cls");

   do{
     stc(9); cout<<"    Welcome to Vestrea RPG.  \n"; stc(7);
     cout<<" Select your class: \n 1 - Archer \n 2 - Warrior \n 3 - Wizard \n - "; stc(7);
     getline(cin, classChoice);
      if(classChoice == "1"){
         playerClass = "Archer";
         tempSpeed = 15;
         tempMana = 10;
         tempHp = 50;
         tempAttack = 4;
      }
      else if(classChoice == "2"){
         playerClass = "Warrior";
         tempHp = 60;
         tempMana = 10;
         tempSpeed = 5;
         tempAttack = 9;
      }
      else if(classChoice == "3"){
         playerClass = "Wizard";
         tempMana = 30;
         tempHp = 45;
         tempSpeed = 5;
         tempAttack = 4;
      }
      else{
         cout<<"You did not select a class.\n";
      }
    }while(playerClass == "");

   system("cls");

    do{
        cout<<" Choose your name!\n - ";
        getline(cin, playerName);
    }while(playerName=="");

   system("cls");

    if(playerClass == "Archer"){
        player1={playerName, playerClass, tempHp, tempSpeed, tempMana, tempVigor, tempAttack + 4, 3 ,"Shot arrow", "Punch", "Bow" };
    }
    else if(playerClass == "Warrior"){
        player1={playerName, playerClass, tempHp, tempSpeed, tempMana, tempVigor, tempAttack, 4 ,"Sword cut", "Punch", "Sword" };
    }
    else if(playerClass == "Wizard"){
        player1={playerName, playerClass, tempHp, tempSpeed, tempMana, tempVigor, tempAttack + 4, 4 , "Spell", "Punch", "Staff" };
    }

   cout<<"[Welcome "; stc(6); cout<<playerName; stc(7); cout<<" you are a "; stc(6); cout<<playerClass; stc(7); cout<<"!!]\n";

   inBiome(player1);

   sleep(1);

      return 0;
   }
   
 void inBiome(player &player1){
         srand(time(NULL));
         string scenario = "";
         int biomeColor;
         int tempRandomNumber = (rand()%3) + 1;
         switch(tempRandomNumber){
            case 1:
               scenario = "Florest";
               biomeColor = 2;
               break;
            case 2:
               scenario = "Plains";
               biomeColor = 10;
               break;
            case 3:
               scenario = "Tundra";
               biomeColor = 11;
               break;
            default:
               scenario = "Plains";
               biomeColor = 10;
               break;
           }
        
         string firstMove;
         bool idleing=true;
         while(idleing){
            if(player1.hp <= 0){
               idleing = false;
               system("cls");
               cout<<"You died, restart the game.";
            }
            else{
            cout<<"\n\n You are in a "; stc(biomeColor); cout<<scenario; stc(7); cout<<" biome, you can either: \n";
            cout<<" 1 - Explore around \n 2 - Stay still\n - ";
            getline(cin, firstMove);

            if(firstMove == "1"){
               fightScenario(player1); //add a explore biomes later
            }
            else if(firstMove == "2"){
               cout<<"Standing still..\n";
               sleep(4);
            }
            else{
                  cout<<"Invalid\n";
            }
           }
         }
}


void fightScenario(player &player1){
     system("cls"); 

     monster enemy;
     int availableMonsters=4;
     int tempRandomNumber = (rand()%availableMonsters) + 1;
       switch(tempRandomNumber) {
           case 1:
             enemy = bigSpider; 
             break;
           case 2:
             enemy = goblin;
             break;
           case 3:
             enemy = scorpion;
             break;
           case 4:
             enemy = dragon;
             break;
       }

     string optionFightOrRun;
     cout<<"You were walking around and found a "; stc(4); cout<<enemy.name; stc(7); cout<<"!!\n";
     cout<<" 1 - Fight\n 2 - Try to escape\n - ";
     getline(cin, optionFightOrRun);

     tempRandomNumber = (rand()%2) + 1;
      if(optionFightOrRun == "2"){
        switch(tempRandomNumber) {
           case 1:
             system("cls");
             cout<<"You did escape.\n";
             sleep(1);
             inBiome(player1);
             break;
           case 2:
             system("cls");
             cout<<"You did not escape, you got to fight him.\n";
             sleep(2);
             fight(player1, enemy);
             break;
         }
      }
      else if(optionFightOrRun == "1" || tempRandomNumber == 2){
        fight(player1, enemy);
      }
}

void fight(player &player1, monster &enemy){
   system("cls");
   cout<<"\n  Fight Started!!\n";
   stc(6); cout<<"    "<<player1.name; stc(7); cout<<" vs "; stc(4); cout<<enemy.name; stc(7);
   
   sleep(2);
   system("cls");

   bool playerWon;
   bool fighthing=true;

    while(fighthing){
       string answer;
       string abilityAnswer;
       bool selecting;

       if(player1.hp <= 0){
          playerWon = false;
          fighthing = false;
          break;
        }
       else if(enemy.hp <= 0){
          playerWon = true;
          fighthing = false;
          break;
        }
       else{
        
         if(player1.speed >= enemy.speed) {
            sleep(1); 
            system("cls");
         }
         else if(player1.speed < enemy.speed){
            displayHud(player1,enemy);
            int damage;
            cout<<"|----------------|\n";
            
            srand(time(NULL));
            int tempRandomNumber = (rand()%2)+1;
            switch(tempRandomNumber){
               case 1:
                 damage = enemy.damageOne;
                 break;
               case 2:
                 damage = enemy.damageTwo;
                 break;
            }
            cout<<"Player had "; stc(2); cout<<player1.hp; stc(7); cout<<" HP, ";
            player1.hp -= damage; 
            stc(4); cout<<enemy.name; stc(7); cout<<" did "; stc(12); cout<<damage; stc(7); cout<<" damage and now player has ";
            stc(2); player1.hp > 0 ? cout<<player1.hp : cout<<0;
            stc(7); cout<<" HP\n";

            holder();

            if(player1.hp <= 0){
               playerWon = false;
               fighthing = false;
               break;
            }

            system("cls");
         }
        
        selecting = true;
        while(selecting){
               displayHud(player1, enemy);

               do{
                  cout<<"|-- Options --|\n";
                  cout<<" 1 - Attack\n 2 - Check Status/Skills\n - ";
                  getline(cin, answer);
                  cout<<'\n';
               }while(answer != "1" && answer != "2");

               if(answer == "1"){
                  do{
                     cout<<"\n 1 - "<<player1.firstAbility<<"\n 2 - "<<player1.secondAbility<<"\n - ";
                     cin>>abilityAnswer;
                  }while(abilityAnswer != "1" && abilityAnswer != "2");

                  if(abilityAnswer == "1"){
                     cout<<enemy.name<<" had "; stc(2); cout<<enemy.hp; stc(7); cout<<" HP, ";
                     enemy.hp -= player1.damageOne; 
                     stc(6); cout<<player1.name; stc(7); cout<<" did "; stc(12); cout<<player1.damageOne; stc(7); cout<<" damage and now enemy has ";
                     stc(2); enemy.hp > 0 ? cout<<enemy.hp : cout<<0;
                     stc(7); cout<<" HP\n";
                     holder();
                     selecting = false;
                     if(enemy.hp <=0){
                        fighthing = false;
                        playerWon = true;
                     }
                  }
                  else if(abilityAnswer == "2"){
                     cout<<enemy.name<<" had "; stc(2); cout<<enemy.hp; stc(7); cout<<" HP, ";
                     enemy.hp -= player1.damageTwo; 
                     stc(6); cout<<player1.name; stc(7); cout<<" did "; stc(12); cout<<player1.damageTwo; stc(7); cout<<" damage and now enemy has ";
                     stc(2); enemy.hp > 0 ? cout<<enemy.hp : cout<<0;
                     stc(7); cout<<" HP\n";
                     holder();
                     selecting = false;
                     if(enemy.hp <=0){
                        fighthing = false;
                        playerWon = true;
                     }
                  }
               }
               else if(answer == "2"){
                  getPlayerInfo(player1);
               }
         }
        
        if(player1.speed > enemy.speed && enemy.hp > 0){
            displayHud(player1,enemy);
            int damage;
            cout<<"|----------------|\n";

            srand(time(NULL));
            int tempRandomNumber = (rand()%2)+1;
            switch(tempRandomNumber){
               case 1:
                 damage = enemy.damageOne;
                 break;
               case 2:
                 damage = enemy.damageTwo;
                 break;
            }
            cout<<"Player had "; stc(2); cout<<player1.hp; stc(7); cout<<" HP, ";
            player1.hp -= damage; 
            stc(4); cout<<enemy.name; stc(7); cout<<" did "; stc(12); cout<<damage; stc(7); cout<<" damage and now player has ";
            stc(2); player1.hp > 0 ? cout<<player1.hp : cout<<0;
            stc(7); cout<<" HP\n";

            holder();
            sleep(2);
        }
       sleep(2);

      }
    }

   if(playerWon){
      system("cls");
      stc(6); cout<<player1.name; stc(7); cout<<" won the battle against "; stc(4); cout<<enemy.name; stc(7); cout<<"!!\n";
      cout<<"You got a "<<enemy.drop<<" from him.\n";
      holder();
   }
   else{
      system("cls");
      stc(4); cout<<enemy.name; stc(7); cout<<" won the battle against "; stc(6); cout<<player1.name; stc(7); cout<<"!!\n";
      holder();
   }

   stc(7);
}

void getPlayerInfo(player &player1){
     cout<<"\n Name: "; cout<<player1.name;
     cout<<"\n Class: "; stc(6); cout<<player1.fplayerClass; stc(7);
     cout<<"\n HP: ";  stc(2); cout<<player1.hp; stc(7);
     cout<<"\n Speed: ";  stc(3);  cout<<player1.speed; stc(7);
     cout<<"\n Mana: ";   stc(11); cout<<player1.mana; stc(7);
     cout<<"\n Vigor: ";  stc(3);  cout<<player1.vigor; stc(7);
     cout<<"\n First Ability: "; cout<<player1.firstAbility;
     cout<<"\n Second Ability: "; cout<<player1.secondAbility;
     cout<<"\n Item: ";  stc(14);  cout<<player1.item;   stc(7);
     cout<<'\n';
     holder();
     system("cls");
} 

void displayHud(player &player1, monster &enemy){
     system("cls");
     cout<<"\n\n["; stc(4); cout<<" "<<enemy.name; stc(7); cout<<" ]";
     cout<<" [  "; stc(2); cout<<enemy.hp; stc(7); cout<<" Hp ]\n";
     cout<<"\n\n["; stc(6); cout<<" "<<player1.name; stc(7); cout<<" ]";
     cout<<" [  "; stc(2); cout<<player1.hp; stc(7); cout<<" Hp   ]\n";
}

void holder(){
   string answer;
   stc(8); cout<<"-Press Enter to continue "; stc(7);
   getline(cin, answer);
}
