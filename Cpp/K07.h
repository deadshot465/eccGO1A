#pragma once
#include "IExecutable.h"
class K07 :
	public IExecutable
{
public:
	K07();
	~K07();

	// IExecutable ����Čp������܂���
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;
};

