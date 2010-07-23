#include "libqcontenthub.h"


namespace qcontent {

int HubClient::add_queue(const std::string &name, int capacity)
{
    m_error_str.clear();
    try {
        return m_client.call("add", name, capacity).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::del_queue(const std::string &name)
{
    m_error_str.clear();
    try {
        return m_client.call("del", name).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::start_queue(const std::string &name)
{
    m_error_str.clear();
    try {
        return m_client.call("start", name).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::stop_queue(const std::string &name)
{
    m_error_str.clear();
    try {
        return m_client.call("stop", name).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::force_del_queue(const std::string &name)
{
    m_error_str.clear();
    try {
        return m_client.call("fdel", name).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::push_queue(const std::string &name, const std::string &content)
{
    m_error_str.clear();
    try {
        return m_client.call("push", name, content).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::pop_queue(const std::string &name, std::string &content)
{
    m_error_str.clear();
    try {
        content = m_client.call("pop", name).get<std::string>();
        if (content == QCONTENTHUB_STRERROR) {
            m_error_str = "qcontenthub server str error";
            return -1;
        }
        return 0;
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::stats(std::string &stats_content)
{
    m_error_str.clear();
    try {
        stats_content = m_client.call("stats").get<std::string>();
        return 0;
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

int HubClient::stat_queue(const std::string &name, std::string &stats_content)
{
    m_error_str.clear();
    try {
        stats_content = m_client.call("stat", name).get<std::string>();
        return 0;
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return -1;
    }
}

const std::string& HubClient::error_str()
{
    return m_error_str;
}

}
