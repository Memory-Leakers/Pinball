#include "ModuleUI.h"

#include "Application.h"

ModuleUI::ModuleUI(Application* app, bool start_enabled) : Module(app, start_enabled) 
{
}

bool ModuleUI::Start()
{
	texture = App->textures->Load("Assets/Images/Fonts/font1.png");

	for (int i = 0; i < 10; i++)
	{
		numSection[i].x = 23 * i;
		numSection[i].y = 0;
		numSection[i].w = 23;
		numSection[i].h = 37;
	}

    return true;
}

UpdateStatus ModuleUI::Update()
{
    return UpdateStatus::UPDATE_CONTINUE;
}

UpdateStatus ModuleUI::PostUpdate()
{
    //Draw all current UIs
	for (int i = 0; i < MAX_UI_ITEMS; i++)
	{
		if (uiArray[i] != nullptr)
		{
			for (int j = 0; j < uiArray[i]->totalDigits; j++)
			{
				int tempPos = uiArray[i]->x;
				tempPos += (24 * j);
				App->renderer->Blit(texture, tempPos, uiArray[i]->y,1.0f, &numSection[uiArray[i]->digitVec.at(j)]);
			}
		}
	}
    return UpdateStatus::UPDATE_CONTINUE;
}




/// <summary>
/// Get number and position of the UI
/// Make the number into digits
/// Store it into an UI item in the ui array
/// It prints on screen on the PostUpdate function
/// </summary>
/// <param name="num"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
uint ModuleUI::CreateUI(int num, int x, int y)
{
	//  Get position of the UI
	itemUI* item = new itemUI();
	item->x = x;
	item->y = y;

	//Make the number into an array of digits
	//	Declare Variables
	std::stack<int> digits;

	//Getting digits from number in order Logic
	if (num != 0) {
		while (num > 0)
		{
			int digit = num % 10;
			num /= 10;
			digits.push(digit);
		}

		item->totalDigits = digits.size();

		while (!digits.empty())
		{
			int digit = digits.top();
			item->digitVec.push_back(digit);
			digits.pop();
		}
	}
	else
	{
		item->digitVec.push_back(0);
		item->totalDigits = 1;
	}


    for (int i = 0; i < MAX_UI_ITEMS; i++)
    {
		if (uiArray[i] == nullptr)
		{
			uiArray[i] = item;
			return (uint)i;
		}
    }
}

void ModuleUI::DestroyUI(uint index)
{
	delete uiArray[index];
	uiArray[index] = nullptr;
}

bool ModuleUI::CleanUp()
{
	for (int i = 0; i < MAX_UI_ITEMS; i++)
	{
		if (uiArray[i] != nullptr)
		{
			delete uiArray[i];
			uiArray[i] = nullptr;
		}
	}

	return true;
}

void itemUI::ChangeUI(int num)
{
	//Make the number into an array of digits
	//	Declare Variables
	std::stack<int> digits;

	this->digitVec.clear();

	//Getting digits from number in order Logic
	if (num != 0) {
		while (num > 0)
		{
			int digit = num % 10;
			num /= 10;
			digits.push(digit);
		}

		this->totalDigits = digits.size();

		while (!digits.empty())
		{
			int digit = digits.top();
			this->digitVec.push_back(digit);
			digits.pop();
		}
	}
	else
	{
		this->digitVec.push_back(0);
		this->totalDigits = 1;
	}
}
