#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

class GameComponent{
public:
	virtual void draw() = 0;
	virtual void update() = 0;

	virtual void onKeyPressed(char, int, int, bool)  {};

	virtual ~GameComponent() {}
};

#endif // MIRAGE_GAMECOMPONENT_HPP__