#pragma once
#include "NameSpace.h"
#include "MoveDirection.h"
#include "Solve.h"
#include <stdlib.h>

namespace NPuzzle
{
	public class GameSave
	{
	public:
		int32_t _time;
		int32_t _turn;
		int32_t _size_path;
		int32_t _split_height;
		int32_t _split_width;
		int32_t _size_row;
	};
	public class GameProcessor
	{
	public:
		GameProcessor(int Height, int Width, std::string path)
		{
			InitializeComponent(Height, Width);
			MoveList = new MoveDirectionList;
			SOLVE = new SolveGame(HaidArray, Flag, split_height, split_width);
			this->image_path = path;
		}
	public:
		~GameProcessor()
		{
			for (int i = 0; i < split_height; ++i)
			{
				delete[] HaidArray[i];
				delete[] Flag[i];
			}
			delete[] HaidArray;
			delete[] Flag;
			delete MoveList;
			delete SOLVE;
		}

	public:
		int split_width = 3;	/// Mặc định là 3
		int split_height = 3;	/// Mặc định là 3
		int Game_Time = 0;
		int Game_Turn = 0;
		std::string image_path;
		MoveDirectionList* MoveList;
		SolveGame* SOLVE;
		MyPoint blank_pos;
		int** HaidArray;
		int** Flag;

		void ErrorTestCase();

		void InitializeComponent(int Height, int Width);
		bool CanBoardSolve();
		void MakeBoardRandom();
		void Shuffle();
		void DefaultBoard();
		bool EquaDefaultBoard();
		bool CheckFinish();
	};
}