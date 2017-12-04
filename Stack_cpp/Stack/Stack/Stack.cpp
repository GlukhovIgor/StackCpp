// Stack.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
class stack {
	private:
		struct node;
		struct node {
			int value;
			node *prev;
		};
		node *head = nullptr;
		int stackSize = 0;
	public:
		void push(int elem) {
			node *y = new(node);
			(*y).value = elem;
			(*y).prev = head;
			head = y;
			stackSize++;
		}
		int pop() {
			if (stackSize > 0) {
				node *newhead = (*head).prev;
				int poppedElement = (*head).value;
				delete(head);
				head = newhead;
				stackSize--;
				return poppedElement;
			}
			else    return -10;
		}
};
int main()
{
	stack myStack;
	int status = 1, c, elem, poppedElem;
	while (status) {
		cout << "Enter what you want to do with the node: " << endl
			<< "1) pop element from stack" << endl
			<< "2) push element into stack" << endl;
		cin >> c;
		switch (c) {
			case 1:
				poppedElem = myStack.pop();
				if (poppedElem == -10)
					cout << "Cannot pop from empty Stack" << endl;
				else
					cout << "Popped element is: " << poppedElem << endl;
				break;
			case 2:
				cout << "Enter value you want to push into stack: " << endl;
				cin >> elem;
				myStack.push(elem);
				break;
			default:
				cerr << "No such operation is available" << endl;
		}
		cout << "Would you like to continue? Enter 1 for YES, 0 for NO" << endl;
		cin >> c;
	}
    return 0;
}

