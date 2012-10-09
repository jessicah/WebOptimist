
#include "OptimistApp.h"

#include "OptimistWindow.h"
#include <WebPage.h>
#include <WebView.h>
#include <WebViewConstants.h>
#include <Alert.h>

const char* kApplicationSignature = "application/x-vnd.jessicah-WebOptimist";

OptimistApp::OptimistApp()
	: BApplication(kApplicationSignature)
{
		
	//(new OptimistWindow(BRect(10,10,500,700)))->Show();
}

OptimistApp::~OptimistApp()
{
}

void
OptimistApp::AboutRequested()
{
	BAlert* alert = new BAlert("About WebOptimist",
		"Experimenting with integrating Stack and Tile experience...",
		"No way!");
	alert->Go();
}

void
OptimistApp::ReadyToRun()
{
	BWebPage::InitializeOnce();
		BWebPage::SetCacheModel(B_WEBKIT_CACHE_MODEL_WEB_BROWSER);
		
		(new OptimistWindow(BRect(50,50,800,1200)))->Show();
	
}

int main(int, char**)
{
	new OptimistApp();
	be_app->Run();
	delete be_app;
	
	return 0;
}
