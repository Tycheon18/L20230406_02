#include "Transition.h"

FTransition::FTransition(int NewCurrentState, string NewCondition, int NewNextState)
{
	CurrentState = NewCurrentState;
	Condition = NewCondition;
	NextState = NewNextState;
}
