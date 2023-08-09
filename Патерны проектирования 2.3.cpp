// Добавить к коду на слайде 24 презентации по Паттернам проектирования (выслана в Тимс) возможность создавать игровые компьютеры.

#include <iostream>
using namespace std;

//Продукт (PC) определяет интерфейс объектов, создаваемых фабричным методом
class PC abstract
{
protected:
    string box = "";
    string processor = "";
    string mainboard = "";
    string hdd = "";
    string memory = "";
public:
    virtual void SetBox() = 0;
    virtual void SetProcessor() = 0;
    virtual void SetMainboard() = 0;
    virtual void SetHdd() = 0;
    virtual void SetMemory() = 0;
    void ShowPC()
    {
        cout << "Box: " + box
            + "\nProcessor: " + processor
            + "\nMainboard: " + mainboard
            + "\nHdd: " + hdd
            + "\nMemory: " + memory
            + "\n\n";
    }
};
//Конкретный продукт реализует интерфейс Product (в нашем случае, РС)
class OfficePC :public PC
{
public:
    void SetBox()override
    {
        box = "BlackBox";
    }
    void SetProcessor()override
    {
        processor = "AMD Athlon II X4 840 (3.1 GHz)";
    }
    void SetMainboard()override
    {
        mainboard = "AMD A58 FCH (Bolton D2)";
    }
    void SetHdd()override
    {
        hdd = "Seagate Desktop HDD 7200.12 500GB";
    }
    void SetMemory()override
    {
        memory = "4 Gb DDR3-1600 MHz";
    }
};

//Конкретный продукт реализует интерфейс Product (в нашем случае, РС)
class HomePC :public PC
{
public:
    void SetBox()override
    {
        box = "SilverBox";
    }
    void SetProcessor()override
    {
        processor = "Intel Core i7-4790 (3.6 GHz)";
    }
    void SetMainboard()override
    {
        mainboard = "Intel B85";
    }
    void SetHdd()override
    {
        hdd = "Western Digital Elements 1.5TB";
    }
    void SetMemory()override
    {
        memory = "16 Gb DDR3-1600 MHz";
    }
};

class GamePC :public PC
{
public:
    void SetBox()override
    {
        box = "BlackRedBox";
    }
    void SetProcessor()override
    {
        processor = "AMD Ryzen 9 5900X (4.8 GHz)";
    }
    void SetMainboard()override
    {
        mainboard = "MSI MPG X570 GAMING EDGE WIFI";
    }
    void SetHdd()override
    {
        hdd = "Western Digital Blue 3D NAND SATA SSD 1TB";
    }
    void SetMemory()override
    {
        memory = "Corsair Vengeance RGB Pro 32GB (2 x 16GB) DDR4-3200MHz";
    }
};


//создатель объявляет фабричный метод, возвращающий объект типа Product.
class Creator abstract
{
public:
    virtual PC* FactoryMethod() = 0;
};

//конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorHomePC :public Creator
{
public:
    PC* FactoryMethod()override
    {
        PC* pc = new HomePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainboard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

//конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorOfficePC :public Creator
{
public:
    PC* FactoryMethod()override
    {
        PC* pc = new OfficePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainboard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

class CreatorGamePC :public Creator
{
public:
    PC* FactoryMethod()override
    {
        PC* pc = new GamePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainboard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

//Паттерн позволяет использовать в клиентском коде программы не специфические
//классы, а манипулировать абстрактными объектами на более высоком уровне.
void Factory(Creator** creators, int size)
{
    //Создатель "полагается" на свои подклассы в определении фабричного метода,
    //который будет возвращать экземпляр подходящего конкретного продукта.
    for (int i = 0; i < size; i++)
    {
        PC* pc = creators[i]->FactoryMethod();
        pc->ShowPC();
    }
}

int main()
{
    Creator* creators[3];
    creators[0] = new CreatorHomePC();
    creators[1] = new CreatorOfficePC();
    creators[2] = new CreatorGamePC();
    Factory(creators, 3);
}
