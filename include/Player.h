#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#pragma once
class Player :public Moving_Object {
public:
	using Moving_Object::Moving_Object;
	
private:

	int m_Score = 0, m_Lives = 3;
	
};
