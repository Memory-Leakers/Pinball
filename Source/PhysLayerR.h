#include "GameObject.h"
#include "Coins.h"
#include "Boing.h"
#include "CoinsManager.h"

#define COINNUM 15
#define COIN_ROW 5
#define COIN_COLUMN 3

class PhysLayerR : public GameObject
{
public:
	PhysLayerR(std::string name, std::string tag, Application* _app);

	int timeCount = 0;

	bool showBG = false;

	void Update() override;

	void setSensor(bool value);

	void swapLowerTexture();

	Coins* coinPool[COINNUM];

	CoinsManager* coinmanagement = nullptr;

	Boing* boing2;
	Boing* boing3;

	int count = 15;

};

