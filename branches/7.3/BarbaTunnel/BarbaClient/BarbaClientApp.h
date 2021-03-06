#pragma once
#include "BarbaApp.h"
#include "BarbaClientConfig.h"
#include "BarbaClientConnectionManager.h"

class BarbaClientApp : public BarbaApp
{
public:
	BarbaClientApp();
	virtual ~BarbaClientApp();
	virtual void Initialize();
	virtual void Dispose();
	virtual bool IsServerMode() {return false;}
	virtual bool ProcessPacket(PacketHelper* packet, bool send);
	virtual LPCTSTR GetName() {return _T("Barba Client");}
	static bool ShouldGrabPacket(PacketHelper* packet, BarbaClientConfig* config);
	
	std::vector<BarbaClientConfig> Configs;
	BarbaClientConnectionManager ConnectionManager;
	std::string HttpGetTemplate;
	std::string HttpPostTemplate;
	std::string HttpGetTemplateBombard;
	std::string HttpPostTemplateBombard;

protected:
	void Load() override;

private:
	BarbaClientConfig* ShouldGrabPacket(PacketHelper* packet);
};

extern BarbaClientApp* theClientApp;