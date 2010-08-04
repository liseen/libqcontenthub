#include "liburlqueue.h"


namespace qcontent {

int UrlQueue::push_url(const std::string &site, const std::string &content)
{
    m_error_str.clear();
    try {
        return m_client.call("push", site, content).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return QCONTENTHUB_ERROR;
    }
}

int UrlQueue::pop_url(std::string &record)
{
    m_error_str.clear();
    try {
        record = m_client.call("pop").get<std::string>();
        if (record == QCONTENTHUB_STRERROR) {
            m_error_str = "qcontenthub server pop error";
            return QCONTENTHUB_ERROR;
        } else if (record == QCONTENTHUB_STRAGAIN) {
            return QCONTENTHUB_AGAIN;
        }
        return QCONTENTHUB_OK;
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return QCONTENTHUB_ERROR;
    }
}

int UrlQueue::set_default_interval(int interval)
{
    m_error_str.clear();
    try {
        return m_client.call("set_default_interval", interval).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return QCONTENTHUB_ERROR;
    }
}

int UrlQueue::set_site_interval(const std::string &site, int interval)
{
    m_error_str.clear();
    try {
        return m_client.call("set_site_interval", site, interval).get<int>();
    } catch (std::exception& e) {
       m_error_str = std::string(e.what());
       return QCONTENTHUB_ERROR;
    }
}

int UrlQueue::stats(std::string &stats_content)
{
    m_error_str.clear();
    try {
        stats_content = m_client.call("stats").get<std::string>();
        return QCONTENTHUB_OK;
    } catch (std::exception& e) {
        m_error_str = std::string(e.what());
        return QCONTENTHUB_ERROR;
    }
}

int UrlQueue::stat_site(const std::string &site, std::string &stats_content)
{
    m_error_str.clear();
    try {
        stats_content = m_client.call("stat_site", site).get<std::string>();
        return QCONTENTHUB_OK;
    } catch (std::exception& e) {
        m_error_str = std::string(e.what());
        return QCONTENTHUB_ERROR;
    }
}


const std::string& UrlQueue::error_str()
{
    return m_error_str;
}

}
