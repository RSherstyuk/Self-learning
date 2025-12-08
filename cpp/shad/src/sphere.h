// cpp

#include <cmath>

struct Vec3 {

  double x, y, z;
  Vec3() : x(0), y(0), z(0) {}
  Vec3(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
  Vec3 operator+(const Vec3 &o) const { return {x + o.x, y + o.y, z + o.z}; }
  Vec3 operator-(const Vec3 &o) const { return {x - o.x, y - o.y, z - o.z}; }
  Vec3 operator*(double s) const { return {x * s, y * s, z * s}; }

  static double dot(const Vec3 &a, const Vec3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  static Vec3 cross(const Vec3 &a, const Vec3 &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
  }
  static double norm(const Vec3 &v) { return std::sqrt(dot(v, v)); }

  static Vec3 normalize(const Vec3 &v) {
    double n = norm(v);
    if (n <= 1e-12)
      return {0, 0, 0};
    return {v.x / n, v.y / n, v.z / n};
  }
};

static double dot(const Vec3 &a, const Vec3 &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

static Vec3 cross(const Vec3 &a, const Vec3 &b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
static double norm(const Vec3 &v) { return std::sqrt(dot(v, v)); }

struct Quat {
  double w;

  double x, y, z;

  Quat() : w(1), x(0), y(0), z(0) {}

  Quat(double W, double X, double Y, double Z) : w(W), x(X), y(Y), z(Z) {}

  static Quat fromAxisAngle(const Vec3 &axis, double angleRad) {
    Vec3 a = Vec3::normalize(axis);
    double s = std::sin(angleRad / 2.0);
    return Quat(std::cos(angleRad / 2.0), a.x * s, a.y * s, a.z * s);
  }

  Quat conjugate() const { return Quat(w, -x, -y, -z); }

  double length() const { return std::sqrt(w * w + x * x + y * y + z * z); }

  void normalize() {
    double L = length();
    if (L <= 1e-12) {
      w = 1;
      x = y = z = 0;
      return;
    }
    w /= L;
    x /= L;
    y /= L;
    z /= L;
  }
};

static Quat mul(const Quat &a, const Quat &b) {
  return Quat(a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
              a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
              a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
              a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w);
}

static Vec3 rotateVector(const Quat &q, const Vec3 &v) {
  Quat p(0, v.x, v.y, v.z);
  Quat qc = q.conjugate();
  Quat tmp = mul(q, p);
  Quat res = mul(tmp, qc);
  return {res.x, res.y, res.z};
}

void integrateAngularVelocity(Quat &q, const Vec3 &omega, double dt) {
  double omegaMag = norm(omega);
  if (omegaMag < 1e-12)
    return;
  Vec3 axis = {omega.x / omegaMag, omega.y / omegaMag, omega.z / omegaMag};
  double theta = omegaMag * dt; 
  Quat qd = Quat::fromAxisAngle(axis, theta);

  q = mul(qd, q);  
  q.normalize();
}
