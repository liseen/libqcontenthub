#ifndef LIBQCONTENTHUB_H
#define LIBQCONTENTHUB_H

#include <msgpack/rpc/client.h>
#include <string>

#include "qcontenthub/qcontenthub.h"

namespace qcontent {

class HubClient {
    HubClient(const std::string &host, uint16_t port, uint32_t timeout = 10000000):m_client(m_host, m_port), m_host(host), m_port(port), m_timeout(timeout) {
        m_client.set_timeout(timeout);
    }

    int add_queue(const std::string &name, int capacity = 1000);
    int del_queue(const std::string &name);
    int start_queue(const std::string &name);
    int stop_queue(const std::string &name);
    int force_del_queue(const std::string &name);
    int push_queue(const std::string &name, const std::string &content);
    int pop_queue(const std::string &name, std::string &content);
    int stats(std::string &stats_content);
    int stat_queue(const std::string &name, std::string &stats_content);

    const std::string& error_str();

private:
    std::string m_error_str;
    msgpack::rpc::client m_client;
    std::string m_host;
    uint16_t m_port;
    uint32_t m_timeout;
};


}

#endif
