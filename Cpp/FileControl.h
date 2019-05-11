#pragma once
#include "IExecutable.h"

class FileControl : public IExecutable {

public:
	// IExecutable を介して継承されました
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;
};