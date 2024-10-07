#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

class tPoint {

private:
  sf::CircleShape point;
  sf::Vector2f position;
  sf::Vector2f speed;

public:
  tPoint(float x = 0, float y = 0)
      : position(x, y), speed(rand() % 50 + 1, rand() % 50 + 1) {
    point.setRadius(5);
    point.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    point.setPosition(position);
  }

  void updateLM(float time, sf::Vector2u windowSize);
  void updateRM(float time, sf::Vector2u windowSize);
  void draw(sf::RenderWindow &window);
};