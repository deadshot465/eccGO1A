#pragma once
#include "IExecutable.h"

class FileControl : public IExecutable {

public:
	// IExecutable ����Čp������܂���
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;
};