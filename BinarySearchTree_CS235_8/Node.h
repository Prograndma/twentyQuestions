#ifndef NODE_H
#define NODE_H

#include <sstream>

using namespace std;

template<typename T>

class Node
{

public:
	Node(const T& data)				// the all public struct class node. Has a left and right pointer and some data. 
	{
		m_Data = data;
		m_Left = nullptr;
		m_Right = nullptr;
	}

	void giveNode(const T& newItem, const T& question, Node<T>*& oldNode)
	{
		Node<T>* temp = oldNode;
		oldNode = new Node<T>(question);
		oldNode->m_Left = new Node<T>(newItem);
		oldNode->m_Right = temp;
	}


	T m_Data;
	Node* m_Left;
	Node* m_Right;



};
#endif