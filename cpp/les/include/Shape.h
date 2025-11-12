#define PI 3.1415

class Shape {
public:
  Shape(int r) : r(r) {}

  virtual ~Shape(){};

  virtual double getSquare() const = 0;

  double getR() const {
    return r;
  }

protected:
  double r;
};

class Circle : public Shape {
public:
  double getSquare() const override {
    return r * r * PI;
  }

  Circle(double r_val) : Shape(r_val) {};

};

class Sphere : public Shape {
public:
  Sphere(double r_val) : Shape(r_val) {}

  double getSquare() const override {
    return 4.0 * PI * r * r;
  }
};
