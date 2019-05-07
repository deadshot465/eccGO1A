#pragma once
#include "IDispatchable.h"

class IExecutable :
	public IDispatchable
{
public:
	IExecutable();
	~IExecutable();

	virtual void execute(int num);


	// IDispatchable ����Čp������܂���
	virtual void question1() override = 0;
	virtual void question2() override = 0;
	virtual void question3() override = 0;
	virtual void question4() override = 0;

};