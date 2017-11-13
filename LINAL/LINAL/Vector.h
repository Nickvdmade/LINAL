#pragma once
class Vector
{
public:
	Vector(const float xDirection, const float yDirection);
	~Vector();
	Vector Scale(const float scalair) const;
	Vector AddVector(const Vector vector) const;
	Vector SubtractVector(const Vector vector) const;
	void Show();
	float GetX() const;
	float GetY() const;

private:
	float xDirection_;
	float yDirection_;
};

