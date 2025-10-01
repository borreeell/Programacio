// MosaicMondrianSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

// Funcio per construir el mosaic segons la mida actual de la finestra
void mosaicMondrian(vector<RectangleShape>& formes, vector<RectangleShape>& linies)
{
    formes.clear();
    linies.clear();

    // Variables geometriques principals
    RectangleShape rectangleBlanc, separador, rectangleGroc, quadratBlau, quadratVermell;

    rectangleBlanc.setSize(Vector2f(101, 46));
    rectangleBlanc.setPosition(0, 0);
    rectangleBlanc.setFillColor(Color::White);
    formes.push_back(rectangleBlanc);

    separador.setSize(Vector2f(13, 46));
    separador.setPosition(101, 0);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    rectangleBlanc.setSize(Vector2f(326, 46));
    rectangleBlanc.setPosition(114, 0);
    rectangleBlanc.setFillColor(Color::White);
    formes.push_back(rectangleBlanc);

    separador.setSize(Vector2f(13, 46));
    separador.setPosition(440, 0);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    quadratVermell.setSize(Vector2f(262, 46));
    quadratVermell.setPosition(450, 0);
    quadratVermell.setFillColor(Color::Red);
    formes.push_back(quadratVermell);

    separador.setSize(Vector2f(13, 500));
    separador.setPosition(699, 0);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    quadratBlau.setSize(Vector2f(260, 500));
    quadratBlau.setPosition(710, 0);
    quadratBlau.setFillColor(Color::Blue);
    formes.push_back(quadratBlau);

    separador.setSize(Vector2f(13, 500));
    separador.setPosition(940, 0);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    separador.setSize(Vector2f(710, 13));
    separador.setPosition(0, 46);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    quadratVermell.setSize(Vector2f(300, 500));
    quadratVermell.setPosition(0, 59);
    quadratVermell.setFillColor(Color::Red);
    formes.push_back(quadratVermell);

    separador.setSize(Vector2f(13, 500));
    separador.setPosition(300, 59);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    rectangleGroc.setSize(Vector2f(385, 500));
    rectangleGroc.setPosition(313, 59);
    rectangleGroc.setFillColor(Color::Yellow);
    formes.push_back(rectangleGroc);
}

int main()
{
    VideoMode mode(950, 500);
    RenderWindow finestra(mode, "Mosaic Mondrian", Style::Close);

    vector<RectangleShape> formes;
    vector<RectangleShape> linies;
    
    // Construccio de mosaic
    mosaicMondrian(formes, linies);

    while (finestra.isOpen()) {
        Event event;

        // Comprova els events
        while (finestra.pollEvent(event)) {
            // Habilita el boto de tancar la finestra
            if (event.type == Event::Closed) {
                finestra.close();
            }
        }
        
        // Dibuixa els blocs de color
        for (auto& f : formes) finestra.draw(f);
        
        finestra.display();
    }

    return 0;
}