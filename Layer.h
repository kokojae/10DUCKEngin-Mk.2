#pragma once
class Layer
{
public:
	Layer();
	~Layer();

	const static int DEFAULT = 1 << 1;
	const static int BLOCK = 1 << 2;
	const static int PLAYER = 1 << 3;
};

