#ifndef _rtpclient_h_
#define _rtpclient_h_

#include <gst/gst.h>
#include <cstring>

/**
 * UDP video client class
 */
namespace HighFlyers
{
class RtpClient
{
private:

    /**< gstreamer pipeline */
    GstElement* pipeline;

    /**< source of video (udp) */
    GstElement* src;

    /**< rtp depayloader */
    GstElement* depayloader;

    /**< video_rate */
    GstElement* video_rate;

    /**< fmt */
    GstElement* fmt;

    /**< video convert */
    GstElement* video_convert;

    /**< queue */
    GstElement* queue1;

    /**< encoder */
    GstElement* encoder;

    /**< queue */
    GstElement* queue2;

    /**< muxer */
    GstElement* mux;

    /**< file output */
    GstElement* sink;

    /**< ID of GstBus */
    guint bus_watch_id;

    /**< UDP server port */
    int _port;

    /**< UDP server host name */
    char* _ip;

    /**< handler of forwarding messages from the streaming threads */
    static gboolean bus_call(GstBus* bus, GstMessage* msg, gpointer data);

public:
    RtpClient();
    ~RtpClient();

    /**
     * \param IP Address
     *
     * server's IP Address
     */
    void set_ip(const char* host);

    /**
    * \param port
    *
    * server's port
    */
    void set_port(int port);

    /**
    * \return hostname or IP Address
    *
    * getter for host
    */
    char* get_ip()
    {
        return _ip;
    }

    /**
    * \return port
    *
    * getter for port
    */
    int get_port()
    {
        return _port;
    }

    /**
    * \param file name (mkv format)
    *
    * Save input stream to file
    */
    void read_to_file(const char* fileName);
};
}
#endif