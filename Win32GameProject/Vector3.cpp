#include "Vector3.h"

Vector3::Vector3() {}

Vector3::Vector3(float x, float y, float z) {
	_x = x;
	_y = y;
	_z = z;
}

void Vector3::operator=		(const Vector3& v) {
	_x = v._x;
	_y = v._y;
	_z = v._z;
}

Vector3 Vector3::operator+=	(const Vector3& v) {
	_x += v._x;
	_y += v._y;
	_z += v._z;
	return *this;
}

Vector3 Vector3::operator-=	(const Vector3& v) {
	_x -= v._x;
	_y -= v._y;
	_z -= v._z;
	return *this;
}

Vector3 Vector3::operator*=	(const float& scalar) {
	_x *= scalar;
	_y *= scalar;
	_z *= scalar;
	return *this;
}

Vector3 Vector3::operator/=	(const float& scalar) {
	_x /= scalar;
	_y /= scalar;
	_z /= scalar;
	return *this;
}

Vector3 Vector3::operator+	(const Vector3& v) const {
	return Vector3(*this) += v;
}

Vector3 Vector3::operator-	(const Vector3& v) const {
	return Vector3(*this) -= v;
}

Vector3 Vector3::operator*	(const float& scalar) const {
	return Vector3(*this) *= scalar;
}

Vector3 Vector3::operator/	(const float& scalar) const {
	return Vector3(*this) /= scalar;
}