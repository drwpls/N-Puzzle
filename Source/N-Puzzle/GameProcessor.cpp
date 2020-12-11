#pragma once
#include "GameProcessor.h"
#include <fstream>
#include <time.h>
using std::ofstream;
using std::ifstream;
using std::ios;

void NPuzzle::GameProcessor::InitializeComponent(int Height, int Width)
{
	split_height = Height;
	split_width = Width;

	HaidArray = new int* [split_height];

	for (int i = 0; i < split_height; ++i)
	{
		HaidArray[i] = new int[split_width];
	}
	Flag = new int* [split_height];
	for (int i = 0; i < split_height; ++i)
	{
		Flag[i] = new int[split_width];
	}

	int tesst = 0;
	tesst = split_width + 1;

	DefaultBoard();
	Shuffle();
}

bool NPuzzle::GameProcessor::CanBoardSolve()
{
	// Chuyển về mảng int 1 chiều.
	int size = split_width * split_height;
	int* tmp = new int[size];
	int gc = 0;
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
		{
			tmp[gc] = HaidArray[i][j];
			gc++;
		}

	int reverse_position = 0;
	int sum_reverse_postion = 0;

	for (int i = 0; i < size - 1; ++i)
	{// phần tử cuối là 0, tức ô trống, nên không xét tới
		reverse_position = 0;
		for (int j = 0; j < i; ++j)
		{
			// tính từng nghịch thế của các phần tử
			if (tmp[j] > tmp[i])
				reverse_position += 1;
		}
		sum_reverse_postion += reverse_position;

	}
	if (sum_reverse_postion % 2 == 0) return true;
	else return false;
	delete[] tmp;
}

void NPuzzle::GameProcessor::ErrorTestCase()
{
	HaidArray[0][0] = 1;
	HaidArray[0][1] = 7;
	HaidArray[0][2] = 6;
	HaidArray[0][3] = 10;
	HaidArray[0][4] = 21;

	HaidArray[1][0] = 13;
	HaidArray[1][1] = 5;
	HaidArray[1][2] = 9;
	HaidArray[1][3] = 24;
	HaidArray[1][4] = 20;

	HaidArray[2][0] = 12;
	HaidArray[2][1] = 8;
	HaidArray[2][2] = 22;
	HaidArray[2][3] = 3;
	HaidArray[2][4] = 2;

	HaidArray[3][0] = 19;
	HaidArray[3][1] = 16;
	HaidArray[3][2] = 15;
	HaidArray[3][3] = 17;
	HaidArray[3][4] = 11;

	HaidArray[4][0] = 14;
	HaidArray[4][1] = 18;
	HaidArray[4][2] = 4;
	HaidArray[4][3] = 23;
	HaidArray[4][4] = 25;

	blank_pos.Y = 4;
	blank_pos.X = 4;
}

void NPuzzle::GameProcessor::DefaultBoard()
{
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
			HaidArray[i][j] = i * split_width + j + 1;
	blank_pos.X = split_width - 1;
	blank_pos.Y = split_height - 1;
}

bool NPuzzle::GameProcessor::EquaDefaultBoard()
{
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
			if (HaidArray[i][j] != i * split_width + j + 1)
				return false;
	if (blank_pos.X != split_width - 1) return false;
	if (blank_pos.Y = split_height - 1) return false;
	return true;
}

void NPuzzle::GameProcessor::MakeBoardRandom()
{
	// Chuyển về mảng int 1 chiều.
	int size = split_width * split_height;
	int* tmp = new int[size];
	int gc = 0;
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
		{
			tmp[gc] = HaidArray[i][j];
			gc++;
		}

	int rd1, rd2, maxint = split_height * split_width;
	srand((unsigned int)time(0));

	for (int i = 0; i < 2 * split_height * split_width; ++i)
	{
		rd1 = rand() % (maxint - 2) + 1;
		rd2 = rand() % (maxint - 2) + 1;
		if (rd1 != rd2)
			std::swap(tmp[rd1], tmp[rd2]);
	}

	gc = 0;
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
		{
			HaidArray[i][j] = tmp[gc];
			gc++;
		}
	delete[] tmp;
}

void NPuzzle::GameProcessor::Shuffle()
{
	do
		MakeBoardRandom();
	while (CanBoardSolve() != true || EquaDefaultBoard() == true);
}

bool NPuzzle::GameProcessor::CheckFinish()
{
	bool checker = true;
	for (int i = 0; i < split_height; ++i)
		for (int j = 0; j < split_width; ++j)
		{
			if (i == split_height - 1 && j == split_width - 1)
			{
				continue;
			}
			if (HaidArray[i][j] != split_width * i + j + 1)
				checker = false;
		}
	return checker;
}
