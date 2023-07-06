//
//
//

#ifndef PROG2_PC3_2021_2_PC3_H
#define PROG2_PC3_2021_2_PC3_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class CPizza {
protected:
    vector<string> ingredientes;
    double precio;
public:
    CPizza(){};
    CPizza(double _precio): precio(_precio) {}
    void listar_ingredientes() {
        cout << "Ingredientes:\n";
        for (auto& item: ingredientes)
            cout <<"- " << item << endl;
    }
    virtual void preparar() = 0;
    double get_precio() { return precio; }
};

class CHawaiana: public CPizza {
public:
        CHawaiana(double _precio): CPizza(_precio) {
        ingredientes.emplace_back("Pinna");
        ingredientes.emplace_back("Masa Blanda");
        ingredientes.emplace_back("Queso");
        ingredientes.emplace_back("Salsa de tomate");
    }
    void preparar() override {
        cout << "Preparacion de Hawaiana:" << endl;
        cout << "Untar salsa de tomate sobre la masa" << endl;
        cout << "Agregar queso y pinna"<< "\n";
    }
};

class CPepperoni: public CPizza {
    bool incluyeBordeDeQueso = false;
public:
    CPepperoni(double precio,
               bool incluyeBordeDeQueso): CPizza(precio),
               incluyeBordeDeQueso(incluyeBordeDeQueso) {
        ingredientes.emplace_back("Pepperoni");
        ingredientes.emplace_back("Jamon");
        ingredientes.emplace_back("Queso Mozzarella");
        ingredientes.emplace_back("Masa gruesa");
        ingredientes.emplace_back("Salsa de tomate");
    }
    void preparar() override {
        cout << "Preparacion de Pepperoni:" << endl;
        cout << "Untar salsa de tomate sobre la masa " << endl;
        cout << "Adicionar queso, jamon y finalmente el peperoni"<< "\n";
        if (incluyeBordeDeQueso)
            cout << "NOTA: Incluir borde de Queso\n";
    }
};

class COrden {
    vector<CPizza*> pizzas;
public:
    COrden() {}
    void agregar_pizza(CPizza* pizza) {
        pizzas.push_back(pizza);
    }

    friend ostream& operator << (ostream& os, COrden& orden) {
        for (int i = 0; i < orden.pizzas.size(); ++i) {
            os << "Pizza #" << i + 1 << ":\n";
            orden.pizzas[i]->listar_ingredientes();
            orden.pizzas[i]->preparar();
            os << "--------------------------\n";
        }
        return os;
    }
};

#endif //PROG2_PC3_2021_2_PC3_H
