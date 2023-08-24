#pragma once

class UI
{

private:
	int CTime;
	int Coin_Count;

	int Time;
	int Time2;
	int Time3;
	int Time_Count;
	
	int Coin_Image[4];
	int Number_Image[15];
	int Number2_Image[10];
	int Number3_Image[10];
	int Number4_Image[5];

	int MarioName_Image;
	int Time_Image;
	int Select_Image;
	int Select2_Image;
	int World_Image;
	int Carsol_Image;
public:
	UI();
	~UI() {};

	void Update();


	void Draw()const;

};

