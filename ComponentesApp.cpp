//
// Created by madeira on 02/11/24.
//

#include "ComponentesApp.h"

const string & ComponentesApp::getNome() const {
    return nome;
}

void ComponentesApp::setNome(const string &nome) {
    ComponentesApp::nome = nome;
}

PortaAndApp::PortaAndApp() {
    setNome("and");

    // setIsDragging(false);
    //
    // RectangleShape tmpShape;
    // tmpShape.setSize(Vector2f(50.f, 30.f));
    // tmpShape.setFillColor(Color::Blue);
    // tmpShape.setPosition(Vector2f(30, 100));
    //
    // Text tmpLabel;
    // tmpLabel.setFont(getFont());
    // tmpLabel.setString(getNome());
    // tmpLabel.setCharacterSize(14);
    // tmpLabel.setFillColor(Color::White);
    // tmpLabel.setPosition(position.x + 5, position.y + 5);
    //
    // setShape(tmpShape);
    // setLabel(tmpLabel);
}

void PortaAndApp::lerEntradaPortas() {
//implementação das entradas aqui
    // tmpLabel.setPosition(position.x + 5, position.y + 5);

}

ComponentesApp *PortaAndApp::alocarComponenteApp() {
    return new PortaAndApp;
}

WireApp::WireApp() {
    setNome("wire");
}

void WireApp::lerEntradaPortas() {
    //implementar a entrada de dados
}

ComponentesApp *WireApp::alocarComponenteApp() {
    return new WireApp;
}

// const RectangleShape & ComponentesApp::getShape() {
//     return shape;
// }
//
// const Text & ComponentesApp::getLabel() {
//     return label;
// }
//
// const bool ComponentesApp::getIsDragging() {
//     return isDragging;
// }
//
// void ComponentesApp::setShape(const RectangleShape &shape) {
//     ComponentesApp::shape = shape;
// }
//
// void ComponentesApp::setLabel(const Text &label) {
//     ComponentesApp::label = label;
// }
//
// void ComponentesApp::setIsDragging(const bool isDraggin) {
//     ComponentesApp::isDragging = isDragging;
// }
