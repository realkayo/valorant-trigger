#pragma once
class color
{
public:
	bool isPurple(byte red, byte green, byte blue) {
		return red >= 110 && blue >= 100 && abs(red - blue) <= 13 && abs(red - green) >= 60 && green < 170;
	}
};

