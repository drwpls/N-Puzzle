#pragma once
#include "PlayZone.h"
namespace NPuzzle
{
	public ref class HighScorePlayer
	{
	public:
		HighScorePlayer()
		{
			Name = "Player";
			time = 0;
			Game_Turn = 0;
			height = 0;
			width = 0;
		}
	public:
		String^ Name;
		int time;
		int Game_Turn;
		int height;
		int width;
	};

	public ref class Panel_HighScorePlayer : public System::Windows::Forms::UserControl
	{
	public:
		Panel_HighScorePlayer(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Panel_HighScorePlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Void InitializeComponent(void)
		{
			this->label_Size_Player = (gcnew System::Windows::Forms::Label());
			this->label_Turn_Player = (gcnew System::Windows::Forms::Label());
			this->label_Time_PLayer = (gcnew System::Windows::Forms::Label());
			this->label_Name_Player = (gcnew System::Windows::Forms::Label());
			// 
			// label_Size_Player1
			// 
			this->label_Size_Player->AutoSize = true;
			this->label_Size_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_Size_Player->Location = System::Drawing::Point(250, 0);
			this->label_Size_Player->Name = L"label_Size_Player1";
			this->label_Size_Player->Size = System::Drawing::Size(28, 16);
			this->label_Size_Player->TabIndex = 2;
			this->label_Size_Player->Text = L"0x0";
			// 
			// label_Turn_Player1
			// 
			this->label_Turn_Player->AutoSize = true;
			this->label_Turn_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_Turn_Player->Location = System::Drawing::Point(172, 0);
			this->label_Turn_Player->Name = L"label_Turn_Player1";
			this->label_Turn_Player->Size = System::Drawing::Size(15, 16);
			this->label_Turn_Player->TabIndex = 2;
			this->label_Turn_Player->Text = L"0";
			// 
			// label_Time_PLayer1
			// 
			this->label_Time_PLayer->AutoSize = true;
			this->label_Time_PLayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_Time_PLayer->Location = System::Drawing::Point(95, 0);
			this->label_Time_PLayer->Name = L"label_Time_PLayer1";
			this->label_Time_PLayer->Size = System::Drawing::Size(15, 16);
			this->label_Time_PLayer->TabIndex = 1;
			this->label_Time_PLayer->Text = L"0";
			// 
			// label_Name_Player1
			// 
			this->label_Name_Player->AutoSize = true;
			this->label_Name_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_Name_Player->Location = System::Drawing::Point(3, 0);
			this->label_Name_Player->Name = L"label_Name_Player1";
			this->label_Name_Player->Size = System::Drawing::Size(47, 16);
			this->label_Name_Player->TabIndex = 0;
			this->label_Name_Player->Text = L"Player";

			// 
			// Form
			// 
			this->Controls->Add(this->label_Size_Player);
			this->Controls->Add(this->label_Turn_Player);
			this->Controls->Add(this->label_Time_PLayer);
			this->Controls->Add(this->label_Name_Player);
			this->Name = L"panel_player1";
			this->Size = System::Drawing::Size(311, 17);
			this->TabIndex = 2;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::ComponentModel::Container^ components;
	public:
		System::Windows::Forms::Label^ label_Size_Player;
		System::Windows::Forms::Label^ label_Turn_Player;
		System::Windows::Forms::Label^ label_Time_PLayer;
		System::Windows::Forms::Label^ label_Name_Player;
	};

	public ref class HighScoreConsole : public System::Windows::Forms::Form
	{
	public:
		HighScoreConsole(void)
		{
			this->MinimizeBox = false;
			this->MaximizeBox = false;
			InitializeComponent();
		}

	protected:
		~HighScoreConsole()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		System::Windows::Forms::Label^ Label_High_Score;
		System::Windows::Forms::ComboBox^ ChooseOption;
		Panel_HighScorePlayer^ Title;
		array<NPuzzle::Panel_HighScorePlayer^>^ Panel_HighScore5Player;
		array<NPuzzle::HighScorePlayer^>^ HighScore5Player;

		void SetPanel_HighScore(Panel_HighScorePlayer^, HighScorePlayer^);
		void User_Choose_All();
		void User_Choose_Pro();
		void User_Choose_Advance();
		void User_Choose_Amateur();
		void ChooseOption_Changed(System::Object^ sender, System::EventArgs^ e);

	private:
		System::ComponentModel::Container^ components;
		void InitializeComponent(void)
		{
			this->Label_High_Score = (gcnew System::Windows::Forms::Label());
			this->ChooseOption = (gcnew System::Windows::Forms::ComboBox());
			this->Title = (gcnew Panel_HighScorePlayer());
			this->Panel_HighScore5Player = gcnew array<Panel_HighScorePlayer^>(5);

			for (int i = 0; i < 5; ++i)
				this->Panel_HighScore5Player[i] = (gcnew Panel_HighScorePlayer());

			for (int i = 0; i < 5; ++i)
				this->Panel_HighScore5Player[i]->SuspendLayout();
			this->SuspendLayout();

			this->Label_High_Score->AutoSize = true;
			this->Label_High_Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_High_Score->Location = System::Drawing::Point(14, 9);
			this->Label_High_Score->Name = L"Label_High_Score";
			this->Label_High_Score->Size = System::Drawing::Size(137, 24);
			this->Label_High_Score->TabIndex = 0;
			this->Label_High_Score->Text = L"HIGH SCORE";

			this->Title->Location = System::Drawing::Point(12, 49);
			this->Title->Name = L"panel_title";
			this->Title->label_Name_Player->Text = L"Name";
			this->Title->label_Time_PLayer->Text = L"Time";
			this->Title->label_Turn_Player->Text = L"Turn";
			this->Title->label_Size_Player->Text = L"Size";

			this->Title->label_Name_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->label_Time_PLayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->label_Turn_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->label_Size_Player->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			for (int i = 0; i < 5; ++i)
			{
				this->Panel_HighScore5Player[i]->Location = System::Drawing::Point(12, 87 + i * 23);
				this->Panel_HighScore5Player[i]->Name = L"panel_player1" + i.ToString();
			}

			this->ChooseOption->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ChooseOption->FormattingEnabled = true;
			this->ChooseOption->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"All", L"Pro-Player", L"Advance-Player", L"Amateur-Player" });
			this->ChooseOption->Location = System::Drawing::Point(202, 9);
			this->ChooseOption->Name = L"ChooseOption";
			this->ChooseOption->Size = System::Drawing::Size(121, 21);
			this->ChooseOption->TabStop = false;

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 208);
			this->Controls->Add(this->Label_High_Score);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->ChooseOption);

			for (int i = 0; i < 5; ++i)
				this->Controls->Add(this->Panel_HighScore5Player[i]);

			this->Name = L"HighScoreConsole";
			this->Text = L"High Score";
			this->Title->ResumeLayout(false);
			this->Title->PerformLayout();

			for (int i = 0; i < 5; ++i)
			{
				this->Panel_HighScore5Player[i]->ResumeLayout(false);
				this->Panel_HighScore5Player[i]->PerformLayout();
			}

			this->ResumeLayout(false);
			this->PerformLayout();
			this->ChooseOption->SelectedIndexChanged += gcnew System::EventHandler(this, &HighScoreConsole::ChooseOption_Changed);
		}
	};

	public ref class GameWonConsole : public System::Windows::Forms::Form
	{
	public:
		GameWonConsole(void)
		{
			this->MinimizeBox = false;
			this->MaximizeBox = false;
			this->ControlBox = false;

			InitializeComponent();
		}

	protected:
		~GameWonConsole()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		System::Windows::Forms::TextBox^ textbox_InputName;
		System::Windows::Forms::Label^ label_Game_Won;
		System::Windows::Forms::Label^ label_Size;
		System::Windows::Forms::Label^ label_Time;
		System::Windows::Forms::Label^ label_Turn;
		System::Windows::Forms::Label^ label_YourName;
		System::Windows::Forms::Button^ button_OK;

	private:
		System::ComponentModel::Container^ components;

		System::Void button_OK_Click(System::Object^ sender, System::EventArgs^ e);
	public:
		int time;
		int Game_Turn;
		int height;
		int width;
		String^ Player_Name;

		void InitializeComponent(void)
		{
			this->textbox_InputName = (gcnew System::Windows::Forms::TextBox());
			this->label_Game_Won = (gcnew System::Windows::Forms::Label());
			this->label_Size = (gcnew System::Windows::Forms::Label());
			this->label_Time = (gcnew System::Windows::Forms::Label());
			this->label_Turn = (gcnew System::Windows::Forms::Label());
			this->label_YourName = (gcnew System::Windows::Forms::Label());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textbox_InputName
			// 
			this->textbox_InputName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textbox_InputName->Location = System::Drawing::Point(68, 148);
			this->textbox_InputName->Name = L"textbox_InputName";
			this->textbox_InputName->Size = System::Drawing::Size(211, 38);
			this->textbox_InputName->TabIndex = 0;
			this->textbox_InputName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_Game_Won
			// 
			this->label_Game_Won->AutoSize = true;
			this->label_Game_Won->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Game_Won->Location = System::Drawing::Point(92, 9);
			this->label_Game_Won->Name = L"label_Game_Won";
			this->label_Game_Won->Size = System::Drawing::Size(176, 31);
			this->label_Game_Won->TabIndex = 1;
			this->label_Game_Won->Text = L"TOO EASY\?";
			// 
			// label_Size
			// 
			this->label_Size->AutoSize = true;
			this->label_Size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Size->Location = System::Drawing::Point(132, 49);
			this->label_Size->Name = L"label_Size";
			this->label_Size->Size = System::Drawing::Size(93, 20);
			this->label_Size->TabIndex = 2;
			this->label_Size->Text = L"SIZE 30x30";
			this->label_Size->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Time
			// 
			this->label_Time->AutoSize = true;
			this->label_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Time->Location = System::Drawing::Point(22, 86);
			this->label_Time->Name = L"label_Time";
			this->label_Time->Size = System::Drawing::Size(82, 20);
			this->label_Time->TabIndex = 3;
			this->label_Time->Text = L"TIME: 500";
			this->label_Time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Turn
			// 
			this->label_Turn->AutoSize = true;
			this->label_Turn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Turn->Location = System::Drawing::Point(244, 86);
			this->label_Turn->Name = L"label_Turn";
			this->label_Turn->Size = System::Drawing::Size(88, 20);
			this->label_Turn->TabIndex = 4;
			this->label_Turn->Text = L"TURN: 500";
			this->label_Turn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_YourName
			// 
			this->label_YourName->AutoSize = true;
			this->label_YourName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_YourName->Location = System::Drawing::Point(115, 114);
			this->label_YourName->Name = L"label_YourName";
			this->label_YourName->Size = System::Drawing::Size(120, 20);
			this->label_YourName->TabIndex = 5;
			this->label_YourName->Text = L"YOUR NAME:";
			this->label_YourName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(136, 192);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(75, 23);
			this->button_OK->TabIndex = 6;
			this->button_OK->Text = L"OK";
			this->button_OK->UseVisualStyleBackColor = true;
			// 
			// GameWonConsole
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 222);
			this->Controls->Add(this->button_OK);
			this->Controls->Add(this->label_YourName);
			this->Controls->Add(this->label_Turn);
			this->Controls->Add(this->label_Time);
			this->Controls->Add(this->label_Size);
			this->Controls->Add(this->label_Game_Won);
			this->Controls->Add(this->textbox_InputName);
			this->Name = L"GameWonConsole";
			this->Text = L"YOU WON!";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->button_OK->Click += gcnew System::EventHandler(this, &GameWonConsole::button_OK_Click);

		}
	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys KeyData) override
		{
			switch (KeyData)
			{
			case (Keys::Enter):
			{
				EventArgs^ e;
				button_OK_Click(this, e);
				break;
			}
			default:
				return Form::ProcessCmdKey(msg, KeyData);
			};
			return 0;
		}
	};

	public ref class NewGameChoiceConsole : public System::Windows::Forms::Form
	{
	public:
		NewGameChoiceConsole(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
		}

	protected:
		~NewGameChoiceConsole()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container^ components;
		void InitializeComponent(void);
	public:
		int textbox_split_height_int;
		int textbox_split_width_int;
		bool sumbit_newgame_clicked = 0;
		bool image_radio_button_chosen = 0;
		String^ Image_Path;
		String^ Image_Name;

	private:
		System::Windows::Forms::Label^ Label_Size;
		System::Windows::Forms::Label^ Label_Height;
		System::Windows::Forms::Label^ Label_Width;

		System::Windows::Forms::Label^ Label_Number_Image;
		System::Windows::Forms::RadioButton^ RadioButton_Image;
		System::Windows::Forms::RadioButton^ RadioButton_Number;
		System::Windows::Forms::Button^ Button_Submit;
		System::Windows::Forms::Button^ Button_ChooseFile;
		System::Windows::Forms::Label^ Label_FileChosen;

		System::Windows::Forms::NumericUpDown^ NumericUpDown_Height;
		System::Windows::Forms::NumericUpDown^ NumericUpDown_Width;

		System::Void RadioButton_Number_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void RadioButton_Image_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void Button_ChooseFile_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Button_Submit_Click(System::Object^ sender, System::EventArgs^ e);
	};

	//===========================================//

	public ref class MainConsole : public System::Windows::Forms::Form
	{
	public:
		MainConsole(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
		}
	protected:
		~MainConsole()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container^ components;
		void InitializeComponent();

	private:
		//int windows_width = 1000;
		//int windows_height = 400;
		array<NPuzzle::HighScorePlayer^>^ HighScore5Player;

		System::Windows::Forms::MenuStrip^ Menu_Bar;
		System::Windows::Forms::ToolStripMenuItem^ Menu;
		System::Windows::Forms::ToolStripMenuItem^ Menu_NewGame;
		System::Windows::Forms::ToolStripMenuItem^ Menu_SaveGame;
		System::Windows::Forms::ToolStripMenuItem^ Menu_LoadGame;
		System::Windows::Forms::ToolStripMenuItem^ Menu_HighScore;

		System::Windows::Forms::ToolStripMenuItem^ Help;
		System::Windows::Forms::ToolStripMenuItem^ Help_Solve_Game;
		System::Windows::Forms::ToolStripMenuItem^ Help_Hint;
		System::Windows::Forms::ToolStripMenuItem^ Help_Undo;
		System::Windows::Forms::ToolStripMenuItem^ Help_Redo;

		System::Windows::Forms::Panel^ Panel_Time;
		System::Windows::Forms::Label^ Label_Time;
		System::Windows::Forms::Label^ Label_Time_Display;

		System::Windows::Forms::Panel^ Panel_Turn;
		System::Windows::Forms::Label^ Label_Turn;
		System::Windows::Forms::Label^ Label_Turn_Display;

	public:
		NPuzzle::PlayZone^ MainPlayZone;
		NPuzzle::PlayZone^ PlayAreaNew;

		SaveFileDialog^ saveGame_Click;
		OpenFileDialog^ loadGame_Click;

		System::Void Menu_NewGame_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Menu_SaveGame_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Menu_LoadGame_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Menu_HighScore_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Picture_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Help_Undo_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Help_Redo_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Help_Hint_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Help_Solve_Game_Click(System::Object^ sender, System::EventArgs^ e);
		Timer^ Sole_this_Game;

		System::Void Read_HighScore();
		System::Void Write_HighScore();
		System::Void WinThisGame();
		bool WonThisGame = false;

		void KeyPress(System::Object^ sender, KeyEventArgs^ e);
		void DirectionPress(System::Object^ sender, PreviewKeyDownEventArgs^ e);

		MoveDirection reverseMove(MoveDirection);
		bool CanMoveLeft();
		bool CanMoveRight();
		bool CanMoveDown();
		bool CanMoveUp();

		void MakeMove(MoveDirection direction);
		void MakeNewMove(MoveDirection direction);
		void MakeUndoMove();
		void MakeRedoMove();

		System::Windows::Forms::Timer^ Time_Count;
		System::Windows::Forms::Timer^ Animation;
		void UpdateTime(Object^ sender, EventArgs^ e);
		void MakeMoveTest(Object^ sender, EventArgs^ e);
		System::Windows::Forms::PictureBox^ MovingBox;
		System::Windows::Forms::PictureBox^ BlankBox;

	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys KeyData) override
		{
			switch (KeyData)
			{
			case (Keys::Control | Keys::N):
			{
				EventArgs^ e;
				Menu_NewGame_Click(this, e);
				break;
			}

			case (Keys::Control | Keys::S):
			{
				EventArgs^ e;
				Menu_SaveGame_Click(this, e);
				break;
			}

			case (Keys::Control | Keys::L):
			{
				EventArgs^ e;
				Menu_LoadGame_Click(this, e);
				break;
			}

			case (Keys::Control | Keys::Z):
			{
				this->MakeUndoMove();
				break;
			}

			case (Keys::Control | Keys::Y):
			{
				this->MakeRedoMove();
				break;
			}

			case (Keys::Control | Keys::H):
			{
				EventArgs^ e;
				Menu_HighScore_Click(this, e);
				break;
			}

			case (Keys::Up):
			{
				if (this->CanMoveUp())
					this->MakeNewMove(UP);
				break;
			}

			case (Keys::Down):
			{
				if (this->CanMoveDown())
					this->MakeNewMove(DOWN);
				break;
			}

			case (Keys::Left):
			{
				if (this->CanMoveLeft())
					this->MakeNewMove(LEFT);
				break;
			}

			case (Keys::Right):
			{
				if (this->CanMoveRight())
					this->MakeNewMove(RIGHT);
				break;
			}

			case (Keys::H):
			{
				EventArgs^ e;
				Help_Hint_Click(this, e);
				break;
			}

			case (Keys::Space):
			{
				//WinThisGame();
				break;
			}
			default:
				return Form::ProcessCmdKey(msg, KeyData);
			};
			return 0;
		}
	};
}