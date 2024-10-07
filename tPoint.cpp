#include "tPoint.hpp"

void tPoint::updateLM(float time, sf::Vector2u windowSize) {
  position += speed * time;

  if (position.x < 0 || position.x > windowSize.x) {
    speed.x = -speed.x + (rand() % 50 - 10);
  }
  if (position.y < 0 || position.y > windowSize.y) {
    speed.y = -speed.y + (rand() % 50 - 10);
  }

  point.setPosition(position);
}

void tPoint::updateRM(float time, sf::Vector2u windowSize) {
  position += speed * time;

  if (rand() % 100 < 50) {
    speed.x = (rand() % 50) * (rand() % 2 == 0 ? 1 : -1);
    speed.y = (rand() % 50) * (rand() % 2 == 0 ? 1 : -1);
  }

  if (position.x < 0 || position.x > windowSize.x) {
    speed.x = -speed.x + (rand() % 50 - 10);
  }
  if (position.y < 0 || position.y > windowSize.y) {
    speed.y = -speed.y + (rand() % 50 - 10);
  }

  point.setPosition(position);
}

void tPoint::draw(sf::RenderWindow &window) { window.draw(point); }