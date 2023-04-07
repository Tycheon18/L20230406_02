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

	States.push_back(new FState(1, "배회"));
	States.push_back(new FState(2, "추격"));
	States.push_back(new FState(3, "공격"));
	States.push_back(new FState(4, "죽음"));
	States.push_back(new FState(5, "필살기"));

	for (int i = 0; i < States.size(); i++)
	{
		cout << States[i]->Name << endl;
	}

	for (auto iter : States) // For Each Loop
	{
		cout << iter->Name << endl;
	}
	
	list<FTransition*> Transitions;

	Transitions.push_back(new FTransition(1,"적발견",2));
	Transitions.push_back(new FTransition(2, "적놓침", 1));
	Transitions.push_back(new FTransition(2, "사정거리접근", 3));
	Transitions.push_back(new FTransition(3, "사정거리이탈", 2));
	Transitions.push_back(new FTransition(3,"HP없음",4));

	//범위 기반 for문
	for (auto iter = Transitions.begin(); iter != Transitions.end(); ++iter)
	{
		cout << (*iter)->Condition << endl;
	}

	for (auto iter : Transitions)
	{
		cout << iter->Condition << endl;
	}

	map<int, FTransition*> TransitionsMap;

	TransitionsMap[1] = new FTransition(1, "적발견", 2);
	TransitionsMap[2] = new FTransition(2, "적놓침", 1);
	TransitionsMap[3] = new FTransition(2, "사정거리접근", 3);
	TransitionsMap[4] = new FTransition(3, "사정거리이탈", 2);
	TransitionsMap[5] = new FTransition(3, "HP없음", 4);

	for (auto iter : TransitionsMap)
	{
		cout << iter.first << endl;
		cout << iter.second->Condition << endl;
	}

	//int MonsterCurrentState = 2;
	//std::string MonsterCondition = "적놓침";
	//int MonsterNextState;

	//for (int i = 0; i < 5; i++)
	//{
	//	if (Transition[i]->CurrentState == MonsterCurrentState &&
	//		Transition[i]->Condition == MonsterCondition)
	//	{
	//		MonsterNextState = Transition[i]->NextState;
	//	}
	//}

	//cout << "현재 몬스터의 상태는 " << State[MonsterCurrentState - 1]->Name;
	//cout << "이고 조건은 " << MonsterCondition << " 을 해서 ";
	//cout << "몬스터가 다음에는 " << State[MonsterNextState - 1]->Name;
	//cout << "행동을 합니다." << endl;

	return 0;
}