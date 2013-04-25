/*!
 Linphone Web - Web plugin of Linphone an audio/video SIP phone
 Copyright (C) 2012  Yann Diorcet <yann.diorcet@linphone.org>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef H_PROXYCONFIGAPI
#define H_PROXYCONFIGAPI

#include <linphonecore.h>
#include "wrapperapi.h"

FB_FORWARD_PTR(CoreAPI)

FB_FORWARD_PTR(ProxyConfigAPI)
class ProxyConfigAPI: public WrapperAPI {
    friend class FactoryAPI;
private:
	LinphoneProxyConfig *mProxyConfig;

	ProxyConfigAPI(LinphoneProxyConfig *proxyConfig);
    
protected:
	void initProxy();
    
public:
	ProxyConfigAPI();
	~ProxyConfigAPI();

	CoreAPIPtr getCore() const;

	std::string getContactParameters() const;
	void setContactParameters(const std::string &parameter);

	bool getDialEscapePlus() const;
	void setDialEscapePlus(bool escape);

	std::string getDialPrefix() const;
	void setDialPrefix(const std::string &prefix);

	std::string getDomain() const;
	int getError() const;

	bool publishEnabled() const;
	void enablePublish(bool enable);

	std::string getSipSetup() const;
	void setSipSetup(const std::string &sip_setup);

	bool isRegistered() const;
	//getSipSetupContext

	void setServerAddr(const std::string &server_addr);
	std::string getServerAddr() const;

	void setIdentity(const std::string &identity);
	std::string getIdentity() const;

	void setRoute(const std::string &route);
	std::string getRoute() const;

	void setExpires(int expires);
	int getExpires() const;

	void enableRegister(bool val);
	bool registerEnabled() const;

	int getState() const;

	void edit();
	int done();

	std::string normalizeNumber(const std::string &username) const;
	void refreshRegister();

	inline LinphoneProxyConfig *getRef() {
		mUsed = true;
		return mProxyConfig;
	}
};

#endif //H_PROXYCONFIGAPI
