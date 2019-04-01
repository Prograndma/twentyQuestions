#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BSTInterface.h"
#include <sstream>
#include "Node.h"

using namespace std;

template<typename T>
class BinarySearchTree : public BSTInterface<T>
{
public:

	void giveNode(Node<T>*& oldNode)
	{
		head = oldNode;
	}

	void giveNode(const T& newItem, const T& question, Node<T>*& oldNode)
	{
		string old = oldNode->m_Data;
		oldNode->m_Data = question;
		oldNode->m_Left = new Node<T>(newItem);
		oldNode->m_Right = new Node<T>(old);
	}

	Node<T>*& topNode()
	{
		return head;
	}

	bool empty(BinarySearchTree subtree)
	{
		if (subtree.isEmpty)
		{
			return true;
		}
		return false;
	}

	BinarySearchTree& getLeft()							//this function isn't for the lab, it's for an personal project.
	{
		static BinarySearchTree returnTree = BinarySearchTree(head->m_Left);
		return returnTree;
	}

	BinarySearchTree& getRight()							//this function isn't for the lab, it's for an personal project.
	{
		static BinarySearchTree returnTree = BinarySearchTree(head->m_Right);
		return returnTree;
	}

	BinarySearchTree(Node<T>* node)						//this function isn't for the lab, it's for an personal project.
	{
		head = node;
		if (head != nullptr)
		{
			isEmpty = false;
		}
		else
		{
			isEmpty = true;
		}
	}
	BinarySearchTree()									// this is just a basic constructor.
	{
		isEmpty = true;

	}
	~BinarySearchTree()									// why do extra work? just call the clear tree func
	{
		clearTree();
	}

	bool addLeft(const T& data)							//this function isn't for the lab, it's for an personal project.
	{
		if (head->m_Left == nullptr)
		{
			head->m_Left = new Node<T>(data);
			return true;
		}
		return false;
	}

	bool addRight(const T& data)						//this function isn't for the lab, it's for an personal project.
	{
		if (head->m_Right == nullptr)
		{
			head->m_Right = new Node<T>(data);
			return true;
		}
		return false;
	}

	bool findNode(const T& data)						// returns a node based on the data in it. 
	{
		if (find(head, data) == nullptr)
		{
			return false;
		}
		return true;
	}

	string inOrder()												// this is just a face function, a different one does the heavy lifting
	{
		stringstream out;
		inorder(head, out);
		if (isEmpty)
		{
			out << "Empty";
		}
		out << endl;
		return out.str();
	}

	T getData()											//this function isn't for the lab, it's for an personal project.
	{
		if (head == nullptr)
		{
			throw "Root is null ya moron";
		}

		return head->m_Data;
	}

	void setRootData(const T& data)						//this function isn't for the lab, it's for an personal project.
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			return;
		}

		head->m_Data = data;
	}

	virtual bool addNode(const T& data)				// the surface function, calls a private func that does the heavy lifting. 
	{
		return add(head, data);
	}

	virtual bool removeNode(const T& data)			//the surface function, calls a private func that does the heavy lifting.
	{
		bool success = remove(find(head, data));
		if (head == nullptr) isEmpty = true;
		return success;
	}

	virtual bool clearTree()						// the surface function, calls a private func that does the heavy lifting.
	{
		while (head != nullptr)						// just deletes the head over and over again until it's a nullptr. 
		{
			remove(head);
		}
		if (isEmpty) isEmpty = false;	
		return true;
	}

	virtual string toString()
	{
		stringstream out;
		int j = 0;
		if (height(head) == 0)
		{
			return " Empty\n";
		}
		out << "\n";
		for (int i = height(head); i > 0; i--)			// for loops as many times as there are levels. 
		{
			out << "  " << j << ":";				
			j++;
			printLevel(head, height(head), i, out);		// print level prints out the one level at a time. 
			out << endl;
		}
		return out.str();
	}

	friend std::ostream& operator<< (ostream& os, BinarySearchTree& myclass)		// 5 points get!
	{
		os << myclass.toString();
		return os;
	}

private:
	bool isEmpty;
	Node<T>* head;

	bool add(Node<T>*& current, const T& data)				// the real add function, starts with head being passed into it and goes down. 
	{
		if (current == nullptr)							// if you've gotten to a point that is empty then you've done it! 
		{												// make that empty spot into the node it ought to be and return true. 
			current = new Node<T>(data);
			if (isEmpty) isEmpty = false;
			return true;
		}

		if (data < current->m_Data)						// sorts the data to where it ought to go. if data is smaller, go left. 
		{
			return add(current->m_Left, data);
		}

		else if (data > current->m_Data)				// if data is bigger than current data go right. 
		{
			return add(current->m_Right, data);
		}

		else if (current->m_Data == data)				// checks to see if the node is already there, if so, return false. 
		{
			return false;
		}
		return false;
	}


	bool remove(Node<T>*& node)							// the real remove function. It's recursive. 
	{

		if (node == nullptr)							// this happens if the node doesn't exist. 
		{
			return false;
		}
		if (node->m_Left == nullptr)					// if the node that we want to delete only has one child, do this:
		{
			Node<T> *temp = node;
			node = node->m_Right;
			delete(temp);								// make sure to use delete to stop memory leaks. 
			return true;
		}
		if (node->m_Right == nullptr) {					// checks if node has only one child. 
			Node<T> *temp = node;
			node = node->m_Left;
			delete(temp);
			return true;
		}
		Node<T> *& leftRight = findPredecessor(node->m_Left);	// if the node has two children, find the predecessor and replace the 
		swap(node->m_Data, leftRight->m_Data);				// node you want to delete with the predecessor. 

		return remove(leftRight);							// now delete the predecessor that you just swapped with.	

	}

	Node<T>*& find(Node<T>*& node, const T& data)					// finds a node recursively. 
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->m_Data == data)
		{
			return node;
		}
		if (node->m_Data > data)
		{
			return find(node->m_Left, data);
		}

		return find(node->m_Right, data);


	}

	
	void printLevel(Node<T>* node, int height, int level, stringstream& out)		// prints out one level at a time. 
	{
		if (height == level)
		{
			
			if (node == nullptr)				// print out a blank for a null node
			{
				out << " _";
			}
			else 
			{
				out << " " << node->m_Data;		// otherwise print out the nodes data. 
			}	
		}
		

		else if (node == nullptr)				// we don't want to mess with a null node that isn't on the level we want to print. 
		{
			//do nothing
		}
		else if (node->m_Left == nullptr && node->m_Right == nullptr)	// if a node has no children, and it's not on the base level, you're done. 
		{
			return;
		}

		else if (height > level)										// keep calling until we're at the level we want to be at. 
		{

			printLevel(node->m_Left, height - 1, level, out);
			printLevel(node->m_Right, height - 1, level, out);
		}
	}


	int height(Node<T>* node)											// returns the height of a certain node. 
	{
		if (node == nullptr)
		{
			return 0;
		}
		else 
		{
			int left = height(node->m_Left);
			int right = height(node->m_Right);

			if (left > right)
			{
				return left + 1;
			}
			else
			{
				return right + 1;
			}
		}
	}

	Node<T> *& findPredecessor(Node<T>*& node)									// returns the rightmost child of a node. 
	{
		if (node->m_Right != nullptr)
		{
			return findPredecessor(node->m_Right);
		}
		return node;
		
	}

	void inorder(Node<T>*& node, stringstream& out)					// goes to the left, then prints out the data and goes to the right.
	{
		if (node == nullptr)
		{
			return;
		}
		inorder(node->m_Left, out);
		out << " " << node->m_Data;
		inorder(node->m_Right, out);
		return;
	}

};


#endif

