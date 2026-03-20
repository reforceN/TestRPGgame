
struct monster{
      std::string name;
      int hp;
      int speed;
      int damageOne;
      int damageTwo;
      std::string drop;
      std::string firstAbility;
      std::string secondAbility;
};

struct player{
    std::string name;
    std::string fplayerClass;
    int hp;
    int speed;
    int mana;
    int vigor;
    int damageOne;
    int damageTwo;
    std::string firstAbility;
    std::string secondAbility;
    std::string item;
};


 monster bigSpider{"Giant Spider", 8, 8, 3, 1,"String", "Poison Bite", "Attack" };
 monster scorpion{"Scorpion", 12, 8, 6, 3, "Scorpion Scale", "Bite", "Attack"};
 monster goblin{"Goblin", 15, 4, 8, 4,"Rusty Sword", "Rush", "Attack" };
 monster dragon{"Dragon", 200, 15, 50, 20, "Dragon Scale", "Fire Ball", "Attack" };



