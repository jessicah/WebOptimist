
#ifndef OPTIMIST_APP_H
#define OPTIMIST_APP_H

#include <Application.h>

//class OptimistWindow;

class OptimistApp : public BApplication {
public:
	OptimistApp();
	virtual ~OptimistApp();
	
	virtual void AboutRequested();
	virtual void ReadyToRun();
private:
};

extern const char* kApplicationSignature;

#endif // OPTIMIST_APP_H
