#pragma once
#include "GameProcessor.h"
#include "CutBMP.h"
#include "MoveDirection.h"

namespace NPuzzle {
	public ref class PlayZone : public System::Windows::Forms::UserControl
	{
	public:
		PlayZone()
		{

		}
		PlayZone(int _Height, int _Width, String^ _Image_path)
		{
			this->image_path = _Image_path;
			std::string image_path_stdstring = "";
			if (this->image_path != nullptr)
				for (int i = 0; i < _Image_path->Length; ++i)
					image_path_stdstring.push_back((char)_Image_path[i]);

			GameData = new GameProcessor(_Height, _Width, image_path_stdstring);
			CalculatorSizeAndFile(image_path_stdstring);
			InitializeComponent(GameData);
		}
	protected:
		~PlayZone()
		{
			if (components)
			{
				delete components;
			}
			Delete_split_image(this->GameData->split_height, this->GameData->split_width, image_path);
			delete GameData;
		}
	public:
		System::ComponentModel::Container^ components;
		void InitializeComponent(GameProcessor*);
		void Delete_split_image(int _Height, int _Width, String^ _image_path);

	public:
		String^ image_path;
		int max_windows_width = 550;
		int max_windows_height = 400;
		int time_count_btn = 150;

		int box1_width;
		int box1_height;
		double box1_ratio;

		int image_width;
		int image_height;
		double image_ratio;

		int panel_width;
		int panel_height;

		int cell_width;
		int cell_height;

		bool pick_play_with_image = 0;
		int time = 0;

	public:
		GameProcessor* GameData;

	public:
		System::Windows::Forms::Panel^ PanelBoard;
		array<System::Windows::Forms::PictureBox^, 2>^ pictures;

	public:
		void PaintTheBox(Object^ sender, PaintEventArgs^ e);
		void CalculatorSizeAndFile(std::string);
	};
}
