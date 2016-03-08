// Class ReportModule Declaration
#pragma once
#include "stdafx.h"
#include<time.h>
#include <string>

#include "Module.h"

using namespace std;

#ifndef REPORT_MODULE_H
#define REPORT_MODULE_H

class ReportModule : public Module {

private:
	static ReportModule * reportModule;
	ReportModule();

public:
	static ReportModule * getInstance();

	void display();
};

#endif // REPORT_MODULE_H
