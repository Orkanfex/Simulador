//
// Created by madeira on 02/11/24.
//

#ifndef COMPONENTESAPP_H
#define COMPONENTESAPP_H

# include <string>
#include "Componentes.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class ComponentesApp {
    string nome;
    RectangleShape shape;
    Text label;
    Font fonte;
    bool isDragging;
    //talvez as posições dos componentes entram aqui

public:
    const string &getNome() const;
    // const RectangleShape &getShape();
    // const Text &getLabel();
    // const bool getIsDragging();
    // const Font &getFont();
    void setNome(const string &nome);
    // void setShape(const RectangleShape &shape);
    // void setLabel(const Text &label);
    // void setFont(const Font &font);
    // void setIsDragging(const bool isDraggin);
    virtual void lerEntradaPortas()=0;
    virtual ComponentesApp* alocarComponenteApp() = 0;
};

class PortaAndApp: private AND, public ComponentesApp {
public:
    PortaAndApp();
    void lerEntradaPortas() override;
    ComponentesApp *alocarComponenteApp() override;
};

class WireApp: private WIRE, public ComponentesApp {
public:
    WireApp();
    void lerEntradaPortas() override;
    ComponentesApp *alocarComponenteApp() override;
};



#endif //COMPONENTESAPP_H
