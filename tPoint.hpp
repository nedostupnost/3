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
      : position(x, y), speed(rand() % 3, rand() % 3) {
    point.setRadius(5);
    point.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    point.setPosition(position);
  }

  void updateLM(float time, sf::Vector2u windowSize,
                std::vector<tPoint> &points);
  void updateRM(float time, sf::Vector2u windowSize,
                std::vector<tPoint> &points);
  void draw(sf::RenderWindow &window);
};