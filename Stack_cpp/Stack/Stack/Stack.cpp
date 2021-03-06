// Stack.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
class stack {
	private:
		struct node {
			int value;
			node *prev;
		};
		node *head = nullptr;
		unsigned int stackSize = 0;
	public:
		void push(int elem) {
			head = new node{ elem, head };
			++stackSize;
		}
		int pop() {
			if (stackSize != 0) {
				node *newhead = (*head).prev;
				int poppedElement = (*head).value;
				delete(head);
				head = newhead;
				--stackSize;
				return poppedElement;
			}
		}
		bool empty() const { return stackSize == 0; }
		~stack();
};
stack::~stack() {
	cout << "Deleting stack .. " << endl;
	while (stackSize != 0) {
		cout << "deleted element is: " << pop() << endl;
	}
}
int main()
{
	stack myStack;
	int status = 1, c, elem;
	while (status) {
		cout << "Enter what you want to do with the stack: " << endl
			<< "1) pop element from stack" << endl
			<< "2) push element into stack" << endl;
		cin >> c;
		switch (c) {
			case 1:
				if (myStack.empty())
					cout << "Cannot pop from empty Stack" << endl;
				else {
					cout << "Popped element is: " << myStack.pop() << endl;
				}					
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
		if (c == 0) { break; }
	}
    return 0;
}