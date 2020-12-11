#pragma once
#include "Console.h"
void NPuzzle::NewGameChoiceConsole::InitializeComponent(void)
{
	this->Label_Size = (gcnew System::Windows::Forms::Label());
	this->Label_Height = (gcnew System::Windows::Forms::Label());
	this->Label_Width = (gcnew System::Windows::Forms::Label());

	this->Label_Number_Image = (gcnew System::Windows::Forms::Label());
	this->RadioButton_Image = (gcnew System::Windows::Forms::RadioButton());
	this->RadioButton_Number = (gcnew System::Windows::Forms::RadioButton());
	this->Button_Submit = (gcnew System::Windows::Forms::Button());

	this->Button_ChooseFile = (gcnew System::Windows::Forms::Button());
	this->Label_FileChosen = (gcnew System::Windows::Forms::Label());

	this->NumericUpDown_Height = (gcnew System::Windows::Forms::NumericUpDown());
	this->NumericUpDown_Width = (gcnew System::Windows::Forms::NumericUpDown());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown_Height))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown_Width))->BeginInit();

	// 
	// Label_Size
	// 
	this->Label_Size->AutoSize = true;
	this->Label_Size->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Size->Location = System::Drawing::Point(10, 15);
	this->Label_Size->Name = L"Size";
	this->Label_Size->Size = System::Drawing::Size(43, 17);
	this->Label_Size->TabIndex = 5;
	this->Label_Size->Text = L"Size: ";

	// 
	// Label_Height
	// 
	this->Label_Height->AutoSize = true;
	this->Label_Height->Location = System::Drawing::Point(62, 19);
	this->Label_Height->Name = L"label2";
	this->Label_Height->Size = System::Drawing::Size(38, 13);
	this->Label_Height->TabIndex = 6;
	this->Label_Height->Text = L"Height";
	// 
	// Label_Width
	// 
	this->Label_Width->AutoSize = true;
	this->Label_Width->Location = System::Drawing::Point(62, 38);
	this->Label_Width->Name = L"label3";
	this->Label_Width->Size = System::Drawing::Size(35, 13);
	this->Label_Width->TabIndex = 7;
	this->Label_Width->Text = L"Width";

	// 
	// Label_Number_Image
	// 
	this->Label_Number_Image->AutoSize = true;
	this->Label_Number_Image->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Number_Image->Location = System::Drawing::Point(10, 64);
	this->Label_Number_Image->Name = L"label4";
	this->Label_Number_Image->Size = System::Drawing::Size(43, 17);
	this->Label_Number_Image->TabIndex = 10;
	this->Label_Number_Image->Text = L"Image or Number?: ";
	// 
	// RadioButton_Number
	// 
	this->RadioButton_Number->AutoSize = true;
	this->RadioButton_Number->Location = System::Drawing::Point(12, 84);
	this->RadioButton_Number->Name = L"RadioButton_Number";
	this->RadioButton_Number->Size = System::Drawing::Size(85, 17);
	this->RadioButton_Number->TabIndex = 4;
	this->RadioButton_Number->TabStop = true;
	this->RadioButton_Number->Text = L"Number";
	this->RadioButton_Number->UseVisualStyleBackColor = true;
	this->RadioButton_Number->Checked = true;
	// 
	// RadioButton_Image
	// 
	this->RadioButton_Image->AutoSize = true;
	this->RadioButton_Image->Location = System::Drawing::Point(13, 107);
	this->RadioButton_Image->Name = L"RadioButton_Image";
	this->RadioButton_Image->Size = System::Drawing::Size(85, 17);
	this->RadioButton_Image->TabIndex = 3;
	this->RadioButton_Image->TabStop = true;
	this->RadioButton_Image->Text = L"Image";
	this->RadioButton_Image->UseVisualStyleBackColor = true;
	// 
	// Button_Submit
	// 
	this->Button_Submit->Location = System::Drawing::Point(12, 182);
	this->Button_Submit->Name = L"button1";
	this->Button_Submit->Size = System::Drawing::Size(75, 23);
	this->Button_Submit->TabIndex = 2;
	this->Button_Submit->Text = L"Submit";
	this->Button_Submit->UseVisualStyleBackColor = true;
	// 
	// Button_ChooseFile
	// 
	this->Button_ChooseFile->Enabled = false;
	this->Button_ChooseFile->Location = System::Drawing::Point(43, 130);
	this->Button_ChooseFile->Name = L"Button_ChooseFile";
	this->Button_ChooseFile->Size = System::Drawing::Size(75, 23);
	this->Button_ChooseFile->TabIndex = 11;
	this->Button_ChooseFile->Text = L"Choose File";
	this->Button_ChooseFile->UseVisualStyleBackColor = true;

	// 
	// Label_FileChosen
	// 
	this->Label_FileChosen->AutoSize = true;
	this->Label_FileChosen->Location = System::Drawing::Point(124, 135);
	this->Label_FileChosen->Name = L"Label_FileChosen";
	this->Label_FileChosen->Size = System::Drawing::Size(0, 13);
	this->Label_FileChosen->TabIndex = 12;

	// 
	// NewGameChoiceConsole
	// 
	this->components = gcnew System::ComponentModel::Container();
	this->Size = System::Drawing::Size(400, 250);
	this->Text = L"New Game";
	this->Padding = System::Windows::Forms::Padding(0);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

	// 
	// NumericUpDown_Height
	// 
	this->NumericUpDown_Height->Location = System::Drawing::Point(120, 15);
	this->NumericUpDown_Height->Name = L"numericUpDown1";
	this->NumericUpDown_Height->Size = System::Drawing::Size(120, 20);
	this->NumericUpDown_Height->TabIndex = 13;
	this->NumericUpDown_Height->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
	this->NumericUpDown_Height->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
	this->NumericUpDown_Height->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
	// 
	// NumericUpDown_Width
	// 
	this->NumericUpDown_Width->Location = System::Drawing::Point(120, 35);
	this->NumericUpDown_Width->Name = L"numericUpDown1";
	this->NumericUpDown_Width->Size = System::Drawing::Size(120, 20);
	this->NumericUpDown_Width->TabIndex = 13;
	this->NumericUpDown_Width->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
	this->NumericUpDown_Width->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
	this->NumericUpDown_Width->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });

	// 
	// Add Control to Form
	// 
	this->Controls->Add(this->Label_Size);
	this->Controls->Add(this->Label_Height);
	this->Controls->Add(this->Label_Width);
	this->Controls->Add(this->Label_Number_Image);
	this->Controls->Add(this->RadioButton_Image);
	this->Controls->Add(this->RadioButton_Number);
	this->Controls->Add(this->Button_Submit);
	this->Controls->Add(this->Button_ChooseFile);
	this->Controls->Add(this->Label_FileChosen);
	this->Controls->Add(this->NumericUpDown_Height);
	this->Controls->Add(this->NumericUpDown_Width);

	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown_Height))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown_Width))->EndInit();

	this->ResumeLayout(false);
	this->PerformLayout();

	this->RadioButton_Number->Click += gcnew System::EventHandler(this, &NewGameChoiceConsole::RadioButton_Number_CheckedChanged);
	this->RadioButton_Image->Click += gcnew System::EventHandler(this, &NewGameChoiceConsole::RadioButton_Image_CheckedChanged);
	this->Button_ChooseFile->Click += gcnew System::EventHandler(this, &NewGameChoiceConsole::Button_ChooseFile_Click);
	this->Button_Submit->Click += gcnew System::EventHandler(this, &NewGameChoiceConsole::Button_Submit_Click);
}

void NPuzzle::NewGameChoiceConsole::RadioButton_Number_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Button_ChooseFile->Enabled = false;
}
void NPuzzle::NewGameChoiceConsole::RadioButton_Image_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->Button_ChooseFile->Enabled = true;
}
void NPuzzle::NewGameChoiceConsole::Button_ChooseFile_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ chooseFile_Dialog = gcnew OpenFileDialog;

	chooseFile_Dialog->InitialDirectory = System::IO::Directory::GetCurrentDirectory();
	chooseFile_Dialog->Filter = "Bmp Image (*.bmp)|*.bmp";
	if (chooseFile_Dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Label_FileChosen->Text = chooseFile_Dialog->SafeFileName;
		this->Image_Path = chooseFile_Dialog->FileName;
		this->Image_Name = chooseFile_Dialog->SafeFileName;
	}
}
void NPuzzle::NewGameChoiceConsole::Button_Submit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Convert::ToInt32(this->NumericUpDown_Height->Value);
	textbox_split_height_int = Convert::ToInt32(this->NumericUpDown_Height->Value);
	textbox_split_width_int = Convert::ToInt32(this->NumericUpDown_Width->Value);

	if (this->RadioButton_Number->Checked == true)
	{
		image_radio_button_chosen = false;
		this->Image_Path = nullptr;
		sumbit_newgame_clicked = 1;
		this->Close();
	}

	if (this->RadioButton_Image->Checked == true)
	{
		if (Image_Path == nullptr)
			MessageBox::Show(L"Chưa chọn ảnh!");
		else
		{
			image_radio_button_chosen = true;
			sumbit_newgame_clicked = 1;
			this->Close();
		}

	}
}

void NPuzzle::HighScoreConsole::SetPanel_HighScore(Panel_HighScorePlayer^ panel, HighScorePlayer^ player)
{
	panel->label_Name_Player->Text = player->Name;
	panel->label_Time_PLayer->Text = player->time.ToString();
	panel->label_Turn_Player->Text = player->Game_Turn.ToString();
	panel->label_Size_Player->Text = player->height.ToString() + "x" + player->width.ToString();
}
void NPuzzle::HighScoreConsole::User_Choose_All()
{
	for (int i = 0; i < 5; ++i)
		this->SetPanel_HighScore(this->Panel_HighScore5Player[i], HighScore5Player[i]);
	for (int i = 0; i < 5; ++i)
		this->Panel_HighScore5Player[i]->Show();
}
void NPuzzle::HighScoreConsole::User_Choose_Pro()
{
	int count = 0, i = 0;
	while (i < 5)
	{
		if (this->HighScore5Player[i]->height * this->HighScore5Player[i]->width > 5 * 5)
		{
			this->SetPanel_HighScore(this->Panel_HighScore5Player[count], HighScore5Player[i]);
			this->Panel_HighScore5Player[i]->Show();
			++count;
		}
		++i;
	}

	for (int j = count; j < 5; ++j)
		this->Panel_HighScore5Player[j]->Hide();
}
void NPuzzle::HighScoreConsole::User_Choose_Advance()
{
	int count = 0, i = 0;
	while (i < 5)
	{
		if (this->HighScore5Player[i]->height * this->HighScore5Player[i]->width < 5 * 5)
			if (this->HighScore5Player[i]->height * this->HighScore5Player[i]->width > 4 * 4)
			{
				this->SetPanel_HighScore(this->Panel_HighScore5Player[count], HighScore5Player[i]);
				this->Panel_HighScore5Player[i]->Show();
				++count;
			}
		++i;
	}

	for (int j = count; j < 5; ++j)
		this->Panel_HighScore5Player[j]->Hide();
}
void NPuzzle::HighScoreConsole::User_Choose_Amateur()
{
	int count = 0, i = 0;
	while (i < 5)
	{
		if (this->HighScore5Player[i]->height * this->HighScore5Player[i]->width > 0)
			if (this->HighScore5Player[i]->height * this->HighScore5Player[i]->width < 4 * 4)
			{
				this->SetPanel_HighScore(this->Panel_HighScore5Player[count], HighScore5Player[i]);
				this->Panel_HighScore5Player[i]->Show();
				++count;
			}
		++i;
	}

	for (int j = count; j < 5; ++j)
		this->Panel_HighScore5Player[j]->Hide();
}
void NPuzzle::HighScoreConsole::ChooseOption_Changed(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::ComboBox^ combobox = (System::Windows::Forms::ComboBox^)sender;
	if (combobox->SelectedIndex == 0)
		User_Choose_All();
	if (combobox->SelectedIndex == 1)
		User_Choose_Pro();
	if (combobox->SelectedIndex == 2)
		User_Choose_Advance();
	if (combobox->SelectedIndex == 3)
		User_Choose_Amateur();
}
void NPuzzle::GameWonConsole::button_OK_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Player_Name = this->textbox_InputName->Text;
	if (this->Player_Name->Length >= 10)
		MessageBox::Show("Name must be less than 10 character!");
	else
		this->Close();
}

void NPuzzle::MainConsole::InitializeComponent()
{
	String^ Resource_Path;
	Resource_Path = "Resource";
	System::IO::Directory::CreateDirectory(Resource_Path);
	Resource_Path = "Resource\\Image";
	System::IO::Directory::CreateDirectory(Resource_Path);
	Resource_Path = "Resource\\GameSave";
	System::IO::Directory::CreateDirectory(Resource_Path);
	Resource_Path = "Resource\\HighScore";
	System::IO::Directory::CreateDirectory(Resource_Path);
	String^ HighScore_File = "Resource\\HighScore\\HighScore";
	HighScore5Player = gcnew array<HighScorePlayer^>(5);
	for (int i = 0; i < 5; ++i)
		HighScore5Player[i] = gcnew HighScorePlayer();

	if (!System::IO::File::Exists(HighScore_File))
	{
		//System::IO::File::Create(HighScore_File);		
		// tạo file và ghi 5 defalut vào HighScore lại vào trong highscore
		Write_HighScore();
	}
	else
	{
		// Nếu tồn tại, đọc trong file highscore
		Read_HighScore();
	}

	// Khởi tạo bảng 3x3 với mảng số
	MainPlayZone = (gcnew NPuzzle::PlayZone(3, 3, nullptr));
	Time_Count = gcnew System::Windows::Forms::Timer;
	Sole_this_Game = gcnew System::Windows::Forms::Timer();
	Sole_this_Game->Interval = 250;
	Sole_this_Game->Tick += gcnew System::EventHandler(this, &MainConsole::Help_Hint_Click);

	this->Menu_Bar = (gcnew System::Windows::Forms::MenuStrip());
	this->Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Menu_NewGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Menu_SaveGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Menu_LoadGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Menu_HighScore = (gcnew System::Windows::Forms::ToolStripMenuItem());

	this->Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Help_Hint = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Help_Solve_Game = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Help_Undo = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->Help_Redo = (gcnew System::Windows::Forms::ToolStripMenuItem());

	this->Panel_Time = (gcnew System::Windows::Forms::Panel());
	this->Label_Time = (gcnew System::Windows::Forms::Label());
	this->Label_Time_Display = (gcnew System::Windows::Forms::Label());

	this->Panel_Turn = (gcnew System::Windows::Forms::Panel());
	this->Label_Turn = (gcnew System::Windows::Forms::Label());
	this->Label_Turn_Display = (gcnew System::Windows::Forms::Label());

	this->Menu_Bar->SuspendLayout();
	this->MainPlayZone->SuspendLayout();
	this->Panel_Time->SuspendLayout();
	this->Panel_Turn->SuspendLayout();
	this->SuspendLayout();

	this->Menu_Bar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
		this->Menu,
			this->Help
	});
	this->Menu_Bar->Location = System::Drawing::Point(0, 0);
	this->Menu_Bar->Name = L"Menu_Bar";
	this->Menu_Bar->Size = System::Drawing::Size(this->MainPlayZone->Width + 16 + this->MainPlayZone->time_count_btn, 24);
	this->Menu_Bar->TabIndex = 0;
	this->Menu_Bar->Text = L"Menu_Bar";

	this->Menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
		this->Menu_NewGame,
			this->Menu_SaveGame,
			this->Menu_LoadGame,
			this->Menu_HighScore,
	});
	this->Menu->Name = L"Menu";
	this->Menu->Size = System::Drawing::Size(50, 20);
	this->Menu->Text = L"Menu";

	this->Menu_NewGame->Name = L"Menu_NewGame";
	this->Menu_NewGame->Size = System::Drawing::Size(180, 22);
	this->Menu_NewGame->Text = L"NewGame";

	this->Menu_SaveGame->Name = L"Menu_SaveGame";
	this->Menu_SaveGame->Size = System::Drawing::Size(180, 22);
	this->Menu_SaveGame->Text = L"Save Game";

	this->Menu_LoadGame->Name = L"Menu_LoadGame";
	this->Menu_LoadGame->Size = System::Drawing::Size(180, 22);
	this->Menu_LoadGame->Text = L"Load Game";

	this->Menu_HighScore->Name = L"Menu_HightScore";
	this->Menu_HighScore->Size = System::Drawing::Size(180, 22);
	this->Menu_HighScore->Text = L"View High Score";

	this->Help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
		this->Help_Hint,
			this->Help_Solve_Game,
			this->Help_Undo,
			this->Help_Redo,
	});
	this->Help->Name = L"Help";
	this->Help->Size = System::Drawing::Size(50, 20);
	this->Help->Text = L"Help";

	this->Help_Hint->Name = L"Help_Hint";
	this->Help_Hint->Size = System::Drawing::Size(180, 22);
	this->Help_Hint->Text = L"Hint (H)";

	this->Help_Solve_Game->Name = L"Help_Solve_Game";
	this->Help_Solve_Game->Size = System::Drawing::Size(180, 22);
	this->Help_Solve_Game->Text = L"Solve This Game";

	this->Help_Undo->Name = L"Help_Undo";
	this->Help_Undo->Size = System::Drawing::Size(180, 22);
	this->Help_Undo->Text = L"Undo (Ctrl + Z)";

	this->Help_Redo->Name = L"Help_Redo";
	this->Help_Redo->Size = System::Drawing::Size(180, 22);
	this->Help_Redo->Text = L"Redo (Ctrl + Y)";

	this->Panel_Time->Controls->Add(this->Label_Time);
	this->Panel_Time->Controls->Add(this->Label_Time_Display);
	this->Panel_Time->Location = System::Drawing::Point(this->MainPlayZone->Width, 24);
	this->Panel_Time->Name = L"Panel_Time";
	this->Panel_Time->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
	this->Panel_Time->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

	this->Label_Time->AutoSize = true;
	this->Label_Time->Font = (gcnew System::Drawing::Font(L"Arial", static_cast<float>(MainPlayZone->Height / 30), System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Time->Location = System::Drawing::Point(10, 10);
	this->Label_Time->Name = L"Label_Time";
	this->Label_Time->Size = System::Drawing::Size(42, 16);
	this->Label_Time->Text = L"TIME:";

	this->Label_Time_Display->AutoSize = false;
	this->Label_Time_Display->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	this->Label_Time_Display->Dock = DockStyle::Fill;
	this->Label_Time_Display->Font = (gcnew System::Drawing::Font(L"Arial", static_cast<float>(MainPlayZone->Height / 30), System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Time_Display->Location = System::Drawing::Point(60, this->Panel_Time->Height / 2);
	this->Label_Time_Display->Name = L"Label_Time_Display";
	this->Label_Time_Display->Size = System::Drawing::Size(42, 16);
	this->Label_Time_Display->Text = L"0";

	this->Time_Count->Enabled = 0;
	this->Time_Count->Interval = 1000;
	this->Time_Count->Tick += gcnew System::EventHandler(this, &MainConsole::UpdateTime);

	this->Panel_Turn->Controls->Add(this->Label_Turn);
	this->Panel_Turn->Controls->Add(this->Label_Turn_Display);
	this->Panel_Turn->Location = System::Drawing::Point(this->MainPlayZone->Width, 24 + this->MainPlayZone->Height / 2);
	this->Panel_Turn->Name = L"Panel_Turn";
	this->Panel_Turn->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
	this->Panel_Turn->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

	this->Label_Turn->AutoSize = true;
	this->Label_Turn->Font = (gcnew System::Drawing::Font(L"Arial", static_cast<float>(MainPlayZone->Height / 30), System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Turn->Location = System::Drawing::Point(10, 10);
	this->Label_Turn->Name = L"Label_Turn";
	this->Label_Turn->Size = System::Drawing::Size(42, 16);
	this->Label_Turn->Text = L"TURN:";

	this->Label_Turn_Display->AutoSize = false;
	this->Label_Turn_Display->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	this->Label_Turn_Display->Dock = DockStyle::Fill;
	this->Label_Turn_Display->Font = (gcnew System::Drawing::Font(L"Arial", static_cast<float>(MainPlayZone->Height / 30), System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Label_Turn_Display->Location = System::Drawing::Point(60, this->Panel_Turn->Height / 2);
	this->Label_Turn_Display->Name = L"Label_Turn_Display";
	this->Label_Turn_Display->Size = System::Drawing::Size(42, 16);
	this->Label_Turn_Display->Text = this->MainPlayZone->GameData->MoveList->getNow()->getTurn().ToString();

	this->MainPlayZone->BackColor = System::Drawing::Color::DarkGray;
	this->MainPlayZone->Name = "PlayArea";
	this->MainPlayZone->Size = System::Drawing::Size(this->MainPlayZone->box1_width + 24, this->MainPlayZone->box1_height + 24);
	this->MainPlayZone->Location = System::Drawing::Point(0, 24);
	this->MainPlayZone->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

	this->Controls->Add(this->Menu_Bar);
	this->Controls->Add(this->MainPlayZone);
	this->Controls->Add(this->Panel_Time);
	this->Controls->Add(this->Panel_Turn);
	this->components = gcnew System::ComponentModel::Container();
	this->Size = System::Drawing::Size(this->MainPlayZone->Width + 16 + this->MainPlayZone->time_count_btn, this->MainPlayZone->Height + 62);
	this->Text = L"mxn puzzle";
	this->DoubleBuffered = true;
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->MainMenuStrip = this->Menu_Bar;
	this->MainPlayZone->ResumeLayout(false);
	this->MainPlayZone->PerformLayout();
	this->Menu_Bar->ResumeLayout(false);
	this->Menu_Bar->PerformLayout();
	this->Panel_Time->ResumeLayout(false);
	this->Panel_Time->PerformLayout();
	this->Panel_Turn->ResumeLayout(false);
	this->Panel_Turn->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

	this->Menu_NewGame->Click += gcnew System::EventHandler(this, &MainConsole::Menu_NewGame_Click);
	this->Menu_SaveGame->Click += gcnew System::EventHandler(this, &MainConsole::Menu_SaveGame_Click);
	this->Menu_LoadGame->Click += gcnew System::EventHandler(this, &MainConsole::Menu_LoadGame_Click);
	this->Menu_HighScore->Click += gcnew System::EventHandler(this, &MainConsole::Menu_HighScore_Click);

	this->Help_Hint->Click += gcnew System::EventHandler(this, &MainConsole::Help_Hint_Click);
	this->Help_Solve_Game->Click += gcnew System::EventHandler(this, &MainConsole::Help_Solve_Game_Click);
	this->Help_Undo->Click += gcnew System::EventHandler(this, &MainConsole::Help_Undo_Click);
	this->Help_Redo->Click += gcnew System::EventHandler(this, &MainConsole::Help_Redo_Click);
	for (int i = 0; i < this->MainPlayZone->GameData->split_height; ++i)
		for (int j = 0; j < this->MainPlayZone->GameData->split_width; ++j)
			this->MainPlayZone->pictures[i, j]->Click += gcnew System::EventHandler(this, &MainConsole::Picture_Click);

	// Bắt sự kiện nhấn phím
	// Override ProcessCmdKey rồi
	//this->MainPlayZone->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainConsole::KeyPress);
	//this->MainPlayZone->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainConsole::DirectionPress);
	//this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainConsole::KeyPress);
	//this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainConsole::DirectionPress);
}
void NPuzzle::MainConsole::Menu_NewGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Khởi tạo dialog new game
	NPuzzle::NewGameChoiceConsole^ NewGameConsole;
	NewGameConsole = gcnew NPuzzle::NewGameChoiceConsole;
	NewGameConsole->ShowInTaskbar = false;
	NewGameConsole->Owner = this;
	NewGameConsole->StartPosition = FormStartPosition::CenterParent;
	NewGameConsole->ShowDialog();

	// Nếu bấm Submit, nếu không bấm thì thôi.

	if (NewGameConsole->sumbit_newgame_clicked == 1)
	{
		int _split_height = NewGameConsole->textbox_split_height_int;
		int _split_width = NewGameConsole->textbox_split_width_int;
		String^ _image_path = NewGameConsole->Image_Path;

		this->MainPlayZone->SuspendLayout();
		this->SuspendLayout();
		MainPlayZone->~PlayZone();
		MainPlayZone = (gcnew NPuzzle::PlayZone(_split_height, _split_width, _image_path));

		this->MainPlayZone->BackColor = System::Drawing::Color::DarkGray;
		this->MainPlayZone->Name = "PlayArea";
		this->MainPlayZone->Size = System::Drawing::Size(this->MainPlayZone->box1_width + 24, this->MainPlayZone->box1_height + 24);
		this->MainPlayZone->Location = System::Drawing::Point(0, 24);
		this->MainPlayZone->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

		this->Controls->Add(this->MainPlayZone);
		this->MainPlayZone->ResumeLayout(false);
		this->MainPlayZone->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

		this->Panel_Time->Location = System::Drawing::Point(this->MainPlayZone->Width, 24);
		this->Panel_Time->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
		this->Label_Time_Display->Location = System::Drawing::Point(60, this->Panel_Time->Height / 2);

		this->Panel_Turn->Location = System::Drawing::Point(this->MainPlayZone->Width, 24 + this->MainPlayZone->Height / 2);
		this->Panel_Turn->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
		this->Label_Turn_Display->Location = System::Drawing::Point(60, this->Panel_Turn->Height / 2);
		this->Height = this->MainPlayZone->Height + 62;
		this->Width = this->MainPlayZone->Width + 16 + this->MainPlayZone->time_count_btn;
		this->Label_Turn_Display->Text = this->MainPlayZone->GameData->MoveList->getNow()->getTurn().ToString();

		this->Label_Time_Display->Text = "0";
		this->Time_Count->Enabled = false;
		this->Sole_this_Game->Enabled = false;
		this->WonThisGame = false; // chưa win game này

		//this->MainPlayZone->Focus();
		for (int i = 0; i < this->MainPlayZone->GameData->split_height; ++i)
			for (int j = 0; j < this->MainPlayZone->GameData->split_width; ++j)
				this->MainPlayZone->pictures[i, j]->Click += gcnew System::EventHandler(this, &MainConsole::Picture_Click);
	}
}
void NPuzzle::MainConsole::Menu_SaveGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveGame_Click = gcnew SaveFileDialog;
	String^ SystemString_SavedPuzlPath;
	std::string std_SavedPuzlPath = "";

	saveGame_Click->InitialDirectory = System::IO::Directory::GetCurrentDirectory();
	saveGame_Click->Filter = "Puzzle File (*.pzl)|*.pzl";

	if (saveGame_Click->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		SystemString_SavedPuzlPath = saveGame_Click->FileName;
	}

	if (SystemString_SavedPuzlPath != nullptr)
	{
		for (int i = 0; i < SystemString_SavedPuzlPath->Length; ++i)
			std_SavedPuzlPath.push_back((char)SystemString_SavedPuzlPath[i]);
		ofstream ofi(std_SavedPuzlPath, ios::out | ios::binary);

		if (ofi.is_open())
		{
			int _size_path = (int)this->MainPlayZone->GameData->image_path.size();
			int _size_row = sizeof(int) * this->MainPlayZone->GameData->split_width;
			char* char_SavedImagePath = new char[_size_path + 1];
			for (int i = 0; i < MainPlayZone->GameData->image_path.size(); ++i)
				char_SavedImagePath[i] = MainPlayZone->GameData->image_path[i];
			char_SavedImagePath[MainPlayZone->GameData->image_path.size()] = '\0';

			ofi.write((char*)(&this->MainPlayZone->GameData->blank_pos.Y), 4);
			ofi.write((char*)(&this->MainPlayZone->GameData->blank_pos.X), 4);
			ofi.write((char*)(&this->MainPlayZone->GameData->Game_Time), 4);
			ofi.write((char*)(&this->MainPlayZone->GameData->Game_Turn), 4);
			ofi.write((char*)(&this->MainPlayZone->GameData->split_width), 4);
			ofi.write((char*)(&this->MainPlayZone->GameData->split_height), 4);
			ofi.write((char*)(&_size_path), 4);
			ofi.write((char*)(&_size_row), 4);
			ofi.write(char_SavedImagePath, _size_path + 1);
			for (int i = 0; i < MainPlayZone->GameData->split_height; ++i)
				ofi.write((char*)((this->MainPlayZone->GameData->HaidArray[i])), _size_row);
			ofi.close();
			delete[] char_SavedImagePath;
			MessageBox::Show("Save SuccessFully");
		}
		else MessageBox::Show("Error!");
	}
}
void NPuzzle::MainConsole::Menu_LoadGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->loadGame_Click = gcnew OpenFileDialog;
	String^ SystemString_SavedPuzlPath = nullptr;
	std::string std_SavedPuzlPath;
	loadGame_Click->InitialDirectory = System::IO::Directory::GetCurrentDirectory();
	loadGame_Click->Filter = "puzzle file (*.pzl)|*.pzl";
	loadGame_Click->RestoreDirectory = true;

	if (loadGame_Click->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		SystemString_SavedPuzlPath = loadGame_Click->FileName;

	if (SystemString_SavedPuzlPath != nullptr)
	{
		//std_SavedPuzlPath = msclr::interop::marshal_as< std::string >(SystemString_SavedPuzlPath);
		for (int i = 0; i < SystemString_SavedPuzlPath->Length; ++i)
			std_SavedPuzlPath.push_back((char)SystemString_SavedPuzlPath[i]);
		std::string std_image_path = "";
		ifstream ifi(std_SavedPuzlPath, ios::in | ios::binary);
		if (ifi.is_open())
		{
			MyPoint blankpos;
			int _time;
			int _turn;
			int _size_path;
			int _split_width;
			int _split_height;
			int _size_row;
			ifi.read((char*)(&blankpos.Y), 4);
			ifi.read((char*)(&blankpos.X), 4);
			ifi.read((char*)(&_time), 4);
			ifi.read((char*)(&_turn), 4);
			ifi.read((char*)(&_split_width), 4);
			ifi.read((char*)(&_split_height), 4);
			ifi.read((char*)(&_size_path), 4);
			ifi.read((char*)(&_size_row), 4);

			char* char_SavedImagePath = new char[_size_path + 1];
			ifi.read(char_SavedImagePath, _size_path + 1);
			for (int i = 0; i < _size_path; ++i)
				std_image_path.push_back(char_SavedImagePath[i]);

			String^ SystemString_ImagePath = nullptr;
			if (_size_path > 1)
				SystemString_ImagePath = gcnew String(char_SavedImagePath);

			int** tmp = new int* [_split_height];
			for (int i = 0; i < _split_height; ++i)
				tmp[i] = new int[_split_width];
			for (int i = 0; i < _split_height; ++i)
				ifi.read((char*)((tmp[i])), _size_row);

			ifi.close();

			// đọc xong

			if (SystemString_ImagePath != nullptr && !System::IO::File::Exists(SystemString_ImagePath))
			{
				MessageBox::Show("Failed Load Image to game, path does not exist");
				for (int i = 0; i < _split_height; ++i)
					delete[] tmp[i];
				delete[] tmp;
				delete[] char_SavedImagePath;
				return;
			}


			MainPlayZone->~PlayZone();
			MainPlayZone = gcnew PlayZone();
			MainPlayZone->GameData = new GameProcessor(_split_height, _split_width, std_image_path);

			MainPlayZone->GameData->blank_pos = blankpos;
			MainPlayZone->GameData->Game_Time = _time;
			MainPlayZone->GameData->Game_Turn = _turn;
			MainPlayZone->GameData->MoveList->getNow()->setTurn(_turn);
			for (int i = 0; i < _split_height; ++i)
				for (int j = 0; j < _split_width; ++j)
					this->MainPlayZone->GameData->HaidArray[i][j] = tmp[i][j];

			this->MainPlayZone->image_path = SystemString_ImagePath;
			this->MainPlayZone->CalculatorSizeAndFile(std_image_path);
			this->MainPlayZone->InitializeComponent(MainPlayZone->GameData);

			this->Controls->Add(this->MainPlayZone);

			this->Panel_Time->Location = System::Drawing::Point(this->MainPlayZone->Width, 24);
			this->Panel_Time->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
			this->Label_Time_Display->Location = System::Drawing::Point(60, this->Panel_Time->Height / 2);

			this->Panel_Turn->Location = System::Drawing::Point(this->MainPlayZone->Width, 24 + this->MainPlayZone->Height / 2);
			this->Panel_Turn->Size = System::Drawing::Size(this->MainPlayZone->time_count_btn, this->MainPlayZone->Height / 2);
			this->Label_Turn_Display->Location = System::Drawing::Point(60, this->Panel_Turn->Height / 2);
			this->Height = this->MainPlayZone->Height + 62;
			this->Label_Turn_Display->Text = this->MainPlayZone->GameData->MoveList->getNow()->getTurn().ToString();

			this->Label_Time_Display->Text = this->MainPlayZone->GameData->Game_Time.ToString();
			this->Time_Count->Enabled = false;
			this->Sole_this_Game->Enabled = false;
			this->WonThisGame = false; // chưa win game này

			for (int i = 0; i < this->MainPlayZone->GameData->split_height; ++i)
				for (int j = 0; j < this->MainPlayZone->GameData->split_width; ++j)
					this->MainPlayZone->pictures[i, j]->Click += gcnew System::EventHandler(this, &MainConsole::Picture_Click);

			//delete _game;
			MessageBox::Show("Load Successfully");
			for (int i = 0; i < _split_height; ++i)
				delete[] tmp[i];
			delete[] tmp;
			delete[] char_SavedImagePath;
		}
		else
			MessageBox::Show("Load Error");
	}
}
void NPuzzle::MainConsole::Menu_HighScore_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Khởi tạo dialog new game
	NPuzzle::HighScoreConsole^ _HighScoreConsole;
	_HighScoreConsole = gcnew NPuzzle::HighScoreConsole;
	_HighScoreConsole->ShowInTaskbar = false;
	_HighScoreConsole->Owner = this;
	_HighScoreConsole->StartPosition = FormStartPosition::CenterParent;
	_HighScoreConsole->HighScore5Player = HighScore5Player;
	_HighScoreConsole->ChooseOption->SelectedIndex = 0; // == choose All
	_HighScoreConsole->User_Choose_All();
	_HighScoreConsole->ShowDialog();

}
void NPuzzle::MainConsole::Help_Hint_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->MainPlayZone->GameData->CheckFinish() != true)
	{
		MoveDirection HintMove;
		HintMove = this->MainPlayZone->GameData->SOLVE->GenMove();
		MakeNewMove(HintMove);
	}
	else
		Sole_this_Game->Enabled = false;
}

void NPuzzle::MainConsole::Help_Solve_Game_Click(System::Object^ sender, System::EventArgs^ e)
{
	Sole_this_Game->Enabled = true;
}
void NPuzzle::MainConsole::Help_Undo_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->MakeUndoMove();
}
void NPuzzle::MainConsole::Help_Redo_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->MakeRedoMove();
}
void NPuzzle::MainConsole::Picture_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::PictureBox^ piturebox = (System::Windows::Forms::PictureBox^) sender;
	int numberic = piturebox->TabIndex;
	int split_width = this->MainPlayZone->GameData->split_width;
	int split_height = this->MainPlayZone->GameData->split_height;
	MyPoint blank = this->MainPlayZone->GameData->blank_pos;

	if (blank.X < split_width - 1)
		if (this->MainPlayZone->GameData->HaidArray[blank.Y][blank.X + 1] == numberic)
			this->MakeNewMove(LEFT);

	if (blank.X > 0)
		if (this->MainPlayZone->GameData->HaidArray[blank.Y][blank.X - 1] == numberic)
			this->MakeNewMove(RIGHT);

	if (blank.Y < split_height - 1)
		if (this->MainPlayZone->GameData->HaidArray[blank.Y + 1][blank.X] == numberic)
			this->MakeNewMove(UP);

	if (blank.Y > 0)
		if (this->MainPlayZone->GameData->HaidArray[blank.Y - 1][blank.X] == numberic)
			this->MakeNewMove(DOWN);
}

// Override ProcessCmdKey rồi
void NPuzzle::MainConsole::KeyPress(System::Object^ sender, KeyEventArgs^ e)
{
	if (e->Control && e->KeyCode == Keys::S)
	{

		// Save Game
	}

	if (e->Control && e->KeyCode == Keys::Z)
	{
		// Undo
		this->MakeUndoMove();
	}

	if (e->Control && e->KeyCode == Keys::Y)
	{
		// Redo
		this->MakeRedoMove();
	}

	if (e->Control && e->KeyCode == Keys::H)
	{
		// Hint
	}
	if (e->KeyCode == Keys::Enter)
	{

	}
}
void NPuzzle::MainConsole::DirectionPress(System::Object^ sender, PreviewKeyDownEventArgs^ e)
{
	if (e->KeyCode == Keys::Up)
	{
		if (this->CanMoveUp())
			this->MakeNewMove(UP);
		e->IsInputKey = true;
	}

	if (e->KeyCode == Keys::Down)
	{
		if (this->CanMoveDown())
			this->MakeNewMove(DOWN);
		e->IsInputKey = true;
	}

	if (e->KeyCode == Keys::Left)
	{
		if (this->CanMoveLeft())
			this->MakeNewMove(LEFT);
		e->IsInputKey = true;
	}

	if (e->KeyCode == Keys::Right)
	{
		if (this->CanMoveRight())
			this->MakeNewMove(RIGHT);
		e->IsInputKey = true;
	}
}

NPuzzle::MoveDirection NPuzzle::MainConsole::reverseMove(MoveDirection direction)
{
	if (direction == MoveDirection::UP)
		return MoveDirection::DOWN;

	if (direction == MoveDirection::DOWN)
		return MoveDirection::UP;

	if (direction == MoveDirection::LEFT)
		return MoveDirection::RIGHT;

	if (direction == MoveDirection::RIGHT)
		return MoveDirection::LEFT;
	return MoveDirection::EMPTY;
}
bool NPuzzle::MainConsole::CanMoveRight()
{
	if (this->MainPlayZone->GameData->blank_pos.X > 0)
		return true;
	else return false;
}
bool NPuzzle::MainConsole::CanMoveLeft()
{
	if (this->MainPlayZone->GameData->blank_pos.X < this->MainPlayZone->GameData->split_width - 1)
		return true;
	else return false;
}
bool NPuzzle::MainConsole::CanMoveDown()
{
	if (this->MainPlayZone->GameData->blank_pos.Y > 0)
		return true;
	else return false;
}
bool NPuzzle::MainConsole::CanMoveUp()
{
	if (this->MainPlayZone->GameData->blank_pos.Y < this->MainPlayZone->GameData->split_height - 1)
		return true;
	else return false;
}
void NPuzzle::MainConsole::MakeMove(MoveDirection direction)
{
	MyPoint position = this->MainPlayZone->GameData->blank_pos;
	MyPoint blank = this->MainPlayZone->GameData->blank_pos;

	if (direction == MoveDirection::UP)
		position.Y = blank.Y + 1;
	if (direction == MoveDirection::DOWN)
		position.Y = blank.Y - 1;
	if (direction == MoveDirection::LEFT)
		position.X = blank.X + 1;
	if (direction == MoveDirection::RIGHT)
		position.X = blank.X - 1;
	// -> Đổi chỗ 2 picture postion và blank
	// Dịch chuyển position vào vị trí blank:
	int PositionValue = this->MainPlayZone->GameData->HaidArray[position.Y][position.X] - 1;

	Point PictureInPosition;

	PictureInPosition.Y = PositionValue / this->MainPlayZone->GameData->split_width;
	PictureInPosition.X = PositionValue % this->MainPlayZone->GameData->split_width;

	this->MovingBox = this->MainPlayZone->pictures[PictureInPosition.Y, PictureInPosition.X];
	this->BlankBox = this->MainPlayZone->pictures[this->MainPlayZone->GameData->split_height - 1, this->MainPlayZone->GameData->split_width - 1];

	PictureBox pictureboxtmp;
	int inttmp;

	// picture của blank luôn luôn là pictures[this->Game->split_height - 1, this->Game->split_width - 1]
	pictureboxtmp.Location = this->MainPlayZone->pictures[PictureInPosition.Y, PictureInPosition.X]->Location;
	this->MainPlayZone->pictures[PictureInPosition.Y, PictureInPosition.X]->Location = this->MainPlayZone->pictures[this->MainPlayZone->GameData->split_height - 1, this->MainPlayZone->GameData->split_width - 1]->Location;
	this->MainPlayZone->pictures[this->MainPlayZone->GameData->split_height - 1, this->MainPlayZone->GameData->split_width - 1]->Location = pictureboxtmp.Location;

	inttmp = this->MainPlayZone->GameData->HaidArray[position.Y][position.X];
	this->MainPlayZone->GameData->HaidArray[position.Y][position.X] = this->MainPlayZone->GameData->HaidArray[blank.Y][blank.X];
	this->MainPlayZone->GameData->HaidArray[blank.Y][blank.X] = inttmp;
	this->MainPlayZone->GameData->blank_pos = position;

	this->Label_Turn_Display->Text = this->MainPlayZone->GameData->Game_Turn.ToString();
	this->Time_Count->Enabled = true;

}
void NPuzzle::MainConsole::MakeMoveTest(Object^ sender, EventArgs^ e)
{
	//this->MainPlayZone->pictures[2, 1]->Location = Point(this->MainPlayZone->pictures[2, 1]->Location.X, this->MainPlayZone->pictures[2, 1]->Location.Y+5);
	PictureBox pictureboxtmp;
	pictureboxtmp.Location = this->MovingBox->Location;
	this->MovingBox->Location = this->MainPlayZone->pictures[this->MainPlayZone->GameData->split_height - 1, this->MainPlayZone->GameData->split_width - 1]->Location;
	this->MainPlayZone->pictures[this->MainPlayZone->GameData->split_height - 1, this->MainPlayZone->GameData->split_width - 1]->Location = pictureboxtmp.Location;
	/*this->MainPlayZone->pictures[2, 1]->Invalidate();
	this->MainPlayZone->pictures[2, 1]->Update();*/
	this->Animation->Enabled = false;

}
void NPuzzle::MainConsole::MakeNewMove(MoveDirection direction)
{
	// Make move in GameProcessor
	this->MainPlayZone->GameData->MoveList->addMove(direction);

	// Turn = Turn + 1
	this->MainPlayZone->GameData->Game_Turn = this->MainPlayZone->GameData->Game_Turn + 1;

	// Make Move in UI
	MakeMove(direction);
	if (this->MainPlayZone->GameData->CheckFinish() == true && WonThisGame == false)
	{
		this->Time_Count->Enabled = false;
		WonThisGame = true;
		if (Sole_this_Game->Enabled == false)
			WinThisGame();
		// show chỗ nhập tên!
	}
}
void NPuzzle::MainConsole::MakeUndoMove()
{
	MoveDirection tmp;
	tmp = this->MainPlayZone->GameData->MoveList->Undo();
	tmp = reverseMove(tmp);
	if (tmp != MoveDirection::EMPTY)
	{
		this->MainPlayZone->GameData->Game_Turn = this->MainPlayZone->GameData->Game_Turn - 1;
		MakeMove(tmp);
	}

}
void NPuzzle::MainConsole::MakeRedoMove()
{
	MoveDirection tmp;
	tmp = this->MainPlayZone->GameData->MoveList->Redo();
	if (tmp != MoveDirection::EMPTY)
	{
		this->MainPlayZone->GameData->Game_Turn = this->MainPlayZone->GameData->Game_Turn + 1;
		MakeMove(tmp);
	}

}
void NPuzzle::MainConsole::UpdateTime(Object^ sender, EventArgs^ e)
{
	this->MainPlayZone->GameData->Game_Time++;
	this->Label_Time_Display->Text = (this->MainPlayZone->GameData->Game_Time).ToString();
}
void NPuzzle::MainConsole::WinThisGame()
{
	GameWonConsole^ gamewon = gcnew GameWonConsole;

	gamewon->time = this->MainPlayZone->GameData->Game_Time;
	gamewon->Game_Turn = this->MainPlayZone->GameData->Game_Turn;
	gamewon->height = this->MainPlayZone->GameData->split_height;
	gamewon->width = this->MainPlayZone->GameData->split_width;

	gamewon->label_Size->Text = "SIZE: " + gamewon->height.ToString() + "x" + gamewon->width.ToString();
	gamewon->label_Time->Text = "TIME: " + gamewon->time.ToString();
	gamewon->label_Turn->Text = "TURN: " + gamewon->Game_Turn.ToString();

	gamewon->ShowInTaskbar = false;
	gamewon->Owner = this;
	gamewon->StartPosition = FormStartPosition::CenterParent;
	gamewon->ShowDialog();

	// chèn vào 
	int pos = 0;
	while (pos < 5 && gamewon->time > this->HighScore5Player[pos]->time && this->HighScore5Player[pos]->Game_Turn != 0)
		++pos;
	if (pos < 5)
	{
		for (int i = 4; i > pos; --i)
		{
			HighScore5Player[i]->time = HighScore5Player[i - 1]->time;
			HighScore5Player[i]->Game_Turn = HighScore5Player[i - 1]->Game_Turn;
			HighScore5Player[i]->height = HighScore5Player[i - 1]->height;
			HighScore5Player[i]->width = HighScore5Player[i - 1]->width;
			HighScore5Player[i]->Name = HighScore5Player[i - 1]->Name;
		}

		HighScore5Player[pos]->time = gamewon->time;
		HighScore5Player[pos]->Game_Turn = gamewon->Game_Turn;
		HighScore5Player[pos]->height = gamewon->height;
		HighScore5Player[pos]->width = gamewon->width;
		HighScore5Player[pos]->Name = gamewon->Player_Name;

		Write_HighScore();
	}
	EventArgs^ e;
	Menu_HighScore_Click(this, e);
}
System::Void NPuzzle::MainConsole::Read_HighScore()
{
	std::string HighScore_File = "Resource\\HighScore\\HighScore";
	ifstream ifi(HighScore_File, ios::in | ios::binary);
	if (!ifi.is_open())
		MessageBox::Show("Error Open HighScore Store File!!");
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			char* _name = new char[11];
			int len;
			int time;
			int Game_Turn;
			int height;
			int width;

			ifi.read((char*)&len, sizeof(int));
			ifi.read(_name, len);
			ifi.read((char*)&time, sizeof(int));
			ifi.read((char*)&Game_Turn, sizeof(int));
			ifi.read((char*)&height, sizeof(int));
			ifi.read((char*)&width, sizeof(int));
			_name[len] = '\0';
			this->HighScore5Player[i]->Name = gcnew String(_name);
			this->HighScore5Player[i]->time = time;
			this->HighScore5Player[i]->Game_Turn = Game_Turn;
			this->HighScore5Player[i]->height = height;
			this->HighScore5Player[i]->width = width;
			delete[] _name;
		}
	}
}
System::Void NPuzzle::MainConsole::Write_HighScore()
{
	std::string HighScore_File = "Resource\\HighScore\\HighScore";
	ofstream ofi(HighScore_File, ios::out | ios::binary);
	if (!ofi.is_open())
		MessageBox::Show("Error Open HighScore Store File!!");
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			char* _name = new char[10];
			int len = this->HighScore5Player[i]->Name->Length;
			for (int j = 0; j < len; ++j)
				_name[j] = (char)this->HighScore5Player[i]->Name[j];

			int time = this->HighScore5Player[i]->time;
			int Game_Turn = this->HighScore5Player[i]->Game_Turn;
			int height = this->HighScore5Player[i]->height;
			int width = this->HighScore5Player[i]->width;

			ofi.write((char*)&len, sizeof(int));
			ofi.write(_name, len);
			ofi.write((char*)&time, sizeof(int));
			ofi.write((char*)&Game_Turn, sizeof(int));
			ofi.write((char*)&height, sizeof(int));
			ofi.write((char*)&width, sizeof(int));
			delete[] _name;
		}
	}
	return System::Void();
}