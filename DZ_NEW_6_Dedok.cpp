#include <iostream>
using namespace std;
enum EntityType {
    BIRD,
    LIVESTOCK,
    HUMAN
};

union Characteristic {
    float flightSpeed;   
    bool clovenHoofed;   
    int iqLevel;        
};

struct LivingEntity {
    float movementSpeed;
    EntityType type;
    char color[20];
    Characteristic characteristic;
};

void inputLivingEntity(LivingEntity& entity) {
    cout << "Введите скорость передвижения: ";
    cin >> entity.movementSpeed;

    int type;
    cout << "Введите тип (0 - птица, 1 - скот, 2 - человек): ";
    cin >> type;
    entity.type = EntityType(type);

    cout << "Введите цвет: ";
    cin >> entity.color;

    switch (entity.type) {
    case BIRD:
        cout << "Введите скорость полета: ";
        cin >> entity.characteristic.flightSpeed;
        break;
    case LIVESTOCK:
        cout << "Это парнокопытное? (0 - нет, 1 - да): ";
        cin >> entity.characteristic.clovenHoofed;
        break;
    case HUMAN:
        cout << "Введите уровень IQ: ";
        cin >> entity.characteristic.iqLevel;
        break;
    default:
        break;
    }
}

void printLivingEntity(const LivingEntity& entity) {
    cout << "Скорость передвижения: " << entity.movementSpeed << "\n";
    cout << "Тип: ";
    switch (entity.type) {
    case BIRD:
        cout << "Птица" << "\n";
        break;
    case LIVESTOCK:
        cout << "Скот" << "\n";
        break;
    case HUMAN:
        cout << "Человек" << "\n";
        break;
    default:
        break;
    }
    cout << "Цвет: " << entity.color << "\n";

    switch (entity.type) {
    case BIRD:
        cout << "Скорость полета: " << entity.characteristic.flightSpeed << "\n";
        break;
    case LIVESTOCK:
        cout << (entity.characteristic.clovenHoofed ? "Парнокопытное" : "Не парнокопытное") << "\n";
        break;
    case HUMAN:
        cout << "Уровень IQ: " << entity.characteristic.iqLevel << "\n";
        break;
    default:
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    LivingEntity entity;

    inputLivingEntity(entity);
    printLivingEntity(entity);
}
