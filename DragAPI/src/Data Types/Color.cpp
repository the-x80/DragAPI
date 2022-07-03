#include "Color.h"

DragAPI::Color::Color():
	red(0), green(0), blue(0), alpha(0)
{
}

DragAPI::Color::Color(Color& other):
	red(other.red), green(other.green), blue(other.blue), alpha(other.alpha)
{
}

DragAPI::Color::Color(Color&& other) noexcept :
	red(other.red), green(other.green), blue(other.blue), alpha(other.alpha)
{
}

DragAPI::Color::Color(float r, float g, float b) :
	red(r), green(g), blue(b), alpha(1)
{
}

DragAPI::Color::Color(float r, float g, float b, float a) :
	red(r), green(g), blue(b), alpha(a)
{
}

DragAPI::Color::~Color()
{
}
