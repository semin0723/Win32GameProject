#pragma once

class Vector3 {
public:
	float _x;
	float _y;
	float _z;
	Vector3();
	Vector3(float x, float y, float z);

	void operator=	(const Vector3& v);

	Vector3 operator+=	(const Vector3& v);
	Vector3 operator-=	(const Vector3& v);
	Vector3 operator*=	(const float& scalar);
	Vector3 operator/=	(const float& scalar);

	Vector3 operator+	(const Vector3& v) const;
	Vector3 operator-	(const Vector3& v) const;
	Vector3 operator*	(const float& scalar) const;
	Vector3 operator/	(const float& scalar) const;
};