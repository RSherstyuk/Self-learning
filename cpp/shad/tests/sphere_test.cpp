#include "sphere.h"
#include <gtest/gtest.h>

TEST(SPhere, sp) {
  double R = 0.5; 

  Vec3 position{0, R, 0}; 
  Quat orientation;       

  Vec3 velocity{1.0, 0.0, 0.0};

  Vec3 planeNormal{0.0, 1.0, 0.0}; 

  double dt = 0.01;

  for (int step = 0; step < 300; ++step) {
    position = position + velocity * dt;

    double speed = norm(velocity);
    if (speed > 1e-12) {
      Vec3 dir = Vec3::normalize(velocity);

      Vec3 axis = cross(planeNormal, dir);
      double axisLen = norm(axis);
      if (axisLen > 1e-12) {
        axis = axis * (1.0 / axisLen);
        Vec3 omega = axis * (speed / R); // |ω| = v/R
        // 3)

        integrateAngularVelocity(orientation, omega, dt);

      }
    }

    if (step % 30 == 0) {
      std::cout << "t=" << (step * dt) << " pos=(" << position.x << ","
                << position.y << "," << position.z << ")" << " q=("
                << orientation.w << "," << orientation.x << "," << orientation.y
                << "," << orientation.z << ")n" << std::endl;
    }
  }
}

