#include "tPoint.hpp"

int main(void) {
  srand(unsigned(time(NULL)));

  const short num = 100;
  std::vector<tPoint> points;

  for (int i = 0; i < num; i++) {
    points.emplace_back(rand() % 800, rand() % 600);
  }

  sf::RenderWindow window(sf::VideoMode(800, 600),
                          "To4ki moi lyubimie, to4e4ki");
  sf::Clock clock;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    float time = clock.restart().asSeconds();

    window.clear();

    for (auto &point : points) {
      point.updateRM(time, window.getSize());
      point.draw(window);
    }

    window.display();
  }
}