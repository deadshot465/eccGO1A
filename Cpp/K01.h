#pragma once
#include "IExecutable.h"

class K01 :
	public IExecutable
{
public:
	K01();
	~K01();

	// IExecutable ����Čp������܂���
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;

};

