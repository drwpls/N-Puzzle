#include "PlayZone.h"

void NPuzzle::PlayZone::PaintTheBox(Object^ sender, PaintEventArgs^ e)
{
	float FontSize = (float)(cell_height > cell_width ? cell_width : cell_height) / 3;
	System::Drawing::Font^ drawingfont = gcnew System::Drawing::Font("Arial", FontSize);
	PictureBox^ picturebox = (PictureBox^)sender;
	//int Picture_Number = picturebox->TabIndex + 1;
	int Picture_Number = picturebox->TabIndex;
	String^ Pictur_String = Picture_Number.ToString();
	if (Picture_Number == (this->GameData->split_height * this->GameData->split_width))
		Pictur_String = String::Empty;	// ô blank thì không draw gì cả
	Point middle;
	if (Picture_Number < 10)
	{
		middle.X = static_cast<int>(cell_width - FontSize * 1.5) / 2;
		middle.Y = static_cast<int>(cell_height - FontSize * 1.5) / 2;
	}

	if (Picture_Number >= 10 && Picture_Number < 100)
	{
		middle.X = static_cast<int>(cell_width - FontSize * 1.9) / 2;
		middle.Y = static_cast<int>(cell_height - FontSize * 1.5) / 2;
	}

	if (Picture_Number >= 100 && Picture_Number < 1000)
	{
		middle.X = static_cast<int>(cell_width - FontSize * 2.4) / 2;
		middle.Y = static_cast<int>(cell_height - FontSize * 1.5) / 2;
	}

	e->Graphics->DrawString(Pictur_String, drawingfont, Brushes::Red, middle);
}

void NPuzzle::PlayZone::InitializeComponent(GameProcessor* Game)
{
	this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->BackColor = System::Drawing::Color::DarkGray;
	this->Name = "PlayArea";
	this->Size = System::Drawing::Size(box1_width + 24, box1_height + 24);
	this->Location = System::Drawing::Point(0, 24);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

	this->SuspendLayout();

	this->PanelBoard = gcnew System::Windows::Forms::Panel;
	this->PanelBoard->Location = System::Drawing::Point(12, 12);
	this->PanelBoard->Size = System::Drawing::Size(box1_width, box1_height);
	this->PanelBoard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->PanelBoard->BackColor = System::Drawing::Color::White;

	pictures = gcnew array<System::Windows::Forms::PictureBox^, 2>(this->GameData->split_height, this->GameData->split_width);

	int y0 = -1, x0 = -1;
	int pos_x, pos_y;
	int array_data;

	for (int i = 0; i < this->GameData->split_height; ++i)
	{
		for (int j = 0; j < this->GameData->split_width; ++j)
		{
			array_data = Game->HaidArray[i][j];

			pos_x = (array_data - 1) % Game->split_width;
			pos_y = (array_data - 1) / Game->split_width;

			this->pictures[pos_y, pos_x] = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[pos_y, pos_x]))->BeginInit();

			this->pictures[pos_y, pos_x]->Name = L"picture_" + pos_y.ToString() + pos_x.ToString();
			this->pictures[pos_y, pos_x]->Size = System::Drawing::Size(cell_width + 1, cell_height + 1);
			this->pictures[pos_y, pos_x]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictures[pos_y, pos_x]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictures[pos_y, pos_x]->Location = System::Drawing::Point(x0 + cell_width * j, y0 + cell_height * i);
			this->pictures[pos_y, pos_x]->TabIndex = array_data;
			this->pictures[pos_y, pos_x]->TabStop = false;
			this->pictures[pos_y, pos_x]->BackColor = System::Drawing::Color::White;

			if (this->image_path == nullptr)
			{
				this->pictures[pos_y, pos_x]->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PlayZone::PaintTheBox);
			}
			else
			{
				if (array_data != this->GameData->split_height * this->GameData->split_width)
					this->pictures[pos_y, pos_x]->Image = Image::FromFile(L"Resource\\Image\\" + pos_y.ToString() + L"-" + pos_x.ToString() + ".bmp");
			}
		}
	}
	//Control các picture
	for (int i = 0; i < this->GameData->split_height; ++i)
		for (int j = 0; j < this->GameData->split_width; ++j)
		{
			this->PanelBoard->Controls->Add(this->pictures[i, j]);
		}


	// Đánh dấu và hiệu lực các picture box
	for (int i = 0; i < this->GameData->split_height; ++i)
		for (int j = 0; j < this->GameData->split_width; ++j)
		{
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[i, j]))->EndInit();
		}
	this->Controls->Add(PanelBoard);
}

void NPuzzle::PlayZone::CalculatorSizeAndFile(std::string image_path_stdstring)
{
	box1_height = max_windows_height;
	box1_width = max_windows_width - time_count_btn;

	if (this->image_path != nullptr)
	{
		CutBMP_(image_path_stdstring, this->GameData->split_height, this->GameData->split_width, this->image_height, this->image_width);
	}
	else
	{
		image_width = box1_width;
		image_height = box1_height;
	}

	image_ratio = static_cast<double>(image_width) / image_height;
	box1_ratio = static_cast<double>(box1_width) / box1_height;

	if (image_ratio > box1_ratio)
	{
		box1_height = static_cast<int>(box1_height / image_ratio);
		box1_width = box1_width;
	}
	else
	{
		box1_height = box1_height;
		box1_width = static_cast<int>(box1_width * image_ratio);
	}

	cell_width = box1_width / this->GameData->split_width;
	cell_height = box1_height / this->GameData->split_height;

	panel_height = (cell_height)*this->GameData->split_height + 1;
	panel_width = (cell_width)*this->GameData->split_width + 1;
	box1_height = panel_height + 0;
	box1_width = panel_width + 0;
	this->Width = box1_width;
	this->Height = box1_height;
}

void NPuzzle::PlayZone::Delete_split_image(int _Height, int _Width, String^ _image_path)
{
	for (int i = 0; i < this->GameData->split_height; ++i)
		for (int j = 0; j < this->GameData->split_width; ++j)
			delete this->pictures[i, j]->Image;

	if (_image_path != nullptr)
	{
		String^ File_Need_delete_Folder = "Resource\\Image\\";
		String^ File_Need_Delete;
		for (int i = 0; i < this->GameData->split_height; ++i)
			for (int j = 0; j < this->GameData->split_width; ++j)
			{
				File_Need_Delete = File_Need_delete_Folder + i.ToString() + L"-" + j.ToString() + L".bmp";
				System::IO::File::Delete(File_Need_Delete);
			}
	}
}

