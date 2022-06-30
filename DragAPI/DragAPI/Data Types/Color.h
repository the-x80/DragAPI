#pragma once
#ifndef DRAG_API_COLOR_H
#define DRAG_API_COLOR_H

namespace DragAPI {
	class Color {
	private:
		
	public:
		float red, green, blue, alpha;
		Color();
		Color(Color& other);
		Color(Color&& other) noexcept;
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);
		~Color();

		static Color FromHSV(float hue, float saturation, float value);
	};
	class Color32 {
	private:
		unsigned char red, green, blue, alpha;
	public:
		Color32();
		Color32(Color& other);
		Color32(Color&& other);
		Color32(unsigned char r, unsigned char g, unsigned char b);
		Color32(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		~Color32();
	};
}


#endif