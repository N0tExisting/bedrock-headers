#pragma once

#include "Color.h"

struct MapDecoration {
	char getX() const;
	char getY() const;
	mce::Color &getColor() const;
	bool isRenderedOnFrame() const;
	std::string &getLabel() const;
};