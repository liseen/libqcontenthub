#ifndef LIBURLQUEUE_H
#define LIBURLQUEUE_H

#include <msgpack/rpc/client.h>
#include <string>

#include "qcontenthub/qcontenthub.h"

namespace qcontent {

class UrlQueue {
public:
    UrlQueue(const std::string &host, uint16_t port, uint32_t timeout = 3 ) : \
        m_client(host, port), m_host(host), m_port(port), m_timeout(timeout) {

        m_client.set_timeout(timeout);
    }

    int push_url(const std::string &site, const std::string &recod);
    int pop_url(std::string &record);

    int set_default_interval(int interval);
    int set_site_interval(const std::string &site, int interval);
    int start_site(const std::string &site);
    int stop_site(const std::string &site);
    int clear_empty_site();
    int stats(std::string &stats_content);
    int stat_site(const std::string &site, std::string &stats_content);
    const std::string& error_str();

private:
    std::string m_error_str;
    msgpack::rpc::client m_client;
    std::string m_host;
    uint16_t m_port;
    uint32_t m_timeout;
};

} // end namespace qcontent

#endif

