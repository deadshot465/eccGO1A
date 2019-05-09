#pragma once
#include "IExecutable.h"

class K08 : public IExecutable {
public:
	K08();
	~K08();

	// IExecutable を介して継承されました
	virtual void question1() override;
	virtual void question2() override;
	virtual void question3() override;
	virtual void question4() override;
};