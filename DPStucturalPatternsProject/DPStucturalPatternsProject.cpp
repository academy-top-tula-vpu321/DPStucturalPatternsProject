#include <iostream>
#include "Composite.h"


int main()
{
    srand(time(nullptr));

    std::vector<IFactory*> factories;
    factories.push_back(new InfantryFactory());
    factories.push_back(new ArcherFactory());
    factories.push_back(new HorsemanFactory());

    Unit* legion1 = new GroupUnit("Legion 1");
    for (int i{}; i < 5; i++)
    {
        auto legion = (GroupUnit*)legion1;
        Unit* unit = factories[rand() % factories.size()]->Create();
        legion->Add(unit);
    }

    Unit* legion2 = new GroupUnit("Legion 2");
    for (int i{}; i < 10; i++)
    {
        auto legion = (GroupUnit*)legion2;
        Unit* unit = factories[rand() % factories.size()]->Create();
        legion->Add(unit);
    }

    Unit* falanga1 = new GroupUnit("Falanga 1");
    for (int i{}; i < 7; i++)
    {
        auto legion = (GroupUnit*)falanga1;
        Unit* unit = factories[rand() % factories.size()]->Create();
        legion->Add(unit);
    }
    ((GroupUnit*)legion1)->Add(falanga1);

    std::cout << falanga1->ToString() << "\n";
    std::cout << legion1->ToString() << "\n";

    Unit* army = new GroupUnit("Army");
    ((GroupUnit*)army)->Add(legion1);
    ((GroupUnit*)army)->Add(legion2);

    std::cout << army->ToString() << "\n";
}
