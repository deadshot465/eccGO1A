#pragma once
#include "IDispatchable.h"

class IExecutable :
	public IDispatchable
{
public:
	IExecutable();
	~IExecutable();

	virtual void execute(int num);

	// IDispatchable を介して継承されました
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;
};