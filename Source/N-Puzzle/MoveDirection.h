#pragma once
namespace NPuzzle
{
	public enum MoveDirection
	{
		EMPTY, UP, LEFT, DOWN, RIGHT
	};

	class MoveDirectionNode
	{
	public:
		MoveDirectionNode(MoveDirection Move, MoveDirectionNode* next, MoveDirectionNode* previous)
		{
			this->_turn = 0;
			this->_Move = Move;
			this->_next = next;
			this->_previous = previous;
		}
		~MoveDirectionNode() {}

	public:
		void setTurn(int Turn)
		{
			this->_turn = Turn;
		}
		void setMove(MoveDirection Move)
		{
			this->_Move = Move;
		}
		void setNext(MoveDirectionNode* Next)
		{
			this->_next = Next;
		}
		void setPrevious(MoveDirectionNode* Previous)
		{
			this->_previous = Previous;
		}
		int getTurn()
		{
			return this->_turn;
		}
		MoveDirection getMove()
		{
			return this->_Move;
		}
		MoveDirectionNode* getNext()
		{
			return this->_next;
		}
		MoveDirectionNode* getPrevious()
		{
			return this->_previous;
		}
	private:
		int _turn;
		MoveDirection _Move;
		MoveDirectionNode* _next;
		MoveDirectionNode* _previous;
	};

	public class MoveDirectionList
	{
	public:
		MoveDirectionList()
		{
			MoveDirectionNode* first = new MoveDirectionNode(EMPTY, nullptr, nullptr);
			this->_head = first;
			this->_now = first;
			this->_tail = first;
		}

		~MoveDirectionList()
		{
			// xoá tất cả các node có trong list
			this->deleteMove(this->_head, this->_tail);
		}


	public:
		void setHead(MoveDirectionNode* Head)
		{
			this->_head = Head;
		}
		MoveDirectionNode* getHead()
		{
			return this->_head;
		}

		void setNow(MoveDirectionNode* Now)
		{
			this->_now = Now;
		}
		MoveDirectionNode* getNow()
		{
			return this->_now;
		}

		void setTail(MoveDirectionNode* Tail)
		{
			this->_tail = Tail;
		}
		MoveDirectionNode* getTail()
		{
			return this->_tail;
		}

		void deleteMove(MoveDirectionNode* startnode, MoveDirectionNode* endnode)
		{
			MoveDirectionNode* tmp;
			while (startnode->getTurn() != endnode->getTurn())
			{
				tmp = startnode->getNext();
				delete startnode;
				startnode = tmp;
			}
			delete startnode;
		}

		void addMove(MoveDirection _moveDirection)
		{
			if (_now != _tail)
			{
				deleteMove(_now->getNext(), _tail);
			}

			MoveDirectionNode* tmp = new MoveDirectionNode(_moveDirection, nullptr, _now);
			_now->setNext(tmp);
			tmp->setTurn(_now->getTurn() + 1);
			_tail = tmp;
			_now = tmp;
		}

		MoveDirection Undo()
		{
			if (_now == _head)
				return EMPTY;

			_now = _now->getPrevious();
			return _now->getNext()->getMove();
		}

		MoveDirection Redo()
		{
			if (_now == _tail)
				return EMPTY;

			_now = _now->getNext();
			return _now->getMove();
		}

	private:
		MoveDirectionNode* _head;
		MoveDirectionNode* _now;
		MoveDirectionNode* _tail;
	};
}
