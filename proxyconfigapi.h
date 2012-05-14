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

#include <JSAPIAuto.h>
#include <linphonecore.h>

class ProxyConfigAPI : public FB::JSAPIAuto {
private:
	LinphoneProxyConfig *mProxyConfig;

	ProxyConfigAPI(LinphoneProxyConfig *proxyConfig);
	void init_proxy();
public:
	ProxyConfigAPI();
	~ProxyConfigAPI();

	int setServerAddr(const std::string &server_addr);
	std::string getServerAddr() const;

	int setIdentity(const std::string &identity);
	std::string getIdentity() const;

	int setRoute(const std::string &route);
	std::string getRoute() const;

	void setExpires(int expires);
	int getExpires() const;

	void enableRegister(bool val);
	bool registerEnabled() const;

	int getState();

	void edit();
	int done();

	inline LinphoneProxyConfig *getRef() const{
		return mProxyConfig;
	}
	static boost::shared_ptr<ProxyConfigAPI> get(LinphoneProxyConfig *proxyConfig);
};

#endif //H_PROXYCONFIGAPI
