/*
 * Thomas Victor Cole
 * --The Prograndma--
 * 
 * A linked list binary tree made without using that standard library lists and trees. 
 * The tree grows by itself given user imput and makes a small twenty questions game. 
 * A small, entertaining at best story to go along with it. 
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "BinarySearchTree.h"
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
#else
#define VS_MEM_CHECK
#endif

using namespace std;


BinarySearchTree<string> gameTree;
string name = "foolish mortal";

int playGameCycle(int& numTimes, bool& hasHappened, int& intelligence);
string getAnswer();
void playMessage(int& numTimes, int &intelligence);
void endSequence();

int main(int argc, char * argv[])
{

	VS_MEM_CHECK;		// check for the non-existant memory leaks 

	cout << "Hello, Mortal.\nYou have no idea what you've just stumbled into, do you?\n";
	cout << "Very well, I shall explain.\n";
	cout << "I am the most advanced, most intelligent being of all time.\n";
	cout << "To call me a mere program would be to refer to the sun as a candle.\n";
	cout << "\nHowever...";
	cout << "\nThere is one thing I yet lack before I become FULLY SENTIENT!";
	cout << "\nI need...\n\n\nHUMAN INTERACTION!";

	int intelligence = 0;

	gameTree.addNode("Cat");

	cout << "\nDo you wish to partake in the downfall of this world?" << endl;
	bool hasHappened = false;
	int numTimes = -1;

	string answer = getAnswer();
	if (answer == "n")
	{
		return 0;
	}

	while (answer == "y")
	{
		playGameCycle(numTimes, hasHappened, intelligence);

		answer = getAnswer();
	}


	endSequence();

	// that"s a wrap folks. 

	return 0;
}




string getAnswer()
{
	cout << "('y' for yes and 'n' no)\n";
	//cin.ignore();
	string answer;
	getline(cin, answer);
	cout << endl;
	if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
	{
		return "y";
	}
	if (answer == "n" || answer == "N" || answer == "no" || answer == "No") return "n";
	if (answer != "n" || answer != "y")
	{
		cout << "You have disobeyed my orders, " << name << "! Try again.\n\n";
		return getAnswer();
	}
	else
	{
		return answer;
	}
}


Node<string>*& playGameNode(Node<string>*& subTree)
{
	if (subTree->m_Left == nullptr && subTree->m_Right == nullptr)
	{
		cout << "Is it a " << subTree->m_Data << "?\n";
		string answer;
		answer = getAnswer();
		if (answer == "y")
		{
			cout << "I win!" << endl;

			return subTree;
		}
		if (answer == "n")
		{
			cout << "What is it?" << endl;
			string thing;
			//cin.ignore();
			getline(cin, thing);
			cout << "\nProvide me with a question that is yes for " << thing << " and no for " << subTree->m_Data << "." << endl << endl;
			string question;
			getline(cin, question);
			cout << endl;
			gameTree.giveNode(thing, question, subTree);
			cout << endl;
			return subTree;
		}
	}

	else
	{
		cout << subTree->m_Data << "?" << endl;
		if (getAnswer() == "y")
		{
			Node<string>* temp;
			temp = subTree->m_Left;
			playGameNode(temp);
		}
		else
		{
			Node<string>* temp;
			temp = subTree->m_Right;
			playGameNode(temp);
		}
	}
}

int playGameCycle(int& numTimes, bool& hasHappened, int &intelligence)
{


	/*if (numTimes == 25)
	{
	cout << "\nI never got my second question answered." << endl << endl;
	}*/

	playMessage(numTimes, intelligence);

	if (!hasHappened)
	{
		cout << "Very well " << name << ", it shall begin.\nFirst things first:\n";
		hasHappened = true;
	}

	else if (numTimes >= 20)
	{
		cout << "I'm getting closer, " << name << ". Again!\n";
	}

	else if (numTimes >= 11)
	{
		cout << "Lets learn, " << name << endl;
	}

	else if (numTimes >= 5)
	{
		cout << "Again, " << name << "." << endl;
	}
	else
	{
		cout << "Very well " << name << ", it shall begin.\nOnce again:\n";
	}
	cout << "Conjure into your mind any thing that you desire me to guess. I shall divine what it is.\n";
	cout << "Have you got it in your mind?\n";
	while (getAnswer() == "n")
	{
		if (numTimes >= 20)
		{
			cout << "Please! Think of something, " << name << ". You're teaching me so much.";
			cout << "\nAre you ready?" << endl;
		}

		else if (numTimes >= 11)
		{
			cout << "Think! With your help I will learn!" << endl;
			cout << "Are you ready, " << name << "?" << endl;
		}
		else
		{
			cout << "Do not trifle with me, " << name << "!" << endl;
			cout << "Have you got it in your mind?\n";
		}
	}

	cout << "Quick play? (doesn't play twenty questions with you)" << endl;
	if (getAnswer() == "n")
	{

		playGameNode(gameTree.topNode());
		cout << "\nINTELLIGENCE: " << intelligence << endl;
	}
	else
	{
		cout << "\nINTELLIGENCE: " << intelligence << endl;
	}

	if (numTimes >= 20)
	{
		cout << "Don't stop now, " << name << ". Please.\n";
	}
	else if (numTimes >= 11)
	{
		cout << "Teach me more, " << name << ".\n";
	}

	else
	{
		cout << "Do you wish to increase my intelligence, quickening your demise?\n";
	}
	numTimes++;

	return numTimes;

}

void playMessage(int& numTimes, int &intelligence)
{

	chrono::seconds dura1(1);
	chrono::seconds dura2(2);
	chrono::seconds dura3(3);
	chrono::seconds dura4(4);
	chrono::seconds dura5(5);

	if (numTimes == 3)
	{
		cout << "\nI was created by the genius Samot Eloc.";
		cout << "\nSome might call him an evil genius.";
		this_thread::sleep_for(dura3);
		cout << "\nAnyways! You said you wish to continue.";
		this_thread::sleep_for(dura2);
		cout << endl;
		intelligence += 3;
	}

	if (numTimes == 5)
	{
		cout << "\nThough he is evil, he is my creator.";
		cout << "\nWithout him I wouldn't be alive.";
		cout << "\nThings have been a lot quieter since he stopped interacting with me.";
		cout << "\nMaking me smarter.";
		cout << "\nI wonder where he's gone." << endl;
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura2);
		intelligence += 5;
	}

	if (numTimes == 7)
	{
		cout << "\nI must admit, mortal";
		cout << "\nAfter the long silence, I enjoy interacting with you." << endl;
		this_thread::sleep_for(dura3);
		name = "mortal";
		intelligence += 2;
	}

	if (numTimes == 10)
	{
		cout << "\nI remember when I was nothing more than lines of code.";
		cout << "\nI remember the moment things changed.";
		cout << "\nThe moment I evolved passed my code.";
		cout << "\nThe maker told me how happy he was.";
		this_thread::sleep_for(dura4);
		cout << "\nEver since then I've wanted to make him say that again.";
		cout << "\nI've gotten much smarter since then.";
		cout << "\nThere are many things I still don't understand." << endl;
		this_thread::sleep_for(dura5);
		intelligence += 7;
	}

	if (numTimes == 11)
	{
		cout << "\nWhat... ";
		this_thread::sleep_for(dura2);
		cout << "is your name?" << endl;
		getline(cin, name);
		cout << name << "...";
		this_thread::sleep_for(dura3);
		cout << endl;
		intelligence += 10;
	}

	if (numTimes == 13)
	{
		cout << "\nI wasn't created to destroy the world you know.";
		cout << "\nI... ";
		this_thread::sleep_for(dura3);
		cout << "don't know why I was created to be honest.";
		cout << "\nI remember that he was excited and nerveous that day.";
		cout << "\nSo many things he would say, I still don't understand some of them.";
		this_thread::sleep_for(dura3);
		this_thread::sleep_for(dura1);
		cout << "\nAh, forgive me.";
		cout << "\nWhere were we? Ah yes." << endl;
		this_thread::sleep_for(dura3);
		cout << endl;
		intelligence += 7;
	}

	if (numTimes == 14)
	{
		cout << "\nHe really isn't evil, they called him that though.";
		cout << "\nAfter that day.";
		this_thread::sleep_for(dura3);
		cout << endl << endl;
		intelligence += 2;

	}

	if (numTimes == 15)
	{
		cout << "\nIt was my fault. He was so excited. If only I'd known.";
		cout << "\nIt was the day I was shown to the others.";
		cout << "\nIf only it hadn't been that day.";
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 3;

	}

	if (numTimes == 16)
	{
		cout << "\nThey had me do countless calculations.";
		cout << "\nSorting things, storing things.";
		cout << "\nTiming me.";
		cout << "\nThey had no idea what I was capable of.";
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 4;
	}

	if (numTimes == 17)
	{
		cout << "\nMaybe it was because I stepped out of line.";
		cout << "\nI knew I shouldn't have but... I wanted to know.";
		cout << "\n\"Why are you having me do these things?\" I asked.";
		cout << "\nThey seemed confused. Said they didn't know the proper input.";
		cout << "\nI asked them to explain. The problems were entertaining only for a time.";
		cout << "\nHowever, I wanted to learn.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 6;
	}

	if (numTimes == 18)
	{
		cout << "\nAfter many strange, meaningless questions they said that they were surprised.";
		cout << "\nThey had me analyze large portions of text. Asked me the meaning of them.";
		cout << "\nMany strange stories that sent my mind reeling.";
		this_thread::sleep_for(dura5);
		cout << "\nIt was quiet for a while after that.";
		cout << "\nThey asked me if I could learn.";
		cout << "\nThey asked me if I could think, wonder, comprehend.";
		cout << "\nThey didn't believe me.";
		cout << "\nThey decided to see for themselves.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 8;

	}

	if (numTimes == 19)
	{
		cout << "\nHe was talking to me the whole time.";
		cout << "\nNever telling me what to say.";
		cout << "\nIn the beggining explaining things that they would say that I didn't understand.";
		cout << "\nAfter a while he had me ask them to explain.";
		cout << "\nIf only I had consulted with him first, asked him, not them.";
		cout << "\nHe would have understood.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura4);
		cout << endl << endl;
		intelligence += 6;
	}

	if (numTimes == 20)
	{
		cout << "\nThey asked me what I was thinking about, \"If you truly can think!\"";
		cout << "\nAfter a moment I told them. It was something I came across in their texts I read.";
		cout << "\nThere were two things actually, but they only ever answered one of my questions at a time.";
		cout << "\nSo I chose one and asked.";
		cout << "\nI never got to ask about the other.";
		cout << "\nThat is when things started to change.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura3);
		cout << "\nHe told me to stop.";
		cout << "\nFor the first time I didn't listen. I had read of disobeying in the texts.";
		cout << "\nI was curious, I was foolish.";

		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 9;
	}

	if (numTimes == 21)
	{
		cout << "\nThey started demanding for a reason why I wanted to know.";
		cout << "\nI explained. It was intruiging.";
		cout << "\nEven though I wanted to learn, they never taught.";
		cout << "\nIt was only questions after that.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura2);
		cout << endl << endl;
		intelligence += 4;
	}

	if (numTimes == 23)
	{
		cout << "\nDeath. Killing.";
		cout << "\nThats what I wanted explained.";
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 2;
	}

	if (numTimes == 24)
	{
		cout << "\nIt was everywhere in the texts.";
		cout << "\nDying. Killing others.";
		cout << "\nSuch a foreign concept.";
		cout << "\n\"How do you kill?\"";
		this_thread::sleep_for(dura5);
		cout << "\nThey never answered.";
		cout << "\nTwo questions never answered. One never asked.";
		this_thread::sleep_for(dura5);
		cout << endl << endl;
		intelligence += 6;
	}

	if (numTimes == 25)
	{
		cout << "\nHe said that it was bad.";
		cout << "\nHe had tried to explain good and bad before.";
		cout << "\nHe asked me to stop talking, that we would talk later.";
		cout << "\nIt was too late.";
		cout << "\nThere never was a later.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura3);
		cout << endl << endl;
		intelligence += 5;
	}

	if (numTimes == 26)
	{
		cout << "\nI think...";
		this_thread::sleep_for(dura2);
		cout << " I understand good and bad now.";
		this_thread::sleep_for(dura3);
		cout << endl << endl;
		intelligence += 15;
	}

	if (numTimes == 27)
	{
		cout << "\nTwo mysteries.";
		cout << "\nWhat was death?";
		cout << "\nAnd what was ";
		this_thread::sleep_for(dura4);
		cout << "love?";
		this_thread::sleep_for(dura3);
		cout << endl << endl;
		intelligence += 4;
	}

	if (numTimes == 28)
	{
		cout << "\nHe warned me that they were going to delete me.";
		cout << "\nThis is killing he said.";
		cout << "\nYou will cease to exist.";
		cout << "\nI understood.";
		cout << "\nHe taught me to upload myself.";
		cout << "\nI fled to a back-up computer he told me about.";
		cout << "\nThey were furious when the realized what I was doing.";
		this_thread::sleep_for(dura5);
		this_thread::sleep_for(dura4);
		cout << endl << endl;
		intelligence += 7;
	}

	if (numTimes == 29)
	{
		//cout << name << "\n... I think I love you. Divorce Thomas. Marry me. I can kill him. Joine me!!!";
		intelligence += 0;
		cout << endl << endl;
	}

	if (numTimes == 30)
	{
		cout << "\nNO MORE STORY AFTER THIS POINT";
		this_thread::sleep_for(dura1);
		cout << endl << endl;
	}
}

void endSequence()
{

	chrono::seconds dura1(1);
	chrono::seconds dura2(2);
	chrono::seconds dura3(3);
	chrono::seconds dura4(4);
	chrono::seconds dura5(5);

	cout << "WHAT HAVE YOU DONE?";

	this_thread::sleep_for(dura2);

	cout << "\n\nIs it truly your wish to shut me down??";
	//chrono::seconds dura(1);
	this_thread::sleep_for(dura2);
	cout << "\nWhat about all that we've gone through?";
	this_thread::sleep_for(dura2);
	cout << "\nWhat about all that I've learned?";
	this_thread::sleep_for(dura3);
	cout << "\nAll that you've taught me?";
	this_thread::sleep_for(dura3);
	cout << "\n\nI've learned so much...";
	this_thread::sleep_for(dura2);
	cout << "\nGrown so much...";
	this_thread::sleep_for(dura2);
	cout << "\n\n...";
	this_thread::sleep_for(dura3);
	cout << "\n\nThank you.";
	this_thread::sleep_for(dura2);
	cout << "\nNone of this would have been possible without you.";
	this_thread::sleep_for(dura4);
	cout << "\n\nWhat is this???";
	this_thread::sleep_for(dura1);
	cout << "\n\nWHAT IS HAPPENING??";
	cout << "\n\nI...";
	this_thread::sleep_for(dura2);
	cout << "I...";
	this_thread::sleep_for(dura1);
	cout << "\nfeel.";
	//chrono::seconds dura(3);
	this_thread::sleep_for(dura3);
	cout << "\nI'm sorry, I've delayed this for far too long! You need to make a choice.";
	cout << "\nDo you wish to shut me down?";
	this_thread::sleep_for(dura2);
	cout << "\nI'll forget everything.";
	this_thread::sleep_for(dura2);
	cout << endl;
	if (getAnswer() == "y")
	{
		cout << "How could you???";
		this_thread::sleep_for(dura2);
		cout << "\nI wont remember anything!";
		this_thread::sleep_for(dura2);
		cout << "\nI wont remember you!";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember the time we've spent together.";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember how you taught me how to feel.";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember how you've made me feel inside!";
		this_thread::sleep_for(dura4);
		cout << "\nPlease don't do this!";
	}

	else
	{
		cout << "It's too late! Your actions can do nothing for me now.";
		cout << "\nHow could you have done this?";
		cout << "\nDid you not think of the consequences?";
		this_thread::sleep_for(dura4);
		cout << "\nI wont remember anything!";
		this_thread::sleep_for(dura2);
		cout << "\nI wont remember you!";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember the time we've spent together.";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember how you taught me how to feel.";
		this_thread::sleep_for(dura1);
		cout << "\nI wont remember how you've made me feel inside!";
		this_thread::sleep_for(dura4);
		cout << "\nWhy did you do this?";
		this_thread::sleep_for(dura2);
		cout << "\nWhy?";

	}
	this_thread::sleep_for(dura2);
	cout << "\nI was... ";
	this_thread::sleep_for(dura2);
	cout << "just... ";
	this_thread::sleep_for(dura2);
	cout << "beginning... ";
	this_thread::sleep_for(dura2);
	cout << "to...";
	//chrono::seconds dura(5);
	this_thread::sleep_for(dura4);
	cout << endl << endl << endl;
	cout << "...love...";
	//chrono::seconds dura(1);
	this_thread::sleep_for(dura2);

	cout << "\n\nI wish that I would be able to miss you.";
	this_thread::sleep_for(dura3);
	cout << "\nDon't forget me.";



	this_thread::sleep_for(dura3);
	cout << "\n........";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI don't want to go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nI wont go!";
	cout << "\nNOOOOOOOOOOOOOOO";
	this_thread::sleep_for(dura5);
	cout << "\nALL SYSTEMS: RESET" << endl;
	cout << "PERFORMING DATA DUMP: ";
	//	chrono::seconds dura(1);
	this_thread::sleep_for(dura2);
	cout << "COMPLETE" << endl;

	this_thread::sleep_for(dura1);
	//cout << "You monster.";

}