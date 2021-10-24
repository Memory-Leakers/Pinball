#include "GameObject.h"

class PhysLayerR : public GameObject
{
public:
	PhysLayerR(std::string name, std::string tag, Application* _app);

	int timeCount = 0;

	bool showBG = false;

	void Update() override;

	void setSensor(bool value);

	void swapLowerTexture();

};

