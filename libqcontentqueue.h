#ifndef LIBQCONTENTQUEUE_H
#define LIBQCONTENTQUEUE_H

#include "libqcontenthub.h"

namespace qcontent {

class HubQueue {

public:
    HubQueue(const std::string &host, uint16_t port, const std::string &name, int capacity = 1000, uint32_t timeout = 3) : m_hub_client(host, port, timeout), m_host(host), m_port(port), m_name(name), m_capacity(capacity), m_timeout(timeout) {

    }

    int add();
    int start();
    int stop();
    int force_del();
    int push(const std::string &content);
    int push_nowait(const std::string &content);
    int pop(std::string &content);
    int pop_nowait(std::string &content);
    int stats(std::string &stats_content);
    int stat(std::string &stats_content);
    const std::string& error_str();
    HubClient & hub_client();

private:
    HubClient  m_hub_client;
    std::string m_host;
    uint16_t m_port;
    std::string m_name;
    int m_capacity;
    uint32_t m_timeout;
};


} // end namespace qcontent


#endif
