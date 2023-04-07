#include <iostream>
#include "State.h"
#include "Transition.h"
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
	vector<FState*> States;

	//FState* State[4];
	//FTransition* Transition[5];

	States.push_back(new FState(1, "��ȸ"));
	States.push_back(new FState(2, "�߰�"));
	States.push_back(new FState(3, "����"));
	States.push_back(new FState(4, "����"));
	States.push_back(new FState(5, "�ʻ��"));

	for (int i = 0; i < States.size(); i++)
	{
		cout << States[i]->Name << endl;
	}

	for (auto iter : States) // For Each Loop
	{
		cout << iter->Name << endl;
	}
	
	list<FTransition*> Transitions;

	Transitions.push_back(new FTransition(1,"���߰�",2));
	Transitions.push_back(new FTransition(2, "����ħ", 1));
	Transitions.push_back(new FTransition(2, "�����Ÿ�����", 3));
	Transitions.push_back(new FTransition(3, "�����Ÿ���Ż", 2));
	Transitions.push_back(new FTransition(3,"HP����",4));

	//���� ��� for��
	for (auto iter = Transitions.begin(); iter != Transitions.end(); ++iter)
	{
		cout << (*iter)->Condition << endl;
	}

	for (auto iter : Transitions)
	{
		cout << iter->Condition << endl;
	}

	map<int, FTransition*> TransitionsMap;

	TransitionsMap[1] = new FTransition(1, "���߰�", 2);
	TransitionsMap[2] = new FTransition(2, "����ħ", 1);
	TransitionsMap[3] = new FTransition(2, "�����Ÿ�����", 3);
	TransitionsMap[4] = new FTransition(3, "�����Ÿ���Ż", 2);
	TransitionsMap[5] = new FTransition(3, "HP����", 4);

	for (auto iter : TransitionsMap)
	{
		cout << iter.first << endl;
		cout << iter.second->Condition << endl;
	}

	//int MonsterCurrentState = 2;
	//std::string MonsterCondition = "����ħ";
	//int MonsterNextState;

	//for (int i = 0; i < 5; i++)
	//{
	//	if (Transition[i]->CurrentState == MonsterCurrentState &&
	//		Transition[i]->Condition == MonsterCondition)
	//	{
	//		MonsterNextState = Transition[i]->NextState;
	//	}
	//}

	//cout << "���� ������ ���´� " << State[MonsterCurrentState - 1]->Name;
	//cout << "�̰� ������ " << MonsterCondition << " �� �ؼ� ";
	//cout << "���Ͱ� �������� " << State[MonsterNextState - 1]->Name;
	//cout << "�ൿ�� �մϴ�." << endl;

	return 0;
}