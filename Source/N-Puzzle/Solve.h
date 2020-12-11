#pragma once
#include <math.h>
#include <algorithm>
#include "MoveDirection.h"
namespace NPuzzle
{
	public class MyPoint
	{
	public:
		MyPoint(int Y, int X)
		{
			this->Y = Y;
			this->X = X;
		}
		MyPoint()
		{
			Y = X = 0;
		}
	public:
		int Y, X;
	};

	class SolveGame {

	public:
		SolveGame(int** arr, int** flag, int split_height, int split_width)
		{
			this->arr = arr;
			this->flag = flag;
			this->split_height = split_height;
			this->split_width = split_width;
			CASE = 0;
		}


		int split_width = 3, split_height = 3;

		int** arr;
		int** flag;
		int CASE;
		MyPoint blank = { 0, 0 };
		MyPoint now_position = { 0, 0 };

		bool Solve_CanMove(MoveDirection Direct)
		{
			switch (Direct)
			{
			case MoveDirection::LEFT:
			{
				if (blank.X < split_width - 1)
					if (flag[blank.Y][blank.X + 1] == 1)
						return true;
				return false;
			}

			case MoveDirection::RIGHT:
			{
				if (blank.X > 0)
					if (flag[blank.Y][blank.X - 1] == 1)
						return true;
				return false;
			}

			case MoveDirection::UP:
			{
				if (blank.Y < split_height - 1)
					if (flag[blank.Y + 1][blank.X] == 1)
						return true;
				return false;
			}

			case MoveDirection::DOWN:
			{
				if (blank.Y > 0)
					if (flag[blank.Y - 1][blank.X] == 1)
						return true;
				return false;
			}
			default: return false;
			}
		}
		void Solve_MakeMove(MoveDirection Direct)
		{
			switch (Direct)
			{
			case MoveDirection::LEFT:
			{
				std::swap(arr[blank.Y][blank.X], arr[blank.Y][blank.X + 1]);
				blank.X += 1;
				break;
			}

			case MoveDirection::RIGHT:
			{
				std::swap(arr[blank.Y][blank.X], arr[blank.Y][blank.X - 1]);
				blank.X -= 1;
				break;
			}

			case MoveDirection::UP:
			{
				std::swap(arr[blank.Y][blank.X], arr[blank.Y + 1][blank.X]);
				blank.Y += 1;
				break;
			}

			case MoveDirection::DOWN:
			{
				std::swap(arr[blank.Y][blank.X], arr[blank.Y - 1][blank.X]);
				blank.Y -= 1;
				break;
			}
			}
		}
		int Solve_dPoint(MyPoint first, MyPoint second)
		{
			return abs(first.X - second.X) + abs(first.Y - second.Y);
		}
		int Solve_Find_Move_In_5_Turn(MyPoint now_position, int index, int turnpreview, int firstdpoint)
		{
			MyPoint INDEX;

			for (int i = 0; i < split_height; ++i)
				for (int j = 0; j < split_width; ++j)
				{
					if (index == arr[i][j])
						INDEX = { i, j };
				}
			int dxy = Solve_dPoint(INDEX, now_position);
			if (turnpreview > 7) return 10;

			if (dxy < firstdpoint)
				return turnpreview;
			if (dxy > firstdpoint)
				return 10;

			int x = 10;
			int xtmp = 10;
			if (Solve_CanMove(MoveDirection::LEFT))
			{
				Solve_MakeMove(MoveDirection::LEFT);
				xtmp = Solve_Find_Move_In_5_Turn(now_position, index, turnpreview + 1, firstdpoint);
				x = xtmp < x ? xtmp : x;
				Solve_MakeMove(MoveDirection::RIGHT);
			}
			if (Solve_CanMove(MoveDirection::RIGHT))
			{
				Solve_MakeMove(MoveDirection::RIGHT);
				xtmp = Solve_Find_Move_In_5_Turn(now_position, index, turnpreview + 1, firstdpoint);
				x = xtmp < x ? xtmp : x;
				Solve_MakeMove(MoveDirection::LEFT);
			}

			if (Solve_CanMove(MoveDirection::DOWN))
			{
				Solve_MakeMove(MoveDirection::DOWN);
				xtmp = Solve_Find_Move_In_5_Turn(now_position, index, turnpreview + 1, firstdpoint);
				x = xtmp < x ? xtmp : x;
				Solve_MakeMove(MoveDirection::UP);
			}
			if (Solve_CanMove(MoveDirection::UP))
			{
				Solve_MakeMove(MoveDirection::UP);
				xtmp = Solve_Find_Move_In_5_Turn(now_position, index, turnpreview + 1, firstdpoint);
				x = xtmp < x ? xtmp : x;
				Solve_MakeMove(MoveDirection::DOWN);
			}
			return x;
		}
		MoveDirection Solve_Move_index_to_now_position(MyPoint now_position, int index)
		{
			MyPoint INDEX;
			for (int i = 0; i < split_height; ++i)
				for (int j = 0; j < split_width; ++j)
				{
					if (index == arr[i][j])
						INDEX = { i, j };
				}

			int firstdpoint = Solve_dPoint(INDEX, now_position);

			int _up, _down, _left, _right;
			_up = _down = _left = _right = 10;

			if (Solve_CanMove(MoveDirection::UP))
			{
				Solve_MakeMove(MoveDirection::UP);
				_up = Solve_Find_Move_In_5_Turn(now_position, index, 1, firstdpoint);
				Solve_MakeMove(MoveDirection::DOWN);
			}
			if (Solve_CanMove(MoveDirection::DOWN))
			{
				Solve_MakeMove(MoveDirection::DOWN);
				_down = Solve_Find_Move_In_5_Turn(now_position, index, 1, firstdpoint);
				Solve_MakeMove(MoveDirection::UP);
			}
			if (Solve_CanMove(MoveDirection::LEFT))
			{
				Solve_MakeMove(MoveDirection::LEFT);
				_left = Solve_Find_Move_In_5_Turn(now_position, index, 1, firstdpoint);
				Solve_MakeMove(MoveDirection::RIGHT);
			}
			if (Solve_CanMove(MoveDirection::RIGHT))
			{
				Solve_MakeMove(MoveDirection::RIGHT);
				_right = Solve_Find_Move_In_5_Turn(now_position, index, 1, firstdpoint);
				Solve_MakeMove(MoveDirection::LEFT);
			}

			int _min = 9;
			_min = _min < _up ? _min : _up;
			_min = _min < _down ? _min : _down;
			_min = _min < _left ? _min : _left;
			_min = _min < _right ? _min : _right;

			if (_min == _down)
			{
				return MoveDirection::DOWN;
			}
			if (_min == _right)
			{
				return MoveDirection::RIGHT;
			}
			if (_min == _up)
			{
				return MoveDirection::UP;
			}
			if (_min == _left)
			{
				return MoveDirection::LEFT;
			}
			return MoveDirection::EMPTY;
		}
		MoveDirection Solve_Make_blank_near_INDEX(MyPoint INDEX)
		{
			int dxy = Solve_dPoint(INDEX, blank);
			int dxy_; // sau khi move

			if (Solve_CanMove(MoveDirection::DOWN))
			{
				Solve_MakeMove(MoveDirection::DOWN);
				dxy_ = Solve_dPoint(INDEX, blank);
				Solve_MakeMove(MoveDirection::UP);
				if (dxy > dxy_)
					return MoveDirection::DOWN;
			}

			if (Solve_CanMove(MoveDirection::RIGHT))
			{
				Solve_MakeMove(MoveDirection::RIGHT);
				dxy_ = Solve_dPoint(INDEX, blank);
				Solve_MakeMove(MoveDirection::LEFT);
				if (dxy > dxy_)
					return MoveDirection::RIGHT;
			}
			if (Solve_CanMove(MoveDirection::UP))
			{
				Solve_MakeMove(MoveDirection::UP);
				dxy_ = Solve_dPoint(INDEX, blank);
				Solve_MakeMove(MoveDirection::DOWN);
				if (dxy > dxy_)
					return MoveDirection::UP;
			}
			if (Solve_CanMove(MoveDirection::LEFT))
			{
				Solve_MakeMove(MoveDirection::LEFT);
				dxy_ = Solve_dPoint(INDEX, blank);
				Solve_MakeMove(MoveDirection::RIGHT);
				if (dxy > dxy_)
					return MoveDirection::LEFT;
			}
			return MoveDirection::EMPTY;
		}
		MoveDirection Solve_Make_Right_Position(MyPoint now_position, int index)
		{
			MyPoint INDEX;
			for (int i = 0; i < split_height; ++i)
				for (int j = 0; j < split_width; ++j)
				{
					if (index == arr[i][j])
						INDEX = { i, j };
				}

			if (abs(blank.X - INDEX.X) <= 1 && abs(blank.Y - INDEX.Y) <= 1)
			{
				return Solve_Move_index_to_now_position(now_position, index);
			}
			else
			{
				return Solve_Make_blank_near_INDEX(INDEX);
			}
		}
		MoveDirection Solve_Make_blank_Setup_Position(MyPoint now_position)
		{
			if (blank.X < split_width - 1)
				if (blank.Y < now_position.Y + 2)
				{
					return MoveDirection::UP;
				}
				else
				{
					return MoveDirection::LEFT;
				}

			return MoveDirection::DOWN;
		}
		MoveDirection Solve_Make_Setup_Position(MyPoint vitridangxet, int index)
		{
			MyPoint INDEX;

			if (vitridangxet.X == split_width - 2)
			{
				index = index + 1;
				for (int i = 0; i < split_height; ++i)
					for (int j = 0; j < split_width; ++j)
					{
						if (index == arr[i][j])
							INDEX = { i, j };
					}
				if (abs(blank.X - INDEX.X) <= 1 && abs(blank.Y - INDEX.Y) <= 1)
					return Solve_Move_index_to_now_position(vitridangxet, index);
				else
					return Solve_Make_blank_near_INDEX(INDEX);
			}

			if (vitridangxet.X == split_width - 1)
			{
				index = index - 1;
				for (int i = 0; i < split_height; ++i)
					for (int j = 0; j < split_width; ++j)
					{
						if (index == arr[i][j])
							INDEX = { i, j };
					}
				if (abs(blank.X - INDEX.X) <= 1 && abs(blank.Y - INDEX.Y) <= 1)
				{
					vitridangxet.X--;
					vitridangxet.Y++;
					return Solve_Move_index_to_now_position(vitridangxet, index);
				}
				else
					return Solve_Make_blank_near_INDEX(INDEX);
			}
			return MoveDirection::EMPTY;
		}
		MoveDirection Solve_Make_blank_Setup_Position2()
		{
			if (blank.Y < split_height - 1)
			{
				return MoveDirection::UP;
			}
			else
			{
				return MoveDirection::RIGHT;
			}
		}
		MoveDirection Solve_Make_Setup_Position2(MyPoint vitridangxet, int index)
		{
			MyPoint INDEX;
			if (vitridangxet.Y == split_height - 2)
			{
				index = index + split_width;
				for (int i = 0; i < split_height; ++i)
					for (int j = 0; j < split_width; ++j)
					{
						if (index == arr[i][j])
							INDEX = { i, j };
					}
				if (abs(blank.X - INDEX.X) <= 1 && abs(blank.Y - INDEX.Y) <= 1)
					return Solve_Move_index_to_now_position(vitridangxet, index);
				else
					return Solve_Make_blank_near_INDEX(INDEX);
			}

			if (vitridangxet.Y == split_height - 1)
			{
				index = index - split_width;
				for (int i = 0; i < split_height; ++i)
					for (int j = 0; j < split_width; ++j)
					{
						if (index == arr[i][j])
							INDEX = { i, j };
					}
				if (abs(blank.X - INDEX.X) <= 1 && abs(blank.Y - INDEX.Y) <= 1)
				{
					vitridangxet.X++;
					vitridangxet.Y--;
					return Solve_Move_index_to_now_position(vitridangxet, index);
				}
				else
					return Solve_Make_blank_near_INDEX(INDEX);
			}
			return MoveDirection::EMPTY;
		}
		MoveDirection GenMove()
		{
			for (int i = 0; i < split_height; ++i)
			{
				for (int j = 0; j < split_width; j++)
				{
					if (arr[i][j] == split_height * split_width)
						blank = { i,j };
				}
			}

			MoveDirection RESULT;


			for (int i = 0; i < split_height; ++i)
			{
				for (int j = 0; j < split_width; j++)
				{
					flag[i][j] = 1;
				}
			}

			if (!(CASE == -1 || CASE == -2))
				CASE = 0;
			else
			{
				if (CASE == -1)
				{
					for (int i = 0; i < now_position.Y; ++i)
						for (int j = 0; j < split_width; ++j)
							flag[i][j] = 0;
					for (int j = 0; j < now_position.X - 1; ++j)
						flag[now_position.Y][j] = 0;
				}
				if (CASE == -2)
				{
					for (int i = 0; i < split_height - 2; ++i)
						for (int j = 0; j < split_width; ++j)
							flag[i][j] = 0;
					for (int j = 0; j < now_position.X; ++j)
					{
						flag[split_height - 1][j] = 0;
						flag[split_height - 2][j] = 0;
					}
				}

			}
			for (int i = 0; i < split_height - 2; ++i)
			{
				if (CASE != 0) break;

				for (int j = 0; j < split_width; ++j)
				{
					if (CASE != 0) break;		// control break

					if (arr[i][j] == split_width * i + j + 1)
					{
						flag[i][j] = 0;			// các vị trí đã đúng
						if (j == split_width - 2 && arr[i][j + 1] != i * split_width + j + 2)
						{
							flag[i][j] = 1;
							now_position = { i, j };
							CASE = 1;
						}
					}
					else
					{
						if (j < split_width - 2)
						{
							now_position = { i, j };
							CASE = 1;
						}
						else
							if (j == split_width - 2)
							{
								if (CASE == -1)
								{
									flag[i][j] = 1;
									now_position = { i, j + 1 };
								}
								else
									if (arr[i][j] == split_width * i + j + 2)
										flag[i][j] = 2;		// setup position
									else
									{
										now_position = { i, j };
										CASE = 1;
									}
							}


							else if (j == split_width - 1)
							{
								if (arr[i + 1][j - 1] == split_width * i + j)
									flag[i][j] = 2;
								now_position = { i, j };

								if (arr[i][j] == split_width * i + j || (arr[i][j] == split_height * split_width && arr[i + 1][j] == split_width * i + j) || CASE == -1)
								{
									flag[i][j - 1] = 1;
									CASE = -1;
								}
								else
									CASE = 1;
							}
					}
				}
			}

			// xử lý số 2, chưa có vị trí đang xét.
			if (CASE == 0)
				for (int j = 0; j < split_width - 2; ++j)
				{
					if (CASE != 0) break;
					if (arr[split_height - 2][j] == split_width * (split_height - 2) + j + 1 && arr[split_height - 1][j] == split_width * (split_height - 1) + j + 1)
					{
						flag[split_height - 2][j] = 0;
						flag[split_height - 1][j] = 0;
					}
					else
					{
						if (arr[split_height - 2][j] == split_width * (split_height - 1) + j + 1)
						{
							flag[split_height - 2][j] = 2;		// setup position
							now_position = { split_height - 1 , j };
							if (arr[split_height - 2][j + 1] == split_width * (split_height - 2) + j + 1)
							{
								flag[split_height - 1][j] = 2;		// setup position
							}
							if (arr[split_height - 1][j] == split_width * (split_height - 2) + j + 1 || (arr[split_height - 1][j] == split_height * split_width && arr[split_height - 1][j + 1] == split_width * (split_height - 2) + j + 1) || CASE == -2)
							{
								flag[split_height - 2][j] = 1;
								CASE = -2;
							}
							else
								CASE = 2;
						}
						else
						{
							if (CASE == -2)
							{
								now_position = { split_height - 1 , j };
							}
							else
							{
								now_position = { split_height - 2 , j };
								CASE = 2;
							}
						}
					}

				}

			if (CASE == 0)
				CASE = 3;
			while (1)
			{
				MyPoint INDEX;
				int index = now_position.Y * split_width + now_position.X + 1;
				if (CASE == 3)
				{
					if (blank.Y == split_height - 2 && blank.X == split_width - 2)
					{
						RESULT = MoveDirection::UP;
						break;
					}
					if (blank.Y == split_height - 1 && blank.X == split_width - 2)
					{
						RESULT = MoveDirection::LEFT;
						break;
					}
					if (blank.Y == split_height - 1 && blank.X == split_width - 1)
					{
						RESULT = MoveDirection::DOWN;
						break;
					}
					if (blank.Y == split_height - 2 && blank.X == split_width - 1)
					{
						RESULT = MoveDirection::RIGHT;
						break;
					}
				}
				for (int i = 0; i < split_height; ++i)
					for (int j = 0; j < split_width; ++j)
					{
						if (index == arr[i][j])
							INDEX = { i, j };
					}

				if (CASE == -1)
				{
					int indextmp = now_position.Y * split_width + now_position.X;
					MyPoint tmp = now_position;
					tmp.Y += 2;
					RESULT = Solve_Make_Right_Position(tmp, indextmp);
					if (indextmp == arr[now_position.Y + 2][now_position.X])
						CASE = 0;
					break;
				}

				if (CASE == -2)
				{
					int indextmp = (now_position.Y - 1) * split_width + now_position.X + 1;
					MyPoint tmp = now_position;
					tmp.X += 2;
					RESULT = Solve_Make_Right_Position(tmp, indextmp);
					if (indextmp == arr[now_position.Y][now_position.X + 2])
						CASE = 0;
					break;
				}

				if (CASE == 1)
				{//if (vitridangxet.Y < split_height - 2)
					if (now_position.X < split_width - 2)
					{
						RESULT = Solve_Make_Right_Position(now_position, index);
						break;
					}
					if (now_position.X == split_width - 2)
					{
						if (arr[now_position.Y][now_position.X] == split_height * split_width)
							if (arr[now_position.Y][now_position.X + 1] == now_position.Y * split_width + now_position.X + 2)
								if (arr[now_position.Y + 1][now_position.X] == now_position.Y * split_width + now_position.X + 1)
								{
									RESULT = MoveDirection::UP;
									break;
								}
						RESULT = Solve_Make_Setup_Position(now_position, index);
						break;
					}
					if (now_position.X == split_width - 1)
					{
						if (flag[now_position.Y][now_position.X] == 2 && flag[now_position.Y][now_position.X - 1] == 2)
							if (blank.X == now_position.X && blank.Y == now_position.Y)
							{
								RESULT = MoveDirection::RIGHT;
								break;
							}
							else
							{
								RESULT = Solve_Make_blank_Setup_Position(now_position);
								break;
							}
						RESULT = Solve_Make_Setup_Position(now_position, index);
						break;
					}
				}

				if (CASE == 2)
				{//if (vitridangxet.Y >= split_height - 2)
					if (now_position.Y == split_height - 2)
					{
						if (arr[now_position.Y][now_position.X] == split_height * split_width)
							if (arr[now_position.Y][now_position.X + 1] == now_position.Y * split_width + now_position.X + 1)
								if (arr[now_position.Y + 1][now_position.X] == (now_position.Y + 1) * split_width + now_position.X + 1)
								{
									RESULT = MoveDirection::LEFT;
									break;
								}
						RESULT = Solve_Make_Setup_Position2(now_position, index);
						break;
					}

					if (now_position.Y == split_height - 1)
					{
						if (flag[now_position.Y][now_position.X] == 2 && flag[now_position.Y - 1][now_position.X] == 2)
							if (blank.X == now_position.X && blank.Y == now_position.Y)
							{
								RESULT = MoveDirection::DOWN;
								break;
							}
							else
							{
								RESULT = Solve_Make_blank_Setup_Position2();
								break;
							}
						RESULT = Solve_Make_Setup_Position2(now_position, index);
						break;
					}
				}
			}

			return RESULT;
		}
	};
}