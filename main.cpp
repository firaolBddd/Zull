//Firaol Berehanu
//this code run the actul game logic of zull
//zull is a text based adventure game
//the obejctive is to get into the school 
//find all the mystical tressuare and use an
//ender peral to get back home
//12/3/2023


#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
#include <map>


using namespace std;

int main(){
  char input[80];
  char output[80];
  char item1[80];
  char item2[80];
  vector<Item*> Inventory;

  //directions
  char* north = (char*)("North");
  char* east = (char*)("East");
  char* south = (char*)("South");
  char* west = (char*)("West");

  //room init
  Room* outside = new Room();
  outside->setName((char*)("outside "));
  Room*Spell_class = new Room();
 Spell_class->setName((char*)("Spell_class"));
  Room* Gym = new Room();
  Gym->setName((char*)("Gym"));
  Room* charms_class = new Room();
  charms_class->setName((char*)("charms_class "));
  Room* healing_office = new Room();
  healing_office->setName((char*)("healing_office "));
  Room* Cortyard = new Room();
  Cortyard->setName((char*)("Cortyard "));
  Room* Math_class = new Room();

Math_class->setName((char*)("Math_class "));
  Room* Flying_Broom_closet = new Room();
  Flying_Broom_closet->setName((char*)("Flying_Broom_closet "));
  Room* Janitor_closet = new Room();
  Janitor_closet->setName((char*)("Janitor_closet "));
  Room* potion_class = new Room();
  potion_class->setName((char*)("potion_class "));
  Room* Deans_office = new Room();
  Deans_office->setName((char*)("Deans_office "));
  Room* Front_desk = new Room();
  Front_desk->setName((char*)("Front_desk "));
  Room* Magical_Beast_yard = new Room();
  Magical_Beast_yard->setName((char*)("Magical_Beast_yard "));
  Room* Law_class = new Room();
  Law_class->setName((char*)("Law_class "));
  Room* weapons = new Room();
  weapons->setName((char*)("weapons "));
  Room* Magic_101 = new Room();
  Magic_101->setName((char*)("Magic_101 "));

  //outside
  outside->setExit(east, Magic_101);
  outside->setExit(south, potion_class);
  outside->setExit(west,Spell_class);
  //Spell_class
 Spell_class->setExit(east, outside);
 Spell_class->setExit(west, Gym);
  //Gym
  Gym->setExit(east ,Spell_class);
  Gym->setExit(south , charms_class);
  //charms_class
  charms_class->setExit(north, Gym);
  charms_class->setExit(east, Cortyard);
  charms_class->setExit(south, Math_class);
  charms_class->setExit(west, healing_office);
  //healing_office
  healing_office->setExit(east, charms_class);
  //Cortyard
  Cortyard->setExit(west, charms_class);
  //Math_class
  Math_class->setExit(north, charms_class);
  Math_class->setExit(east, Flying_Broom_closet);
  //Flying_Broom_closet
  Flying_Broom_closet->setExit(west, Math_class);
  Flying_Broom_closet->setExit(east, Janitor_closet);
  //Janitor_closet
  Janitor_closet->setExit(west, Flying_Broom_closet);
  Janitor_closet->setExit(east, potion_class);
  //potion_class
  potion_class->setExit(west, Janitor_closet);
  potion_class->setExit(north, outside);
  potion_class->setExit(east, Deans_office);
  //Deans_office
  Deans_office->setExit(west, potion_class);
  Deans_office->setExit(east, Front_desk);
  //Front_desk
  Front_desk->setExit(west, Deans_office);
  Front_desk->setExit(north, Law_class);
  Front_desk->setExit(east, Magical_Beast_yard);
  //Magical_Beast_yard
  Magical_Beast_yard->setExit(west, Front_desk);
  //Law_class
  Law_class->setExit(south, Front_desk);
  Law_class->setExit(north, weapons);
 //weapons
  weapons->setExit(south, Law_class);
  weapons->setExit(north, Magic_101);
  //Magic_101
  Magic_101->setExit(south, weapons);
  Magic_101->setExit(west, outside);

  healing_office->addItem((char*)("Sight_Potion"));
  Cortyard->addItem((char*)("Charm_of_undying"));
  weapons->addItem((char*)("Cloack_of_inveisabilty"));
  Magical_Beast_yard->addItem((char*)("Pheniox_dagger"));
  Front_desk->addItem((char*)("Ender_perl"));
  outside->addItem((char*)("Grimoire"));

  //actual gameplay time
  Room* roomCurrent = outside;
  cout << "Welcome to Zuul! Input 'help' for commands" << endl;
  cout << "This your first mission as a wizard but it wont be easy!" << endl;
  cout << "gather all 5 mystical treasures and then find an ender perl" << endl;
  cout << "through the ender perl outside to telport you back to hogwartz" << endl;

  while(true){
    roomCurrent->printDesc(output); //prints current room
    cout << "What do you want to do?" << endl;
    cin >> input;
    cout << endl;
    if(strcmp(input, "inv") == 0){ //INVENTORY ======================
      cout << "Inventory: " << endl;
      if(Inventory.size() > 0){
        for(int i = 0; i < Inventory.size(); i++){
          Inventory[i]->getName(output);
          cout << output << endl;
        }
      }
    }else if(strcmp(input, "take") == 0){//TAKE ======================
      cout << "Which item?" << endl;
      cin >> input;
      if(strcmp(input, "Ender_perl") == 0 && roomCurrent == outside){
        cout << "You have found teh sacred tressaures, no throw the perl and lets get you home!! " << endl;
        if(Inventory.size() > 4){//win condition
          cout << "you have completed your mission young wizard" << endl;
          return 0;
        }else{
          cout << "not quite yet i think your missing somthing " << endl;
        }
      }else{
        roomCurrent->giveItems(Inventory, input);
      }
    }else if(strcmp(input, "drop") == 0){ //DROP ======================
      cout << "Which item?" << endl;
      cin>> input;
      roomCurrent->takeItems(Inventory, input);
    }else if(strcmp(input, "move") == 0){ //MOVE ======================
      cout << "'North', 'East', 'South', or 'West'?" << endl;
      cin >> input;
      cout << endl;
      roomCurrent->getExit(input, roomCurrent);
    }else if(strcmp(input, "help") == 0){ //HELP ======================
      cout << "Possible commands: 'move', 'help', 'quit', 'inv', take, drop" << endl;
    }else if(strcmp(input, "quit") == 0){ //QUIT ======================
      cout << "Thank you for playing Zuul :3";
      return 0;
    }else{
      cout << "Sorry, you can't do that. Input 'help' for help" << endl;
    }
  }
  return 0;
}

