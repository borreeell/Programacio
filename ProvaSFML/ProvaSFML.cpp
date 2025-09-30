// ProvaSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(500, 500), "Title", Style::Close); // Defineix la finestra amb les propietats
    window.setFramerateLimit(60);

    RectangleShape rect(Vector2f(50, 50)); // Creem un rectangle dins de la finestra
    rect.setFillColor(Color::Red); // Color del rectangle
    rect.setOrigin(Vector2f(25, 25)); // Origen de l'objecte
    rect.setPosition(Vector2f(50, 50)); // Posicio de l'objecte

    while (window.isOpen()) {
        Event event;

        // Comprova els events
        while (window.pollEvent(event)) {
            // Si l'event es = tancar, tanca la finestra
            if (event.type == Event::Closed) {
                window.close();
            }
        }


        window.clear(Color::Black); // Color de fons de la finestra
        window.draw(rect); // Dibuixem el rectangle
        window.display(); // Renderitzem la finestra
    }
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
