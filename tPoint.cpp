#include "tPoint.hpp"
#include <cmath>

void tPoint::updateLM(float time, sf::Vector2u windowSize,
                      std::vector<tPoint> &points) {
  position += speed * time;

  if (position.x < 0) {
    position.x = 0;
    speed.x *= -1;
  } else if (position.x > windowSize.x) {
    position.x = windowSize.x;
    speed.x *= -1;
  }

  if (position.y < 0) {
    position.y = 0;
    speed.y *= -1;
  } else if (position.y > windowSize.y) {
    position.y = windowSize.y;
    speed.y *= -1;
  }

  if (position.x < 0 || position.x > windowSize.x) {
    speed.x = -speed.x + (rand() % 3);
  }
  if (position.y < 0 || position.y > windowSize.y) {
    speed.y = -speed.y + (rand() % 3);
  }

  for (const auto &other : points) {
    if (&other != this) {
      float distance = sqrt(pow(position.x - other.position.x, 2) +
                            pow(other.position.y - other.position.y, 2));

      if (distance < 20) {
        sf::Vector2f direction = position - other.position;
        direction /= distance;
        speed += direction * static_cast<float>(50);
      }
    }
  }

  point.setPosition(position);
}

void tPoint::updateRM(float time, sf::Vector2u windowSize,
                      std::vector<tPoint> &points) {
  position += speed * time;

  if (position.x < 0) {
    position.x = 0;
    speed.x *= -1;
  } else if (position.x > windowSize.x) {
    position.x = windowSize.x;
    speed.x *= -1;
  }

  if (position.y < 0) {
    position.y = 0;
    speed.y *= -1;
  } else if (position.y > windowSize.y) {
    position.y = windowSize.y;
    speed.y *= -1;
  }

  if (rand() % 100 < 1) {
    speed.x = (rand() % 100) * (rand() % 2 == 0 ? 1 : -1);
    speed.y = (rand() % 100) * (rand() % 2 == 0 ? 1 : -1);
  }

  if (position.x < 0 || position.x > windowSize.x) {
    speed.x = -speed.x + (rand() % 50 - 10);
  }
  if (position.y < 0 || position.y > windowSize.y) {
    speed.y = -speed.y + (rand() % 50 - 10);
  }

  for (const auto &other : points) {
    if (&other != this) {
      float distance = sqrt(pow(position.x - other.position.x, 2) +
                            pow(position.y - other.position.y, 2));
      if (distance < 10) {
        sf::Vector2f direction = position - other.position;
        direction /= distance;
        speed += direction * static_cast<float>(50);
      }
    }
  }

  point.setPosition(position);
}

void tPoint::draw(sf::RenderWindow &window) { window.draw(point); }