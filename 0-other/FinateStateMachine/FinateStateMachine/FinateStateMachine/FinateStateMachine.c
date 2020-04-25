/*
@Author :Simon Lien
@Date:2020.04.25
@File: FinateStateMachine.c
@GitHub Address:https://github.com/SimonLien/CodeStudyForDataStructure
*/

#include "stdio.h"
#include "windows.h"
typedef  unsigned int uint;

uint g_max_size;	//total state number

enum Zodiac
{
	Rat=1,
	Ox,
	Tiger,
	Hare,
	Dragon,
	Snake,
	Horse,
	Sheep,
	Monkey,
	Rooster,
	Dog,
	Pig
};

enum Event
{
	EVENT1=1,
	EVENT2,
	EVENT3,
	EVENT4,
	EVENT5,
	EVENT6,
	EVENT7,
	EVENT8,
	EVENT9,
	EVENT10,
	EVENT11,
	EVENT12,
};


typedef struct FSMTable_s	//state table
{
	uint event;		//event
	uint CurState;	//current state
	void (*eventActFunc)();	//a pointer to point to the function.
	uint NextState;
}FSMTable_t;

typedef struct FSM_s	//point to state table
{
	FSMTable_t *FsmTable;
	uint CurState;
}FSM_t;


void RatAct()
{
	//do something action.
	printf("i am Rat\n");
}
void OxAct()
{
	//do something action.
	printf("i am Ox\n");
}
void TigerAct()
{
	//do something action.
	printf("i am Tiger\n");
}
void HareAct()
{
	//do something action.
	printf("i am Hare\n");
}

void DragonAct()
{
	//do something action.
	printf("i am Dragon\n");
}
void SnakeAct()
{
	//do something action.
	printf("i am Snake\n");
}

void HorseAct()
{
	//do something action.
	printf("i am Horse\n");
}
void SheepAct()
{
	//do something action.
	printf("i am Sheep\n");
}
void MonkeyAct()
{
	//do something action.
	printf("i am Monkey\n");
}
void RoosterAct()
{
	//do something action.
	printf("i am Rooster\n");
}
void DogAct()
{
	//do something action.
	printf("i am Dog\n");
}
void PigAct()
{
	//do something action.
	printf("i am Pig\n");
}

FSMTable_t Table_State[]=
{
	//	event		CurState	eventActFunc	NextState
	{EVENT1,	Rat,		RatAct,				Ox},
	{EVENT2,	Ox,			OxAct,				Tiger},
	{EVENT3,	Tiger,		TigerAct,				Hare},
	{EVENT4,	Hare,		HareAct,				Dragon},
	{EVENT5,	Dragon,		DragonAct,				Snake},
	{EVENT6,	Snake,		SnakeAct,				Horse},
	{EVENT7,	Horse,		HorseAct,				Sheep},
	{EVENT8,	Sheep,		SheepAct,				Monkey},
	{EVENT9,	Monkey,		MonkeyAct,				Rooster},
	{EVENT10,	Rooster,	RoosterAct,				Dog},
	{EVENT11,	Dog,		DogAct,				Pig},
	{EVENT12,	Pig,		PigAct,				Rat},
};



void FSM_Regiser(FSM_t *pFsm,FSMTable_t *pTable)	//Finate state machine regist 
{
	pFsm->FsmTable=pTable;
}

void FSM_Transfer(FSM_t *pFsm,uint state)		//current state transfer to next state
{
	pFsm->CurState=state;
}

void FSM_Init(FSM_t *pFsm)
{
	g_max_size=sizeof(Table_State)/sizeof(FSMTable_t);
	pFsm->CurState=EVENT1;
	FSM_Regiser(pFsm,Table_State);
}

void Polling_Event(uint *event)
{
	if (*event==12)
	{
		*event=1;
	}
	else
	{
		(*event)++;
	}
}
void EverntActHandle(FSM_t *pFsm,uint event)
{
	FSMTable_t *pActTbale=pFsm->FsmTable;
	void (*eventActFunc)()=NULL;
	uint NextState;
	uint CurState=pFsm->CurState;
	uint flag=0;
	uint i=0;
	for (i=0;i<g_max_size;i++)
	{
		if (event==pActTbale[i].event)
		{
			if (CurState==pActTbale[i].CurState)
			{
				flag=1;
				eventActFunc=pActTbale[i].eventActFunc;
				NextState=pActTbale[i].NextState;
				break;
			}
		}
	}
	if (flag)
	{
		if (eventActFunc)
		{
			eventActFunc();
		}
		FSM_Transfer(pFsm,NextState);
	}
	else
	{
		//do nothing
	}
}

int main()
{
	FSM_t fsm;
	
	uint event =EVENT1;
	FSM_Init(&fsm);
	while (1)
	{
		printf("event %d is coming ...\n",event);
		EverntActHandle(&fsm,event);
		printf("current state is %d\n",fsm.CurState);
		Polling_Event(&event);
		Sleep(2000);
	}
	
	return 0;
}