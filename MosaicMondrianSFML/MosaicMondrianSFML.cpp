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
    RectangleShape rectangleBlanc, separador, rectangleGroc, quadratBlau;

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

    rectangleGroc.setSize(Vector2f(262, 46));
    rectangleGroc.setPosition(450, 0);
    rectangleGroc.setFillColor(Color::Yellow);
    formes.push_back(rectangleGroc);

    separador.setSize(Vector2f(13, 46));
    separador.setPosition(699, 0);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);

    quadratBlau.setSize(Vector2f(260, 147));
    quadratBlau.setPosition(710, 0);
    quadratBlau.setFillColor(Color::Blue);
    formes.push_back(quadratBlau);

    separador.setSize(Vector2f(710, 13));
    separador.setPosition(0, 46);
    separador.setFillColor(Color(59, 61, 60));
    formes.push_back(separador);
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

        while (finestra.pollEvent(event)) {
            if (event.type == Event::Closed) {
                finestra.close();
            }
        }



        //finestra.clear(Color::Black);
        
        // Dibuixa els blocs de color
        for (auto& f : formes) finestra.draw(f);
        
        finestra.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
